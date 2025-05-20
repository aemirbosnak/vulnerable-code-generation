//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retro Arithmetic Game */

int main() {
    int num1, num2, answer, user_answer, score = 0;
    char operator;
    srand(time(NULL));
    
    printf("Welcome to Retro Arithmetic Game!\n\n");
    printf("Instructions: \n");
    printf("You will be given randomly generated arithmetic questions.\n");
    printf("Answer as many questions as you can within 60 seconds.\n");
    printf("Each correct answer gives you a score of 10.\n");
    printf("Let's get started!\n");
    
    clock_t start_time = clock();
    while((clock() - start_time) / CLOCKS_PER_SEC < 60) {
        num1 = rand() % 20 + 1; 
        num2 = rand() % 20 + 1;

        switch(rand() % 4) {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
            case 3:
                operator = '/';
                answer = num1 / num2;
                break;
            default:
                break;
        }
        
        printf("%d %c %d = ", num1, operator, num2);
        scanf("%d", &user_answer);
        fflush(stdin);
        if(user_answer == answer) {
            score += 10;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }
    
    printf("\nTime's up!\n");
    printf("You scored %d points.\n", score);
    return 0;
}