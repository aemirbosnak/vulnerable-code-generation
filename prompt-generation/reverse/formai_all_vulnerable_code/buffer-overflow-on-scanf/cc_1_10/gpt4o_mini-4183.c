//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define EMAIL_LENGTH 100

typedef struct Subscriber {
    char email[EMAIL_LENGTH];
} Subscriber;

// Function prototypes
void addSubscriber(Subscriber* subscribers, int* count);
void viewSubscribers(Subscriber* subscribers, int count);
void deleteSubscriber(Subscriber* subscribers, int* count);
void displayMenu();
void clearInputBuffer();

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int subscriberCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear input buffer to handle newline character

        switch (choice) {
            case 1:
                addSubscriber(subscribers, &subscriberCount);
                break;
            case 2:
                viewSubscribers(subscribers, subscriberCount);
                break;
            case 3:
                deleteSubscriber(subscribers, &subscriberCount);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Add Subscriber\n");
    printf("2. View Subscribers\n");
    printf("3. Delete Subscriber\n");
    printf("4. Exit\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void addSubscriber(Subscriber* subscribers, int* count) {
    if (*count >= MAX_SUBSCRIBERS) {
        printf("Subscriber list is full! Cannot add more subscribers.\n");
        return;
    }

    printf("Enter email to subscribe: ");
    fgets(subscribers[*count].email, EMAIL_LENGTH, stdin);
    subscribers[*count].email[strcspn(subscribers[*count].email, "\n")] = 0;  // Remove newline character

    (*count)++;
    printf("Subscriber added: %s\n", subscribers[*count - 1].email);
}

void viewSubscribers(Subscriber* subscribers, int count) {
    if (count == 0) {
        printf("No subscribers to display.\n");
        return;
    }

    printf("\n--- Current Subscribers ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, subscribers[i].email);
    }
}

void deleteSubscriber(Subscriber* subscribers, int* count) {
    if (*count == 0) {
        printf("No subscribers to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the subscriber to delete (1 to %d): ", *count);
    scanf("%d", &index);
    clearInputBuffer();  // Clear input buffer to handle newline character

    if (index < 1 || index > *count) {
        printf("Invalid subscriber number!\n");
        return;
    }

    index--;  // Convert to zero-based index
    for (int i = index; i < *count - 1; i++) {
        subscribers[i] = subscribers[i + 1];  // Shift subscribers to the left
    }
    (*count)--;  // Reduce subscriber count

    printf("Subscriber deleted successfully.\n");
}