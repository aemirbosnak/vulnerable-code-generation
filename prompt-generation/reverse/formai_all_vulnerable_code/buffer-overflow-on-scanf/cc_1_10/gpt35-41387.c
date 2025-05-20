//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INPUT_LENGTH 100 // Maximum input length
#define MAX_THREADS 10 // Maximum number of threads
#define MIN_THREADS 2 // Minimum number of threads
#define RANDOM_INPUT_SIZE 10 // Size of randomly generated input

pthread_mutex_t input_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for input
pthread_mutex_t output_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for output

char input[MAX_INPUT_LENGTH]; // Input buffer
char output[MAX_INPUT_LENGTH]; // Output buffer

int num_threads = 2; // Number of threads
pthread_t threads[MAX_THREADS]; // Array of thread ids

/* Input sanitizer function */
void sanitize_input(char* input, char* output, int size)
{
    int i, j = 0;
    for(i = 0; i < size; i++) {
        if(input[i] >= 'a' && input[i] <= 'z')
            output[j++] = input[i];
        else if(input[i] >= 'A' && input[i] <= 'Z')
            output[j++] = input[i] + ('a' - 'A');
    }
    output[j] = '\0';
}

/* Input randomizer function */
void randomize_input(char* input, int size)
{
    int i;
    for(i = 0; i < size; i++)
        input[i] = rand() % 26 + 'a';
    input[size] = '\0';
}

/* Thread function */
void* thread_func(void* arg)
{
    long tid = (long)arg;
    char my_input[MAX_INPUT_LENGTH]; // Local input buffer
    char my_output[MAX_INPUT_LENGTH]; // Local output buffer
    
    /* Randomize input */
    pthread_mutex_lock(&input_mutex);
    randomize_input(input, RANDOM_INPUT_SIZE);
    strncpy(my_input, input, MAX_INPUT_LENGTH);
    pthread_mutex_unlock(&input_mutex);
    
    /* Sanitize input */
    sanitize_input(my_input, my_output, strlen(my_input));
    
    /* Print output */
    pthread_mutex_lock(&output_mutex);
    printf("Thread %ld output: %s\n", tid, my_output);
    strncpy(output, my_output, MAX_INPUT_LENGTH);
    pthread_mutex_unlock(&output_mutex);
    
    pthread_exit(NULL);
}

int main()
{
    int i;
    
    /* Get number of threads from user */
    do {
        printf("Enter number of threads (minimum %d, maximum %d): ", MIN_THREADS, MAX_THREADS);
        scanf("%d", &num_threads);
    } while(num_threads < MIN_THREADS || num_threads > MAX_THREADS);
    
    /* Create threads */
    for(i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)(long)i);
    }
    
    /* Wait for threads to finish */
    for(i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    /* Print final output */
    printf("Final output: %s\n", output);
    
    return 0;
}