//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000    // Maximum size of the array
#define BUCKET_COUNT 10   // Number of buckets

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        struct Node* previous = NULL;
        while (current != NULL && current->data < value) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            newNode->next = *head;
            *head = newNode;
        } else {
            newNode->next = current;
            previous->next = newNode;
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    struct Node* buckets[BUCKET_COUNT] = { NULL };

    // Step 1: Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_COUNT / (n + 1); // Determine bucket index
        insertNode(&buckets[index], arr[i]); // Insert into the corresponding bucket
    }

    // Step 2: Sort each bucket and concatenate them
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data; // Place sorted data back into original array
            struct Node* temp = current;
            current = current->next;
            free(temp); // Free memory of the node
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test bucket sort
int main() {
    int arr[MAX_SIZE], n;

    printf("Welcome to the Magical Bucket Sort!\n");
    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Your unsorted array: ");
    displayArray(arr, n);

    bucketSort(arr, n); // Perform bucket sort

    printf("Your sorted array: ");
    displayArray(arr, n); // Display the sorted array

    printf("Magic of sorting complete! Until next time!\n");
    return 0;
}