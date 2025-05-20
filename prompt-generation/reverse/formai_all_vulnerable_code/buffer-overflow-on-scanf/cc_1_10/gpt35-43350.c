//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_NAME_LENGTH 30

// Represents a single question
struct Question {
    char prompt[100]; // The question prompt
    char options[MAX_ANSWERS][50]; // The answer options
    int correct_answer; // The index of the correct answer in options
};

// Represents an exam
struct Exam {
    char name[MAX_NAME_LENGTH]; // The name of the exam
    struct Question questions[MAX_QUESTIONS]; // The array of questions
    int num_questions; // The number of questions in the exam
};

// Prompt the user for an answer to a question
int choose_answer() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Print a question to the console
void print_question(struct Question q) {
    printf("%s\n", q.prompt);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

// Add a question to an exam
void add_question(struct Exam* e) {
    struct Question q;
    printf("Enter the question prompt: ");
    scanf("%s", q.prompt);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("Enter answer %d: ", i+1);
        scanf("%s", q.options[i]);
    }
    printf("Enter the index of the correct answer: ");
    scanf("%d", &q.correct_answer);

    e->questions[e->num_questions++] = q;
}

// Take an exam and compute the score
int take_exam(struct Exam e) {
    int score = 0;
    for (int i = 0; i < e.num_questions; i++) {
        printf("Question %d:\n", i+1);
        print_question(e.questions[i]);
        int choice = choose_answer();
        if (choice == e.questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %d\n", e.questions[i].correct_answer+1);
        }
    }
    return score;
}

int main() {
    int choice;
    struct Exam e;
    memset(&e, 0, sizeof(struct Exam)); // Clear the exam array

    printf("Welcome to the Online Examination System\n");
    printf("Please enter the name of the exam: ");
    scanf("%s", e.name);

    do {
        // Display menu
        printf("\nChoose an option:\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. Exit\n");

        // Get user choice
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                if (e.num_questions < MAX_QUESTIONS) {
                    add_question(&e);
                } else {
                    printf("Maximum number of questions reached.\n");
                }
                break;
            case 2:
                if (e.num_questions > 0) {
                    int score = take_exam(e);
                    printf("Your score is %d out of %d\n", score, e.num_questions);
                } else {
                    printf("No questions added yet. Please add questions first.\n");
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}