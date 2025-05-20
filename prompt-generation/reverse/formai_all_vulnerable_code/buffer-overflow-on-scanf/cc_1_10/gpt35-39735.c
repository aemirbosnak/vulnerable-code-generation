//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer;
    int correct_answers = 0;
    int question_counter = 0;
    char operator;
    
    srand(time(0)); // Seed the random number generator
    
    while (question_counter < 10) { // Ask 10 questions
        num1 = rand() % 10 + 1; // Generate random numbers between 1 and 10
        num2 = rand() % 10 + 1;
        
        switch (rand() % 4) { // Generate a random operator
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
                answer = num1 / num2; // Integer division
                break;
        }
        
        int user_answer;
        printf("Question %d: What is %d %c %d?\n", question_counter + 1, num1, operator, num2);
        scanf("%d", &user_answer);
        
        if (user_answer == answer) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The answer is %d\n", answer);
        }
        
        question_counter++;
    }
    
    printf("You got %d out of 10 questions correct.\n", correct_answers);
    
    return 0;
}