//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTY_ATTENDEES 100
#define MAX_NAME_LENGTH 50
#define MAX_GIFT_LENGTH 100

// Structure for Guest Information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char gift[MAX_GIFT_LENGTH];
} Guest;

// Function Prototypes
void addGuest(Guest *guests, int *count);
void displayGuests(Guest *guests, int count);
void surprises(Guest *guests, int count);
void freeMemory(Guest *guests);

int main() {
    Guest *guests = (Guest *)malloc(sizeof(Guest) * MAX_PARTY_ATTENDEES);
    if (guests == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int count = 0;
    int option;
    
    printf("🎉 Welcome to the Surprise Party Planner! 🎉\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a guest\n");
        printf("2. Display all guests\n");
        printf("3. Surprise time planning!\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count < MAX_PARTY_ATTENDEES) {
                    addGuest(guests, &count);
                } else {
                    printf("🎈 Can't add more guests! Party is reaching capacity! 🎈\n");
                }
                break;
            case 2:
                displayGuests(guests, count);
                break;
            case 3:
                surprises(guests, count);
                break;
            case 4:
                printf("👋 Exiting the Party Planner! See you next time! 👋\n");
                freeMemory(guests);
                return 0;
            default:
                printf("❌ Invalid option, please try again! ❌\n");
        }
    }
    
    freeMemory(guests);
    return 0;
}

void addGuest(Guest *guests, int *count) {
    printf("Enter the guest's name: ");
    scanf("%s", guests[*count].name);
    printf("Enter the guest's gift suggestion: ");
    scanf("%s", guests[*count].gift);
    printf("🎉 Guest %s added with a gift suggestion: %s 🎉\n", guests[*count].name, guests[*count].gift);
    (*count)++;
}

void displayGuests(Guest *guests, int count) {
    if (count == 0) {
        printf("😢 No guests have been added yet! 😢\n");
        return;
    }

    printf("\n🎊 List of Guests 🎊\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Gift: %s\n", i + 1, guests[i].name, guests[i].gift);
    }
}

void surprises(Guest *guests, int count) {
    if (count == 0) {
        printf("😱 No one is here to surprise! 😱\n");
        return;
    }

    printf("\n🎉 It's Surprise Time! 🎉\n");
    for (int i = 0; i < count; i++) {
        printf("🎁 Surprise for %s with their gift: %s 🎁\n", guests[i].name, guests[i].gift);
    }
}

void freeMemory(Guest *guests) {
    free(guests);
}