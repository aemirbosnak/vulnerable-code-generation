//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s source destination sync_type\n", argv[0]);
        return 1;
    }

    char *src_path = argv[1];
    char *dest_path = argv[2];
    char sync_type = argv[3][0];

    FILE *src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        perror("fopen");
        return 1;
    }

    FILE *dest_file = fopen(dest_path, "w");
    if (dest_file == NULL) {
        perror("fopen");
        fclose(src_file);
        return 1;
    }

    char buf[MAX_BUF_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buf, 1, MAX_BUF_SIZE, src_file)) > 0) {
        if (ferror(src_file)) {
            perror("fread");
            fclose(src_file);
            fclose(dest_file);
            return 1;
        }

        if (sync_type == 'a') {
            fseek(dest_file, 0, SEEK_END);
        } else if (sync_type == 'r') {
            fseek(dest_file, 0, SEEK_SET);
        }

        if (fwrite(buf, 1, bytes_read, dest_file)!= bytes_read) {
            perror("fwrite");
            fclose(src_file);
            fclose(dest_file);
            return 1;
        }
    }

    if (ferror(src_file)) {
        perror("fread");
        fclose(src_file);
        fclose(dest_file);
        return 1;
    }

    fclose(src_file);
    fclose(dest_file);

    return 0;
}