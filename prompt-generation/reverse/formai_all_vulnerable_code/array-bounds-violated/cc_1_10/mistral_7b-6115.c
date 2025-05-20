//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_CHAR 255

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    char answer;
} Question;

void generate_questions(Question *qbank, int num_questions);
int check_answer(Question q, char user_answer);

int main() {
    Question qbank[MAX_QUESTIONS];
    int num_questions, num_correct = 0;
    int i, q_num, user_answer;

    srand(time(NULL));

    generate_questions(qbank, MAX_QUESTIONS);

    printf("Welcome to the Online Quiz!\n");
    printf("Answer the following questions within the given time limit.\n");
    printf("You will be given 10 seconds to answer each question.\n");
    printf("Press 'q' to quit at any time.\n\n");

    num_questions = rand() % MAX_QUESTIONS + 1;

    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\n", i + 1, qbank[i].question);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("\n%d. %s", j + 1, qbank[i].options[j]);
        }

        scanf("%d", &user_answer);

        if (user_answer < 1 || user_answer > MAX_OPTIONS) {
            printf("Invalid option! Please try again.\n");
            i--;
            continue;
        }

        if (check_answer(qbank[i], (char)(user_answer - 1))) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", qbank[i].options[qbank[i].answer - 1]);
        }

        sleep(10);

        printf("\nPress Enter to move on to the next question.\n");
        getchar();
    }

    printf("\nQuiz Complete!\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, num_questions);

    return 0;
}

void generate_questions(Question *qbank, int num_questions) {
    int i;

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        fgets(qbank[i].question, MAX_CHAR, stdin);
        qbank[i].question[strlen(qbank[i].question) - 1] = '\0';

        printf("Enter options for question %d (separated by commas): ", i + 1);
        char options_str[MAX_CHAR];
        fgets(options_str, MAX_CHAR, stdin);
        options_str[strlen(options_str) - 1] = '\0';

        char *token = strtok(options_str, ", ");
        int j = 0;

        while (token != NULL) {
            strcpy(qbank[i].options[j], token);
            token = strtok(NULL, ", ");
            j++;
        }

        qbank[i].answer = rand() % MAX_OPTIONS + 1;
    }
}

int check_answer(Question q, char user_answer) {
    return q.answer == (user_answer - 'A' + 1);
}