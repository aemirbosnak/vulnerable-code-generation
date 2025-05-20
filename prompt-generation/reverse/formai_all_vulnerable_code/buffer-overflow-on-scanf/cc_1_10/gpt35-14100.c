//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

/* Function to convert character to ASCII art */
void convertToArt(char c) {

    switch(c) {

        case 'a':
            printf("      /\\      \n");
            printf("     /  \\     \n");
            printf("    /    \\    \n");
            printf("   /------\\   \n");
            printf("  /        \\  \n");
            printf(" /          \\ \n");
            printf("/____________\\\n");
            break;

        case 'b':
            printf(" ________   \n");
            printf("|        \\  \n");
            printf("|         \\ \n");
            printf("|_________\\ \n");
            printf("|         / \n");
            printf("|        /  \n");
            printf("|________/  \n");
            break;

        case 'c':
            printf("   ______  \n");
            printf(" /        \\ \n");
            printf("/          \\\n");
            printf("\\          /\n");
            printf(" \\        / \n");
            printf("   ------  \n");
            break;

         /* More cases for other characters can be added here */

         default:
            printf("Character not supported");
    }
}

/* Main function */
int main() {

    char input;
    printf("Enter a character: ");
    scanf("%c", &input);
    convertToArt(input); /* Call the function to convert to ASCII art */

    return 0;
}