//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int num1, num2, operator, answer, user_answer, correct_answers = 0, incorrect_answers = 0;
    char operation_symbol;
    srand(time(0));
    
    // Generate 10 math problems
    for(int i=1; i<=10; i++) {
        num1 = rand() % 10;
        num2 = rand() % 10;
        operator = rand() % 4;
        
        // Determine operation
        switch(operator) {
            case 0:
                answer = num1 + num2;
                operation_symbol = '+';
                break;
            case 1:
                answer = num1 - num2;
                operation_symbol = '-';
                break;
            case 2:
                answer = num1 * num2;
                operation_symbol = '*';
                break;
            case 3:
                answer = num1 / num2;
                operation_symbol = '/';
                break;
        }
        
        // Print problem and get user's answer
        printf("\nProblem #%d: %d %c %d = ", i, num1, operation_symbol, num2);
        scanf("%d", &user_answer);
        
        // Check if answer is correct
        if(user_answer == answer) {
            printf("Correct!");
            correct_answers++;
        }
        else {
            printf("Incorrect! The correct answer is %d", answer);
            incorrect_answers++;
        }
    }
    
    // Print results
    printf("\n\nYou got %d problems correct and %d problems incorrect.", correct_answers, incorrect_answers);
    
    return 0;
}