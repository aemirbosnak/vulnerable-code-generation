//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int correct_answers = 0;
int wrong_answers = 0;
char name[25];

// Function to generate random numbers
int rand_num(int n) {
    srand(time(NULL));
    return rand() % n;
}

// Function to print questions and collect answers
void ask_question(char question[], char answer[]) {
    char input[50];
    printf("%s ", question);
    scanf("%s", &input);
    if (strcmp(input, answer) == 0) {
        printf("Correct! Great job, %s\n", name);
        correct_answers++;
    } else {
        printf("Wrong answer! The correct answer is %s\n", answer);
        wrong_answers++;
    }
}

// Main function
int main() {
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", &name);

    printf("Let's start the exam!\n\n");

    // Question 1
    char q1[] = "Which of the following is not a programming language?\n";
    char a1[] = "Google";
    ask_question(q1, a1);

    // Question 2
    char q2[] = "What does GCC stand for?\n";
    char a2[] = "GNU Compiler Collection";
    ask_question(q2, a2);

    // Question 3
    char q3[] = "What is the size of an int data type in C?\n";
    char a3[] = "4 bytes";
    ask_question(q3, a3);

    // Question 4
    char q4[] = "Which operator is used to access a structure member?\n";
    char a4[] = "->";
    ask_question(q4, a4);

    // Question 5
    char q5[] = "What is the extension of a C source code file?\n";
    char a5[] = ".c";
    ask_question(q5, a5);

    // Print results
    printf("\n\nThank you for taking the exam, %s!\n", name);
    printf("\nHere are your results:\n");
    printf("Correct answers: %d\n", correct_answers);
    printf("Wrong answers: %d\n", wrong_answers);

    return 0;
}