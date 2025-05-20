//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter a word or phrase: ");
    fgets(input, 50, stdin);
    // Removing the newline character from the end of the string
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }
    // Converting the input to ASCII art
    for (int i = 0; i < len; i++) {
        switch(input[i]) {
            case 'A':
            case 'a':
                printf("  /\\  \n");
                printf(" /  \\ \n");
                printf("/____\\\n");
                break;
            case 'B':
            case 'b':
                printf(" ____  \n");
                printf("|    \\ \n");
                printf("|____/\n");
                printf("|    \\\n");
                printf("|____/\n");
                break;
            case 'C':
            case 'c':
                printf("  ___ \n");
                printf(" /    \\\n");
                printf("|      \n");
                printf(" \\___/\n");
                break;
            case 'D':
            case 'd':
                printf(" ____  \n");
                printf("|    \\ \n");
                printf("|     \\\n");
                printf("|____/\n");
                break;
            case 'E':
            case 'e':
                printf(" ____ \n");
                printf("|     \\\n");
                printf("|_____\n");
                printf("|     \\\n");
                printf("|_____/\n");
                break;
            case 'F':
            case 'f':
                printf(" ____ \n");
                printf("|     \\\n");
                printf("|_____\n");
                printf("|     \n");
                printf("|     \n");
                break;
            // Add more cases for other characters
            default:
                printf("     \n");
                printf("     \n");
                printf("     \n");
                break;
        }
    }
    return 0;
}