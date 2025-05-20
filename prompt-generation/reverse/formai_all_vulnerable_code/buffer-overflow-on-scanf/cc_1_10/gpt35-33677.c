//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 100000

int main(int argc, char *argv[]) {
    char file_input_name[MAX_FILENAME_LENGTH];
    char file_output_name[MAX_FILENAME_LENGTH];
    char message[MAX_BUFFER_SIZE];

    printf("Enter input file name: ");
    scanf("%s", file_input_name);

    FILE *file_input = fopen(file_input_name, "rb");

    if (file_input == NULL) {
        printf("Could not open input file\n");
        return 1;
    }

    printf("Enter output file name: ");
    scanf("%s", file_output_name);

    FILE *file_output = fopen(file_output_name, "wb");

    if (file_output == NULL) {
        printf("Could not open output file\n");
        fclose(file_input);
        return 1;
    }

    printf("Enter secret message: ");
    scanf("%s", message);

    int message_length = strlen(message);

    if (message_length * 8 > MAX_BUFFER_SIZE) {
        printf("Message too long for image\n");
        fclose(file_input);
        fclose(file_output);
        return 1;
    }

    unsigned char *buffer = malloc(MAX_BUFFER_SIZE);

    if (buffer == NULL) {
        printf("Could not allocate memory\n");
        fclose(file_input);
        fclose(file_output);
        return 1;
    }

    int buffer_size = fread(buffer, sizeof(unsigned char), MAX_BUFFER_SIZE, file_input);

    if (buffer_size == 0) {
        printf("Could not read from input file\n");
        fclose(file_input);
        fclose(file_output);
        free(buffer);
        return 1;
    }

    int i, j;
    unsigned char c, mask;

    for (i = 0, j = 0; j < message_length; i++) {
        c = buffer[i];

        if (j % 8 == 0) {
            mask = 0x01;
        }

        if (j / 8 < buffer_size - 1) {
            buffer[i] = (buffer[i] & ~mask) | ((message[j / 8] & (0x01 << (j % 8))) >> (j % 8));
        }

        j++;
        mask <<= 1;
    }

    fwrite(buffer, sizeof(unsigned char), buffer_size, file_output);

    free(buffer);
    fclose(file_input);
    fclose(file_output);

    printf("Steganography complete. Use a hex editor to view the result\n");
    return 0;
}