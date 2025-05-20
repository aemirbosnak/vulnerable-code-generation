//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
// Bucket Sort Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_RAND 100

// Structure for holding the data
typedef struct {
    int value;
    int index;
} Data;

// Function to generate random numbers
int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate random data
Data* generateData(int size) {
    Data* data = malloc(size * sizeof(Data));
    for (int i = 0; i < size; i++) {
        data[i].value = randInt(0, MAX_RAND);
        data[i].index = i;
    }
    return data;
}

// Function to sort the data using bucket sort
void bucketSort(Data* data, int size) {
    int buckets[MAX_RAND];
    memset(buckets, 0, sizeof(buckets));

    // Count the number of elements in each bucket
    for (int i = 0; i < size; i++) {
        buckets[data[i].value]++;
    }

    // Sort the data using bucket sort
    int j = 0;
    for (int i = 0; i < MAX_RAND; i++) {
        while (buckets[i] > 0) {
            data[j++].value = i;
            buckets[i]--;
        }
    }
}

// Function to print the sorted data
void printData(Data* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Generate random data
    Data* data = generateData(MAX_SIZE);

    // Sort the data using bucket sort
    bucketSort(data, MAX_SIZE);

    // Print the sorted data
    printData(data, MAX_SIZE);

    return 0;
}