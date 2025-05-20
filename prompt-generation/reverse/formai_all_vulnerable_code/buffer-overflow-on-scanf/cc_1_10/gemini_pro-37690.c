//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the array we want to search
int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
int size = sizeof(arr) / sizeof(arr[0]);

// Define the search key
int key;

// Define the thread data structure
typedef struct {
    int start;
    int end;
    int result;
} thread_data;

// Define the thread function
void *search_thread(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *) arg;

    // Search the array for the key
    for (int i = data->start; i <= data->end; i++) {
        if (arr[i] == key) {
            data->result = i;
            return NULL;  // Found the key, so return immediately
        }
    }

    // Key not found in this thread's range
    data->result = -1;
    return NULL;
}

int main() {
    // Get the search key from the user
    printf("Enter the search key: ");
    scanf("%d", &key);

    // Create the thread pool
    pthread_t threads[4];

    // Divide the array into four equal parts and create a thread for each part
    int part_size = size / 4;
    for (int i = 0; i < 4; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->start = i * part_size;
        data->end = (i + 1) * part_size - 1;
        data->result = -1;
        pthread_create(&threads[i], NULL, search_thread, data);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check if the key was found by any thread
    int found = 0;
    for (int i = 0; i < 4; i++) {
        thread_data *data = (thread_data *) threads[i];
        if (data->result != -1) {
            printf("Key found at index %d\n", data->result);
            found = 1;
            break;
        }
    }

    // If the key was not found, print a message
    if (!found) {
        printf("Key not found\n");
    }

    return 0;
}