//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILENAME 256

void encrypt(const char *input_file, const char *output_file, int shift) {
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        fclose(input);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char ch = buffer[i];

            // Encrypt uppercase letters
            if (ch >= 'A' && ch <= 'Z') {
                ch = ((ch - 'A' + shift) % 26) + 'A';
            }
            // Encrypt lowercase letters
            else if (ch >= 'a' && ch <= 'z') {
                ch = ((ch - 'a' + shift) % 26) + 'a';
            }

            buffer[i] = ch;
        }
        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);
    printf("Hooray! The file has been encrypted and saved as %s\n", output_file);
}

int main() {
    char input_filename[MAX_FILENAME];
    char output_filename[MAX_FILENAME];
    int shift;

    printf("Welcome to the Happy File Encryptor!\n");
    printf("Let's secure your file with a cheerful encryption!\n");

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    printf("Enter the shift value (1-25) for encryption: ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Oops! The shift value should be between 1 and 25. Let's set it to 3 by default!\n");
        shift = 3;
    }

    encrypt(input_filename, output_filename, shift);

    printf("Thank you for using the Happy File Encryptor! Have a great day!\n");
    return 0;
}