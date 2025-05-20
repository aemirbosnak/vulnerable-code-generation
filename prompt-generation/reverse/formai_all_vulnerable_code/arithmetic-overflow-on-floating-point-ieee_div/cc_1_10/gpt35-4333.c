//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Welcome message
    printf("Hey there, let's have some math fun! Get ready to do some happy calculations!\n");

    // Generate random numbers for the exercise
    srand(time(NULL));
    int a = rand() % 101;
    int b = rand() % 101;

    // Addition
    printf("\nLet's start with an easy one. What is %d + %d?\n", a, b);
    int ans_add;
    scanf("%d", &ans_add);
    if (ans_add == a + b) {
        printf("Great job, you got it right! :)\n");
    } else {
        printf("Oops, the correct answer is %d. But don't worry, you'll get the next one! :)\n", a + b);
    }

    // Subtraction
    printf("\nNow let's try something a bit harder. What is %d - %d?\n", a, b);
    int ans_sub;
    scanf("%d", &ans_sub);
    if (ans_sub == a - b) {
        printf("Excellent, you're a math whiz! :)\n");
    } else {
        printf("Uh oh, the correct answer is %d. But keep on smiling, you'll get the next one! :)\n", a - b);
    }

    // Multiplication
    printf("\nNext up, a multiplication question. What is %d * %d?\n", a, b);
    int ans_mul;
    scanf("%d", &ans_mul);
    if (ans_mul == a * b) {
        printf("You're on a roll, keep it up! :)\n");
    } else {
        printf("Don't worry, the correct answer is %d. But don't let that stop your happy vibes! :)\n", a * b);
    }

    // Division
    printf("\nLet's finish off with a division question. What is %d / %d?\n", a, b);
    float ans_div;
    scanf("%f", &ans_div);
    if (ans_div == (float) a / b) {
        printf("Awesome job, you're a math star! :)\n");
    } else {
        printf("No worries, the correct answer is %.2f. Keep that happy attitude! :)\n", (float) a / b);
    }

    // Final message
    printf("\nThanks for playing! Remember, always keep that happy spirit and don't be afraid to make mistakes. That's how we learn and grow! :)\n");

    return 0;
}