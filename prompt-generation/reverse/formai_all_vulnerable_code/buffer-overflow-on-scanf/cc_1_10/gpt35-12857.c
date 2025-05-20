//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int num1, num2, result, user_ans, count = 0;
    char operator;
    
    srand(time(NULL));
    
    printf("Welcome to the Math Practice Program!\n");
    printf("You will be given 10 questions to solve.\n");
    printf("Please enter the result of the following equations.\n");
    
    for(int i = 0; i < 10; i++) {
        num1 = rand() % 50 + 1;
        num2 = rand() % 50 + 1;
        
        if(num1 % 2 == 0 && num2 % 2 == 0) {
            operator = '+';
            result = num1 + num2;
        }
        else if(num1 % 2 == 0 && num2 % 2 != 0) {
            operator = '-';
            result = num1 - num2;
        }
        else if(num1 % 2 != 0 && num2 % 2 == 0) {
            operator = '*';
            result = num1 * num2;
        }
        else {
            operator = '/';
            result = num1 / num2;
        }
        
        printf("\nQuestion %d: %d %c %d = ", i+1, num1, operator, num2);
        scanf("%d", &user_ans);
        if(user_ans == result) {
            printf("Correct!");
            count++;
        }
        else {
            printf("Incorrect. The correct answer is %d.", result);
        }
    }
    
    printf("\n\nYou have completed the Math Practice Program!\n");
    printf("You answered %d out of 10 questions correctly.", count);
    
    return 0;
}