//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input_file_name[100];
    char output_file_name[100];
    FILE *input_file, *output_file;
    char buffer[BUFFER_SIZE];
    int key;
    int i;

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Open input file
    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Open output file
    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        fclose(input_file);
        exit(1);
    }

    // Encrypt file
    while (fread(buffer, BUFFER_SIZE, 1, input_file)!= 0) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, BUFFER_SIZE, 1, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");

    return 0;
}