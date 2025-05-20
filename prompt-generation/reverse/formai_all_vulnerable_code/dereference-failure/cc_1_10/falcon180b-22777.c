//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 4096

typedef struct {
    char path[MAX_PATH];
    double size;
    int is_file;
} file_info;

void get_files_in_dir(const char* path, file_info files[], int* num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char new_path[MAX_PATH];
            sprintf(new_path, "%s/%s", path, entry->d_name);
            get_files_in_dir(new_path, files, num_files);
        } else {
            file_info file;
            strcpy(file.path, path);
            strcat(file.path, "/");
            strcat(file.path, entry->d_name);

            struct stat stat_buf;
            if (stat(file.path, &stat_buf) == -1) {
                printf("Error getting file info: %s\n", file.path);
                exit(1);
            }

            file.size = stat_buf.st_size;
            file.is_file = S_ISREG(stat_buf.st_mode);

            files[*num_files] = file;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void print_files(file_info files[], int num_files) {
    printf("File\tSize\tIs File\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%.2f KB\t%s\n", files[i].path, files[i].size / 1024.0, files[i].is_file? "Yes" : "No");
    }
}

void analyze_disk_space(const char* path) {
    struct statvfs stat_vfs;
    if (statvfs(path, &stat_vfs) == -1) {
        printf("Error getting disk space info: %s\n", path);
        exit(1);
    }

    double total_space = stat_vfs.f_blocks * stat_vfs.f_frsize;
    double used_space = (double)stat_vfs.f_blocks - stat_vfs.f_bfree;
    double free_space = stat_vfs.f_bfree * stat_vfs.f_frsize;

    printf("Disk Space Analysis:\n");
    printf("Total Space: %.2f GB\n", total_space / (1024.0 * 1024.0));
    printf("Used Space: %.2f GB\n", used_space / (1024.0 * 1024.0));
    printf("Free Space: %.2f GB\n", free_space / (1024.0 * 1024.0));

    file_info files[1000];
    int num_files = 0;

    get_files_in_dir(path, files, &num_files);
    print_files(files, num_files);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}