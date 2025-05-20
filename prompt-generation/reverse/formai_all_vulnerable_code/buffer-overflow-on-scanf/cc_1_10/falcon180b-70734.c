//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int age;
    int lucky_number;
    int prediction;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for their name
    printf("What is your name? ");
    scanf("%s", name);

    // Prompt the user for their age
    printf("How old are you? ");
    scanf("%d", &age);

    // Generate a lucky number for the user
    lucky_number = rand() % 100;

    // Prompt the user for their prediction
    printf("What would you like to predict?\n");
    printf("1. Love life\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. Wealth\n");
    scanf("%d", &choice);

    // Perform the prediction based on the user's choice
    switch (choice) {
        case 1:
            printf("Your love life is looking good!\n");
            printf("You will meet someone special within the next %d days.\n", lucky_number);
            break;
        case 2:
            printf("Your career is about to take off!\n");
            printf("You will receive a promotion or job offer within the next %d days.\n", lucky_number);
            break;
        case 3:
            printf("Your health is in good hands!\n");
            printf("You will experience a boost in energy and vitality within the next %d days.\n", lucky_number);
            break;
        case 4:
            printf("Your wealth is about to increase!\n");
            printf("You will receive an unexpected windfall within the next %d days.\n", lucky_number);
            break;
        default:
            printf("I'm sorry, I cannot predict that.\n");
            break;
    }

    return 0;
}