//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_BUF_SIZE 1024

// Custom checksum calculation function
unsigned int calculate_checksum(unsigned char *data, unsigned int length) {
    unsigned int checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

int main() {
    char filename[MAX_BUF_SIZE];
    unsigned char file_data[MAX_BUF_SIZE];
    unsigned int file_size, checksum;

    printf("Welcome to the Checksum Calculator!\n");
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fread(file_data, 1, MAX_BUF_SIZE, file);
    file_size = ftell(file);
    fclose(file);

    printf("File size: %d bytes\n", file_size);
    printf("File data:\n");
    for (int i = 0; i < file_size; i++) {
        printf("%.2X ", file_data[i]);
    }
    printf("\n");

    checksum = calculate_checksum(file_data, file_size);
    printf("Checksum: %.2X\n", checksum);

    char user_input[MAX_BUF_SIZE];
    printf("Enter data to calculate checksum (up to %d bytes): ", MAX_BUF_SIZE);
    scanf("%s", user_input);

    unsigned int user_data_length = strlen(user_input);
    unsigned char user_data[MAX_BUF_SIZE];

    for (int i = 0; i < user_data_length; i++) {
        user_data[i] = (unsigned char) toupper(user_input[i]);
    }

    checksum = calculate_checksum(user_data, user_data_length);
    printf("Checksum: %.2X\n", checksum);

    return 0;
}