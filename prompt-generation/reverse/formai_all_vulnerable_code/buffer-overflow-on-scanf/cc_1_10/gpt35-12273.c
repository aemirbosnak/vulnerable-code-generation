//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Function to print the ASCII art based on the input string
void print_ascii_art(char input[])
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        char current_char = input[i];

        switch (current_char)
        {
            case 'A':
                printf("   /\\\n");
                printf("  /  \\\n");
                printf(" /____\\\n");
                printf("/      \\\n");
                break;
            case 'B':
                printf(" _____\n");
                printf("|  ___|\n");
                printf("| |___\n");
                printf("|  ___|\n");
                printf("| |____\n");
                printf("|______|\n");
                break;
            case 'C':
                printf("  ____\n");
                printf(" / ___|\n");
                printf("| |    \n");
                printf("| |    \n");
                printf("| |___ \n");
                printf(" \\____|\n");
                break;
            case 'D':
                printf(" _____ \n");
                printf("|  ___|\n");
                printf("| |   \n");
                printf("| |   \n");
                printf("| |___\n");
                printf("|_____|\n");
                break;
            // Add other letters   
            default:
                printf("Invalid input");
                return;
        }
    }
}

int main()
{
    char input[100];

    printf("Enter text to convert to ASCII art: ");
    scanf("%[^\n]", input);

    print_ascii_art(input);

    return 0;
}