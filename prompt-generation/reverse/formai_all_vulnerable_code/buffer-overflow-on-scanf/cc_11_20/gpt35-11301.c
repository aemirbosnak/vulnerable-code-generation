//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, lucky_num;

    srand(time(NULL)); // Get a new seed for pseudo-random number generator

    printf("Welcome to the Automated Fortune Teller!\n\nPlease enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your lucky number: ");
    scanf("%d", &lucky_num);

    printf("\n\nThinking...\n\n");

    int fortune_num = rand() % 10; // Generate a random number between 0 and 9

    // Choose fortune message based on the randomly generated number
    switch(fortune_num) {
        case 0:
            printf("Hello %s, your lucky number is %d, but your future looks bleak. Sorry :(\n", name, lucky_num);
            break;
        case 1:
            printf("Hey %s, good news! Your lucky number %d will bring you wealth and success in the coming days.\n", name, lucky_num);
            break;
        case 2:
            printf("Beware %s, your lucky number %d will bring enemies and danger to your life.\n", name, lucky_num);
            break;
        case 3:
            printf("Hello %s, your age of %d is a lucky number. You will find happiness and love in the near future.\n", name, age);
            break;
        case 4:
            printf("Hey %s, your lucky number %d will lead you to great fortune and fame in the coming years.\n", name, lucky_num);
            break;
        case 5:
            printf("Sorry %s, looks like your lucky number %d won't be bringing you any luck. Be careful!\n", name, lucky_num);
            break;
        case 6:
            printf("Hello %s, your lucky number %d indicates that you will have a long and prosperous life ahead.\n", name, lucky_num);
            break;
        case 7:
            printf("Hey %s, your lucky number %d signifies that you will have a successful career in the near future.\n", name, lucky_num);
            break;
        case 8:
            printf("Good news %s, your lucky number %d implies that you will meet the love of your life soon!\n", name, lucky_num);
            break;
        case 9:
            printf("Sorry %s, it looks like your lucky number %d won't be doing you any good. Beware of misfortune.\n", name, lucky_num);
            break;
    }

    return 0;
}