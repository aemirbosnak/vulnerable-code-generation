//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s source_directory destination_directory backup_file_name\n", argv[0]);
        return 1;
    }

    char source_dir[1024], dest_dir[1024], backup_file[1024];
    strcpy(source_dir, argv[1]);
    strcpy(dest_dir, argv[2]);
    strcpy(backup_file, argv[3]);

    struct stat sb;
    if (stat(source_dir, &sb) == -1) {
        fprintf(stderr, "Error: Source directory '%s' does not exist.\n", source_dir);
        return 1;
    }

    int i;
    for (i = 0; i < sb.st_blocks * sb.st_blksize; i++) {
        char filename[1024];
        sprintf(filename, "%s/%d", source_dir, i);
        if (stat(filename, &sb) == -1)
            continue;

        if (S_ISREG(sb.st_mode)) {
            char dest_filename[1024];
            sprintf(dest_filename, "%s/%d", dest_dir, i);
            if (stat(dest_filename, &sb) == -1) {
                FILE *src, *dest;
                src = fopen(filename, "rb");
                dest = fopen(dest_filename, "wb");
                if (src == NULL || dest == NULL) {
                    fprintf(stderr, "Error: Unable to open file '%s' or '%s' for reading/writing.\n", filename, dest_filename);
                    return 1;
                }
                fseek(src, 0, SEEK_END);
                size_t file_size = ftell(src);
                fseek(src, 0, SEEK_SET);
                size_t bytes_read = fread(backup_file, 1, file_size, src);
                fclose(src);
                fclose(dest);
                if (bytes_read!= file_size) {
                    fprintf(stderr, "Error: Failed to read file '%s' of size %zu.\n", filename, file_size);
                    return 1;
                }
                if (rename(backup_file, filename) == -1) {
                    fprintf(stderr, "Error: Failed to rename '%s' to '%s'.\n", backup_file, filename);
                    return 1;
                }
                fprintf(stderr, "Successfully backed up '%s' to '%s'.\n", filename, dest_filename);
            } else {
                fprintf(stderr, "Error: Destination directory '%s' already exists.\n", dest_dir);
                return 1;
            }
        }
    }

    return 0;
}