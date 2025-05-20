//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, user_answer, result;
    int count_correct = 0;
    int count_incorrect = 0;
    double score_percent = 0.0;
    srand(time(NULL));
    
    printf("Welcome to the Math Exercise Game!\n\n");
    printf("You will be presented with ten random Math problems. Try to get as many correct as you can!\n");
    printf("-------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < 10; i++) {  // loop through 10 problems
        num1 = rand() % 20;         // generate random numbers between 0 and 19
        num2 = rand() % 20;
        operator = rand() % 4;      // generate random operator: 0 - addition, 1 - subtraction, 2 - multiplication, 3 - division
        
        switch(operator) {          // calculate answer based on operator
            case 0:
                answer = num1 + num2;
                printf("%d + %d = ", num1, num2);
                break;
            case 1:
                answer = num1 - num2;
                printf("%d - %d = ", num1, num2);
                break;
            case 2:
                answer = num1 * num2;
                printf("%d * %d = ", num1, num2);
                break;
            case 3:
                if (num2 == 0) {     // prevent divide by zero error
                    num2 = 1;
                }
                answer = num1 / num2;
                printf("%d / %d = ", num1, num2);
                break;
        }
        
        scanf("%d", &user_answer);      // get user input
        
        if (user_answer == answer) {     // compare user answer to correct answer
            printf("Correct!\n\n");
            count_correct++;
        } else {
            printf("Incorrect. The correct answer is %d\n\n", answer);
            count_incorrect++;
        }
    }
    
    score_percent = (double)count_correct / 10.0 * 100.0;  // calculate score percentage
    printf("Congratulations on finishing the Math Exercise Game!\n");
    printf("You got %d problems correct and %d problems incorrect.\n", count_correct, count_incorrect);
    printf("Your score is %.2f percent!\n", score_percent);
    
    return 0;
}