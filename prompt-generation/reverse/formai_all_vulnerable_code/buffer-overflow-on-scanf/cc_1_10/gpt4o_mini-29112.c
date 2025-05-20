//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_SIZE 100

// Node structure for a linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to hold linked list and its size for threading
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Function to visualize the linked list
void* visualizeList(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    Node* current = list->head;

    while (1) {
        printf("\nCurrent Linked List:\n");
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
        sleep(2);
        current = list->head; // Reset current to head for the next visualization
    }
    return NULL;
}

// Function to cleanup the linked list
void cleanupList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->size = 0;
}

// Function to take user input and add nodes to the list
void* addNodes(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    int data;

    printf("Enter integers to add to the list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        addNode(list, data);
    }
    return NULL;
}

int main() {
    LinkedList list = {NULL, 0};
    pthread_t visualizerThread, inputThread;

    // Start the visualization thread
    if (pthread_create(&visualizerThread, NULL, visualizeList, &list) != 0) {
        fprintf(stderr, "Error creating visualizer thread\n");
        return 1;
    }

    // Start the input thread
    if (pthread_create(&inputThread, NULL, addNodes, &list) != 0) {
        fprintf(stderr, "Error creating input thread\n");
        return 1;
    }

    // Wait for the input thread to finish
    pthread_join(inputThread, NULL);

    // Clean up the list after finishing
    cleanupList(&list);

    // Terminate the visualizer thread
    pthread_cancel(visualizerThread);
    pthread_join(visualizerThread, NULL);

    printf("Program finished. Memory cleaned up.\n");
    return 0;
}