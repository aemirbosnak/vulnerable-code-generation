//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initialize random seed
    
    char answers[] = {'A', 'B', 'C', 'D'};  // possible answers

    int num_questions = 10;  // number of questions

    int correct_answers = 0;  // initialize correct answers counter

    // loop through each question
    for (int i = 1; i <= num_questions; i++) {
        printf("Question %d:\n", i);  // print question number
        
        int correct_answer_index = rand() % 4;  // choose random correct answer index
        char correct_answer = answers[correct_answer_index];  // set correct answer letter
        
        // print answer choices
        printf("A) Choice A\nB) Choice B\nC) Choice C\nD) Choice D\n");
        
        char user_answer;  // initialize user answer variable
        
        // loop until valid input is entered
        while (1) {
            printf("Enter your answer (A, B, C, or D): ");
            scanf(" %c", &user_answer);  // scan user input
            
            // check if input is valid
            if (user_answer == 'A' || user_answer == 'B' || user_answer == 'C' || user_answer == 'D') {
                break;  // exit loop if input is valid
            } else {
                printf("Invalid input. Please enter A, B, C, or D.\n");
            }
        }
        
        // check if user answer is correct and increment counter accordingly
        if (user_answer == correct_answer) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", correct_answer);
        }
        
        printf("\n");  // add whitespace for readability
    }
    
    // print exam results
    printf("You answered %d out of %d questions correctly. Your score is %.2f%%.\n",
            correct_answers, num_questions, (float) correct_answers / num_questions * 100);
    
    return 0;
}