//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compress(FILE *input_file, FILE *output_file) {
    char ch;
    int count = 0;
    char previous_char = '\0';

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            if (ch == previous_char) {
                count++;
            } else {
                fprintf(output_file, "%c%d", ch, count);
                count = 1;
                previous_char = ch;
            }
        } else {
            fprintf(output_file, "%c", ch);
            previous_char = '\0';
        }
    }

    if (count > 1) {
        fprintf(output_file, "%c%d", previous_char, count);
    }

    fclose(input_file);
    fclose(output_file);
}

void decompress(FILE *input_file, FILE *output_file) {
    char ch;
    int count = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            fprintf(output_file, "%c", ch);
            count++;
        } else if (ch >= '0' && ch <= '9') {
            count = ch - '0';
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    FILE *input_file, *output_file;
    char filename[50];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("compressed.txt", "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    compress(input_file, output_file);

    printf("Compression completed.\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}