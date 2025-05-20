//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>

int main()
{
    char text[100];
    printf("Enter any text: ");
    scanf("%[^\n]", text); // allows spaces in input
    
    printf("\nHere's your ASCII Art:\n\n");
    for (int i = 0; text[i] != '\0'; i++) {
        switch(text[i]) {
            case 'a':
            case 'A':
                printf("    /\\ \n");
                printf("   /  \\ \n");
                printf("  /----\\\n");
                printf(" /      \\\n\n");
                break;
            case 'b':
            case 'B':
                printf(" |--\\\n");
                printf(" |   )\n");
                printf(" |--/\n");
                printf(" |__)\n\n");
                break;
            case 'c':
            case 'C':
                printf("  .-.\n");
                printf(" | oo \n");
                printf(" \\_/\n\n");
                break;
            case 'd':
            case 'D':
                printf(" |--\\\n");
                printf(" |   )\n");
                printf(" |__/ \n");
                printf(" |   \\ \n\n");
                break;
            // and so on for the rest of the alphabet
            default:
                printf("   \n");
                printf("   \n");
                printf("   \n");
                printf("   \n\n");
                break;
        }
    }
    
    return 0;
}