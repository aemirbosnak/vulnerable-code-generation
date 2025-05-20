//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

void encrypt(char *input_file, char *output_file) {
    FILE *in_file, *out_file;
    char ch, key;
    int i = 0;

    in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    printf("Enter the encryption key: ");
    scanf("%c", &key);

    while ((ch = fgetc(in_file))!= EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = (ch - 'A' + key - 1) % 26 + 'A';
            } else {
                ch = (ch - 'a' + key - 1) % 26 + 'a';
            }
        }
        fprintf(out_file, "%c", ch);
    }

    fclose(in_file);
    fclose(out_file);

    printf("Encryption completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2]);

    return 0;
}