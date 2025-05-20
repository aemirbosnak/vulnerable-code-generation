//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller(void) {
    int choice;
    char name[20];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    printf("Hello, %s! I am the all-knowing Fortune Teller. What would you like me to predict for you today?\n", name);
    printf("1. Love life\n2. Career\n3. Health\n4. Finances\n5. General future\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("In your love life, I see...\n");
            break;
        case 2:
            printf("In your career, I see...\n");
            break;
        case 3:
            printf("For your health, I see...\n");
            break;
        case 4:
            printf("For your finances, I see...\n");
            break;
        case 5:
            printf("For your general future, I see...\n");
            break;
        default:
            printf("I'm sorry, %s. That is not a valid option.\n", name);
            return;
    }
    srand(time(0));
    int random_number = rand() % 10;
    switch (random_number) {
        case 0:
            printf("You will meet your soulmate soon.\n");
            break;
        case 1:
            printf("You will receive a promotion at work.\n");
            break;
        case 2:
            printf("You will win the lottery.\n");
            break;
        case 3:
            printf("You will travel to an exotic location.\n");
            break;
        case 4:
            printf("You will inherit a large sum of money.\n");
            break;
        case 5:
            printf("You will have good luck for the rest of the year.\n");
            break;
        case 6:
            printf("You will experience a major life change.\n");
            break;
        case 7:
            printf("You will make a new friend.\n");
            break;
        case 8:
            printf("You will receive unexpected news.\n");
            break;
        case 9:
            printf("You will have a successful business venture.\n");
            break;
        default:
            printf("I'm sorry, %s. The crystal ball is cloudy today.\n", name);
    }
}

int main(void) {
    fortune_teller();
    return 0;
}