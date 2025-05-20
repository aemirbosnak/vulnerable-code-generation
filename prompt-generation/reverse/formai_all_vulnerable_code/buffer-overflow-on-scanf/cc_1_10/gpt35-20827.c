//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //initialize random seed
    int num1, num2, answer, userAns, count = 0;
    char operator;
    printf("***Welcome to Math Exercise Program***\n\n");
    printf("Let's start with some simple addition exercises.\n\n");
    //generate random numbers and operator
    while(count < 5){
        num1 = rand()%101; //generate number between 0-100
        num2 = rand()%101;
        operator = '+';
        answer = num1 + num2;
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &userAns);
        if(userAns == answer){
            printf("Correct!\n\n");
            count++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    printf("Great job! Let's move onto some subtraction exercises now.\n\n");
    //generate random numbers and operator
    count = 0;
    while(count < 5){
        num1 = rand()%101; //generate number between 0-100
        num2 = rand()%num1+1; //ensure num1 > num2
        operator = '-';
        answer = num1 - num2;
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &userAns);
        if(userAns == answer){
            printf("Correct!\n\n");
            count++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    printf("You're doing great! Let's finish off with some multiplication exercises.\n\n");
    //generate random numbers and operator
    count = 0;
    while(count < 5){
        num1 = rand()%13; //generate number between 0-12
        num2 = rand()%13;
        operator = '*';
        answer = num1 * num2;
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &userAns);
        if(userAns == answer){
            printf("Correct!\n\n");
            count++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    printf("Congratulations, you have completed all the exercises! Great job!\n");
    return 0;
}