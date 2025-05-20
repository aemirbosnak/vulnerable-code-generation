//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 10
#define BAG_NAME_LENGTH 20

typedef struct {
    char name[BAG_NAME_LENGTH];
    int id;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_BAGS == q->front;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Bag bag) {
    if (isFull(q)) {
        printf("Oh no! The baggage queue is full! 🎒✈️\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_BAGS;
    q->bags[q->rear] = bag;
    printf("Hooray! Bag `%s` (ID: %d) has been checked in! 🎉\n", bag.name, bag.id);
}

Bag dequeue(Queue* q) {
    Bag bag = {"", -1};
    if (isEmpty(q)) {
        printf("Whoops! There are no bags to pick up right now! 📦❌\n");
        return bag;
    }
    bag = q->bags[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_BAGS;
    }
    printf("Yay! Bag `%s` (ID: %d) has been transported! 📦➡️\n", bag.name, bag.id);
    return bag;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The baggage queue is empty! 🎈\n");
        return;
    }
    printf("Current baggage queue: \n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (q->bags[i].id != -1) {
            printf("  - Bag `%s` (ID: %d)\n", q->bags[i].name, q->bags[i].id);
        }
    }
}

int main() {
    Queue baggageQueue;
    initQueue(&baggageQueue);
    
    int choice, idCounter = 1;
    char bagName[BAG_NAME_LENGTH];

    while (1) {
        printf("\nWelcome to the Cheerful Baggage Handling System! 🌟\n");
        printf("1. Check in a bag\n");
        printf("2. Transport a bag\n");
        printf("3. Display current bags\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Check in a bag
                if (idCounter > 100) {
                    printf("Unfortunately, we have reached the maximum bag limit! 😢\n");
                    break;
                }
                printf("Enter the name of the bag: ");
                scanf("%s", bagName);
                Bag newBag;
                strncpy(newBag.name, bagName, BAG_NAME_LENGTH);
                newBag.id = idCounter++;
                enqueue(&baggageQueue, newBag);
                break;

            case 2: // Transport a bag
                dequeue(&baggageQueue);
                break;

            case 3: // Display current bags
                displayQueue(&baggageQueue);
                break;

            case 4: // Exit
                printf("Thank you for using the Cheerful Baggage Handling System! Goodbye! 👋🎊\n");
                exit(0);

            default:
                printf("Oops! That's not a valid option. Please choose again! 🙃\n");
        }
        sleep(1); // Pause for a second before the menu reappears
    }
    return 0;
}