//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // Maximum file size

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_SIZE];
    char buffer[MAX_SIZE];
    int filesize;
    int checksum = 0;

    // Get filename from command line argument
    strcpy(filename, argv[1]);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    // Read file contents into buffer
    while (fgets(buffer, MAX_SIZE, file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            checksum += buffer[i];
        }
    }

    // Close file
    fclose(file);

    // Calculate checksum
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;
    checksum = (checksum % 256) + 256;

    // Print checksum
    printf("Checksum: %d\n", checksum);

    return 0;
}