//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>

int main() {
    char inputChar; // initialize variable for input character
    printf("Enter a character: "); 
    scanf("%c", &inputChar); // get input character from user
    printf("\n");

    // generate ASCII art based on input character
    switch(inputChar) {
        case 'A':
            printf("  /\\");
            printf("\n /  \\");
            printf("\n/    \\");
            printf("\n------");
            printf("\n/    \\");
            printf("\n/    \\");
            printf("\n");
            break;
        case 'B':
            printf(" ____");
            printf("\n|    \\");
            printf("\n|__--|");
            printf("\n|    /");
            printf("\n----'");
            printf("\n|___|\n");
            break;
        case 'C':
            printf("    ___");
            printf("\n  /        \\");
            printf("\n |   ___ |");
            printf("\n|   |");
            printf("\n|    ----|");
            printf("\n  \\____/");
            printf("\n");
            break;
        case 'D':
            printf(" ____");
            printf("\n|    \\");
            printf("\n|     |");
            printf("\n|     |");
            printf("\n|____/");
            printf("\n|    \\");
            printf("\n|     |\n");
            break;
        // add more cases for other letters and characters
        default:
            printf("Sorry, invalid input.");
    }
    return 0;
}