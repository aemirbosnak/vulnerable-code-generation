//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the number of questions
#define NUM_QUESTIONS 10

// Struct for each question
typedef struct question_t {
    char prompt[256];
    char answer;
} question;

// Function to take the exam
int take_exam(question* questions) {
    int score = 0;
    char answer;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s", questions[i].prompt);
        scanf(" %c", &answer);
        if (answer == questions[i].answer) {
            score++;
        }
    }
    return score;
}

int main() {
    // Declare and initialize the questions
    question questions[NUM_QUESTIONS] = {
        {"1 + 1 = ", 'B'},
        {"2 + 2 = ", 'C'},
        {"3 + 3 = ", 'D'},
        {"4 + 4 = ", 'A'},
        {"5 + 5 = ", 'E'},
        {"6 + 6 = ", 'B'},
        {"7 + 7 = ", 'C'},
        {"8 + 8 = ", 'D'},
        {"9 + 9 = ", 'A'},
        {"10 + 10 = ", 'E'},
    };
    
    // Take the exam
    int score = take_exam(questions);
    
    // Print the results
    printf("Your score on the exam is %d/%d.", score, NUM_QUESTIONS);
    if (score >= (NUM_QUESTIONS * 0.7)) {
        printf(" Congratulations, you passed the exam!");
    } else {
        printf(" You did not pass the exam. Please study and try again.");
    }
    
    return 0;
}