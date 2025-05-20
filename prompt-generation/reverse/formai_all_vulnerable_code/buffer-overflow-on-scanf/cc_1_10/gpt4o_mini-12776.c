//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int bagNumber;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int count;
} BaggageHandler;

void initializeBaggageHandler(BaggageHandler *handler) {
    handler->count = 0;
}

void addBag(BaggageHandler *handler, const char *name) {
    if (handler->count < MAX_BAGS) {
        strcpy(handler->bags[handler->count].name, name);
        handler->bags[handler->count].bagNumber = handler->count + 1;
        handler->count++;
        printf("🎒 Bag %d (Name: %s) has been added to the conveyor belt!\n", 
        handler->bags[handler->count - 1].bagNumber, name);
    } else {
        printf("🚫 Oops! The conveyor belt is full! Can't add any more bags.\n");
    }
}

void loadBags(BaggageHandler *handler) {
    for (int i = 0; i < handler->count; i++) {
        printf("🚀 Loading bag %d: %s onto the plane...\n", 
        handler->bags[i].bagNumber, handler->bags[i].name);
        sleep(1);  // Simulate time delay for loading bags
    }
    printf("🎉 All bags have been loaded onto the plane!\n");
}

void deliverBags(BaggageHandler *handler) {
    for (int i = 0; i < handler->count; i++) {
        printf("🏖️ Delivering bag %d: %s to the baggage claim...\n", 
        handler->bags[i].bagNumber, handler->bags[i].name);
        sleep(1);  // Simulate time delay for delivering bags
    }
    printf("🎊 Hooray! All bags have been delivered successfully!\n");
}

void listBags(BaggageHandler *handler) {
    printf("📦 Current Bags on the Conveyor Belt:\n");
    for (int i = 0; i < handler->count; i++) {
        printf("   Bag %d: %s\n", handler->bags[i].bagNumber, handler->bags[i].name);
    }
    if (handler->count == 0) {
        printf("   🚫 No bags on the conveyor belt!\n");
    }
}

int main() {
    BaggageHandler handler;
    initializeBaggageHandler(&handler);

    while (1) {
        printf("\n🔥 Welcome to the Airport Baggage Handling System! 🔥\n");
        printf("1. Add Bag\n");
        printf("2. Load Bags\n");
        printf("3. Deliver Bags\n");
        printf("4. List All Bags\n");
        printf("5. Exit\n");
        printf("\nChoose an option (1-5): ");

        int choice;
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                printf("✨ Enter the name of the bag: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                    
                addBag(&handler, name);
                break;
            }
            case 2:
                loadBags(&handler);
                break;
            case 3:
                deliverBags(&handler);
                break;
            case 4:
                listBags(&handler);
                break;
            case 5:
                printf("🌈 Thanks for using our Baggage Handling System! Have a great day!\n");
                exit(0);
            default:
                printf("❗ Invalid option! Please try again.\n");
        }
    }

    return 0;
}