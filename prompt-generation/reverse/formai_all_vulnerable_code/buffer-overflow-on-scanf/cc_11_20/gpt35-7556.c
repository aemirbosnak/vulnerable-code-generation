//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[25];
    int lucky_number, choice;

    printf("Welcome to the Fortune Teller program!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Please enter a lucky number between 1 and 10: ", name);
    scanf("%d", &lucky_number);
    printf("Great! Now, please choose a number between 1 and 5:\n");
    printf("1. You will find love soon.\n");
    printf("2. You will have a successful career.\n");
    printf("3. You will travel to a foreign country.\n");
    printf("4. You will win the lottery.\n");
    printf("5. You will meet your soulmate.\n");
    scanf("%d", &choice);

    srand(time(NULL));
    int fortune = rand() % 100 + 1;

    printf("\n\n");

    if (fortune > 0 && fortune < 25) {
        printf("Sorry, %s, but your fortune is not looking good. You should reconsider your decisions.\n", name);
    } else if (fortune > 24 && fortune < 50) {
        printf("Hmm, %s, your fortune is somewhat average. Be cautious in your endeavors.\n", name);
    } else if (fortune > 49 && fortune < 75) {
        printf("Interesting, %s, your fortune is looking good! Keep up the good work!\n", name);
    } else {
        printf("Wow, %s, you are in luck! Your fortune is looking great! This is definitely your year!\n", name);
    }

    printf("\n");

    switch (choice) {
        case 1:
            printf("Your fortune says that you will find love soon. Keep your heart open and be patient!\n");
            break;
        case 2:
            printf("Your fortune says that you will have a successful career. Keep working hard and you will achieve your goals!\n");
            break;
        case 3:
            printf("Your fortune says that you will travel to a foreign country. Start saving up and get ready for an adventure!\n");
            break;
        case 4:
            printf("Your fortune says that you will win the lottery. Keep playing and you might just hit the jackpot!\n");
            break;
        case 5:
            printf("Your fortune says that you will meet your soulmate. Keep an eye out, they might be closer than you think!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }

    if (lucky_number == fortune % 10) {
        printf("Also, your lucky number has brought you extra luck today! Congratulations!\n");
    }

    printf("\n");

    return 0;
}