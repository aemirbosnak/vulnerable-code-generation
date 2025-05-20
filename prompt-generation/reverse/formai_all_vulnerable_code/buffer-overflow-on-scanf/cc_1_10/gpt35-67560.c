//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>

// Function to generate ASCII art
void generate_ascii_art(char c) {

    switch(c) {

        case 'A':
            printf("      /\\      \n");
            printf("     /  \\     \n");
            printf("    /    \\    \n");
            printf("   /------\\   \n");
            printf("  /        \\  \n");
            break;

        case 'B':
            printf("  ____  \n");
            printf(" |    | \n");
            printf(" |----  \n");
            printf(" |___|  \n");
            break;

        case 'C':
            printf("   ____  \n");
            printf(" /      \n");
            printf("|       \n");
            printf(" \\____  \n");
            break;

        case 'D':
            printf("   ____  \n");
            printf(" |    | \n");
            printf(" |    | \n");
            printf(" |____| \n");
            break;

        case 'E':
            printf("  ____  \n");
            printf(" |___  \n");
            printf(" |___  \n");
            printf(" |____  \n");
            break;

        // add more cases for other letters and symbols

        default:
            printf("Invalid input. \n");
    }
}

int main() {

    char input;
   
    printf("Enter a letter or symbol: ");
    scanf("%c", &input);

    generate_ascii_art(input);

    return 0;
}