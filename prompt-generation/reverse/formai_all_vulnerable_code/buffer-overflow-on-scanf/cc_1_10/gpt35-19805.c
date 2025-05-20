//FormAI DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to display welcome message
void welcomeMsg() {
    printf("Welcome to the C Online Examination System!\n");
}

//Function to display questions and accept input
void askQuestion(char* question, char* answer) {
    char userInput[50];

    printf("\n%s\n", question);
    scanf("%s", userInput);

    //Check the input against the correct answer
    if(strcmp(userInput, answer) == 0) {
        printf("Correct Answer!\n");
    } else {
        printf("Wrong Answer!\n");
    }
}

int main() {
    char* q1 = "What is the output of the following code:\n int i = 5; printf(\"%d\", i++);\n";
    char* a1 = "5";

    char* q2 = "What is the keyword used to exit a loop prematurely?\n";
    char* a2 = "break";

    char* q3 = "What is the keyword used to skip to the next iteration of a loop?\n";
    char* a3 = "continue";

    char* q4 = "What is the output of the following code:\n int x = 5; int y = 3; printf(\"%d\", x / y);\n";
    char* a4 = "1";

    char* q5 = "What is the keyword used to declare a function?\n";
    char* a5 = "int";

    int score = 0; //Initialize user's score

    welcomeMsg();

    askQuestion(q1, a1); //Question 1
    score++;

    askQuestion(q2, a2); //Question 2
    score++;

    askQuestion(q3, a3); //Question 3
    score++;

    askQuestion(q4, a4); //Question 4
    score++;

    askQuestion(q5, a5); //Question 5
    score++;

    printf("\nYou scored %d out of 5!\n", score);

    return 0; //End of program
}