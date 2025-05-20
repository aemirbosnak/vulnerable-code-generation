//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // maximum file size in bytes

// function to read a file into memory
char* read_file(const char* filename) {
    FILE* fp;
    long file_size;
    char* buffer;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    buffer = (char*) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    buffer[file_size] = '\0';
    return buffer;
}

// function to write a buffer to a file
void write_file(const char* filename, const char* buffer) {
    FILE* fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(buffer, strlen(buffer), 1, fp);
    fclose(fp);
}

// function to make a backup of a file
void backup_file(const char* filename) {
    char* buffer;
    char backup_filename[MAX_SIZE];
    int i;

    strcpy(backup_filename, filename);
    i = strlen(backup_filename) - 1;
    while (i >= 0 && backup_filename[i]!= '.') {
        backup_filename[i] = '\0';
        i--;
    }
    strcat(backup_filename, ".bak");

    buffer = read_file(filename);
    write_file(backup_filename, buffer);

    printf("Backup created: %s\n", backup_filename);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    backup_file(argv[1]);

    return 0;
}