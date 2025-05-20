//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int weight; // in kg
    int processingTime; // in seconds
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
} BaggageQueue;

void initializeQueue(BaggageQueue *queue) {
    queue->count = 0;
}

void generateBaggage(BaggageQueue *queue) {
    if (queue->count >= MAX_BAGS) {
        printf("The baggage queue is full! Can't add more.\n");
        return;
    }

    Baggage newBaggage;
    sprintf(newBaggage.name, "Bag-%d", queue->count + 1);
    newBaggage.weight = rand() % 20 + 5; // Weight between 5 and 25 kg
    newBaggage.processingTime = rand() % 3 + 2; // Processing time between 2 and 5 seconds

    queue->bags[queue->count++] = newBaggage;

    printf("🎒 New baggage added: %s, Weight: %d kg, Processing Time: %d seconds\n", newBaggage.name, newBaggage.weight, newBaggage.processingTime);
}

int processBaggage(BaggageQueue *queue) {
    if (queue->count == 0) {
        printf("😢 No baggage to process!\n");
        return -1; 
    }
    
    Baggage bag = queue->bags[0];
    printf("📦 Processing %s... Weight: %d kg | Time: %d seconds\n", bag.name, bag.weight, bag.processingTime);
    sleep(bag.processingTime);
    printf("✅ Successfully processed %s!\n", bag.name);

    // Shift remaining baggage
    for (int i = 1; i < queue->count; i++) {
        queue->bags[i - 1] = queue->bags[i];
    }
    queue->count--;

    return 0; 
}

void displayBaggage(BaggageQueue *queue) {
    printf("\n🎉 Current Baggage Queue 🎉\n");
    for (int i = 0; i < queue->count; i++) {
        printf("%d. %s (Weight: %d kg)\n", i + 1, queue->bags[i].name, queue->bags[i].weight);
    }
    printf("Total bags: %d\n\n", queue->count);
}

int main() {
    srand(time(0)); // Seed for random number generation
    BaggageQueue queue;
    initializeQueue(&queue);

    int choice;
    do {
        printf("👜 Baggage Handling Simulation 👜\n");
        printf("1. Add Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Display Baggage Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateBaggage(&queue);
                break;
            case 2:
                processBaggage(&queue);
                break;
            case 3:
                displayBaggage(&queue);
                break;
            case 4:
                printf("🎈 Thank you for using the Baggage Handling Simulation! Goodbye! 🎈\n");
                break;
            default:
                printf("🚫 Invalid option! Please choose again.\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}