//FormAI DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int a, b, c, d, e, f, g, h;
    char operator1, operator2;

    srand(time(0));     //Seed the random number generator with current time

    //Randomly generate two operators
    int num = rand() % 4;
    switch(num) {
        case 0:
            operator1 = '+';
            break;
        case 1:
            operator1 = '-';
            break;
        case 2:
            operator1 = '*';
            break;
        case 3:
            operator1 = '/';
            break;
        default:
            operator1 = '+';
    }

    num = rand() % 4;
    switch(num) {
        case 0:
            operator2 = '+';
            break;
        case 1:
            operator2 = '-';
            break;
        case 2:
            operator2 = '*';
            break;
        case 3:
            operator2 = '/';
            break;
        default:
            operator2 = '+';
    }

    //Generate random integers for operands
    a = rand() % 10 + 1;     
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
    d = rand() % 10 + 1;
    e = rand() % 10 + 1;
    f = rand() % 10 + 1;
    g = rand() % 10 + 1;
    h = rand() % 10 + 1;

    //Printf statement to display the exercise to user
    printf("Solve this exercise: %d %c %d %c %d %c %d %c %d\n", a, operator1, b, operator2, c, operator1, d, operator2, e);

    //Calculate the result of the exercise
    int result;
    switch(operator1) {
        case '+':
            switch(operator2) {
                case '+':
                    result = a + b + c + d + e;
                    break;
                case '-':
                    result = a + b + c - d - e;
                    break;
                case '*':
                    result = a + b + c * d * e;
                    break;
                case '/':
                    result = a + b + c / d / e;
                    break;
                default:
                    printf("Invalid operator\n");
            }
            break;
        case '-':
            switch(operator2) {
                case '+':
                    result = a - b - c + d + e;
                    break;
                case '-':
                    result = a - b - c - d - e;
                    break;
                case '*':
                    result = a - b - c * d * e;
                    break;
                case '/':
                    result = a - b - c / d / e;
                    break;
                default:
                    printf("Invalid operator\n");
            }
            break;
        case '*':
            switch(operator2) {
                case '+':
                    result = a * b * c + d + e;
                    break;
                case '-':
                    result = a * b * c - d - e;
                    break;
                case '*':
                    result = a * b * c * d * e;
                    break;
                case '/':
                    result = a * b * c / d / e;
                    break;
                default:
                    printf("Invalid operator\n");
            }
            break;
        case '/':
            switch(operator2) {
                case '+':
                    result = a / b / c + d + e;
                    break;
                case '-':
                    result = a / b / c - d - e;
                    break;
                case '*':
                    result = a / b / c * d * e;
                    break;
                case '/':
                    result = a / b / c / d / e;
                    break;
                default:
                    printf("Invalid operator\n");
            }
            break;
        default:
            printf("Invalid operator\n");
    }

    //Get user input for the calculated result
    int userInput;
    printf("Enter your answer: ");
    scanf("%d", &userInput);

    //Check if user input matches calculated result
    if(userInput == result) {
        printf("Congratulations! Your answer is correct!\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", result);
    }

    return 0;
}