//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! I am the Fortune Teller.\n", name);
    printf("What would you like to know?\n");
    printf("1. Love\n2. Money\n3. Health\n4. Career\n5. General\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nLove:\n");
            printf("You will find true love soon.\n");
            printf("Your current relationship will improve.\n");
            printf("You will have a happy and fulfilling love life.\n");
            break;
        case 2:
            printf("\nMoney:\n");
            printf("You will come into a large sum of money.\n");
            printf("You will receive a promotion or raise.\n");
            printf("Your financial situation will improve.\n");
            break;
        case 3:
            printf("\nHealth:\n");
            printf("You will have good health.\n");
            printf("You will recover quickly from any illness.\n");
            printf("You will have a long and healthy life.\n");
            break;
        case 4:
            printf("\nCareer:\n");
            printf("You will have a successful career.\n");
            printf("You will be recognized for your hard work.\n");
            printf("You will achieve your career goals.\n");
            break;
        case 5:
            printf("\nGeneral:\n");
            printf("You will have a happy and fulfilling life.\n");
            printf("You will overcome any obstacles that come your way.\n");
            printf("You will have good luck and fortune.\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            return 0;
    }
    printf("\nThank you for visiting the Fortune Teller!\n");
    return 0;
}