//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the area of a circle
double areaOfCircle(double r){
    return 3.141592 * r * r;
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // declare variables for the correct and incorrect answers
    int correctAnswers = 0;
    int incorrectAnswers = 0;

    // display program instructions
    printf("Welcome to the Math Exercises program!\n\n");
    printf("In this program, you will be presented with a series of math exercises to solve.\n");
    printf("For each exercise, you will be asked to provide the correct answer.\n");
    printf("If you answer correctly, you will earn one point.\n");
    printf("If you answer incorrectly, you will not earn a point.\n");
    printf("At the end of the program, your score will be displayed.\n\n");

    // loop through each exercise
    for (int i = 1; i <= 10; i++) {
        printf("Exercise %d:\n", i);

        // generate a random number within the given range
        int num1 = rand() % 101;
        int num2 = rand() % 101;

        // generate a random operator
        char op = '+';
        int opCode = rand() % 4;
        switch(opCode){
            case 0:
                op = '+';
                break;
            case 1:
                op = '-';
                break;
            case 2:
                op = '*';
                break;
            case 3:
                op = '/';
                break;
            default:
                break;
        }

        // display the exercise to the user
        if(op == '/'){
            // if the operator is division, make sure the numbers are divisible
            if(num1 % num2 != 0){
                int temp = num1;
                num1 = num2;
                num2 = temp;
            }
            printf("%d %c %d = ? (rounded to two decimal places)\n", num1, op, num2);
        } else if(op == '*'){
            // if the operator is multiplication, make sure the numbers are less than 10
            if(num1 > 9 || num2 > 9){
                int temp = num1;
                num1 = rand() % 10;
                num2 = temp;
            }
            printf("%d %c %d = ?\n", num1, op, num2);
        } else {
            // for addition and subtraction, just display the equation
            printf("%d %c %d = ?\n", num1, op, num2);
        }

        // get the user's answer
        double userAnswer;
        scanf("%lf", &userAnswer);

        // calculate the correct answer
        double correctAnswer;
        switch(op){
            case '+':
                correctAnswer = num1 + num2;
                break;
            case '-':
                correctAnswer = num1 - num2;
                break;
            case '*':
                correctAnswer = num1 * num2;
                break;
            case '/':
                correctAnswer = (double) num1 / num2;
                break;
            default:
                break;
        }

        // check if the user's answer is correct
        if(op == '/' || op == '*'){
            // round the answers to two decimal places
            double epsilon = 0.01;
            if(abs(userAnswer - correctAnswer) < epsilon){
                printf("Correct!\n\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer was %.2lf.\n\n", correctAnswer);
                incorrectAnswers++;
            }
        } else {
            if(userAnswer == correctAnswer){
                printf("Correct!\n\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer was %.0lf.\n\n", correctAnswer);
                incorrectAnswers++;
            }
        }
    }

    // display the user's score
    printf("End of exercises!\n");
    printf("You answered %d exercises correctly and %d exercises incorrectly.\n", correctAnswers, incorrectAnswers);

    // bonus exercise: calculate the area of a circle
    printf("\nBonus exercise: calculate the area of a circle!\n");
    printf("Enter the radius of a circle: ");
    double radius;
    scanf("%lf", &radius);
    printf("The area of the circle is %.2lf.\n", areaOfCircle(radius));

    return 0;
}