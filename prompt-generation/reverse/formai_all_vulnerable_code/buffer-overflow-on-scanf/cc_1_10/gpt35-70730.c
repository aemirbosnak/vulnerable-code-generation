//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Automated Fortune Teller v1.0!\n");

    // Declare variables
    char name[20];
    int age, lucky_number, fortune;

    // Get user information
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);
    printf("What is your lucky number? ");
    scanf("%d", &lucky_number);

    // Generate random fortune
    srand(time(NULL));
    fortune = rand() % 5;

    // Output fortune
    printf("\n%s, here is your fortune:\n", name);
    switch(fortune) {
        case 0:
            printf("You will have a great day today!\n");
            break;
        case 1:
            printf("You will meet someone special in the near future.\n");
            break;
        case 2:
            printf("You will come across unexpected wealth in the next few months.\n");
            break;
        case 3:
            printf("You will have a major breakthrough in your career this year.\n");
            break;
        case 4:
            printf("You will travel to a new and exciting place soon.\n");
            break;
        default:
            printf("Error: Something went wrong while generating your fortune.\n");
    }

    // Generate lucky number
    srand(time(NULL));
    lucky_number = rand() % 100 + 1;

    // Output lucky number if it matches user's lucky number
    if(lucky_number == lucky_number) {
        printf("Your lucky number (%d) matches the generated lucky number (%d)! This must be your lucky day!\n", lucky_number, lucky_number);
    }

    // Farewell message
    printf("\nThank you for using the Automated Fortune Teller v1.0!\n");

    return 0;
}