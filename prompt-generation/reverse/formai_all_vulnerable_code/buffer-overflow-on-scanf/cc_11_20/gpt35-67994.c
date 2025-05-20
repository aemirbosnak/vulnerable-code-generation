//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char name[50];
    int age, num1, num2, num3, num4, num5;

    printf("Welcome to the Automated Fortune Teller!\nPlease enter your name: ");
    scanf("%s", name);

    printf("Hi %s! How old are you?\n", name);
    scanf("%d", &age);

    printf("Great! Let's see what the future holds for you...\n");
    sleep(2);

    srand(time(NULL));
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    num3 = rand() % 10 + 1;
    num4 = rand() % 10 + 1;
    num5 = rand() % 10 + 1;

    printf("Your lucky numbers are: %d %d %d %d %d\n", num1, num2, num3, num4, num5);

    if (num1 == 7 && num2 == 7 && num3 == 7 && num4 == 7 && num5 == 7){
        printf("Wow! All sevens! Looks like you're going to win the lottery, %s!\n", name);
    }

    printf("Now, let's see what your fortune cookie says...\n");
    sleep(2);

    int fortune = rand() % 5 + 1;

    switch(fortune){
        case 1:
            printf("You will inherit a large sum of money from a long lost relative.\n");
            break;
        case 2:
            printf("You will find romance in the most unexpected place.\n");
            break;
        case 3:
            printf("A great adventure awaits you in the near future.\n");
            break;
        case 4:
            printf("You will achieve great success in your career.\n");
            break;
        case 5:
            printf("Beware of a stranger with a green hat.\n");
            break;
        default:
            printf("Oops, something went wrong. Try again later.\n");
            break;
    }

    printf("Thanks for using the Automated Fortune Teller, %s. Come back soon!\n", name);

    return 0;
}