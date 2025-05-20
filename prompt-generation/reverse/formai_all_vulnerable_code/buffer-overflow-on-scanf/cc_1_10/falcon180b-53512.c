//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

int main() {
    char key[MAX_SIZE];
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    char buffer[MAX_SIZE];
    FILE *fp_in, *fp_out;
    int i, j, k, n;

    // Get the encryption key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Get the input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open the input file for reading
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the output file for writing
    strcat(input_file, ".enc");
    fp_out = fopen(input_file, "wb");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read the input file and encrypt it
    while ((n = fread(buffer, 1, MAX_SIZE, fp_in)) > 0) {
        for (i = 0; i < n; i++) {
            // Encrypt the character using the key
            j = (int)buffer[i] ^ (int)key[i % strlen(key)];

            // Convert the encrypted character to uppercase
            if (isalpha(j)) {
                if (isupper(j)) {
                    j = j + 32;
                } else {
                    j = j - 32;
                }
            }

            // Write the encrypted character to the output file
            fwrite(&j, 1, 1, fp_out);
        }
    }

    // Close the input and output files
    fclose(fp_in);
    fclose(fp_out);

    printf("File encrypted successfully.\n");

    return 0;
}