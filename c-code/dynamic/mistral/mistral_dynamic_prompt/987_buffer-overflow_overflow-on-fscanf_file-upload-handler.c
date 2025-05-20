#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define UPLOAD_FILE "/tmp/upload.txt"

void handle_upload(FILE *fp) {
    char buffer[BUFFER_SIZE];

    printf("Uploading file...\n");
    fscanf(fp, "%s", buffer);
    printf("Received file: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    FILE *file_ptr;
    char *filename = argv[1];

    if ((file_ptr = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    handle_upload(file_ptr);

    fclose(file_ptr);

    return 0;
}
