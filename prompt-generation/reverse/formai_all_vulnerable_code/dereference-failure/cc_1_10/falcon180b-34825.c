//Falcon-180B DATASET v1.0 Category: Text processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg)
{
    char buffer[BUFFER_SIZE];
    FILE *file = (FILE *) arg;

    // Read from file into buffer
    fread(buffer, sizeof(char), BUFFER_SIZE, file);

    // Reverse the string
    char *ptr = buffer + strlen(buffer) - 1;
    while (ptr >= buffer) {
        *ptr-- = *(ptr + 1);
    }

    // Write the reversed string to file
    fseek(file, -strlen(buffer), SEEK_CUR);
    fwrite(buffer, sizeof(char), strlen(buffer), file);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r+");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w+");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) input_file);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}