//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define NUM_THREADS 3

void *inputThread(void *arg);
void *quizThread(void *arg);
void *scoreThread(void *arg);

int main(void) {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Create input thread
    rc = pthread_create(&threads[0], NULL, inputThread, NULL);
    if (rc) {
        fprintf(stderr, "Error creating input thread: %d\n", rc);
        exit(-1);
    }

    // Create quiz thread
    rc = pthread_create(&threads[1], NULL, quizThread, NULL);
    if (rc) {
        fprintf(stderr, "Error creating quiz thread: %d\n", rc);
        exit(-1);
    }

    // Create score thread
    rc = pthread_create(&threads[2], NULL, scoreThread, NULL);
    if (rc) {
        fprintf(stderr, "Error creating score thread: %d\n", rc);
        exit(-1);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error joining thread %d: %d\n", i, rc);
            exit(-1);
        }
    }

    return 0;
}

void *inputThread(void *arg) {
    char input[10];

    printf("What is your name?: ");
    fgets(input, 10, stdin);

    return NULL;
}

void *quizThread(void *arg) {
    int score = 0;
    int answer;

    printf("Welcome to the periodic table quiz!\n");
    printf("What is the atomic number for helium?: ");
    scanf("%d", &answer);

    if (answer == 2) {
        score++;
    }

    printf("What is the symbol for sodium?: ");
    scanf("%d", &answer);

    if (answer == 11) {
        score++;
    }

    printf("What is the most abundant element in the universe?: ");
    scanf("%d", &answer);

    if (answer == 1) {
        score++;
    }

    return (void *) score;
}

void *scoreThread(void *arg) {
    bool answered = false;

    while (!answered) {
        int score = 0;
        void *ret;

        pthread_join(quizThread, &ret);
        score = (int) ret;

        printf("Your score is %d\n", score);

        if (score == 3) {
            printf("Congratulations! You got a perfect score!\n");
        } else {
            printf("Better luck next time!\n");
        }

        answered = true;
    }

    return NULL;
}