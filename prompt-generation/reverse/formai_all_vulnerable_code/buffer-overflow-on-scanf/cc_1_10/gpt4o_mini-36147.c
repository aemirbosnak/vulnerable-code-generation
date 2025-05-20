//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5 // Maximum number of elements in the queue

typedef struct {
    char *clue;
} Clue;

typedef struct {
    Clue clues[MAX];
    int front, rear;
} ClueQueue;

// Function to initialize the queue
void initQueue(ClueQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
bool isFull(ClueQueue *q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
bool isEmpty(ClueQueue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add a clue to the queue
void enqueue(ClueQueue *q, const char *clue) {
    if (isFull(q)) {
        printf("No more space for clues! The case thickens...\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->clues[q->rear].clue = strdup(clue); // Allocate memory and copy the clue
    printf("Clue added to the queue: \"%s\"\n", clue);
}

// Function to remove a clue from the queue
Clue dequeue(ClueQueue *q) {
    Clue invalidClue = { NULL };

    if (isEmpty(q)) {
        printf("No clues remain in the queue! The case is closed...\n");
        return invalidClue;
    }
    Clue removedClue = q->clues[q->front];
    q->front++;
    if (q->front > q->rear) {
        // Reset the queue if it becomes empty
        initQueue(q);
    }
    printf("Clue removed from the queue: \"%s\"\n", removedClue.clue);
    return removedClue;
}

// Function to view the next clue in the queue
Clue peek(ClueQueue *q) {
    if (isEmpty(q)) {
        Clue invalidClue = { NULL };
        printf("No clues to peek at! All is silent...\n");
        return invalidClue;
    }
    return q->clues[q->front];
}

// Main function simulating Sherlock Holmes' investigation
int main() {
    ClueQueue queue;
    initQueue(&queue);
    char command[20];
    char clue[100];

    printf("Welcome to the Sherlock Holmes Clue Queue Application.\n");
    printf("Enter your commands (enqueue, dequeue, peek, exit):\n");

    while (true) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "enqueue") == 0) {
            printf("Enter the clue to add: ");
            scanf(" %[^\n]", clue); // Read a line of text
            enqueue(&queue, clue);
        } else if (strcmp(command, "dequeue") == 0) {
            Clue removedClue = dequeue(&queue);
            if (removedClue.clue != NULL) {
                free(removedClue.clue); // Free the memory allocated for the clue
            }
        } else if (strcmp(command, "peek") == 0) {
            Clue nextClue = peek(&queue);
            if (nextClue.clue != NULL) {
                printf("Next clue to investigate: \"%s\"\n", nextClue.clue);
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Ending the investigation.\n");
            break;
        } else {
            printf("Unknown command, please try again.\n");
        }
    }

    // Cleanup remaining clues
    while (!isEmpty(&queue)) {
        Clue removedClue = dequeue(&queue);
        if (removedClue.clue != NULL) {
            free(removedClue.clue);
        }
    }

    return 0;
}