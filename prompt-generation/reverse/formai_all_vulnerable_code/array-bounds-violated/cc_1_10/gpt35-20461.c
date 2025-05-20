//FormAI DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char file_name[100];
    char file_extension[10];
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Get the file extension
    int i = strlen(file_name) - 1;
    while (file_name[i] != '.') {
        i--;
    }
    strcpy(file_extension, file_name + i + 1);

    FILE *file_pointer;
    file_pointer = fopen(file_name, "rb");
    if (file_pointer == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the file into memory
    char *data = (char*) malloc(MAX_FILE_SIZE);
    int file_size = 0;
    while (!feof(file_pointer)) {
        data[file_size++] = getc(file_pointer);
    }
    fclose(file_pointer);

    // Check to see if the file is actually a JPEG image
    if (strcmp(file_extension, "jpg") != 0) {
        printf("This data recovery tool only works on JPEG images.\n");
        exit(2);
    }
    int start_byte = -1;
    int end_byte = -1;
    unsigned char jpeg_signature[] = {0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 0x4a, 0x46, 0x49, 0x46, 0x00};
    int signature_length = sizeof(jpeg_signature) / sizeof(jpeg_signature[0]);

    // Search for the JPEG Signature
    for (int i = 0; i < file_size - signature_length; i++) {
        if (memcmp(data + i, jpeg_signature, signature_length) == 0) {
            start_byte = i;
            break;
        }
    }

    // Search for the End of Image (EOI)
    unsigned char eoi_signature[] = {0xff, 0xd9};
    int eoi_length = sizeof(eoi_signature) / sizeof(eoi_signature[0]);
    for (int i = start_byte; i < file_size - eoi_length; i++) {
        if (memcmp(data + i, eoi_signature, eoi_length) == 0) {
            end_byte = i + eoi_length - 1;
            break;
        }
    }

    // Write the recovered image to a new file
    printf("Enter output file name: ");
    scanf("%s", file_name);
    file_pointer = fopen(file_name, "wb");
    if (file_pointer == NULL) {
        printf("Error creating file\n");
        exit(3);
    }
    fwrite(data + start_byte, 1, end_byte - start_byte + 1, file_pointer);
    fclose(file_pointer);
    printf("Successfully recovered JPEG image.\n");
    free(data);
    return 0;
}