//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define BUCKET_COUNT 10

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Bucket {
    Node* head;
} Bucket;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize buckets
void initializeBuckets(Bucket** buckets, int count) {
    for (int i = 0; i < count; i++) {
        buckets[i] = (Bucket*)malloc(sizeof(Bucket));
        buckets[i]->head = NULL;
    }
}

// Function to insert a value into a bucket
void insertIntoBucket(Bucket* bucket, int value) {
    Node* newNode = createNode(value);
    if (bucket->head == NULL) {
        bucket->head = newNode;
    } else {
        Node* current = bucket->head;
        Node* previous = NULL;
        // Inserting in sorted order
        while (current != NULL && current->value < value) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) { // new head
            newNode->next = bucket->head;
            bucket->head = newNode;
        } else {
            newNode->next = current;
            previous->next = newNode;
        }
    }
}

// Function to flatten the buckets into a sorted array
void collectSortedValues(Bucket** buckets, int bucketCount, int* outputArray, int* outputIndex) {
    for (int i = 0; i < bucketCount; i++) {
        Node* current = buckets[i]->head;
        while (current != NULL) {
            outputArray[(*outputIndex)++] = current->value;
            current = current->next;
        }
    }
}

// Function to free the memory allocated for buckets
void freeBuckets(Bucket** buckets, int bucketCount) {
    for (int i = 0; i < bucketCount; i++) {
        Node* current = buckets[i]->head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        free(buckets[i]);
    }
}

// Bucket sort function
void bucketSort(int* inputArray, int length) {
    Bucket* buckets[BUCKET_COUNT];
    initializeBuckets(buckets, BUCKET_COUNT);

    // Find the maximum value for range
    int max = inputArray[0];
    for (int i = 1; i < length; i++) {
        if (inputArray[i] > max) {
            max = inputArray[i];
        }
    }

    // Insert values into respective buckets
    for (int i = 0; i < length; i++) {
        int bucketIndex = (BUCKET_COUNT * inputArray[i]) / (max + 1);
        insertIntoBucket(buckets[bucketIndex], inputArray[i]);
    }

    // Collect sorted values
    int outputIndex = 0;
    int* outputArray = (int*)malloc(sizeof(int) * length);
    collectSortedValues(buckets, BUCKET_COUNT, outputArray, &outputIndex);

    // Display sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", outputArray[i]);
    }
    printf("\n");

    free(outputArray);
    freeBuckets(buckets, BUCKET_COUNT);
}

// Main function
int main() {
    int inputArray[MAX_NUMBERS];
    int numberCount;
    
    printf("Welcome to the Enchanted Bucket Sort!\n");
    printf("How many numbers do you want to sort (max %d)? ", MAX_NUMBERS);
    scanf("%d", &numberCount);

    if (numberCount < 1 || numberCount > MAX_NUMBERS) {
        printf("Please enter a valid number count between 1 and %d!\n", MAX_NUMBERS);
        return 1;
    }

    printf("Please enter %d numbers:\n", numberCount);
    for (int i = 0; i < numberCount; i++) {
        scanf("%d", &inputArray[i]);
    }

    // Start sorting
    bucketSort(inputArray, numberCount);

    return 0;
}