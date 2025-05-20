//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to synchronize files between two directories
void synchronize_files(char* source_dir, char* dest_dir) {
    DIR* src_dir = opendir(source_dir);
    DIR* dest_dir_ptr = opendir(dest_dir);
    struct dirent* dirent;
    char src_path[2048];
    char dest_path[2048];

    while ((dirent = readdir(src_dir))!= NULL) {
        if (dirent->d_type!= DT_DIR) {
            strcpy(src_path, source_dir);
            strcat(src_path, "/");
            strcat(src_path, dirent->d_name);

            dest_dir_ptr = opendir(dest_dir);
            struct dirent* dest_dirent;

            while ((dest_dirent = readdir(dest_dir_ptr))!= NULL) {
                if (strcmp(dest_dirent->d_name, dirent->d_name) == 0) {
                    closedir(dest_dir_ptr);
                    break;
                }
            }

            if (dest_dirent == NULL) {
                strcpy(dest_path, dest_dir);
                strcat(dest_path, "/");
                strcat(dest_path, dirent->d_name);

                if (mkdir(dest_path, 0777)!= 0) {
                    perror("mkdir");
                    exit(1);
                }
            }

            FILE* src_file = fopen(src_path, "r");
            FILE* dest_file = fopen(dest_path, "w");

            if (src_file == NULL || dest_file == NULL) {
                perror("fopen");
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, src_file)!= NULL) {
                fputs(buffer, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir);
    closedir(dest_dir_ptr);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}