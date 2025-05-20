//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to read a file into memory
void read_file(FILE *fp, char *buffer) {
    int bytes_read = 0;
    while ((bytes_read < MAX_FILE_SIZE) &&!feof(fp)) {
        fread(buffer + bytes_read, 1, 1, fp);
        bytes_read++;
    }
    buffer[bytes_read] = '\0'; // Add null terminator
}

// Function to write a buffer to a file
void write_file(FILE *fp, char *buffer) {
    int bytes_written = 0;
    while ((bytes_written < strlen(buffer)) &&!ferror(fp)) {
        fwrite(buffer + bytes_written, 1, 1, fp);
        bytes_written++;
    }
}

// Function to recover a deleted file
void recover_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", filename);
        return;
    }
    char buffer[MAX_FILE_SIZE];
    read_file(fp, buffer);
    fclose(fp);
    FILE *new_fp = fopen("recovered.txt", "wb");
    if (new_fp == NULL) {
        printf("Error: Could not create file recovered.txt.\n");
        return;
    }
    write_file(new_fp, buffer);
    fclose(new_fp);
    printf("File %s recovered!\n", filename);
}

int main() {
    char filename[100];
    printf("Enter the name of the deleted file: ");
    scanf("%s", filename);
    recover_file(filename);
    return 0;
}