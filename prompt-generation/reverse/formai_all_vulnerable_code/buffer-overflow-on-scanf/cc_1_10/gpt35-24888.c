//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function for getting the answer
int getAnswer(int num1, int num2, char operator) {
    switch(operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
}

//function for getting random operator
char getRandomOperator() {
    char operator;
    int random = rand() % 4;
    
    switch(random) {
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

//function for getting random integer within a specified range
int getRandomNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    //seed the random number generator with the current system time
    srand(time(NULL));
    
    //declare variables for menu choices and user input
    int choice, num1, num2, answer, userAnswer, correctCount = 0, incorrectCount = 0;
    char operator;
    
    //display menu options
    printf("Math Exercise Program\n");
    printf("========================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("========================\n");
    
    //get user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    //validate user input
    while(choice < 1 || choice > 4) {
        printf("Invalid choice. Please enter a number between 1 and 4: ");
        scanf("%d", &choice);
    }
    
    //get number of questions
    printf("How many questions do you want to answer? ");
    int numQuestions;
    scanf("%d", &numQuestions);
    
    //validate user input
    while(numQuestions <= 0) {
        printf("Invalid number of questions. Please enter a positive integer: ");
        scanf("%d", &numQuestions);
    }
    
    //loop through the specified number of questions
    for(int i = 1; i <= numQuestions; i++) {
        //get random numbers and operator
        num1 = getRandomNum(1, 20);
        num2 = getRandomNum(1, 20);
        operator = getRandomOperator();
        
        //calculate the correct answer
        answer = getAnswer(num1, num2, operator);
        
        //display the question
        printf("\nQuestion %d: %d %c %d = ", i, num1, operator, num2);
        
        //get user's answer
        scanf("%d", &userAnswer);
        
        //check if user's answer is correct
        if(userAnswer == answer) {
            printf("Correct!");
            correctCount++;
        } else {
            printf("Incorrect! The correct answer is %d.", answer);
            incorrectCount++;
        }
    }
    
    //display results
    printf("\n\nResults:\n");
    printf("Total Questions: %d\n", numQuestions);
    printf("Number Correct: %d\n", correctCount);
    printf("Number Incorrect: %d\n", incorrectCount);
    
    return 0;
}