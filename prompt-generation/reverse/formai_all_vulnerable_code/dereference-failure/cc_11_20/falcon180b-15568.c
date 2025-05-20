//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage:./encryptor [input_file] [output_file] [key] [mode]\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    strncpy(key, argv[3], MAX_KEY_LENGTH);
    for (int i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    char mode = argv[4][0];

    int current_position = 0;
    char buffer[MAX_FILE_SIZE];
    int buffer_position = 0;

    while (fgets(buffer + buffer_position, 1, input_file)!= NULL) {
        if (buffer_position == MAX_FILE_SIZE) {
            printf("Error: Input file too large.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        char c = buffer[buffer_position];
        if (isalpha(c)) {
            c = (c - 'a') % 26 + 'a';
            int index = 0;
            while (key[index]!= c) {
                index++;
                if (index == strlen(key)) {
                    index = 0;
                }
            }

            c = (c + key[index]) % 26 + 'a';
        } else {
            c = c;
        }

        if (mode == 'e') {
            c = (c + 13) % 26 + 'a';
        } else if (mode == 'd') {
            c = (c - 13) % 26 + 'a';
        }

        fputc(c, output_file);
        buffer_position++;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted/decrypted successfully.\n");
    return 0;
}