#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define BUFFER_SIZE 4096
#define NUM_THREADS 10

typedef struct {
    char element[3];
    char question[100];
    char answer[3];
} Question;

Question questions[100];
int question_count = 0;

void *read_csv(void *arg) {
    FILE *file = fopen("periodic_table.txt", "r");
    char buffer[BUFFER_SIZE];
    char *token;

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return NULL;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        token = strtok(buffer, ",");
        strncpy(questions[question_count].element, token, 3);
        token = strtok(NULL, ",");
        strncpy(questions[question_count].question, token, sizeof(questions[question_count].question) - 1);
        token = strtok(NULL, "\n");
        strncpy(questions[question_count].answer, token, 3);
        question_count++;
    }

    fclose(file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, read_csv, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Quiz logic goes here

    return 0;
}
