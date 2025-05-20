//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>

/*
Function to print ASCII art of given text
*/
void printAsciiArt(char* text) {
    char asciiChars[95][11] = { /* ASCII Characters - 10x9 size */
        "         ",
        "  /\\___/\\",
        " ( o   o )",
        " (  =^=  )",
        " (        )",
        "  (      )",
        "   (    )",
        "    (__)______",
        "         | |",
        "    ______| |__",
        "   /           \\",
        "  / /-\\ /-\\ \\",
        " / /   Y   \\ \\",
        " \\/   |_ |   \\/",
        "     /_/ |",
        "    \\ \\ \\",
        "     \\ \\ \\",
        "      \\/_\\/"
        /* More ASCII characters can be added here */
    };
    int length = strlen(text);
    int i, j;
    for (i = 0; i < 10; i++) { /* Loop to print ASCII art row by row */
        for (j = 0; j < length; j++) { /* Loop to print ASCII character for each text character */
            if (text[j] >= 32 && text[j] <= 126) { /* Check if text character is within ASCII range */
                printf("%s ", asciiChars[text[j] - 32][i]); /* Print the corresponding ASCII character */
            } else {
                printf("          "); /* Print blank spaces if text character is outside ASCII range */
            }
        }
        printf("\n");
    }
}

/*
Main function
*/
int main() {
    char text[100];
    printf("Enter a text to convert to ASCII art: ");
    scanf("%[^\n]s", text); /* Read input text until newline character is encountered */
    printAsciiArt(text); /* Call function to print ASCII art of text */
    return 0;
}