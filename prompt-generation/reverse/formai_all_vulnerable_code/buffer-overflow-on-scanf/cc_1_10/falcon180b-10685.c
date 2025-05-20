//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - 'a' + (int)key[0]) % 26 + 'a';
        }
        fputc(ch, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - (int)key[0] + 26) % 26 + 'a';
        }
        fputc(ch, output_file);
    }
}

int main() {
    char input_filename[100];
    char output_filename[100];
    char key[KEY_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    printf("Enter encryption key: ");
    scanf("%s", key);

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}