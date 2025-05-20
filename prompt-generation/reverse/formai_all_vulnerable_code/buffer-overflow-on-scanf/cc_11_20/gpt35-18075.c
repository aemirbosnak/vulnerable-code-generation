//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
/* 
Welcome to the most ridiculous math exercise program you'll ever encounter!
This program will test your math skills, sense of humor, and ability to withstand terrible puns.
Without further ado, let's dive in! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, userAns, tries=0;
    char op;

    srand(time(NULL)); //Setting the time for random numbers

    printf("Welcome to the math exercise program, where you'll laugh and learn.\n");
    printf("Are you ready for some math madness? (y/n)\n");
    scanf(" %c", &op);

    if(op == 'n' || op == 'N')
        printf("Too bad, we're doing it anyway!\n");

    while(op == 'y' || op == 'Y') {
        
        num1 = rand()%10;
        num2 = rand()%10;

        if (num1%2 == 0 && num2%2 ==0)
            op = '*'; //If num1 and num2 are even, multiply them
        else if (num1 < num2)
            op = '+';
        else
            op = '-';

        printf("\nWhat is %d %c %d?\n", num1, op, num2);
        scanf("%d", &userAns);
        
        if(op == '+')
            result = num1 + num2;
        else if(op == '-')
            result = num1 - num2;
        else
            result = num1 * num2;

        if(userAns == result) {
            printf("You got it right! You're a math genius!\n");
            tries=0;
        }
        else {
            printf("Sorry, that's not correct. Try again!\n");
            tries++;

            if(tries==3) {
                printf("Oh no, you've failed too many times. The answer was %d.\n", result);
                tries=0;
            }
        }

        printf("\nWould you like to solve another one? (y/n)\n");
        scanf(" %c", &op);
    }

    printf("Thanks for playing! You're not too bad at this, but you should really work on your puns. Goodbye!\n");

    return 0;
}