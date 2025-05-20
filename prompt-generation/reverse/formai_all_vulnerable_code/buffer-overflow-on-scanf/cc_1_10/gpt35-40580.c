//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    printf("Hey there kiddo, are you ready for some math?\n");
    printf("Let's see if you can handle my unique C math exercise program!\n\n");

    int num1 = rand() % 10;
    int num2 = rand() % 10;

    printf("First question:\n");
    printf("What's the sum of %d and %d?\n", num1, num2);

    int answer;
    scanf("%d", &answer);

    if (answer == num1 + num2) {
        printf("Well look at you, you got that one right!\n\n");
    }
    else {
        printf("Ah, it looks like you need some more practice.\n");
        printf("The correct answer is %d.\n\n", num1 + num2);
    }

    printf("Next question:\n");
    printf("What's 8 divided by 2?\n");

    scanf("%d", &answer);

    if (answer == 4) {
        printf("Wow, you're really good at this!\n");
    }
    else {
        printf("Ooh, sorry kiddo, that's not the right answer.\n");
        printf("The correct answer is 4.\n");
    }

    printf("\nNext question:\n");
    printf("What's the square root of 49?\n");

    scanf("%d", &answer);

    if (answer == 7) {
        printf("You're on a roll, keep it up!\n");
    }
    else {
        printf("Nope, that's not it.\n");
        printf("The correct answer is 7.\n");
    }

    printf("\nNext question:\n");
    printf("What's 3 times 4 minus 2 plus 5 divided by 5?\n");

    scanf("%d", &answer);

    if (answer == 11) {
        printf("You're a math genius!\n");
    }
    else {
        printf("Close, but no cigar.\n");
        printf("The correct answer is 11.\n");
    }

    printf("\nFinal question:\n");
    printf("What's the minimum number of lines this program needs to be?\n");

    scanf("%d", &answer);

    if (answer == 50) {
        printf("Congratulations, you are correct!\n");
    }
    else {
        printf("Nice try, but that's not it.\n");
        printf("The correct answer is 50.\n");
    }

    return 0;
}