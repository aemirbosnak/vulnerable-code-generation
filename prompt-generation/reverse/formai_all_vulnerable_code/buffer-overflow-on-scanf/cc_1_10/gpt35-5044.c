//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get a random number between 1 and 10
int get_random_number() {
    srand(time(NULL)); // seed the random number generator with current time
    return rand() % 10 + 1;
}

// main function
int main() {
    int num1, num2, operation, answer, user_answer;
    
    printf("Welcome to Math Exercise Program!\n");
    printf("You will be given two numbers and a math operation and you have to solve it.\n");
    printf("Let's start...\n\n");
    
    // loop to generate exercises
    for(int i=1; i<=10; i++) {
        num1 = get_random_number(); // get the first randon number
        num2 = get_random_number(); // get the second random number
        operation = rand() % 3; // get a random number between 0 and 2 to represent add, subtract, or multiply operation
        
        switch(operation) {
            case 0: // add operation
                answer = num1 + num2;
                printf("%d + %d =\n", num1, num2);
                break;
            case 1: // subtract operation
                answer = num1 - num2;
                printf("%d - %d =\n", num1, num2);
                break;
            case 2: // multiply operation
                answer = num1 * num2;
                printf("%d * %d =\n", num1, num2);
                break;
        }
        
        scanf("%d", &user_answer); // get user answer
        
        if(user_answer == answer) {
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The correct answer is: %d\n\n", answer);
        }
    }
    
    printf("You have completed the exercises.\n");
    printf("Thank you for using the Math Exercise Program.\n");
    
    return 0;
}