//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>

int main() {
    char message[100], ch;
    int i, j, ascii;

    printf("Enter a message to convert to ASCII art:\n");
    gets(message);

    printf("\nThe ASCII art representation for your message is:\n\n ");

    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ascii = ch - 'a';
            for (j = 0; j < 5; j++) { 
                if (j != 2)
                    printf("%c", (ascii % 2 == 0) ? '*' : '.');
                else
                    printf("%c", ch);
                ascii /= 2;
            }
        }

        else if (ch >= 'A' && ch <= 'Z') {
            ascii = ch - 'A';
            for (j = 0; j < 5; j++) {
                if (j != 2)
                    printf("%c", (ascii % 2 == 0) ? '*' : '.');
                else
                    printf("%c", ch);
                ascii /= 2;
            }
        }

        else if (ch == ' ') {
            for (j = 0; j < 5; j++) 
                printf(" ");
        }

        else {
            printf("\nSorry, the character inputted is not supported!");
            return 0;
        }
        printf("\n ");
    }

    return 0;
}