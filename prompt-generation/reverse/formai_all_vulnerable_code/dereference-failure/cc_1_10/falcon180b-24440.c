//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define KEY_LENGTH 16

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char key_repeat[KEY_LENGTH + 1] = {0};
    strncpy(key_repeat, key, KEY_LENGTH);

    char line[MAX_LINE_LENGTH] = {0};
    char encrypted_line[MAX_LINE_LENGTH] = {0};

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        int line_length = strlen(line);
        int encrypted_line_length = 0;

        for (int i = 0; i < line_length; i++) {
            char c = line[i];

            if (isalpha(c)) {
                c = (c - 'A' + key_repeat[i % KEY_LENGTH]) % 26 + 'A';
            }

            encrypted_line[encrypted_line_length++] = c;
        }

        encrypted_line[encrypted_line_length] = '\0';
        fputs(encrypted_line, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2], argv[3]);

    return 0;
}