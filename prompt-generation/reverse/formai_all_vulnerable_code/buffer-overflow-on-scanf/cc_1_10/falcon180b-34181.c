//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secret_key"

void encrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char ch, key_ch;
    int i, j;

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch = fgetc(input))!= EOF) {
        key_ch = toupper(KEY[i % strlen(KEY)]);
        i++;

        if (isalpha(ch)) {
            if (isupper(ch)) {
                j = (int) ch - 65;
                ch = (char) ((j + (int) key_ch - 65) % 26 + 65);
            } else {
                j = (int) ch - 97;
                ch = (char) ((j + (int) key_ch - 97) % 26 + 97);
            }
        }

        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[100], output_file[100];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    strcpy(output_file, input_file);
    strcat(output_file, ".enc");

    encrypt(input_file, output_file);

    printf("File encrypted successfully\n");
    return 0;
}