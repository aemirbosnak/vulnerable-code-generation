//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_file_name[MAX_FILE_LEN], output_file_name[MAX_FILE_LEN];
    char key[MAX_KEY_LEN];
    int key_len, file_len, i, j, k, temp;
    char ch;

    // Get the input file name from the user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    // Get the output file name from the user
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    // Get the encryption key from the user
    printf("Enter the encryption key (maximum %d characters): ", MAX_KEY_LEN);
    scanf("%s", key);

    // Calculate the length of the key
    key_len = strlen(key);

    // Open the input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Get the length of the input file
    fseek(input_file, 0, SEEK_END);
    file_len = ftell(input_file);
    rewind(input_file);

    // Create the output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: could not create output file.\n");
        fclose(input_file);
        exit(2);
    }

    // Loop through the input file and encrypt each character
    for (i = 0; i < file_len; i++) {
        ch = fgetc(input_file);

        // Encrypt the character using the key
        if (isalpha(ch)) {
            j = tolower(ch) - 'a';
            k = (j + key_len) % 26;
            temp = k + 'a';
            ch = (isupper(ch))? toupper(temp) : temp;
        } else if (isdigit(ch)) {
            ch = (ch + key_len) % 10 + '0';
        } else {
            ch = ch;
        }

        // Write the encrypted character to the output file
        fputc(ch, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption successful.\n");

    return 0;
}