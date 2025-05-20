//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void sync_files(char *source_dir, char *dest_dir) {
    DIR *src_dir = opendir(source_dir);
    if (src_dir == NULL) {
        printf("Error: Could not open source directory.\n");
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(src_dir))!= NULL) {
        char src_path[1024];
        char dest_path[1024];
        strcpy(src_path, source_dir);
        strcat(src_path, "/");
        strcat(src_path, ent->d_name);

        strcpy(dest_path, dest_dir);
        strcat(dest_path, "/");
        strcat(dest_path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            mkdir(dest_path, 0777);
            sync_files(src_path, dest_path);
        } else if (ent->d_type == DT_REG) {
            FILE *src_file = fopen(src_path, "rb");
            if (src_file == NULL) {
                printf("Error: Could not open source file %s.\n", src_path);
                exit(1);
            }

            FILE *dest_file = fopen(dest_path, "wb");
            if (dest_file == NULL) {
                printf("Error: Could not open destination file %s.\n", dest_path);
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            int bytes_read;
            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}