//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1000

int main() {
    char input_file[MAX_BUFFER_SIZE];
    char output_file[MAX_BUFFER_SIZE];
    char key[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    FILE *input = NULL, *output = NULL;
    int key_length = 0, i, j, k, n = 0;
    int bytes_read, bytes_written;

    // Get the input file name
    printf("Enter the input file name: ");
    scanf("%s", input_file);

    // Get the output file name
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Get the encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Calculate the length of the key
    key_length = strlen(key);

    // Open the input file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1;
    }

    // Read the input file
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, input)) > 0) {
        for (i = 0, j = 0; i < bytes_read; i++) {
            // Encrypt the file data
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                if (isupper(c)) {
                    c = 'A' + ((c - 'A' + key_length) % 26);
                } else {
                    c = 'a' + ((c - 'a' + key_length) % 26);
                }
            }

            // Write the encrypted data to the output file
            buffer[n++] = c;
        }

        // Write the buffer to the output file
        bytes_written = fwrite(buffer, 1, n, output);
        if (bytes_written!= n) {
            printf("Error writing to output file.\n");
            fclose(input);
            fclose(output);
            return 1;
        }

        // Reset the buffer
        n = 0;
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");
    return 0;
}