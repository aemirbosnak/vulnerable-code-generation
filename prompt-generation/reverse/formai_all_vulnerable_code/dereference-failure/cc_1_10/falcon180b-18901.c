//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    char c, input_line[500];
    int i, j;

    if(argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if(input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "w");
    if(output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while((c = fgetc(input_file))!= EOF) {
        if(isalpha(c)) {
            // Convert character to uppercase
            c = toupper(c);

            // Get ASCII value of character
            int ascii_value = c - 'A' + 1;

            // Print ASCII art
            for(i = 0; i < 6; i++) {
                for(j = 0; j < 8; j++) {
                    if((ascii_value & (1 << (i * 8 + j)))!= 0) {
                        fprintf(output_file, "*");
                    } else {
                        fprintf(output_file, " ");
                    }
                }
                fprintf(output_file, "\n");
            }
        } else {
            // Print non-alphabetic characters as is
            fprintf(output_file, "%c", c);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}