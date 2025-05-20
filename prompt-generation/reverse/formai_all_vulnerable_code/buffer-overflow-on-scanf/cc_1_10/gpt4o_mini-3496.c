//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define BAG_DESCRIPTION_LEN 50

typedef struct {
    char description[BAG_DESCRIPTION_LEN];
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int front, rear;
} BaggageQueue;

void initializeQueue(BaggageQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

int isFull(BaggageQueue *queue) {
    return (queue->rear + 1) % MAX_BAGS == queue->front;
}

int isEmpty(BaggageQueue *queue) {
    return queue->rear == queue->front;
}

void addBaggage(BaggageQueue *queue) {
    if (isFull(queue)) {
        printf("🎒 Oh dear! The baggage area is full! Cannot add more bags! 🎒\n");
        return;
    }
    Baggage newBag;
    printf("✨ Enter baggage description: ");
    scanf(" %[^\n]%*c", newBag.description);
    queue->bags[queue->rear] = newBag;
    queue->rear = (queue->rear + 1) % MAX_BAGS;
    printf("🧳 Yay! Baggage added: '%s' 🎉\n", newBag.description);
}

void removeBaggage(BaggageQueue *queue) {
    if (isEmpty(queue)) {
        printf("🚫 Oh no! There are no bags to remove! 🚫\n");
        return;
    }
    Baggage removedBag = queue->bags[queue->front];
    queue->front = (queue->front + 1) % MAX_BAGS;
    printf("👜 Goodbye, '%s'! Have a great journey! ✈️\n", removedBag.description);
}

void viewBaggage(BaggageQueue *queue) {
    if (isEmpty(queue)) {
        printf("🛅 The baggage area is empty! No bags to display! 😢\n");
        return;
    }
    printf("📦 Current Baggage in the Queue: 📦\n");
    int index = queue->front;
    while (index != queue->rear) {
        printf("- '%s'\n", queue->bags[index].description);
        index = (index + 1) % MAX_BAGS;
    }
}

void displayMenu() {
    printf("\n🎈 Welcome to the Airport Baggage Handling System! 🎈\n");
    printf("1. Add Baggage\n");
    printf("2. Remove Baggage\n");
    printf("3. View Baggage\n");
    printf("4. Exit\n");
}

int main() {
    BaggageQueue queue;
    initializeQueue(&queue);
    int choice;

    while (1) {
        displayMenu();
        printf("🌟 Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBaggage(&queue);
                break;
            case 2:
                removeBaggage(&queue);
                break;
            case 3:
                viewBaggage(&queue);
                break;
            case 4:
                printf("🎉 Thank you for using the Airport Baggage System! Goodbye! 🎉\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Please choose a valid option. ❌\n");
        }
    }

    return 0;
}