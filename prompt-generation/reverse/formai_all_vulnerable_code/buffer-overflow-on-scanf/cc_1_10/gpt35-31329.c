//FormAI DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int answers[10];  //initialize an array to store the correct answers
    int correct = 0;  //initialize a variable to keep track of the number of correct answers
    int i; //initialize a variable to iterate through the loop
    printf("Welcome to the Math Exercise!\n\n");
    for(i=0; i<10; i++) {
        int num_one = rand() % 10 + 1; //generate a random number between 1 and 10 inclusive
        int num_two = rand() % 10 + 1;
        int operator_choice = rand() % 4; //generate a random number between 0 and 3 to select operator
        char operator;  //initialize a char to hold operator symbol
        int answer;  //initialize a variable to hold user's answer
        switch(operator_choice) { //check the value of operator_choice and assign the respective operation
            case 0:
                operator = '+';
                answers[i] = num_one + num_two; //calculate the correct answer
                break;
            case 1:
                operator = '-';
                answers[i] = num_one - num_two;
                break;
            case 2:
                operator = '*';
                answers[i] = num_one * num_two;
                break;
            case 3:
                operator = '/';
                answers[i] = num_one / num_two;
                break;
            default:
                printf("Error: Invalid operator.\n");
                return 1;
        }

        printf("Question %d: What is %d %c %d?\n", i+1, num_one, operator, num_two);
        scanf("%d", &answer);  //get user's answer
        if(answer == answers[i]) { //check if the answer is correct
            printf("Correct!\n\n");
            correct++; //increment the correct count
        }
        else {
            printf("Incorrect. The correct answer is %d\n\n", answers[i]);
        }   
    }
    printf("You got %d out of 10 correct. Thanks for playing!\n\n", correct); //display the final score
    return 0;
}