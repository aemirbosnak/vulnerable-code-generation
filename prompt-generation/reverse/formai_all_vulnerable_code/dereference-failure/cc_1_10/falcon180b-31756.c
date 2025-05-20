//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input, *output;
    char filename[50], ch;
    int key, i, j;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(0);
    }

    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    output = fopen("encrypted.txt", "w");
    if (output == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(0);
    }

    while ((ch = fgetc(input))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        } else {
            ch = ch;
        }
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");

    return 0;
}