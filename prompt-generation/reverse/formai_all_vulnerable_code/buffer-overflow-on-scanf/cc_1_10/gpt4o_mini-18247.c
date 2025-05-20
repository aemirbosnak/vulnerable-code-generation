//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 10
#define BELT_LENGTH 20

typedef struct {
    int id;
    char description[50];
} Bag;

Bag baggage[MAX_BAGS];
int bag_count = 0;

void add_bag(int id, const char *description) {
    if (bag_count < MAX_BAGS) {
        baggage[bag_count].id = id;
        snprintf(baggage[bag_count].description, sizeof(baggage[bag_count].description), "%s", description);
        bag_count++;
        printf("🎒 Bag %d: '%s' has been added to the conveyor belt! 🥳\n", id, description);
    } else {
        printf("🎉 All bags are currently onboard! Please wait. 🎈\n");
    }
}

void process_bags() {
    printf("\n🚂 The conveyor belt is now operational! 🎊\n");
    for (int i = 0; i < bag_count; i++) {
        printf("🎽 Processing bag %d: '%s' ...", baggage[i].id, baggage[i].description);
        sleep(1); // Simulate processing time
        printf(" ✅ Bag %d has been successfully processed! 🎉\n", baggage[i].id);
    }
    printf("\n🎉 All bags have been joyfully processed! 🌈\n");
}

void display_bags() {
    printf("\n💼 Here are all the bags on the conveyor belt! ✨\n");
    for (int i = 0; i < bag_count; i++) {
        printf("👜 Bag %d: '%s'\n", baggage[i].id, baggage[i].description);
    }
    printf("✨ Total bags: %d\n\n", bag_count);
}

void clear_bags() {
    bag_count = 0;
    printf("🧹 All bags have been cleared from the system! Ready for new adventures! 🌟\n");
}

int main() {
    srand(time(NULL));
    int bag_id = 1;
    char *descriptions[] = {
        "Red backpack",
        "Blue suitcase",
        "Green duffle bag",
        "Brown carry-on",
        "Yellow shopping tote",
        "Black briefcase",
        "Orange travel bag",
        "Pink handbag",
        "Purple golf bag",
        "Gray laptop bag"
    };

    while (1) {
        printf("🌟 Welcome to the Happy Airport Baggage Handling System! 🎈\n");
        printf("1. Add bag to conveyor belt\n");
        printf("2. Process bags on conveyor belt\n");
        printf("3. Display current bags\n");
        printf("4. Clear all bags\n");
        printf("5. Exit\n");
        printf("Please choose an option (1-5): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_bag(bag_id, descriptions[rand() % 10]);
                bag_id++;
                break;
            case 2:
                process_bags();
                break;
            case 3:
                display_bags();
                break;
            case 4:
                clear_bags();
                break;
            case 5:
                printf("😄 Thank you for using the Happy Airport Baggage Handling System! Have a great day! 🌈\n");
                exit(0);
            default:
                printf("❗ Invalid choice, please select again! 🎊\n");
        }
        printf("\n");
    }

    return 0;
}