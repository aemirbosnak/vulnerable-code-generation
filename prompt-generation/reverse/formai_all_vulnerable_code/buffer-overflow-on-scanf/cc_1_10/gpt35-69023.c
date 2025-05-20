//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <string.h>

/* Function to convert text to ASCII art */
void text_to_ascii_art(char text[]) {
    int i, j, k, len;
    char c;

    len = strlen(text);

    /* Printing ASCII art for each character in the text */
    for (i = 0; i < 8; i++) {
        for (j = 0; j < len; j++) {
            c = text[j];

            /* Checking if the character is a space */
            if (c == ' ') {
                for (k = 0; k < 6; k++) {
                    printf(" ");
                }
            } else {
                /* Converting the character to ASCII code */
                int ascii_code = (int)c;

                /* Printing the ASCII art for the character */
                for (k = 0; k < 6; k++) {
                    if ((ascii_code >= 65 && ascii_code <= 90) || (ascii_code >= 97 && ascii_code <= 122)) {
                        printf("%c", ascii_code + i + k);
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("  ");
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    char text[100];

    printf("Enter your romantic message:\n");
    scanf("%[^\n]s", text);

    /* Generating ASCII art for the text*/
    text_to_ascii_art(text);

    return 0;
}