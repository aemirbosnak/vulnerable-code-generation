//FormAI DATASET v1.0 Category: Funny ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello there, welcome to the Happy Program!\n");
    printf("Let's do something fun and create a shapes game!\n");
    
    int option;
    do {
        printf("\nWhat shape do you want to draw?\n");
        printf("1. Square\n");
        printf("2. Triangle\n");
        printf("3. Circle\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nLet's draw a square!\n");
                printf("*********\n");
                printf("*       *\n");
                printf("*       *\n");
                printf("*       *\n");
                printf("*********\n");
                break;
            case 2:
                printf("\nLet's draw an equilateral triangle!\n");
                printf("      *\n");
                printf("     ***\n");
                printf("    *****\n");
                printf("   *******\n");
                printf("  *********\n");
                break;
            case 3:
                printf("\nLet's draw a circle!\n");
                printf("   ** **   \n");
                printf(" *        *\n");
                printf("*          *\n");
                printf("*          *\n");
                printf("*          *\n");
                printf(" *        *\n");
                printf("   ** **   \n");
                break;
            case 4:
                printf("\nBye! Thanks for playing!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }

    } while (option != 4);

    printf("\nHope you enjoyed the Happy Program! Happy coding! :)\n");

    return 0;
}