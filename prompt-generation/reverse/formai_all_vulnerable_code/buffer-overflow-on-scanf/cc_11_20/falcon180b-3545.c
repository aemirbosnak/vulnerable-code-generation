//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];

    srand(time(NULL)); // Initialize random seed with current time
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, I can predict your future!\n\n", name);
    printf("1. Love life\n");
    printf("2. Career\n");
    printf("3. Health\n");
    printf("4. Wealth\n");
    printf("Choose a category: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n%s, in your love life...\n", name);
            int love = rand() % 3; // Generate a random number between 0 and 2
            if(love == 0) {
                printf("You will find true love soon.\n");
            } else if(love == 1) {
                printf("Your current relationship will face challenges.\n");
            } else {
                printf("You will experience heartbreak in the near future.\n");
            }
            break;

        case 2:
            printf("\n%s, in your career...\n", name);
            int career = rand() % 3; // Generate a random number between 0 and 2
            if(career == 0) {
                printf("You will receive a promotion or raise.\n");
            } else if(career == 1) {
                printf("You will face difficulties at work.\n");
            } else {
                printf("You will switch careers soon.\n");
            }
            break;

        case 3:
            printf("\n%s, in your health...\n", name);
            int health = rand() % 3; // Generate a random number between 0 and 2
            if(health == 0) {
                printf("You will experience good health.\n");
            } else if(health == 1) {
                printf("You may face minor health issues.\n");
            } else {
                printf("You will face major health problems.\n");
            }
            break;

        case 4:
            printf("\n%s, in your wealth...\n", name);
            int wealth = rand() % 3; // Generate a random number between 0 and 2
            if(wealth == 0) {
                printf("You will receive unexpected wealth.\n");
            } else if(wealth == 1) {
                printf("You will face financial difficulties.\n");
            } else {
                printf("You will experience a stable financial situation.\n");
            }
            break;

        default:
            printf("\nInvalid choice. Please choose a category from 1 to 4.\n");
    }

    return 0;
}