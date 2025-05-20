//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ELEMENTS 10
#define MAX_QUESTIONS 3

typedef struct {
    char element[20];
    char symbol[3];
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H"},
    {"Helium", "He"},
    {"Lithium", "Li"},
    {"Beryllium", "Be"},
    {"Boron", "B"},
    {"Carbon", "C"},
    {"Nitrogen", "N"},
    {"Oxygen", "O"},
    {"Fluorine", "F"},
    {"Neon", "Ne"}
};

pthread_mutex_t quiz_mutex;

void *ask_question(void *arg) {
    int question_number = *((int *)arg);
    char answer[3];

    // Ask a question
    printf("Question %d: What is the chemical symbol for %s?\n", question_number + 1, periodicTable[question_number].element);
    scanf("%s", answer);

    // Lock mutex to print feedback
    pthread_mutex_lock(&quiz_mutex);
    if(strcmp(answer, periodicTable[question_number].symbol) == 0) {
        printf("Correct! %s is represented by '%s'.\n", periodicTable[question_number].element, periodicTable[question_number].symbol);
    } else {
        printf("Incorrect! %s is represented by '%s', not '%s'.\n", periodicTable[question_number].element, periodicTable[question_number].symbol, answer);
    }
    pthread_mutex_unlock(&quiz_mutex);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_QUESTIONS];
    int question_numbers[MAX_QUESTIONS];
    pthread_mutex_init(&quiz_mutex, NULL);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d random questions about chemical elements.\n", MAX_QUESTIONS);
    
    // Generate and ask questions for the first MAX_QUESTIONS elements
    for(int i = 0; i < MAX_QUESTIONS; i++) {
        question_numbers[i] = rand() % MAX_ELEMENTS;

        // Create a thread for each question
        if(pthread_create(&threads[i], NULL, ask_question, (void *)&question_numbers[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }

        // Sleep briefly to allow for all threads to be created
        usleep(100000); // 100 milliseconds
    }

    // Wait for all threads to finish
    for(int i = 0; i < MAX_QUESTIONS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&quiz_mutex);
    printf("Thank you for playing the Periodic Table Quiz!\n");
    
    return 0;
}