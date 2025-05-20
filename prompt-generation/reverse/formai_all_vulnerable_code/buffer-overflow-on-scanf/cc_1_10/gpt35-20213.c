//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    printf("****************************************************\n");
    printf("*                                                  *\n");
    printf("*              WELCOME TO MATH ADVENTURE            *\n");
    printf("*                                                  *\n");
    printf("****************************************************\n");
    printf("\n\n");

    srand(time(NULL));
    int num1, num2, operator, result;
    int score = 0;
    int i;

    for(i = 1; i <= 10; i++){
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        operator = rand() % 4;

        switch(operator){
            case 0:
                printf("\n%d + %d equals to ?\n", num1, num2);
                result = num1 + num2;
                break;
            case 1:
                printf("\n%d - %d equals to ?\n", num1, num2);
                result = num1 - num2;
                break;
            case 2:
                printf("\n%d x %d equals to ?\n", num1, num2);
                result = num1 * num2;
                break;
            case 3:
                printf("\n%d / %d equals to ?\n", num1, num2);
                result = num1 / num2;
                break;
        }

        int userAnswer;
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        if(result == userAnswer){
            printf("\nCorrect!\n");
            score += 10;
        }
        else{
            printf("\nIncorrect!\n");
        }
    }

    printf("\n\n");
    printf("****************************************************\n");
    printf("*               YOUR FINAL SCORE IS: %d             *\n", score);
    printf("****************************************************\n");

    printf("\n\n");
    printf("THANK YOU FOR PLAYING MATH ADVENTURE!\n");
}