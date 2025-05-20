//FormAI DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>

int main() 
{
    printf("Welcome to the Retro Color Code Converter!\n");
    printf("Enter a color code in hexadecimal format (e.g. #FF0000): ");

    char input[7];
    scanf("%s", input);

    int red, green, blue;

    sscanf(input, "#%02x%02x%02x", &red, &green, &blue);

    printf("RGB values: %d, %d, %d\n", red, green, blue);

    printf("Would you like to convert this color to a different format? (Y/N): ");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y') 
    {
        printf("Choose a format to convert to:\n");
        printf("1. ANSI escape sequence (e.g. \x1B[38;2;255;0;0m)\n");
        printf("2. RGB values in parentheses (e.g. (255,0,0))\n");
        printf("3. CMYK values in parentheses (e.g. (0,1,1,0))\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\x1B[38;2;%d;%d;%dmYour color in ANSI escape sequence: Hello World!\x1B[0m\n", red, green, blue);
                break;
            case 2:
                printf("( %d, %d, %d )\n", red, green, blue);
                break;
            case 3:
                printf("( 0, %.2f, %.2f, %.2f )\n", 1 - ((float) red / 255), 1 - ((float) green / 255), 1 - ((float) blue / 255), 0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    printf("Thank you for using the Retro Color Code Converter!\n");

    return 0;
}