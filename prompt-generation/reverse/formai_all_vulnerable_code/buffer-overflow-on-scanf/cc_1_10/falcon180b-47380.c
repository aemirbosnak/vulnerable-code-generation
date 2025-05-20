//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt_file(FILE* input, FILE* output) {
    char ch;
    int key_index = 0;

    while ((ch = fgetc(input))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = ch + (KEY[key_index] - 'A');
            if (ch > 'Z') {
                ch = ch - 26;
            }
            ch = tolower(ch);
        }
        fputc(ch, output);
        key_index = (key_index + 1) % strlen(KEY);
    }
}

int main() {
    FILE* input, *output;
    char filename[100];

    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", filename);

    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    output = fopen("encrypted.txt", "w");
    if (output == NULL) {
        printf("Error: Cannot create output file!\n");
        fclose(input);
        return 1;
    }

    encrypt_file(input, output);

    printf("File encryption successful!\n");

    fclose(input);
    fclose(output);

    return 0;
}