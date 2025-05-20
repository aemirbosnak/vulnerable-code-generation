//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[100];
    char checksum[50];
} FileChecksum;

void generate_checksum(char* file_name, char* checksum) {
    FILE* file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, file);

    if (bytes_read!= MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        exit(1);
    }

    unsigned char checksum_value = 0;

    for (int i = 0; i < bytes_read; i++) {
        checksum_value += buffer[i];
    }

    sprintf(checksum, "%02X", checksum_value);

    fclose(file);
}

int main() {
    int num_files;
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    FileChecksum files[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name for file %d: ", i+1);
        scanf("%s", files[i].file_name);

        generate_checksum(files[i].file_name, files[i].checksum);

        printf("Checksum for %s: %s\n", files[i].file_name, files[i].checksum);
    }

    return 0;
}