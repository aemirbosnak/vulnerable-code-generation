//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define BUF_SIZE 256

typedef struct {
    int id;
    char destination[BUF_SIZE];
    int status; // 0 for waiting, 1 for sorted
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int count;
} BaggageHandler;

void initializeBaggageHandler(BaggageHandler *handler) {
    handler->count = 0;
}

void addBag(BaggageHandler *handler, const char *destination) {
    if (handler->count < MAX_BAGS) {
        Bag *newBag = &handler->bags[handler->count++];
        newBag->id = handler->count; // simple ID generation
        strncpy(newBag->destination, destination, BUF_SIZE);
        newBag->status = 0; // Mark as waiting
        printf("Bag ID %d added for destination: %s\n", newBag->id, newBag->destination);
    } else {
        printf("Baggage handler is full!\n");
    }
}

void sortBags(BaggageHandler *handler) {
    printf("\nSorting bags...\n");
    for (int i = 0; i < handler->count; i++) {
        handler->bags[i].status = 1; // Mark sorted
        printf("Bag ID %d sorted to %s\n", handler->bags[i].id, handler->bags[i].destination);
        // Simulate a delay for sorting
        sleep(1);
    }
    printf("All bags sorted.\n");
}

void deliverBags(BaggageHandler *handler) {
    printf("\nDelivering bags...\n");
    for (int i = 0; i < handler->count; i++) {
        if (handler->bags[i].status == 1) { // Only deliver sorted bags
            printf("Delivering Bag ID %d to %s\n", handler->bags[i].id, handler->bags[i].destination);
            // Simulate a delay for delivery
            sleep(1);
        }
    }
    printf("All bags delivered.\n");
}

int main() {
    BaggageHandler handler;
    char destination[BUF_SIZE];
    char choice;

    initializeBaggageHandler(&handler);

    printf("Welcome to the Airport Baggage Handling System!\n");

    do {
        printf("\nEnter destination for the bag (or type 'exit' to finish): ");
        scanf("%s", destination);
        
        if (strcmp(destination, "exit") == 0) {
            break;
        }

        addBag(&handler, destination);

        printf("Do you want to add another bag? (y/n): ");
        getchar(); // To consume newline
        choice = getchar();

    } while (choice == 'y');

    sortBags(&handler);
    deliverBags(&handler);

    printf("Thank you for using the Airport Baggage Handling System!\n");
    return 0;
}