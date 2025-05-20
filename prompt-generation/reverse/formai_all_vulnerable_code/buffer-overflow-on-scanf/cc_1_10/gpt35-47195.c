//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 1

struct Question {
    char prompt[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWER_LENGTH];
};

bool validate_answer(char answer[], char correct_answer[]) {
    return strcmp(answer, correct_answer) == 0;
}

int main() {
    struct Question questions[MAX_QUESTIONS];
    int num_questions = 0;

    // Add first question
    printf("Enter question: ");
    fgets(questions[num_questions].prompt, 100, stdin);
    printf("Enter option 1: ");
    fgets(questions[num_questions].options[0], 100, stdin);
    printf("Enter option 2: ");
    fgets(questions[num_questions].options[1], 100, stdin);
    printf("Enter option 3: ");
    fgets(questions[num_questions].options[2], 100, stdin);
    printf("Enter option 4: ");
    fgets(questions[num_questions].options[3], 100, stdin);
    printf("Enter answer (1, 2, 3 or 4): ");
    fgets(questions[num_questions].answer, 2, stdin);
    num_questions++;

    // Add more questions
    char continue_input = 'y';
    while (continue_input == 'y') {
        printf("\nEnter another question? (y/n): ");
        scanf("%c", &continue_input);
        if (continue_input == 'n') {
            break;
        }

        printf("Enter question: ");
        getchar(); // consume newline character
        fgets(questions[num_questions].prompt, 100, stdin);
        printf("Enter option 1: ");
        fgets(questions[num_questions].options[0], 100, stdin);
        printf("Enter option 2: ");
        fgets(questions[num_questions].options[1], 100, stdin);
        printf("Enter option 3: ");
        fgets(questions[num_questions].options[2], 100, stdin);
        printf("Enter option 4: ");
        fgets(questions[num_questions].options[3], 100, stdin);
        printf("Enter answer (1, 2, 3 or 4): ");
        fgets(questions[num_questions].answer, 2, stdin);
        num_questions++;
    }

    // Print all questions and take exam
    int num_correct = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].prompt);
        printf("1. %s", questions[i].options[0]);
        printf("2. %s", questions[i].options[1]);
        printf("3. %s", questions[i].options[2]);
        printf("4. %s", questions[i].options[3]);

        char user_answer[MAX_ANSWER_LENGTH];
        printf("Enter your answer (1, 2, 3 or 4): ");
        fgets(user_answer, 2, stdin);

        if (validate_answer(user_answer, questions[i].answer)) {
            printf("You got it correct!\n");
            num_correct++;
        } else {
            printf("Sorry, that's incorrect.\n");
        }
    }

    printf("You got %d out of %d questions correct.\n", num_correct, num_questions);

    return 0;
}