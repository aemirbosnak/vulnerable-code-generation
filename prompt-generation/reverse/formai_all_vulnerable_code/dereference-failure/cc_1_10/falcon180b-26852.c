//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file_input, *file_output;
    char filename[100], ch;
    int i, j, key, length;

    // Get the filename and key from the user
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter key: ");
    scanf("%d", &key);

    // Open the input and output files
    file_input = fopen(filename, "rb");
    if (file_input == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }
    file_output = fopen("encrypted.txt", "wb");
    if (file_output == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    // Get the length of the file
    fseek(file_input, 0, SEEK_END);
    length = ftell(file_input);
    fseek(file_input, 0, SEEK_SET);

    // Initialize the key matrix
    int key_matrix[26][26];
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            key_matrix[i][j] = (i + j) % 26;
        }
    }

    // Encrypt the file
    for (i = 0; i < length; i++) {
        ch = fgetc(file_input);
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (isalpha(ch)) {
                ch = key_matrix[(int)ch - 65][(int)key - 65] % 26 + 65;
            }
        }
        fputc(ch, file_output);
    }

    // Close the files
    fclose(file_input);
    fclose(file_output);

    printf("File encrypted successfully!\n");
    return 0;
}