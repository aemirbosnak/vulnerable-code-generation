//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_THREADS 5
#define THREAD_STACK_SIZE 1024 * 10

int scores[NUM_THREADS];

struct question {
    char *text;
    char *answer;
    int difficulty;
};

struct question questions[NUM_QUESTIONS] = {
    {"What is the capital of France? ", "Paris", 1},
    {"Who wrote 'To Kill a Mockingbird'? ", "Harper Lee", 2},
    {"What is the tallest mountain in the world? ", "Mount Everest", 3},
    {"What is the smallest country in the world? ", "Vatican City", 2},
    {"Who directed the movie 'Jaws'? ", "Steven Spielberg", 2},
    {"What is the largest ocean in the world? ", "Pacific Ocean", 1},
    {"What is the currency of Japan? ", "Yen", 2},
    {"What is the longest river in the world? ", "Nile", 3},
    {"Who painted the Mona Lisa? ", "Leonardo da Vinci", 3},
    {"What is the highest grossing movie of all time? ", "Avatar", 2}
};

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    int correct_answers = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Thread %d, question %d: %s\n", thread_id, i + 1, questions[i].text);
        char answer[100];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correct_answers++;
        }
    }

    scores[thread_id] = correct_answers;
    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scores:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d score: %d\n", i + 1, scores[i]);
    }

    return 0;
}