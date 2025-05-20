//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize random seed
    srand(time(NULL));

    //define variables
    int num1, num2, operator;
    char input[10];

    //main loop
    while(1) {
        //print menu
        printf("Enter an arithmetic expression in the format: number operator number\n");
        printf("Valid operators are: + - * /\n");

        //read input
        scanf("%s", input);

        //parse input
        num1 = atoi(input);
        operator = input[strlen(input)-1];
        num2 = atoi(input+strlen(input)-2);

        //calculate result
        switch(operator) {
            case '+':
                printf("Result: %d\n", num1+num2);
                break;
            case '-':
                printf("Result: %d\n", num1-num2);
                break;
            case '*':
                printf("Result: %d\n", num1*num2);
                break;
            case '/':
                if(num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    printf("Result: %d\n", num1/num2);
                }
                break;
            default:
                printf("Error: Invalid operator\n");
        }
    }

    return 0;
}