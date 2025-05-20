//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include<stdio.h> //standard IO library
#include<stdlib.h> //standard library
#include<time.h> //time library for generating random numbers

int main() {
    srand(time(NULL)); //initialize seed for random number generator
    int operand1, operand2, answer; //integer variables to hold operands and user's answer
    char operator; //variable to hold the operator
    int total_correct = 0, total_questions = 0; //variables to keep track of user performance
    
    printf("Welcome to Math Exercise Program!\n\n");
    printf("This program will generate random math exercises for you to solve.\n");
    printf("You will be given 10 questions, answer as many as you can correctly.\n\n");
    
    for(int i = 1; i <= 10; i++) { //loop for 10 questions
        operand1 = rand() % 100; //generate random operands between 0 and 99
        operand2 = rand() % 100;
        
        switch(rand() % 4) { //generate random operator (0 for +, 1 for -, 2 for * and 3 for /)
            case 0:
                operator = '+';
                answer = operand1 + operand2;
                break;
            case 1:
                operator = '-';
                answer = operand1 - operand2;
                break;
            case 2:
                operator = '*';
                answer = operand1 * operand2;
                break;
            case 3:
                operator = '/';
                answer = operand1 / operand2;
                break;
        }
        
        printf("Question %d: %d %c %d = ?\n", i, operand1, operator, operand2); //print the question
        
        int user_answer;
        scanf("%d", &user_answer); //get user's answer
        
        if(user_answer == answer) { //check if the answer is correct
            printf("Correct!\n");
            total_correct++;
        }
        else {
            printf("Incorrect. The correct answer is: %d\n", answer);
        }
        total_questions++;
        printf("\n");
    }
    printf("You answered %d questions correctly out of %d.\n", total_correct, total_questions);
    printf("Thank you for using Math Exercise Program!\n");
    return 0;
}