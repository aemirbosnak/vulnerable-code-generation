//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
/*************************************
* Program: Math Wizard
* Author: Chatbot
* Date: 2021-07-26
* Description: A mathematical game
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, user_answer, points = 0;
    srand(time(NULL));
    printf("Welcome to Math Wizard!\n");
    while(1) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        operator = rand() % 4;
        switch(operator) {
            case 0:
                printf("%d + %d = ", num1, num2);
                answer = num1 + num2;
                break;
            case 1:
                printf("%d - %d = ", num1, num2);
                answer = num1 - num2;
                break;
            case 2:
                printf("%d * %d = ", num1, num2);
                answer = num1 * num2;
                break;
            case 3:
                printf("%d / %d = ", num1, num2);
                answer = num1 / num2;
                break;
            default:
                printf("Error\n");
                exit(1);
        }
        scanf("%d", &user_answer);
        if(user_answer == answer) {
            printf("Correct! +10 points!\n");
            points += 10;
        }
        else {
            printf("Wrong! -5 points! Answer: %d\n", answer);
            points -= 5;
        }
        printf("Total points: %d\n\n", points);
    }
    return 0;
}