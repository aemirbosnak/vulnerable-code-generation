//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate a random number between min and max (inclusive) 
int generateRandomNumber(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main(){

    srand(time(0));
    int num1, num2, num3, result;
    char operator;

    printf("Welcome to the Arithmetic Challenge Game.\n\n");
    printf("You will be asked to solve 10 arithmetic problems.\n");
    printf("Each problem will have either a +, -, * or / operator.\n");
    printf("Please enter your answer in integer format.\n");
    printf("You will receive a score out of 10 based on your answers.\n\n");

    int score = 0;
    for(int i=1; i<=10; i++){
        num1 = generateRandomNumber(1, 100);
        num2 = generateRandomNumber(1, 100);
        num3 = generateRandomNumber(1, 100);

        int operatorIndex = generateRandomNumber(0, 3);
        if(operatorIndex == 0){
            operator = '+';
            result = num1 + num2 + num3;
        }
        else if(operatorIndex == 1){
            operator = '-';
            result = num1 - num2 - num3;
        }
        else if(operatorIndex == 2){
            operator = '*';
            result = num1 * num2 * num3;
        }
        else{
            operator = '/';
            result = num1 / num2 / num3;
        }

        printf("\nProblem %d/10: %d %c %d %c %d = ?\n", i, num1, operator, num2, operator, num3);
        int answer;
        scanf("%d", &answer);
        if(answer == result){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect! The correct answer was %d.\n", result);
        }
    }

    printf("\n\nYour score is: %d/10\n", score);
    if(score == 10){
        printf("Congratulations! You are a math genius!\n");
    }
    else if(score >= 7){
        printf("Not bad! You have a good command on arithmetic!\n");
    }
    else{
        printf("Sorry! You need to improve your arithmetic skills!\n");
    }

    return 0;
}