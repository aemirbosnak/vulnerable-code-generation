//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

// Function to calculate the checksum of a buffer
unsigned int calculate_checksum(unsigned char *buffer, int length) {
    unsigned int checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

// Function to read a file into a buffer
unsigned char *read_file(char *filename, int *length) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: file '%s' is too large\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_SET);
    unsigned char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error: could not allocate memory for buffer\n");
        exit(1);
    }
    if (fread(buffer, 1, file_size, file)!= file_size) {
        fprintf(stderr, "Error: could not read file '%s'\n", filename);
        exit(1);
    }
    *length = file_size;
    fclose(file);
    return buffer;
}

// Function to write a buffer to a file
void write_file(char *filename, unsigned char *buffer, int length) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }
    if (fwrite(buffer, 1, length, file)!= length) {
        fprintf(stderr, "Error: could not write file '%s'\n", filename);
        exit(1);
    }
    fclose(file);
}

// Function to print the checksum of a buffer
void print_checksum(unsigned char *buffer, int length, unsigned int checksum) {
    printf("Checksum: %08X\n", checksum);
}

int main() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);
    unsigned char *buffer;
    int length;
    buffer = read_file(filename, &length);
    unsigned int checksum = calculate_checksum(buffer, length);
    print_checksum(buffer, length, checksum);
    write_file("checksum.txt", buffer, length);
    free(buffer);
    return 0;
}