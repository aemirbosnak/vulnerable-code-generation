//Code Llama-13B DATASET v1.0 Category: Checksum Calculator ; Style: scalable
// Checksum Calculator Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned int calculate_checksum(const char *str) {
    unsigned int checksum = 0;
    while (*str) {
        checksum += *str++;
    }
    return checksum;
}

// Function to calculate the checksum of a file
unsigned int calculate_file_checksum(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1;
    }
    unsigned int checksum = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        checksum += c;
    }
    fclose(file);
    return checksum;
}

// Function to print the checksum
void print_checksum(const char *str) {
    unsigned int checksum = calculate_checksum(str);
    printf("Checksum of '%s' is %u\n", str, checksum);
}

// Function to print the checksum of a file
void print_file_checksum(const char *filename) {
    unsigned int checksum = calculate_file_checksum(filename);
    if (checksum == -1) {
        return;
    }
    printf("Checksum of file '%s' is %u\n", filename, checksum);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string> or %s <filename>\n", argv[0], argv[0]);
        return 1;
    }
    if (argc == 2) {
        print_checksum(argv[1]);
    } else {
        print_file_checksum(argv[2]);
    }
    return 0;
}