//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void hex_to_ascii(char *hex_str, char *ascii_str) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(hex_str); i += 2, j++) {
        if (isxdigit(hex_str[i]) && isxdigit(hex_str[i + 1])) {
            sscanf(hex_str + i, "%02x", &k);
            ascii_str[j] = k;
        } else {
            printf("Invalid hexadecimal character at position %d.\n", i);
            exit(1);
        }
    }
    ascii_str[j] = '\0';
}

void ascii_to_hex(char *ascii_str, char *hex_str) {
    int i, j;
    for (i = 0, j = 0; ascii_str[i]!= '\0'; i++, j += 2) {
        sprintf(hex_str + j, "%02x", ascii_str[i]);
    }
    hex_str[j] = '\0';
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char hex_str[MAX_LINE_LENGTH * 2 + 1];
    char ascii_str[MAX_LINE_LENGTH];
    int line_count = 0;

    printf("Enter the name of the file to convert: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_count++;
        if (line_count % 2 == 0) { // Convert ASCII to hexadecimal
            hex_to_ascii(line, ascii_str);
            printf("Hexadecimal: %s\n", ascii_str);
        } else { // Convert hexadecimal to ASCII
            ascii_to_hex(line, hex_str);
            printf("ASCII: %s\n", hex_str);
        }
    }

    fclose(fp);
    return 0;
}