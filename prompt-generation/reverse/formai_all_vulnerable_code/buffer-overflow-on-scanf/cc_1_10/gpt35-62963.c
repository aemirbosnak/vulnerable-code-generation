//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>

// Function to convert text to ASCII art using Cryptic style
void text_to_ascii_art(char text[]) {
    int i, j;
    char ch;
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        switch(ch) {
            case 'A':
            case 'a':
                printf("  /\\  \n /  \\ \n/____\\\n/\\   /\\\n/__\\ /__\\\n");
                break;
            case 'B':
            case 'b':
                printf(" ____\n| __ )\n|  _ \\\n| |_) |\n|____/\n");
                break;
            case 'C':
            case 'c':
                printf("  ___\n / __|\n| (__ \n \\___|\n");
                break;
            case 'D':
            case 'd':
                printf(" _____\n|_   _|\n  | |\n  | |\n  |_|\n");
                break;
            case 'E':
            case 'e':
                printf(" ____\n|  _ \\\n| |_) |\n|  _ < \n|_| \\_\\\n");
                break;
            case 'F':
            case 'f':
                printf(" ____\n|  _ \\\n| |_) |\n|  _ < \n|_|   \n");
                break;
            // continue with all the alphabet and special characters
            default:
                printf("     \n     \n     \n     \n     \n");
                break;
        }
    }
}

// Main function to test the ASCII art generator
int main() {
    char text[100];
    printf("Enter any text to convert to ASCII art: ");
    scanf("%[^\n]s", text);
    printf("\n");
    text_to_ascii_art(text);
    return 0;
}