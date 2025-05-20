//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

void sync_files(char src_path[], char dest_path[]) {

    DIR* src_dir = opendir(src_path);
    DIR* dest_dir = opendir(dest_path);
    struct dirent* entry;

    // check if src and dest paths exist
    if (src_dir == NULL) {
        printf("Error: Source path does not exist.\n");
        exit(1);
    }
    if (dest_dir == NULL) {
        printf("Error: Destination path does not exist.\n");
        exit(1);
    }

    // loop through files in source directory
    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // if file is a regular file
            char src_file[MAX_PATH_LEN];
            char dest_file[MAX_PATH_LEN];
            sprintf(src_file, "%s/%s", src_path, entry->d_name);
            sprintf(dest_file, "%s/%s", dest_path, entry->d_name);

            struct stat src_stat, dest_stat;
            int src_res = stat(src_file, &src_stat);
            int dest_res = stat(dest_file, &dest_stat);

            // if the file exists in src and not in dest, copy file
            if (src_res == 0 && dest_res == -1) {
                printf("Copying file %s to %s\n", src_file, dest_file);
                FILE* src_file_ptr = fopen(src_file, "rb");
                FILE* dest_file_ptr = fopen(dest_file, "wb");
                if (src_file_ptr == NULL || dest_file_ptr == NULL) {
                    printf("Error: Unable to open file.\n");
                    exit(1);
                }
                char buffer[1024];
                size_t read;
                while ((read = fread(buffer, 1, sizeof(buffer), src_file_ptr)) > 0) {
                    fwrite(buffer, 1, read, dest_file_ptr);
                }
                fclose(src_file_ptr);
                fclose(dest_file_ptr);
            }
            // if file exists in both src and dest, check if they have the same modified time
            else if (src_res == 0 && dest_res == 0) {
                if (src_stat.st_mtime > dest_stat.st_mtime) {  // src file is newer, so overwrite dest file
                    printf("Overwriting file %s\n", dest_file);
                    unlink(dest_file);  // delete dest file
                    FILE* src_file_ptr = fopen(src_file, "rb");
                    FILE* dest_file_ptr = fopen(dest_file, "wb");
                    if (src_file_ptr == NULL || dest_file_ptr == NULL) {
                        printf("Error: Unable to open file.\n");
                        exit(1);
                    }
                    char buffer[1024];
                    size_t read;
                    while ((read = fread(buffer, 1, sizeof(buffer), src_file_ptr)) > 0) {
                        fwrite(buffer, 1, read, dest_file_ptr);
                    }
                    fclose(src_file_ptr);
                    fclose(dest_file_ptr);
                }
                else if (src_stat.st_mtime < dest_stat.st_mtime) {  // dest file is newer, so overwrite src file
                    printf("Overwriting file %s\n", src_file);
                    unlink(src_file);  // delete src file
                    FILE* src_file_ptr = fopen(src_file, "wb");
                    FILE* dest_file_ptr = fopen(dest_file, "rb");
                    if (src_file_ptr == NULL || dest_file_ptr == NULL) {
                        printf("Error: Unable to open file.\n");
                        exit(1);
                    }
                    char buffer[1024];
                    size_t read;
                    while ((read = fread(buffer, 1, sizeof(buffer), dest_file_ptr)) > 0) {
                        fwrite(buffer, 1, read, src_file_ptr);
                    }
                    fclose(src_file_ptr);
                    fclose(dest_file_ptr);
                }
            }
            // if file exists in dest but not in src, delete file
            else if (src_res == -1 && dest_res == 0) {
                printf("Deleting file %s\n", dest_file);
                unlink(dest_file);  // delete dest file
            }
        }
        else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {  // if file is a directory
            char src_subdir[MAX_PATH_LEN];
            char dest_subdir[MAX_PATH_LEN];
            sprintf(src_subdir, "%s/%s", src_path, entry->d_name);
            sprintf(dest_subdir, "%s/%s", dest_path, entry->d_name);
            sync_files(src_subdir, dest_subdir);  // recursively call sync_files on subdir
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main() {
    sync_files("src", "dest");
    return 0;
}