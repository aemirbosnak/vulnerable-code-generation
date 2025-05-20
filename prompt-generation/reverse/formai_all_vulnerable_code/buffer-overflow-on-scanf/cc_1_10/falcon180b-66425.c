//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000

void encrypt_file(FILE *input_file, FILE *output_file) {
    int c;
    int line_length = 0;
    char line[MAX_LINE_LEN];

    while ((c = fgetc(input_file))!= EOF) {
        if (line_length >= MAX_LINE_LEN) {
            fprintf(output_file, "\n");
            line_length = 0;
        }

        if (isalpha(c)) {
            c = toupper(c);
            c = ((c - 65) + 13) % 26 + 65;
        } else if (isdigit(c)) {
            c = ((c - 48) + 13) % 10 + 48;
        } else {
            c = c;
        }

        line[line_length++] = c;
    }

    if (line_length > 0) {
        fprintf(output_file, "\n");
    }
}

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_LEN];
    char output_filename[MAX_LINE_LEN];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    encrypt_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}