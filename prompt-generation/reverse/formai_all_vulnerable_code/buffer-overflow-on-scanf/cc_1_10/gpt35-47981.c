//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

char message[MAX_SIZE];
int num_threads;

void *reverse_message(void *thread_id) {
    int id = *(int*)thread_id;
    int start_index = id * (strlen(message) / num_threads);
    int end_index = (id + 1) * (strlen(message) / num_threads) - 1;
    if (id == num_threads - 1) {
        end_index = strlen(message) - 1;
    }
    for (int i = start_index, j = end_index; i < j; ++i, --j) {
        char temp = message[i];
        message[i] = message[j];
        message[j] = temp;
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter a message to reverse: ");
    fgets(message, MAX_SIZE, stdin);
    // Remove new line character from message
    message[strcspn(message, "\n")] = '\0';
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);
    pthread_t threads[num_threads];
    int thread_ids[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        thread_ids[i] = i;
        int ret = pthread_create(&threads[i], NULL, reverse_message, &thread_ids[i]);
        if (ret) {
            printf("Error: pthread_create() failed with error code %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < num_threads; ++i) {
        int ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: pthread_join() failed with error code %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }
    printf("Reversed message: %s\n", message);
    return 0;
}