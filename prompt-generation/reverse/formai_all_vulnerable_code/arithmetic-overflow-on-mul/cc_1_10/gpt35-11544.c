//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random integer between two numbers, inclusive
int generateRandomInt(int low, int high) {
    srand(time(NULL)); // seed the random number generator
    return rand() % (high - low + 1) + low;
}

int main() {
    int num1, num2, ans, userAns, correctAns = 0, totalQues = 0;
    char op;
    printf("********** MATH QUIZ **********\n");
    printf("Enter two numbers to generate math problems (e.g. 5 10): ");
    scanf("%d %d", &num1, &num2);
    while(1) {
        // randomly generate the operator
        int operatorNum = generateRandomInt(1, 4);
        if(operatorNum == 1) {
            op = '+';
            // generate two numbers to add
            int num3 = generateRandomInt(num1, num2);
            int num4 = generateRandomInt(num1, num2);
            ans = num3 + num4;
            printf("%d %c %d = ", num3, op, num4);
        } else if(operatorNum == 2) {
            op = '-';
            // generate two numbers to subtract
            int num3 = generateRandomInt(num1, num2);
            int num4 = generateRandomInt(num1, num2);
            ans = num3 - num4;
            printf("%d %c %d = ", num3, op, num4);
        } else if(operatorNum == 3) {
            op = '*';
            // generate two numbers to multiply
            int num3 = generateRandomInt(num1, num2);
            int num4 = generateRandomInt(num1, num2);
            ans = num3 * num4;
            printf("%d %c %d = ", num3, op, num4);
        } else {
            op = '/';
            // generate two numbers to divide
            int num3 = generateRandomInt(num1, num2);
            int num4 = generateRandomInt(num1, num2);
            // avoid division by zero
            while(num4 == 0) {
                num4 = generateRandomInt(num1, num2);
            }
            ans = num3 / num4;
            printf("%d %c %d = ", num3, op, num4);
        }
        // read in user's answer
        scanf("%d", &userAns);
        totalQues++;
        if(userAns == ans) {
            printf("Correct!\n");
            correctAns++;
        } else {
            printf("Incorrect! The correct answer is %d\n", ans);
        }
        char continueQuiz;
        printf("Would you like to continue? (y/n) ");
        scanf(" %c", &continueQuiz);
        if(continueQuiz == 'n') {
            break;
        }
    }
    // display final results
    printf("You answered %d out of %d questions correctly!\n", correctAns, totalQues);
    return 0;
}