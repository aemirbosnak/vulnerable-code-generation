//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_THREADS 10

typedef struct {
    char question[100];
    char answers[MAX_ANSWERS][100];
    int correct_answer;
} Question;

void *askQuestion(void *arg) {
    char choice;
    int score = 0;
    Question *question = (Question *) arg;

    printf("Question %d: %s\n", question->correct_answer + 1, question->question);

    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i + 1, question->answers[i]);
    }

    printf("Enter your choice: ");
    scanf("%c", &choice);

    if (choice == (question->correct_answer + 'A')) {
        score++;
    }

    pthread_exit(0);
}

int main() {
    int num_questions = 0;
    Question questions[MAX_QUESTIONS];
    pthread_t threads[MAX_THREADS];

    FILE *fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %d", questions[num_questions].question, questions[num_questions].answers[0], questions[num_questions].answers[1], &questions[num_questions].correct_answer)!= EOF) {
        num_questions++;
    }

    fclose(fp);

    int num_threads = 0;

    for (int i = 0; i < num_questions; i++) {
        pthread_create(&threads[num_threads], NULL, askQuestion, &questions[i]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Your score is: %d out of %d.\n", num_questions - num_threads, num_questions);

    return 0;
}