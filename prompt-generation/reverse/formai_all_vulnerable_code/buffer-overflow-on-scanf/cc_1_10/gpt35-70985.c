//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int num1, num2, num3, num4;
    int ans1, ans2, ans3, ans4;

    num1 = rand()%10 + 1;
    num2 = rand()%10 + 1;
    num3 = rand()%10 + 1;
    num4 = rand()%10 + 1;

    printf("Let's play a game of surreal math!\n");

    printf("What is the result of adding %d and %d? ", num1, num2);
    scanf("%d", &ans1);

    if(ans1 == num1 + num2) {
        printf("Correct!\n");
    }
    else {
        printf("Sorry, that's incorrect! The answer was %d.\n", num1+num2);
    }

    printf("Now, what is %d multiplied by %d? ", num2, num3);
    scanf("%d", &ans2);

    if(ans2 == num2 * num3) {
        printf("That's right!\n");
    }
    else {
        printf("Not quite! The answer was %d.\n", num2*num3);
    }

    printf("For the third question, what is %d divided by %d? ", num3, num4);
    scanf("%d", &ans3);

    if(ans3 == num3 / num4) {
        printf("Amazing, that's correct!\n");
    }
    else {
        printf("Incorrect! The answer was %d.\n", num3/num4);
    }

    printf("Now, calculate the remainder when %d is divided by %d. ", num4, num1);
    scanf("%d", &ans4);

    if(ans4 == num4 % num1) {
        printf("Woohoo, you got it!\n");
    }
    else {
        printf("Wrong, the answer was %d.\n", num4%num1);
    }

    printf("That was a surreal math quiz! Thanks for playing.\n");

    return 0;
}