//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 256
#define MAX_PATH 1024

typedef struct {
    char *name;
    int is_infected;
} FileInfo;

void scan_directory(const char *dir_path, int depth, int *total_files, int *infected_files) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH];

    if ((dir = opendir(dir_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, MAX_PATH, "%s/%s", dir_path, ent->d_name);
                scan_directory(path, depth + 1, total_files, infected_files);
            } else {
                FileInfo file_info;
                snprintf(path, MAX_PATH, "%s/%s", dir_path, ent->d_name);
                file_info.name = ent->d_name;
                file_info.is_infected = 0;

                FILE *file;
                if ((file = fopen(path, "rb"))!= NULL) {
                    fseek(file, 0, SEEK_END);
                    long file_size = ftell(file);
                    rewind(file);

                    char buffer[MAX_FILE_NAME];
                    int buffer_size = fread(buffer, 1, MAX_FILE_NAME, file);

                    if (buffer_size > 0) {
                        for (int i = 0; i < buffer_size; i++) {
                            if (!isalnum(buffer[i])) {
                                file_info.is_infected = 1;
                                break;
                            }
                        }
                    }

                    fclose(file);
                }

                *total_files += 1;
                if (file_info.is_infected) {
                    *infected_files += 1;
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    int total_files = 0;
    int infected_files = 0;

    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1], 0, &total_files, &infected_files);

    printf("Total files scanned: %d\n", total_files);
    printf("Infected files found: %d\n", infected_files);

    return 0;
}