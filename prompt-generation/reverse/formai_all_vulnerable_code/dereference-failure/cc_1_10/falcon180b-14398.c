//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void sync_files(char* source_path, char* destination_path) {
    DIR* source_dir = opendir(source_path);
    DIR* destination_dir = opendir(destination_path);
    struct dirent* source_file;
    struct dirent* destination_file;
    char source_file_path[1024];
    char destination_file_path[1024];

    while ((source_file = readdir(source_dir))!= NULL) {
        if (source_file->d_type == DT_REG) {
            strcpy(source_file_path, source_path);
            strcat(source_file_path, "/");
            strcat(source_file_path, source_file->d_name);

            while ((destination_file = readdir(destination_dir))!= NULL) {
                if (destination_file->d_type == DT_REG && strcmp(destination_file->d_name, source_file->d_name) == 0) {
                    strcpy(destination_file_path, destination_path);
                    strcat(destination_file_path, "/");
                    strcat(destination_file_path, destination_file->d_name);

                    struct stat source_stat;
                    struct stat destination_stat;

                    stat(source_file_path, &source_stat);
                    stat(destination_file_path, &destination_stat);

                    if (source_stat.st_mtime > destination_stat.st_mtime) {
                        FILE* source_file_handle = fopen(source_file_path, "rb");
                        FILE* destination_file_handle = fopen(destination_file_path, "wb");

                        if (source_file_handle!= NULL && destination_file_handle!= NULL) {
                            char buffer[BUFFER_SIZE];
                            int bytes_read;

                            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file_handle)) > 0) {
                                fwrite(buffer, 1, bytes_read, destination_file_handle);
                            }

                            fclose(source_file_handle);
                            fclose(destination_file_handle);
                        }
                    }
                }
            }
        }
    }

    closedir(source_dir);
    closedir(destination_dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}