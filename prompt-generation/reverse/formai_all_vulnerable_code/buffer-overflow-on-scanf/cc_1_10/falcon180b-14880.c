//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the contents of a file
void encrypt_file(FILE *in_file, FILE *out_file) {
    char ch;
    int i = 0;

    while ((ch = fgetc(in_file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch >= 'a' && ch <='m') {
                ch += 13;
            } else if (ch >= 'n' && ch <= 'z') {
                ch -= 13;
            }
        }
        fputc(ch, out_file);
    }
}

int main() {
    char in_file_name[100], out_file_name[100];
    printf("Enter the name of the input file: ");
    scanf("%s", in_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", out_file_name);

    FILE *in_file = fopen(in_file_name, "r");
    if (in_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *out_file = fopen(out_file_name, "w");
    if (out_file == NULL) {
        printf("Error opening output file\n");
        fclose(in_file);
        exit(1);
    }

    encrypt_file(in_file, out_file);

    fclose(in_file);
    fclose(out_file);

    printf("File encryption complete!\n");
    return 0;
}