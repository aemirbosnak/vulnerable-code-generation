//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100], ch;
    int i, j, key, n, count = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ch + key - 65;
                if (ch > 90) {
                    ch = ch - 26;
                }
            } else {
                ch = ch + key - 97;
                if (ch > 122) {
                    ch = ch - 26;
                }
            }
        } else {
            ch = ch;
        }
        fputc(ch, output_file);
        count++;
    }

    printf("File encryption completed. %d characters encrypted.\n", count);

    fclose(input_file);
    fclose(output_file);

    return 0;
}