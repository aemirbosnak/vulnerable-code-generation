//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
// C Periodic Table Quiz Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ELEMENTS 118 // Maximum number of elements in the periodic table
#define MAX_THREADS 10 // Maximum number of threads

// Function prototypes
void *thread_main(void *arg);
void print_periodic_table();
void print_element_info(int index);

int main() {
    int num_threads = 1;
    int thread_ids[MAX_THREADS];
    pthread_t threads[MAX_THREADS];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many threads would you like to create? (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_main, (void *)NULL);
        thread_ids[i] = i;
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_main(void *arg) {
    char input[100];
    int index, num_correct = 0;

    printf("Thread %d started\n", (int)arg);

    // Ask questions
    while (1) {
        printf("Enter the atomic number of an element: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        index = atoi(input);
        if (index >= 1 && index <= MAX_ELEMENTS) {
            print_element_info(index);
            num_correct++;
        } else {
            printf("Invalid atomic number\n");
        }
    }

    printf("Thread %d finished with %d correct answers\n", (int)arg, num_correct);

    return NULL;
}

void print_periodic_table() {
    printf("\n");
    for (int i = 1; i <= MAX_ELEMENTS; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_element_info(int index) {
    if (index > MAX_ELEMENTS || index < 1) {
        printf("Invalid atomic number\n");
        return;
    }

    printf("Element %d: ", index);
    switch (index) {
        case 1:
            printf("Hydrogen\n");
            break;
        case 6:
            printf("Carbon\n");
            break;
        case 7:
            printf("Nitrogen\n");
            break;
        case 8:
            printf("Oxygen\n");
            break;
        case 79:
            printf("Gold\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}