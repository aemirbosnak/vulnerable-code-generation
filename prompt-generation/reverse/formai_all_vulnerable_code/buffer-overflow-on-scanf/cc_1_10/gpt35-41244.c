//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int question_id;
    char question[100];
    char options[4][50];
    int correct_answer;
} question;

void add_question();
void display_questions();
void attempt_quiz();

int main() {
    int choice;
    do {
        printf("\n*** ONLINE EXAMINATION SYSTEM ***\n");
        printf("1. Add a question\n");
        printf("2. Display all questions\n");
        printf("3. Attempt quiz\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                display_questions();
                break;
            case 3:
                attempt_quiz();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

question all_questions[50];
int num_questions = 0;

void add_question() {
    printf("\n*** ADD A QUESTION ***\n");
    question q;
    q.question_id = num_questions + 1;
    printf("Enter the question: ");
    scanf(" %[^\n]s", q.question);
    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        scanf(" %[^\n]s", q.options[i]);
    }
    printf("Enter the correct answer (1-4): ");
    scanf("%d", &q.correct_answer);
    all_questions[num_questions++] = q;
    printf("Question added successfully!\n");
}

void display_questions() {
    printf("\n*** ALL QUESTIONS ***\n");
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", all_questions[i].question_id, all_questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, all_questions[i].options[j]);
        }
        printf("\n");
    }
}

void attempt_quiz() {
    printf("\n*** ATTEMPT QUIZ ***\n");
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", all_questions[i].question_id, all_questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, all_questions[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == all_questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\n");
        }
    }
    printf("Your score is %d out of %d.\n", score, num_questions);
}