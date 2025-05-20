//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correct_answer; // Store index of the correct option (0 to MAX_OPTIONS-1)
} Question;

void initialize_questions(Question *questions) {
    // Sample questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Berlin");
    strcpy(questions[0].options[1], "Madrid");
    strcpy(questions[0].options[2], "Paris");
    strcpy(questions[0].options[3], "Rome");
    questions[0].correct_answer = 2;

    strcpy(questions[1].question, "What is 2 + 2?");
    strcpy(questions[1].options[0], "3");
    strcpy(questions[1].options[1], "4");
    strcpy(questions[1].options[2], "5");
    strcpy(questions[1].options[3], "22");
    questions[1].correct_answer = 1;

    // Add more questions here
    // For simplification, we only implement two questions
}

void display_question(const Question *q, int question_number) {
    printf("Q%d: %s\n", question_number + 1, q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf(" %d. %s\n", i + 1, q->options[i]);
    }
}

int take_exam(Question *questions, int total_questions) {
    int score = 0;

    for (int i = 0; i < total_questions; i++) {
        display_question(&questions[i], i);

        int user_answer;
        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &user_answer);

        if (user_answer - 1 == questions[i].correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n\n", questions[i].options[questions[i].correct_answer]);
        }
    }
    return score;
}

void show_result(int score, int total_questions) {
    printf("Your score: %d out of %d\n", score, total_questions);
}

void start_exam() {
    Question questions[MAX_QUESTIONS];
    initialize_questions(questions);

    printf("Welcome to the Online Examination System!\n");
    printf("You will be asked %d questions.\n", MAX_QUESTIONS);
    
    int score = take_exam(questions, MAX_QUESTIONS);
    show_result(score, MAX_QUESTIONS);
}

int main() {
    int choice;

    while (1) {
        printf("1. Start Exam\n");
        printf("2. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_exam();
                break;
            case 2:
                printf("Thank you for using the Online Examination System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}