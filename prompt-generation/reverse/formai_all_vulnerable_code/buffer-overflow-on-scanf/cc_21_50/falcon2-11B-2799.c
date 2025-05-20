//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Prompt user for input
    printf("Welcome to the automated fortune teller! \n");
    printf("Please enter your question: ");
    char question[100];
    scanf("%s", question);
    printf("Please enter your name: ");
    char name[100];
    scanf("%s", name);

    // Generate random answer
    int answer = rand() % 10;
    switch(answer) {
        case 0:
            printf("Your future is uncertain, but that's okay. Keep on keeping on!\n");
            break;
        case 1:
            printf("You'll find love soon, but you'll have to look for it!\n");
            break;
        case 2:
            printf("You'll have a lot of money soon, but it will come with a cost!\n");
            break;
        case 3:
            printf("You'll have a lot of friends soon, but not all of them will be good for you!\n");
            break;
        case 4:
            printf("You'll have a lot of success soon, but you'll have to work for it!\n");
            break;
        case 5:
            printf("You'll have a lot of challenges soon, but you'll come out stronger on the other side!\n");
            break;
        case 6:
            printf("You'll have a lot of adventures soon, but they won't always go as planned!\n");
            break;
        case 7:
            printf("You'll have a lot of surprises soon, but some of them may not be so good!\n");
            break;
        case 8:
            printf("You'll have a lot of opportunities soon, but you'll have to seize them!\n");
            break;
        case 9:
            printf("You'll have a lot of luck soon, but it won't last forever!\n");
            break;
        default:
            printf("Sorry, there must have been a glitch in the system. Please try again later!\n");
    }

    // Print out the user's fortune
    printf("Dear %s, \n", name);
    printf("%s\n", question);
    printf("Your fortune is: \n");
    printf("%s\n", answer == 0? "You're going to have an amazing day!" : answer == 1? "You're going to find love today!" : answer == 2? "You're going to have a lot of money soon!" : answer == 3? "You're going to have a lot of friends soon!" : answer == 4? "You're going to have a lot of success soon!" : answer == 5? "You're going to have a lot of challenges soon!" : answer == 6? "You're going to have a lot of adventures soon!" : answer == 7? "You're going to have a lot of surprises soon!" : answer == 8? "You're going to have a lot of opportunities soon!" : answer == 9? "You're going to have a lot of luck soon!" : "Sorry, your fortune is not available at this time.");

    return 0;
}