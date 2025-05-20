//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char ch, key;
    int i, j;

    if(argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    key = tolower(argv[3][0]);

    while((ch = fgetc(input_file))!= EOF) {
        if(isalpha(ch)) {
            ch = tolower(ch);
            j = 0;
            if(ch >= 'a' && ch <='m') {
                j = 13;
            } else if(ch >= 'n' && ch <= 'z') {
                j = 13 - (ch - 'n');
            }
            ch = (ch - 'a' + j) % 26 + 'a';
        }
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully!\n");

    return 0;
}