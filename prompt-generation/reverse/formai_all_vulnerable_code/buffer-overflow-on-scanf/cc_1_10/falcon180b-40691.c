//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // size of each block of data
#define MAX_FILE_SIZE 100000 // maximum size of the file to be recovered

typedef struct {
    char filename[100];
    int filesize;
} file_header;

void read_file_header(FILE* file, file_header* header) {
    memset(header, 0, sizeof(file_header));
    fseek(file, 0, SEEK_SET);
    fread(header->filename, sizeof(char), 100, file);
    fseek(file, 0, SEEK_SET);
    fread(&header->filesize, sizeof(int), 1, file);
}

void write_file_header(FILE* file, file_header* header) {
    fseek(file, 0, SEEK_SET);
    fwrite(header->filename, sizeof(char), 100, file);
    fseek(file, 0, SEEK_SET);
    fwrite(&header->filesize, sizeof(int), 1, file);
}

void recover_file(FILE* file, char* filename) {
    file_header header;
    char buffer[BLOCK_SIZE];
    int bytes_read;
    FILE* recovered_file;

    read_file_header(file, &header);

    if (header.filesize <= 0 || header.filesize > MAX_FILE_SIZE) {
        printf("Invalid file size: %d\n", header.filesize);
        return;
    }

    recovered_file = fopen(filename, "wb");
    if (recovered_file == NULL) {
        printf("Error opening recovered file: %s\n", filename);
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, recovered_file);
    }

    fclose(file);
    fclose(recovered_file);
    printf("File %s recovered successfully!\n", filename);
}

int main() {
    FILE* file;
    char filename[100];
    int choice;

    do {
        printf("Enter the name of the file to recover: ");
        scanf("%s", filename);

        file = fopen(filename, "rb");
        if (file == NULL) {
            printf("File not found.\n");
        } else {
            printf("File found. Do you want to recover it? (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                recover_file(file, filename);
            }
        }

        fclose(file);
        printf("\n");
    } while (1);

    return 0;
}