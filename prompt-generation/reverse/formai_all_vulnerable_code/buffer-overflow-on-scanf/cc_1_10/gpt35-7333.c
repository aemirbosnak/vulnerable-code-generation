//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_LENGTH 50

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int correct_answer;
} Question;

void add_question(Question questions[], int *num_questions, int max_questions);
void start_test(Question questions[], int num_questions);

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    char choice;

    printf("*** Welcome to the Online Examination System ***\n\n");

    do {
        printf("\nMENU\n");
        printf("1. Add a question\n");
        printf("2. Start the test\n");
        printf("3. Exit\n");

        printf("\nEnter your choice (1-3): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_question(questions, &num_questions, MAX_QUESTIONS);
                break;
            case '2':
                if (num_questions > 0) {
                    start_test(questions, num_questions);
                } else {
                    printf("\nThere are no questions. Please add questions first.\n");
                }
                break;
            case '3':
                printf("\nThank you for using the Online Examination System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while(choice != '3');

    return 0;
}

void add_question(Question questions[], int *num_questions, int max_questions) {
    if (*num_questions >= max_questions) {
        printf("\nMaximum number of questions reached. Cannot add more questions.\n");
    } else {
        char temp[MAX_LENGTH];
        int correct_answer, i;

        printf("\nEnter the question: ");
        scanf(" %[^\n]s", questions[*num_questions].question);

        for (i = 0; i < MAX_OPTIONS; i++) {
            printf("Enter option %d: ", i+1);
            scanf(" %[^\n]s", questions[*num_questions].options[i]);
        }

        printf("Enter the correct answer (1-%d): ", MAX_OPTIONS);
        scanf(" %d", &correct_answer);

        if (correct_answer >= 1 && correct_answer <= MAX_OPTIONS) {
            questions[*num_questions].correct_answer = correct_answer;
            (*num_questions)++;
            printf("\nQuestion added successfully!\n");
        } else {
            printf("\nInvalid answer choice. Question not added.\n");
        }
    }
}

void start_test(Question questions[], int num_questions) {
    int i, answer, score = 0;

    printf("\n--- Starting the test with %d questions ---\n\n", num_questions);

    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("Options:\n");
        int j;
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer (1-%d): ", MAX_OPTIONS);
        scanf(" %d", &answer);

        if (answer == questions[i].correct_answer) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer!\n");
        }
    }

    printf("\n--- Test completed ---\n");
    printf("Your final score is %d/%d.\n", score, num_questions);
}