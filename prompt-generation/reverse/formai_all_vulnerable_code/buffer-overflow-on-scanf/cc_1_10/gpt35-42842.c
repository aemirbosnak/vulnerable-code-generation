//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of questions in the exam
#define MAX_NUM_QUESTIONS 20

typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Function to display the exam questions and options
void displayExam(Question* questions, int num_questions) {
    printf("\n");
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c) %s\n", 'A'+j, questions[i].options[j]);
        }
        printf("\n");
    }
}

// Function to get the user's answers to the exam questions
void getAnswers(Question* questions, int num_questions, int* answers) {
    printf("\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer to question %d: ", i+1);
        char answer[2];
        scanf("%s", answer);
        answers[i] = answer[0] - 'A';
    }
}

// Function to grade the exam and display the score
void gradeExam(Question* questions, int num_questions, int* answers) {
    int correct = 0;
    for (int i = 0; i < num_questions; i++) {
        if (answers[i] == questions[i].correct_option) {
            correct++;
        }
    }
    printf("\nYou scored %d out of %d.\n", correct, num_questions);
}

int main() {
    // Example questions for the exam
    Question questions[MAX_NUM_QUESTIONS] = {
        {"What is the capital of France?", {"London", "Paris", "Berlin", "Madrid"}, 1},
        {"What is the largest planet in our solar system?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
        {"What is the boiling point of water in degrees Celsius?", {"0", "32", "100", "212"}, 2},
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Hg", "Pt"}, 0},
        {"What is the highest mountain in the world?", {"Mount Everest", "Mount Kilimanjaro", "Mount Fuji", "Mount Rainier"}, 0}
    };
    int num_questions = 5;

    // Display the exam questions and options
    displayExam(questions, num_questions);

    // Get the user's answers to the exam questions
    int answers[MAX_NUM_QUESTIONS];
    getAnswers(questions, num_questions, answers);

    // Grade the exam and display the score
    gradeExam(questions, num_questions, answers);

    return 0;
}