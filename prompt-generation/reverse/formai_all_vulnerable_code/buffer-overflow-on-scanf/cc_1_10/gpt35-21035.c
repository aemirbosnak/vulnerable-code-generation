//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int question_count = 10; // Number of questions in the exam
    int correct_answers = 0; // Number of correct answers
    srand(time(0)); // Seed for random number generator
    
    // Welcome message
    printf("Welcome to the C Online Examination System!\n");
    printf("Please answer (a), (b), (c), or (d) for each question.\n\n");
    
    // Loop through each question
    for(int i = 1; i <= question_count; i++) {
        int num1 = rand() % 10 + 1; // Random number 1
        int num2 = rand() % 10 + 1; // Random number 2
        int answer = num1 + num2; // Correct answer
        
        printf("Question %d: What is %d + %d?\n", i, num1, num2);
        printf("(a) %d\n(b) %d\n(c) %d\n(d) %d\n", answer-1, answer, answer+1, answer+2);
        
        char choice;
        scanf(" %c", &choice); // Get user choice
        
        switch(choice) {
            case 'a':
                printf("Incorrect! The correct answer is %d.\n\n", answer);
                break;
            case 'b':
                printf("Correct! Great job!\n\n");
                correct_answers++;
                break;
            case 'c':
                printf("Incorrect! The correct answer is %d.\n\n", answer);
                break;
            case 'd':
                printf("Incorrect! The correct answer is %d.\n\n", answer);
                break;
            default:
                printf("Invalid choice. Skipping question.\n\n");
                break;
        }
    }
    
    // Display results
    printf("Exam complete! You answered %d out of %d questions correctly.\n", correct_answers, question_count);
    printf("Please take a screenshot of this page and email it to your instructor to receive your grade.\n");
    
    return 0;
}