//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define MAX_KEY_VALUE 26

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LENGTH], output_filename[MAX_LENGTH];
    char key[MAX_KEY_LENGTH];
    int key_length, key_value;
    char buffer[MAX_LENGTH];
    int buffer_length, i;
    int j, k;
    int index;

    // Prompt user for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Prompt user for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Prompt user for encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Calculate length of encryption key
    key_length = strlen(key);

    // Validate encryption key
    for (i = 0; i < key_length; i++) {
        if (!isalpha(key[i])) {
            printf("Invalid encryption key. Key must only contain alphabetic characters.\n");
            exit(1);
        }
    }

    // Calculate key value
    key_value = 0;
    for (i = 0; i < key_length; i++) {
        if (isupper(key[i])) {
            key_value += (int)key[i] - 65;
        } else {
            key_value += (int)key[i] - 97;
        }
    }

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file into buffer
    buffer_length = 0;
    while ((fgets(buffer + buffer_length, MAX_LENGTH - buffer_length, input_file))!= NULL) {
        buffer_length += strlen(buffer);
    }

    // Close input file
    fclose(input_file);

    // Encrypt buffer
    for (i = 0; i < buffer_length; i++) {
        if (isalpha(buffer[i])) {
            j = tolower(buffer[i]) - 97;
            if (isupper(key[j % key_length])) {
                k = 65 + (j + key_value) % 26;
            } else {
                k = 97 + (j + key_value) % 26;
            }
            buffer[i] = k;
        }
    }

    // Write encrypted buffer to output file
    fprintf(output_file, "%s", buffer);

    // Close output file
    fclose(output_file);

    return 0;
}