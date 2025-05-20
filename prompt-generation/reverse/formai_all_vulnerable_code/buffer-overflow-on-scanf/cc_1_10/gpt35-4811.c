//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num1, num2;
    char op;
    int answer, userAnswer;
    int correct = 0, incorrect = 0;

    srand(time(NULL));

    printf("Welcome! Let's do some happy math exercises!\n\n");

    for(int i=0; i<5; i++){
        num1 = rand() % 10;
        num2 = rand() % 10;

        switch(rand() % 4){
            case 0:
                op = '+';
                answer = num1 + num2;
                break;
            case 1:
                op = '-';
                answer = num1 - num2;
                break;
            case 2:
                op = '*';
                answer = num1 * num2;
                break;
            case 3:
                op = '/';
                answer = num1 / num2;
                break;
        }

        printf("\nQuestion %d: What is %d %c %d?\n", i+1, num1, op, num2);

        printf("Your answer: ");
        scanf("%d", &userAnswer);

        if(userAnswer == answer){
            printf("Correct! You are a happy math genius!\n");
            correct++;
        }else{
            printf("Incorrect. Sorry, the correct answer is %d. Don't worry, keep trying!\n", answer);
            incorrect++;
        }
    }

    printf("\nThank you for playing! Here is your result:\n");
    printf("Total correct answers: %d\n", correct);
    printf("Total incorrect answers: %d\n", incorrect);

    if(correct == 5){
        printf("Congratulations! You got all answers correct! You are a happy math champion!\n");
    }

    return 0;
}