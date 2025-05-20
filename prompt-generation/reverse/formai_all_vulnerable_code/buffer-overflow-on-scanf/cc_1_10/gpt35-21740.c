//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>

void generateHappyArt(char letter) {
    switch(letter) {
        case 'A':
        printf("  /\\  \n");
        printf(" //\\\\ \n");
        printf("//  \\\\\n");
        printf("=====\n");
        printf("//  \\\\\n");
        break;

        case 'B':
        printf("|||| \n");
        printf("|||| \n");
        printf("|||| \n");
        printf("|--- \n");
        printf("||/  \n");
        printf("|\\\n");
        printf("|||\n");
        printf("|||\n");
        printf("|||\n");
        printf("\\\\\\/\n");
        break;

        case 'C':
        printf("  __ \n");
        printf(" /  \\\n");
        printf("/    \\\n");
        printf("|     \n");
        printf("|     \n");
        printf("\\    /\n");
        printf(" \\__/ \n");
        break;

        case 'D':
        printf("|||| \n");
        printf("|||| \n");
        printf("|||| \n");
        printf("|| | \n");
        printf("|| | \n");
        printf("|| | \n");
        printf("|| | \n");
        printf("|| | \n");
        printf("|||| \n");
        printf("\\\\\\/\n");
        break;

        default:
        printf("Sorry, I don't know how to make that letter happy. :(\n");
    }
}

int main() {
    char input;
    printf("Enter a letter to turn into happy ASCII art: ");
    scanf("%c", &input);

    generateHappyArt(input);

    return 0;
}