//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>

int main() {
    char string[100];
    printf("Enter a string: "); 
    gets(string); // Takes input from the user

    int length = strlen(string); // Get the length of the string
    int i;

    printf("\n");
    for (i = 0; i < length * 6; i++)
        printf("_"); // Prints the top border
    printf("\n\n");

    for (i = 0; i < length; i++) {
        printf("        /");
        if (string[i] % 2 == 0)
            printf("~~~");
        else
            printf("...");
        printf("\\\n");
        printf("       | ");

        if (string[i] % 2 == 0)
            printf("(D)");
        else
            printf("(^)");
        printf(" |    ");
    }
    printf("\n");
    for (i = 0; i < length * 6; i++)
        printf("_"); // Prints the bottom border

    printf("\n\n     ");

    for (i = 0; i < length; i++) {
        if (string[i] % 2 == 0)
            printf("\\ /         ");
        else
            printf("/ \\         ");
    }
    printf("\n   ");

    for (i = 0; i < length; i++) {
        if (string[i] % 2 == 0)
            printf("\\\\          ");
        else
            printf("//          ");
    }
    printf("\n  ");

    for (i = 0; i < length; i++) {
        if (string[i] % 2 == 0)
            printf("//           ");
        else
            printf("\\\\           ");
    }
    printf("\n");

    return 0;
}