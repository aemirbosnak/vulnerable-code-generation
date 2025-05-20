//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DIR_DEPTH 1000
#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
} FileInfo;

void print_file_info(FileInfo *file_info, int num_files) {
    printf("File Name\t\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t\t%zu bytes\n", file_info[i].name, file_info[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    char dir_path[MAX_FILE_NAME_LENGTH];
    strcpy(dir_path, argv[1]);

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(dir_path))!= NULL) {
        int num_files = 0;
        FileInfo file_info[MAX_FILE_NAME_LENGTH];

        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                if (num_files >= MAX_FILE_NAME_LENGTH) {
                    printf("Maximum number of files reached.\n");
                    break;
                }

                sprintf(file_info[num_files].name, "%s", ent->d_name);
                struct stat stat_buf;
                if (stat(ent->d_name, &stat_buf) == 0) {
                    file_info[num_files].size = stat_buf.st_size;
                } else {
                    file_info[num_files].size = 0;
                }
                num_files++;
            }
        }

        closedir(dir);

        if (num_files > 0) {
            print_file_info(file_info, num_files);
        }
    } else {
        perror("");
        return 1;
    }

    return 0;
}