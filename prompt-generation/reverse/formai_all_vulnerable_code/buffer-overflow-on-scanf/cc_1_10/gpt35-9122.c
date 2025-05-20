//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random integer in the range of [min, max]
int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

int main() {

    int num1, num2, guess, answer;
    int totalScore = 0;
    srand(time(0)); // Seed the random number generator with the current time

    printf("Welcome to the Math Quiz!\n");
    printf("You will be presented with two random numbers and your task is to guess the result of a randomly selected arithmetic operation between those numbers.\n");
    printf("For each correct answer, you will earn 10 points.\n\n");

    // Loop for 5 questions
    for(int i=0; i<5; i++) {
        num1 = randomInt(1,10);
        num2 = randomInt(1,10);
        int op = randomInt(1,4); // Randomly select an arithmetic operation

        // Depending on the value of op, perform the corresponding arithmetic operation on num1 and num2 and store it in answer variable
        switch(op) {
            case 1:
                answer = num1 + num2;
                printf("What is %d + %d? ", num1, num2);
                break;
            case 2:
                answer = num1 - num2;
                printf("What is %d - %d? ", num1, num2);
                break;
            case 3:
                answer = num1 * num2;
                printf("What is %d * %d? ", num1, num2);
                break;
            case 4:
                answer = num1 / num2;
                printf("What is %d / %d? ", num1, num2);
                break;
        }

        // Read the user's guess and compare it with the actual answer
        scanf("%d", &guess);
        if(guess == answer) {
            printf("Correct!\n");
            totalScore += 10;
        } else {
            printf("Incorrect. The correct answer was %d.\n", answer);
        }

        printf("\n");
    }

    printf("Quiz complete! Your total score is %d out of %d.\n", totalScore, 50);

    return 0;
}