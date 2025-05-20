//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MATRIX_SIZE 10 // size of matrix
#define P_THRESHOLD 0.6 // threshold probability for percolation

int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0}; // Initialize matrix with all zeros
int count_threads = 0; // Track number of threads created
pthread_mutex_t mutex; // Mutex for thread synchronization

// Function to check if site percolates
int percolate(int i, int j) {
    if (i >= MATRIX_SIZE || i < 0 || j >= MATRIX_SIZE || j < 0) {
        return 0; // If index out of bounds, return 0
    }
    if (matrix[i][j] == 0) {
        return 0; // If site is blocked, return 0
    }
    if (i == MATRIX_SIZE - 1) {
        return 1; // If site is on bottom row (i.e., percolates), return 1
    }
    matrix[i][j] = 0; // Mark site as visited
    return percolate(i+1,j) || percolate(i-1,j) || percolate(i,j+1) || percolate(i,j-1); // Check adjacent sites
}

// Function to simulate percolation process
void *simulate_percolation(void *thread_num) {
    int t_num = *(int *)thread_num;
    srand(time(NULL) + t_num); // Use thread ID for random seed
    float probability = (float)rand() / (float)RAND_MAX; // Generate random probability
    for (int i = t_num; i < MATRIX_SIZE; i += count_threads) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if ((float)rand() / (float)RAND_MAX > P_THRESHOLD) {
                matrix[i][j] = 1; // Mark site as open if random probability is above threshold
            }
        }
    }
    pthread_mutex_lock(&mutex); // Lock mutex for thread synchronization
    count_threads--; // Decrease count of active threads
    pthread_mutex_unlock(&mutex); // Unlock mutex
    return NULL;
}

int main() {
    int n_threads = 4; // Number of threads to be created
    pthread_t threads[n_threads]; // Declare threads array
    int thread_nums[n_threads]; // Array to store thread IDs
    for (int i = 0; i < n_threads; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, simulate_percolation, (void *)&thread_nums[i]); // Create thread
    }
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }
    int percolates = 0;
    for (int j = 0; j < MATRIX_SIZE; j++) {
        if (percolate(0,j)) {
            percolates = 1; // If percolation is successful, exit loop
            break;
        }
    }
    if (percolates) {
        printf("Percolation successful!\n");
    } else {
        printf("Percolation unsuccessful.\n");
    }
    return 0;
}