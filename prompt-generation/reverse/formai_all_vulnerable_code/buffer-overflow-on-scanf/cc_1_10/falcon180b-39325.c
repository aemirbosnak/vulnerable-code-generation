//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 64

int main() {
    char hex[MAX_HEX_LENGTH];
    char ascii[MAX_HEX_LENGTH];
    int i, j, k;

    printf("Welcome to the Retro C Hexadecimal Converter!\n");

    printf("Enter a hexadecimal string: ");
    fgets(hex, MAX_HEX_LENGTH, stdin);

    printf("Enter a delimiter (e.g. space, comma, etc.): ");
    scanf("%s", hex);

    printf("Enter an output file name: ");
    scanf("%s", ascii);

    FILE *output = fopen(ascii, "w");

    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < strlen(hex); i++) {
        if (isxdigit(hex[i])) {
            j = 0;
            while (isxdigit(hex[i])) {
                if (isdigit(hex[i])) {
                    ascii[j] = hex[i] - '0';
                } else {
                    ascii[j] = hex[i] - 'A' + 10;
                }
                i++;
                j++;
            }
            ascii[j] = '\0';
            fprintf(output, "%s", ascii);
            j = 0;
        } else {
            i++;
        }
    }

    fclose(output);

    printf("Hexadecimal string converted to ASCII and saved to file!\n");

    return 0;
}