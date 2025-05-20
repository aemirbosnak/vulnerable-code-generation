//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, answer, userAnswer;
    srand(time(NULL)); // seed the random number generator with the current time
    
    printf("Welcome to the exciting Math Exercise Program!\n\n");
    printf("In this program, you will be asked a series of math questions.\n");
    printf("You will be given a choice of operators to use (+, -, *, /) and a range of numbers to pick from.\n");
    printf("You must answer each question correctly in order to progress to the next level.\n");
    printf("Good luck!\n\n");
    
    int level = 1; // start at level 1
    
    while(1) { // keep looping until the user quits
        
        // generate two random numbers
        num1 = rand()%10 + level*10;
        num2 = rand()%10 + level*10;
        
        // ask the user what operator to use
        printf("Level %d: What operator do you want to use? (+, -, *, /)\n", level);
        scanf("%c", &operator);
        getchar(); // consume the newline character
        
        // calculate the answer using the chosen operator
        switch(operator) {
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
                answer = num1 / num2;
                break;
            default:
                printf("Invalid operator choice. Please try again.\n\n");
                continue; // go back to the beginning of the loop
        }
        
        // ask the user the question and get their answer
        printf("What is %d %c %d?\n", num1, operator, num2);
        scanf("%d", &userAnswer);
        getchar(); // consume the newline character
        
        // check if the user's answer is correct
        if(userAnswer == answer) {
            printf("Correct! You have advanced to level %d.\n\n", ++level);
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", answer);
            if(level > 1) { // only decrement level if they are not on the first level
                level--;
            }
        }
        
        printf("Press enter to continue, or type 'q' to quit.\n");
        char input = getchar();
        if(input == 'q') {
            break; // exit the loop and quit the program
        }
    }
    
    printf("Thanks for playing the Math Exercise Program!\n");
    
    return 0;
}