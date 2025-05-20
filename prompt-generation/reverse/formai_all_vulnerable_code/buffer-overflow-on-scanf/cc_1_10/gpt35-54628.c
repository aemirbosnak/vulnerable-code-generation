//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int num1, num2, operator, user_answer, correct_answer;
    int correct_counter = 0, wrong_counter = 0;
    int total_problems = 0;

    srand(time(0));

    printf("Welcome to the C Math Exercise Program!\n\n");

    while(1){
        num1 = rand() % 100;
        num2 = rand() % 100;

        operator = rand() % 3;
        total_problems++;

        if(operator == 0){
            correct_answer = num1 + num2;
            printf("Problem #%d: %d + %d = ", total_problems, num1, num2);
        }
        else if(operator == 1){
            correct_answer = num1 - num2;
            printf("Problem #%d: %d - %d = ", total_problems, num1, num2);
        }
        else{
            correct_answer = num1 * num2;
            printf("Problem #%d: %d * %d = ", total_problems, num1, num2);
        }

        scanf("%d", &user_answer);

        if(user_answer == correct_answer){
            printf("Correct!\n\n");
            correct_counter++;
        }
        else{
            printf("Wrong! The correct answer is %d.\n\n", correct_answer);
            wrong_counter++;
        }

        printf("Answer %d more problems? (Enter 1 for yes, 0 for no): ", total_problems);
        int play_again;
        scanf("%d", &play_again);

        if(play_again == 0){
            printf("\n\nCorrect answers: %d\n", correct_counter);
            printf("Wrong answers: %d\n", wrong_counter);
            printf("Total problems: %d\n\n", total_problems);
            break;
        }
    }

    return 0;
}