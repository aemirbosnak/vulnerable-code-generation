//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100
#define MAX_USER_LENGTH 20

struct Question {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWER_LENGTH];
    int score;
};

void load_questions(struct Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %d", questions[i].question, questions[i].answer, &questions[i].score)!= EOF) {
        i++;
    }

    fclose(fp);
}

void shuffle_questions(struct Question questions[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = rand() % n;
        struct Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    char username[MAX_USER_LENGTH];
    printf("Enter your name: ");
    scanf("%s", username);

    struct Question questions[MAX_QUESTIONS];
    load_questions(questions);
    shuffle_questions(questions, MAX_QUESTIONS);

    int score = 0;
    int num_questions = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            score += questions[i].score;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }

        num_questions++;

        if (num_questions == 5) {
            printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS * 5);
            break;
        }
    }

    return 0;
}