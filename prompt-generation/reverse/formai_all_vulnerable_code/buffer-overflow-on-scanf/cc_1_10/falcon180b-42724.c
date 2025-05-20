//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_QUESTIONS 50

struct question {
    char *text;
    int difficulty;
    int answer;
};

struct quiz {
    struct question questions[MAX_QUESTIONS];
    int num_questions;
};

void *thread_main(void *arg) {
    struct quiz *quiz = (struct quiz *) arg;
    int score = 0;
    int i;

    for (i = 0; i < quiz->num_questions; i++) {
        printf("Question %d: %s\n", i+1, quiz->questions[i].text);
        int answer = scanf("%d", &quiz->questions[i].answer);

        if (answer == 1 && quiz->questions[i].answer == 1) {
            score++;
        }
    }

    printf("Your score is %d out of %d\n", score, quiz->num_questions);

    pthread_exit(0);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];

    struct quiz quiz;
    quiz.num_questions = 0;

    // Add questions to the quiz
    struct question question1 = {"What is the capital of France? ", 1, 1};
    struct question question2 = {"What is the tallest mountain in the world? ", 2, 2};
    struct question question3 = {"What is the smallest country in the world? ", 3, 3};

    quiz.questions[quiz.num_questions++] = question1;
    quiz.questions[quiz.num_questions++] = question2;
    quiz.questions[quiz.num_questions++] = question3;

    // Create threads for each question
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_main, &quiz);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}