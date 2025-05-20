//FormAI DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer in a specified range
int generateRandomNumberInRange(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main() {
    int num1, num2, operator, answer;
    char operators[4] = {'+', '-', '*', '/'};
    srand(time(NULL));

    printf("Hello, math champ! Let's test your skills with some exciting math problems!\n");
    printf("Get ready...\n\n");

    // Generate 10 random math problems and let the user answer them
    for (int i = 1; i <= 10; i++) {
        num1 = generateRandomNumberInRange(1, 100);
        num2 = generateRandomNumberInRange(1, 100);
        operator = generateRandomNumberInRange(0, 3);

        printf("Problem #%d: What is %d %c %d?\n", i, num1, operators[operator], num2);
        scanf("%d", &answer);

        // Check if the user's answer is correct
        switch (operators[operator]) {
            case '+':
                if (answer == num1 + num2) {
                    printf("Great job, you got it right!\n");
                } else {
                    printf("Oops, that's incorrect. The correct answer is %d.\n", num1 + num2);
                }
                break;
            case '-':
                if (answer == num1 - num2) {
                    printf("Awesome! You got it right!\n");
                } else {
                    printf("Sorry, that's incorrect. The correct answer is %d.\n", num1 - num2);
                }
                break;
            case '*':
                if (answer == num1 * num2) {
                    printf("Congratulations! You are a math wizard!\n");
                } else {
                    printf("Nope, that's incorrect. The correct answer is %d.\n", num1 * num2);
                }
                break;
            case '/':
                if (answer == num1 / num2) {
                    printf("You are a genius! That's the correct answer!\n");
                } else {
                    printf("Incorrect, sorry. The correct answer is %d.\n", num1 / num2);
                }
                break;
        }
        printf("\n");
    }

    printf("That's all for now, champ! Keep practicing and you'll become a math superstar in no time!\n");
    return 0;
}