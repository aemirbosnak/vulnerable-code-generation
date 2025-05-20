//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100

struct Color {
    char name[50];
    char hex[8];
};

struct Color colorTable[MAX_COLOR_NAMES];
int numColors;

void readColorTable() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("colorTable.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open colorTable.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_COLOR_NAMES) {
            printf("Error: Too many color names in colorTable.txt\n");
            exit(1);
        }

        sscanf(line, "%s %s", colorTable[i].name, colorTable[i].hex);
        i++;
    }

    numColors = i;
    fclose(fp);
}

int hexToInt(char hex) {
    if (hex >= '0' && hex <= '9')
        return hex - '0';
    else if (hex >= 'A' && hex <= 'F')
        return hex - 'A' + 10;
    else if (hex >= 'a' && hex <= 'f')
        return hex - 'a' + 10;
    else
        return -1;
}

void convertColor(char *input, char *output) {
    int i;
    for (i = 0; i < numColors; i++) {
        if (strcmp(input, colorTable[i].name) == 0) {
            sprintf(output, "#%s", colorTable[i].hex);
            return;
        }
    }

    printf("Error: Invalid color name '%s'\n", input);
    exit(1);
}

int main() {
    char input[50];
    char output[9];

    readColorTable();

    printf("Enter a color name: ");
    scanf("%s", input);

    convertColor(input, output);

    printf("The hex code for %s is %s\n", input, output);

    return 0;
}