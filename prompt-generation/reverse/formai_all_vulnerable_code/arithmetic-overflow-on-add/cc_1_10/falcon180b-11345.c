//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define CHECKSUM_LENGTH 4

void print_help() {
    printf("Usage:./checksum <filename> <checksum>\n");
    printf("Calculate the checksum of a file.\n");
    printf("filename: The name of the file to calculate checksum for.\n");
    printf("checksum: The expected checksum value.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_help();
        exit(1);
    }

    FILE *fp;
    char filename[MAX_LENGTH];
    char checksum[CHECKSUM_LENGTH];
    char buffer[MAX_LENGTH];
    int checksum_int;

    // Get the filename and checksum from command line arguments
    strcpy(filename, argv[1]);
    strcpy(checksum, argv[2]);

    // Open the file and read its contents into a buffer
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // Calculate the checksum
    int i;
    for (i = 0; i < file_size; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            checksum_int += buffer[i] - '0';
        } else if (buffer[i] >= 'A' && buffer[i] <= 'F') {
            checksum_int += buffer[i] - 'A' + 10;
        } else if (buffer[i] >= 'a' && buffer[i] <= 'f') {
            checksum_int += buffer[i] - 'a' + 10;
        }
    }

    // Convert the checksum to a string
    checksum[0] = (checksum_int / 1000000) % 10 + '0';
    checksum[1] = (checksum_int / 100000) % 10 + '0';
    checksum[2] = (checksum_int / 10000) % 10 + '0';
    checksum[3] = (checksum_int / 1000) % 10 + '0';

    // Compare the calculated checksum with the expected checksum
    if (strcmp(checksum, argv[2]) == 0) {
        printf("Checksum matches.\n");
    } else {
        printf("Checksum does not match.\n");
    }

    return 0;
}