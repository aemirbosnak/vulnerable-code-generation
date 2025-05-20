//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000
#define KEY "mysecretkey"

void encrypt(char *file_path, char *output_path) {
    FILE *input_file, *output_file;
    char ch, key_ch;
    int i, j, key_index;

    input_file = fopen(file_path, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    output_file = fopen(output_path, "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input_file);
        exit(1);
    }

    key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        key_ch = toupper(KEY[key_index]);
        i = (int) ch;
        if (isalpha(ch)) {
            if (isupper(ch)) {
                j = 65;
            } else {
                j = 97;
            }
            i = i + (int) (key_ch - j);
            if (i > 90) {
                i = i - 26;
            } else if (i < 65) {
                i = i + 26;
            }
        } else {
            i = i + (int) (key_ch - 65);
            if (i > 90) {
                i = i - 26;
            } else if (i < 65) {
                i = i + 26;
            }
        }
        key_index++;
        if (key_index >= strlen(KEY)) {
            key_index = 0;
        }
        fputc(i, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_file[MAX_SIZE], output_file[MAX_SIZE];

    printf("Enter the path of the input file: ");
    scanf("%s", input_file);

    strcat(input_file, ".enc");
    strcpy(output_file, input_file);
    strcat(output_file, ".dec");

    encrypt(input_file, output_file);

    printf("Encryption completed successfully!\n");
    printf("Output file: %s\n", output_file);

    return 0;
}