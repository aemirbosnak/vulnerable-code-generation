//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define some constants for our boot optimizer
#define MAX_BOOT_ITEMS 10
#define MAX_ITEM_LENGTH 50
#define SUCCESS 0
#define FAILURE 1

// Structure to hold boot items
typedef struct {
    char name[MAX_ITEM_LENGTH];
    int priority;
} BootItem;

// Function prototypes
void displayBootItems(BootItem items[], int count);
int comparePriority(const void *a, const void *b);
void optimizeBootOrder(BootItem items[], int count);
void addItem(BootItem items[], int *count);
void removeItem(BootItem items[], int *count);
void sortItems(BootItem items[], int count);

// Main function
int main() {
    BootItem bootItems[MAX_BOOT_ITEMS];
    int itemCount = 0;
    int choice;

    printf("🎉 Welcome to the C System Boot Optimizer! 🎉\n");

    do {
        printf("\n1. View Boot Items\n");
        printf("2. Optimize Boot Order\n");
        printf("3. Add a Boot Item\n");
        printf("4. Remove a Boot Item\n");
        printf("5. Exit\n");
        printf("Please enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBootItems(bootItems, itemCount);
                break;
            case 2:
                optimizeBootOrder(bootItems, itemCount);
                break;
            case 3:
                addItem(bootItems, &itemCount);
                break;
            case 4:
                removeItem(bootItems, &itemCount);
                break;
            case 5:
                printf("🎈 Thank you for using the C System Boot Optimizer! Goodbye! 🎈\n");
                break;
            default:
                printf("😅 Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return SUCCESS;
}

// Function to display current boot items
void displayBootItems(BootItem items[], int count) {
    if (count == 0) {
        printf("🚫 No boot items found! Add some items to optimize.\n");
    } else {
        printf("\nCurrent Boot Items:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s (Priority: %d)\n", i + 1, items[i].name, items[i].priority);
        }
    }
}

// Function to compare priority of boot items
int comparePriority(const void *a, const void *b) {
    return ((BootItem *)b)->priority - ((BootItem *)a)->priority; // Descending order
}

// Function to optimize boot order
void optimizeBootOrder(BootItem items[], int count) {
    if (count < 2) {
        printf("🌟 Not enough items to optimize! Add more items first.\n");
        return;
    }

    sortItems(items, count);
    printf("🚀 Boot order optimized! Here's the new order:\n");
    displayBootItems(items, count);
}

// Function to add a new boot item
void addItem(BootItem items[], int *count) {
    if (*count >= MAX_BOOT_ITEMS) {
        printf("😮 Maximum number of boot items reached! Can't add more.\n");
        return;
    }

    BootItem newItem;
    printf("Enter the name of the boot item: ");
    scanf("%s", newItem.name);
    printf("Enter the priority of the boot item (Higher means earlier): ");
    scanf("%d", &newItem.priority);
    
    items[*count] = newItem;
    (*count)++;
    printf("🎉 Boot item '%s' added with priority %d!\n", newItem.name, newItem.priority);
}

// Function to remove a boot item
void removeItem(BootItem items[], int *count) {
    if (*count == 0) {
        printf("🚫 No items to remove!\n");
        return;
    }

    int index;
    printf("Enter the index of the item to remove (1-%d): ", *count);
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("😅 Invalid index! Can't remove the item.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        items[i] = items[i + 1];
    }
    (*count)--;
    printf("🗑️ Boot item removed successfully! There are now %d items left.\n", *count);
}

// Function to sort boot items by priority
void sortItems(BootItem items[], int count) {
    qsort(items, count, sizeof(BootItem), comparePriority);
}