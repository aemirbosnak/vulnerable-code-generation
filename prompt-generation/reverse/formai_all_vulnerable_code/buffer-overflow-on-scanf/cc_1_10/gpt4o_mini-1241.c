//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold guest details
typedef struct Guest {
    char name[50];
    int roomNumber;
} Guest;

// Function declarations
void welcomeToHotel();
void checkIn(Guest *guest);
void checkOut(Guest *guest);
void displayGuestInfo(Guest guest);
void grumpyOldManComplaint();

int main() {
    Guest currentGuest;
    int choice;

    welcomeToHotel();

    while (1) {
        printf("\n1. Check-In\n2. Check-Out\n3. Show Guest Info\n4. Grumpy Old Man's Complaint\n5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(&currentGuest);
                break;
            case 2:
                checkOut(&currentGuest);
                break;
            case 3:
                displayGuestInfo(currentGuest);
                break;
            case 4:
                grumpyOldManComplaint();
                break;
            case 5:
                printf("Thank you for visiting our hotel! Come back soon or we'll start charging you for every minute!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice. Are you trying to confuse me?\n");
        }
    }

    return 0;
}

void welcomeToHotel() {
    printf("=========================================\n");
    printf("Welcome to The Laughing Llama Hotel!\n");
    printf("Where you check in with joy and check out with a chuckle!\n");
    printf("=========================================\n");
}

void checkIn(Guest *guest) {
    printf("Please enter your name: ");
    scanf(" %[^\n]", guest->name); // Read string with spaces
    printf("Finding a cozy room for Mr./Ms. %s...\n", guest->name);
    guest->roomNumber = rand() % 100 + 1; // Randomly assign a room number between 1 and 100
    printf("Congratulations! You've been assigned room number: %d 🛏️\n", guest->roomNumber);
}

void checkOut(Guest *guest) {
    if (strlen(guest->name) == 0) {
        printf("You're not even checked in... Who are you trying to fool? 🤫\n");
        return;
    }
    
    printf("Goodbye, %s! You were wonderful company! Hope to see you again!\n", guest->name);
    guest->name[0] = '\0'; // Clearing guest name
    guest->roomNumber = 0; // Reset room number
}

void displayGuestInfo(Guest guest) {
    if (strlen(guest.name) == 0) {
        printf("There are currently no guests... Looks like the llamas are taking a nap!\n");
        return;
    }
    printf("Guest Name: %s\n", guest.name);
    printf("Room Number: %d\n", guest.roomNumber);
}

void grumpyOldManComplaint() {
    printf("Grumpy Old Man's Complaint: \n");
    printf("1. The breakfast didn't taste like my grandma's waffles!\n");
    printf("2. The elevator is slower than a snail in a marathon!\n");
    printf("3. I demand more grumpiness from the staff!\n");
    printf("4. Where's my knitting club meeting? Oh wait, wrong hotel!\n");
    printf("Please address these complaints or a llama will be unleashed!\n");
}