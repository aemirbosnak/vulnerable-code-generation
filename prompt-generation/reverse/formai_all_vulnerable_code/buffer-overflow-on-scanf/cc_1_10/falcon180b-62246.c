//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 50

struct question {
    char question_text[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int correct_answer;
};

void generate_question(struct question *question) {
    char *options[MAX_OPTIONS];
    int num_options = rand() % 4 + 1;
    int correct_answer_index = rand() % num_options;

    strcpy(question->question_text, "What is the capital of France? ");
    strcpy(options[0], "Paris");
    strcpy(options[1], "Berlin");
    strcpy(options[2], "London");
    strcpy(options[3], "Madrid");

    question->correct_answer = correct_answer_index;
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    struct question questions[num_questions];

    for (int i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
    }

    int num_correct_answers = 0;

    for (int i = 0; i < num_questions; i++) {
        int user_answer_index;
        printf("Question %d: %s\n", i + 1, questions[i].question_text);
        for (int j = 0; j < questions[i].correct_answer + 1; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        scanf("%d", &user_answer_index);

        if (user_answer_index == questions[i].correct_answer) {
            num_correct_answers++;
        }
    }

    printf("You got %d out of %d questions correct.\n", num_correct_answers, num_questions);

    return 0;
}