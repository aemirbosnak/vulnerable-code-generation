//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, lucky_number, fortune_number, option;
    srand(time(0));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s!\n", name);
    printf("How old are you?\n");
    scanf("%d", &age);
    printf("Great! Now, give me your lucky number:\n");
    scanf("%d", &lucky_number);

    fortune_number = (rand() % 100) + 1; // generate random fortune number between 1-100

    printf("Thank you, %s. Would you like me to predict your future?\n", name);
    printf("1. Yes\n2. No\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("Your lucky number is: %d\n", lucky_number);
        printf("Your fortune number is: %d\n", fortune_number);
        printf("Your future prediction is:\n");

        switch(fortune_number % 5) {
            case 0:
                printf("You will receive some exciting news in the near future!\n");
                break;
            case 1:
                printf("You will meet someone special in the next few days!\n");
                break;
            case 2:
                printf("Your hard work will pay off soon, keep pushing!\n");
                break;
            case 3:
                printf("A big change is coming your way, embrace it!\n");
                break;
            case 4:
                printf("You will have great fortune in your future, stay positive!\n");
                break;
            default:
                printf("Oops, something went wrong!\n");
                break;
        }
    } else if (option == 2) {
        printf("No problem, %s. Maybe next time!\n", name);
    } else {
        printf("I didn't understand your input, %s. Please try again later.\n", name);
    }

    return 0;
}