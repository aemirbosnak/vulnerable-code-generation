//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 16
#define MAX_ITEMS 10000
#define MAX_VALUE 10000

int thread_count;
int items_per_thread;
int n;
int *a;
int *count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Allocate memory for array and count
void initialize_arrays() {
    a = malloc(n * sizeof(int));
    count = malloc(n * sizeof(int));
}

// Generate random values for the array
void generate_values(int start, int end) {
    for (int i=start; i<end; i++) {
        a[i] = rand() % MAX_VALUE + 1;
    }
}

// Count the occurrences of each value
void count_values(int start, int end) {
    for (int i=start; i<end; i++) {
        count[a[i]]++;
    }
}

// Merge counts from all threads
void merge_counts() {
    for (int i=1; i<=MAX_VALUE; i++) {
        for (int j=0; j<thread_count; j++) {
            count[i] += count[i + j * MAX_VALUE];
        }
    }
}

// Sort the array using the bucket sort algorithm
void sort() {
    int *temp = malloc(n * sizeof(int));    // Temp array for sorted values
    int *start = malloc((MAX_VALUE + 1) * sizeof(int));   // Starting index of each bucket
    int *end = malloc((MAX_VALUE + 1) * sizeof(int));     // Ending index of each bucket
    
    // Initialize starting and ending indices
    for (int i=1; i<=MAX_VALUE; i++) {
        start[i] = end[i-1];
        end[i] = start[i] + count[i];
    }
    
    // Sort values into buckets
    for (int i=0; i<n; i++) {
        temp[end[a[i]]++] = a[i];
    }
    
    // Copy sorted values back into original array
    for (int i=0; i<n; i++) {
        a[i] = temp[i];
    }
    
    free(temp);
    free(start);
    free(end);
}

// Thread function for counting values
void *count_thread(void *rank) {
    long my_rank = (long) rank;
    int start = my_rank * items_per_thread;
    int end = start + items_per_thread;
    count_values(start, end);
    return NULL;
}

int main(int argc, char *argv[]) {
    long i;
    pthread_t *thread_handles;
    
    // Get user input for number of threads and items
    printf("Enter number of threads: ");
    scanf("%d", &thread_count);
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    // Allocate memory for arrays
    initialize_arrays();
    
    // Initialize random number generator and generate values for array
    srand(time(NULL));
    items_per_thread = n / thread_count;
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    for (i=0; i<thread_count; i++) {
        pthread_create(&thread_handles[i], NULL, count_thread, (void*) i);
    }
    for (i=0; i<thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }
    merge_counts();
    sort();
    
    // Print sorted array
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // Free memory
    free(a);
    free(count);
    free(thread_handles);
    return 0;
}