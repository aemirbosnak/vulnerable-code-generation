//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int search_value;
bool search_result;

// Function to search for a value in the array
void* search(void* arg) {
    int start = *(int*) arg;
    int end = start + MAX_SIZE/4;

    // Searching for the value in the given range
    for(int i=start; i<end; i++) {
        if(arr[i] == search_value) {
            search_result = true;
            break;
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t thread[4];
    int thread_args[4];

    // Initializing the array
    for(int i=0; i<MAX_SIZE; i++) {
        arr[i] = i;
    }

    // Accepting the value to be searched
    printf("Enter the value to be searched: ");
    scanf("%d", &search_value);

    // Creating threads
    for(int i=0; i<4; i++) {
        thread_args[i] = i*MAX_SIZE/4;
        pthread_create(&thread[i], NULL, search, &thread_args[i]);
    }

    // Joining threads
    for(int i=0; i<4; i++) {
        pthread_join(thread[i], NULL);
    }

    // Checking if value is present in the array or not
    if(search_result) {
        printf("%d is present in the array.\n", search_value);
    } else {
        printf("%d is not present in the array.\n", search_value);
    }
    
    return 0;
}