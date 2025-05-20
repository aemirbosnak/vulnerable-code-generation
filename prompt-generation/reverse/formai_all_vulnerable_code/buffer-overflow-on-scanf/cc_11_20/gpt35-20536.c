//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    char arr[50];
    int i = 0, j = 0;

    // Ask user to input alien language
    printf("Please input the alien language: ");
    scanf("%s", arr);

    // Translate the alien language
    for (i; i < 50; i++) {

        // Check for end of string
        if (arr[i] == '\0') {
            break;
        }

        // Start translating
        switch (arr[i]) {
            case '0':
                printf("!");
                break;
            case '1':
                printf("@");
                break;
            case '2':
                printf("#");
                break;
            case '3':
                printf("$");
                break;
            case '4':
                printf("%");
                break;
            case '5':
                printf("^");
                break;
            case '6':
                printf("&");
                break;
            case '7':
                printf("*");
                break;
            case '8':
                printf("(");
                break;
            case '9':
                printf(")");
                break;
            default:
                printf("?");
                break;
        }

        // Add a space every 5 characters
        j++;
        if (j % 5 == 0) {
            printf(" ");
        }
    }

    return 0;
}