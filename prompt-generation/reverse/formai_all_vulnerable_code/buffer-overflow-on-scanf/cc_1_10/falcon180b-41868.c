//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 256

char *hex_str = "0123456789ABCDEF";

char *hex_convert(unsigned char c) {
    return strchr(hex_str, tolower(c));
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_SIZE], output_filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *hex_line = malloc(MAX_LINE_SIZE);
    int line_num = 0;
    int i;
    int hex_line_len = 0;

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        line_num++;
        hex_line_len = 0;
        for (i = 0; i < strlen(line); i++) {
            char c = line[i];
            if (isprint(c)) {
                char hex_c = hex_convert(c);
                strncat(hex_line, hex_c, 2);
                hex_line_len += 2;
            } else {
                strncat(hex_line, ".", 1);
                hex_line_len++;
            }
        }
        fprintf(output_file, "Line %d: %s\n", line_num, hex_line);
        hex_line_len = 0;
    }

    fclose(input_file);
    fclose(output_file);

    free(hex_line);
    return 0;
}