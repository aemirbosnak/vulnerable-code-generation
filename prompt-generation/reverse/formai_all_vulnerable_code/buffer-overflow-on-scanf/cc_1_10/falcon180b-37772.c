//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char red[MAX_COLOR_CODE_LENGTH];
    char green[MAX_COLOR_CODE_LENGTH];
    char blue[MAX_COLOR_CODE_LENGTH];
} ColorCode;

int isValidColorCode(char* colorCode) {
    int i;
    for (i = 0; i < strlen(colorCode); i++) {
        if (!isdigit(colorCode[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

void convertColorCode(ColorCode* colorCode, char* input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '#') {
            for (j = 0; j < MAX_COLOR_CODE_LENGTH; j++) {
                colorCode->red[j] = input[i+1+2*j];
                colorCode->green[j] = input[i+2+2*j];
                colorCode->blue[j] = input[i+3+2*j];
            }
            break;
        }
    }
}

void printColorCode(ColorCode* colorCode) {
    printf("Red: ");
    for (int i = 0; i < strlen(colorCode->red); i++) {
        printf("%c", colorCode->red[i]);
    }
    printf("\nGreen: ");
    for (int i = 0; i < strlen(colorCode->green); i++) {
        printf("%c", colorCode->green[i]);
    }
    printf("\nBlue: ");
    for (int i = 0; i < strlen(colorCode->blue); i++) {
        printf("%c", colorCode->blue[i]);
    }
}

int main() {
    char input[MAX_COLOR_CODE_LENGTH+1];
    ColorCode colorCode;

    printf("Enter a color code: ");
    scanf("%s", input);

    if (!isValidColorCode(input)) {
        printf("Invalid color code\n");
        return 0;
    }

    convertColorCode(&colorCode, input);
    printColorCode(&colorCode);

    return 0;
}