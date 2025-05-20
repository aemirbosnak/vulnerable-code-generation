//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_CHAR 255

typedef struct {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    char answer;
} Question;

Question quiz[MAX_QUESTIONS];
int num_questions = 0;

void showQuestion() {
    int i;
    printf("\n%s\n", quiz[num_questions].question);
    for (i = 0; i < 5; i++) {
        printf("\n%d. %s", i + 1, quiz[num_questions].options[i]);
    }
}

void getAnswer() {
    int choice, i;
    printf("\nEnter your answer (1-5): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        i = choice - 1;
        if (quiz[num_questions].answer == quiz[num_questions].options[i][0]) {
            printf("\nCorrect answer!\n");
        } else {
            printf("\nIncorrect answer. The correct answer is: %c\n", quiz[num_questions].answer);
        }
        num_questions++;
    } else {
        printf("\nInvalid choice! Please try again.\n");
        getAnswer();
    }
}

void createQuestion() {
    int i;
    printf("\nEnter a question: ");
    scanf("%s", quiz[num_questions].question);

    printf("\nEnter options (5 lines, press Ctrl+D after the last option):\n");
    for (i = 0; i < 5; i++) {
        scanf("%s", quiz[num_questions].options[i]);
    }

    printf("\nEnter the answer (A for option 1, B for option 2, etc.): ");
    scanf(" %c", &quiz[num_questions].answer);

    num_questions++;
}

void startQuiz() {
    int i;
    printf("\nWelcome to the Online Examination System!\n");
    printf("\nTotal number of questions: %d\n", num_questions);

    if (num_questions <= 0) {
        printf("\nPlease create some questions first.\n");
        return;
    }

    for (i = 0; i < num_questions; i++) {
        showQuestion();
        getAnswer();
    }

    printf("\nQuiz completed! Congratulations.\n");
}

int main() {
    int choice;

    printf("\nOnline Examination System\n");
    printf("\n1. Start Quiz\n2. Create Question\n3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            startQuiz();
            break;
        case 2:
            createQuestion();
            break;
        case 3:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
            main();
    }

    return 0;
}