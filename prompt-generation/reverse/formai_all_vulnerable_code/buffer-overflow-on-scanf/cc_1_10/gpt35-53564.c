//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Let's do some C math exercises and have some fun!\n");

    //generate two random integers between 1 and 50
    srand(time(NULL));
    int num1 = rand() % 50 + 1;
    int num2 = rand() % 50 + 1;

    printf("What is the sum of %d and %d?\n", num1, num2);

    int answer;
    scanf("%d", &answer);

    int sum = num1 + num2;

    if(answer == sum){
        printf("Correct! Good job!\n");
    } else {
        printf("Sorry, that's incorrect. The correct answer is %d.\n", sum);
    }

    printf("Now let's do some multiplication!\n");

    //generate two random integers between 1 and 20
    int num3 = rand() % 20 + 1;
    int num4 = rand() % 20 + 1;

    printf("What is the product of %d and %d?\n", num3, num4);

    int product;
    scanf("%d", &product);

    int mult = num3 * num4;

    if(product == mult){
        printf("Well done! You got it!\n");
    } else {
        printf("Sorry, that's not right. The correct answer is %d.\n", mult);
    }

    printf("Okay, one more challenge. Let's find the square root of a number!\n");

    //generate a random integer between 1 and 100
    int num5 = rand() % 100 + 1;

    double sqrt_input = (double) num5;
    double sqrt_value = sqrt(sqrt_input);

    printf("What is the square root of %d (rounded to two decimal places)?\n", num5);

    double guess;
    scanf("%lf", &guess);

    if(abs(sqrt_value - guess) < 0.01){
        printf("You did it! You found the square root! Congrats!\n");
    } else {
        printf("Sorry, that's not quite right. The actual answer is %.2lf.\n", sqrt_value);
    }

    printf("Thanks for playing! Let's do some more math exercises next time!\n");

    return 0;
}