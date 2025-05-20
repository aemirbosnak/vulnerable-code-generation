//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 10

int main(void) {
    char colorCode[MAX_LENGTH], convertedCode[MAX_LENGTH];
    int i, j = 0;

    printf("Enter the color code: ");
    scanf("%s", colorCode);

    for (i = 0; colorCode[i] != '\0'; i++) {
        // Convert uppercase characters to lowercase
        if (isupper(colorCode[i])) {
            colorCode[i] = tolower(colorCode[i]);
        }

        // Replace characters
        switch (colorCode[i]) {
            case 'a':
                convertedCode[j++] = '0';
                convertedCode[j++] = '0';
                break;
            case 'b':
                convertedCode[j++] = '0';
                convertedCode[j++] = '1';
                break;
            case 'c':
                convertedCode[j++] = '0';
                convertedCode[j++] = '2';
                break;
            case 'd':
                convertedCode[j++] = '0';
                convertedCode[j++] = '3';
                break;
            case 'e':
                convertedCode[j++] = '0';
                convertedCode[j++] = '4';
                break;
            case 'f':
                convertedCode[j++] = '0';
                convertedCode[j++] = '5';
                break;
            case 'g':
                convertedCode[j++] = '0';
                convertedCode[j++] = '6';
                break;
            case 'h':
                convertedCode[j++] = '0';
                convertedCode[j++] = '7';
                break;
            case 'i':
                convertedCode[j++] = '0';
                convertedCode[j++] = '8';
                break;
            case 'j':
                convertedCode[j++] = '0';
                convertedCode[j++] = '9';
                break;
            case 'k':
                convertedCode[j++] = '1';
                convertedCode[j++] = '0';
                break;
            case 'l':
                convertedCode[j++] = '1';
                convertedCode[j++] = '1';
                break;
            case 'm':
                convertedCode[j++] = '1';
                convertedCode[j++] = '2';
                break;
            case 'n':
                convertedCode[j++] = '1';
                convertedCode[j++] = '3';
                break;
            case 'o':
                convertedCode[j++] = '1';
                convertedCode[j++] = '4';
                break;
            case 'p':
                convertedCode[j++] = '1';
                convertedCode[j++] = '5';
                break;
            case 'q':
                convertedCode[j++] = '1';
                convertedCode[j++] = '6';
                break;
            case 'r':
                convertedCode[j++] = '1';
                convertedCode[j++] = '7';
                break;
            case 's':
                convertedCode[j++] = '1';
                convertedCode[j++] = '8';
                break;
            case 't':
                convertedCode[j++] = '1';
                convertedCode[j++] = '9';
                break;
            case 'u':
                convertedCode[j++] = '2';
                convertedCode[j++] = '0';
                break;
            case 'v':
                convertedCode[j++] = '2';
                convertedCode[j++] = '1';
                break;
            case 'w':
                convertedCode[j++] = '2';
                convertedCode[j++] = '2';
                break;
            case 'x':
                convertedCode[j++] = '2';
                convertedCode[j++] = '3';
                break;
            case 'y':
                convertedCode[j++] = '2';
                convertedCode[j++] = '4';
                break;
            case 'z':
                convertedCode[j++] = '2';
                convertedCode[j++] = '5';
                break;
            default:
                printf("Invalid character: %c\n", colorCode[i]);
                return 1;
        }
    }

    printf("Converted color code: ");
    for (i = 0; i < j; i++) {
        printf("%c", convertedCode[i]);
    }
    printf("\n");

    return 0;
}