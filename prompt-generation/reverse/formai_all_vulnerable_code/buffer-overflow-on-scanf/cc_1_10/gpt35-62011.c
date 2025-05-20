//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random operator
char generateOperator(){
    int op = rand() % 4;
    char operator;
    switch(op){
        case 0:
            operator = '+';
            break;
        case 1:
            operator = '-';
            break;
        case 2:
            operator = '*';
            break;
        case 3:
            operator = '/';
            break;
    }
    return operator;
}

int main(){
    int num_correct = 0, num_wrong = 0;
    printf("Welcome to the Math Exercise Program!\n\n");
    
    // Loop through the questions
    for(int i=0; i<10; i++){
        // Generate two random numbers between 1 and 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        // Generate a random operator
        char operator = generateOperator();
        // Calculate the answer to the question
        float answer;
        switch(operator){
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = (float)num1 / (float)num2;
                break;
        }
        printf("Question %d: %d %c %d = ", i+1, num1, operator, num2);
        // Get user's answer
        float user_answer;
        scanf("%f", &user_answer);
        // Check if user's answer is correct
        if(user_answer == answer){
            printf("Correct!\n");
            num_correct++;
        }else{
            printf("Incorrect. Correct answer is %f\n", answer);
            num_wrong++;
        }
    }
    // Print out summary of results
    printf("\nResults:\n");
    printf("Number correct: %d\n", num_correct);
    printf("Number wrong: %d\n", num_wrong);
    
    return 0;
}