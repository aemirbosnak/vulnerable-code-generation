//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterRoom(int roomNumber);
void ghostEncounter();
void treasureDiscovery();
void doorLock();
void friendlySpirit();
void thankYouMessage();

int main() {
    srand(time(NULL)); // Seed for random number generation
    int choice;

    thankYouMessage();
    
    while (1) {
        printf("\nWelcome to the Haunted House Simulator!\n");
        printf("Choose a room to enter:\n");
        printf("1. The Living Room\n");
        printf("2. The Kitchen\n");
        printf("3. The Basement\n");
        printf("4. The Attic\n");
        printf("5. Exit the Haunted House\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thank you for visiting! Hope you had a spooky time!\n");
            break;
        } else if (choice >= 1 && choice <= 4) {
            enterRoom(choice);
        } else {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
        }
    }

    return 0;
}

void enterRoom(int roomNumber) {
    printf("\nYou enter room number %d...\n", roomNumber);
    int event = rand() % 4; // Generate a random event between 0 and 3

    switch (event) {
        case 0:
            ghostEncounter();
            break;
        case 1:
            treasureDiscovery();
            break;
        case 2:
            doorLock();
            break;
        case 3:
            friendlySpirit();
            break;
    }
}

void ghostEncounter() {
    printf("Suddenly, a ghost appears and floats towards you!\n");
    printf("You feel a chill run down your spine...\n");
    printf("As it approaches, you realize it’s just a friendly ghost who wants to play!\n");
    printf("You spend some time playing games and enjoying its company.\n");
}

void treasureDiscovery() {
    printf("As you wander about, you stumble upon a hidden treasure chest!\n");
    printf("With a shaky hand, you open it to find glittering gold coins and mysterious artifacts!\n");
    printf("Congratulations! You've found riches in the haunted house!\n");
}

void doorLock() {
    printf("You try to leave the room, but the door slams shut behind you!\n");
    printf("It seems you’ve been locked in!\n");
    printf("After a few moments of panic, you find a hidden key in your pocket!\n");
    printf("You unlock the door and finally escape back into the hallway.\n");
}

void friendlySpirit() {
    printf("You encounter a kind spirit who offers to guide you through the house!\n");
    printf("The spirit shares stories of the house's history, helping you appreciate its charm.\n");
    printf("You gain wisdom and courage to face other eerie encounters!\n");
}

void thankYouMessage() {
    printf("Thank you for joining this haunted adventure!\n");
    printf("May your journey be filled with mystery and joy!\n");
}