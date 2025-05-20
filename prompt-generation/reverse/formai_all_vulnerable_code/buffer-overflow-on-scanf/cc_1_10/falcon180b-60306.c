//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[50];
    char output_filename[50];
    char ch;
    int i = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(0);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input_file);
        exit(0);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ch + 3;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        } else if (isdigit(ch)) {
            ch = ch + 2;
            if (ch > '9') {
                ch = ch - 7;
            }
        } else {
            ch = ch;
        }
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");

    return 0;
}