//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to generate a random key
void generate_key(char* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char ch;
    int i;
    while ((ch = fgetc(input_file))!= EOF) {
        if (islower(ch)) {
            ch = (ch - 97 + 26 - (int)key[0]) % 26 + 97;
        } else if (isupper(ch)) {
            ch = (ch - 65 + 26 - (int)key[0]) % 26 + 65;
        }
        fputc(ch, output_file);
    }
}

int main() {
    // Get the input and output file names
    char input_file[100], output_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Get the key length
    int key_length;
    printf("Enter the key length: ");
    scanf("%d", &key_length);

    // Generate the key
    char key[key_length + 1];
    generate_key(key, key_length);

    // Open the input and output files
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Encrypt the file
    encrypt_file(input, output, key);

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");

    return 0;
}