//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ROOM_TYPE 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char roomType[MAX_ROOM_TYPE];
    int nights;
    float totalCost;
} Guest;

Guest guests[MAX_GUESTS];
int guestCount = 0;

float calculateCost(const char *roomType, int nights) {
    if (strcmp(roomType, "Single") == 0) {
        return 100.0 * nights; // 100 gold coins per night
    } else if (strcmp(roomType, "Double") == 0) {
        return 150.0 * nights; // 150 gold coins per night
    } else if (strcmp(roomType, "Suite") == 0) {
        return 250.0 * nights; // 250 gold coins per night
    } else {
        return 0;
    }
}

void addGuest() {
    if (guestCount >= MAX_GUESTS) {
        printf("Alas! The inn hath no more rooms available.\n");
        return;
    }
    
    Guest newGuest;
    
    printf("Enter Guest Name: ");
    scanf(" %[^\n]s", newGuest.name);
    
    printf("Enter Guest Age: ");
    scanf("%d", &newGuest.age);
    
    printf("Select Room Type (Single/Double/Suite): ");
    scanf(" %[^\n]s", newGuest.roomType);
    
    printf("Enter Number of Nights: ");
    scanf("%d", &newGuest.nights);
    
    newGuest.totalCost = calculateCost(newGuest.roomType, newGuest.nights);
    
    guests[guestCount] = newGuest;
    guestCount++;
    
    printf("A warm welcome to %s! Thou shalt pay %.2f gold coins for %d nights in a %s.\n", 
           newGuest.name, newGuest.totalCost, newGuest.nights, newGuest.roomType);
}

void displayGuests() {
    if (guestCount == 0) {
        printf("Nay, there are no guests present in yonder inn.\n");
        return;
    }
    
    printf("Current Guests in the Inn:\n");
    for (int i = 0; i < guestCount; i++) {
        printf("Name: %s, Age: %d, Room Type: %s, Nights: %d, Total Cost: %.2f gold coins\n",
               guests[i].name, guests[i].age, guests[i].roomType, guests[i].nights, guests[i].totalCost);
    }
}

void removeGuest() {
    if (guestCount == 0) {
        printf("Alas! There are no guests to release from yonder inn.\n");
        return;
    }
    
    char guestName[MAX_NAME_LENGTH];
    printf("Enter the name of the guest to be released: ");
    scanf(" %[^\n]s", guestName);
    
    int found = 0;
    for (int i = 0; i < guestCount; i++) {
        if (strcmp(guests[i].name, guestName) == 0) {
            found = 1;
            for (int j = i; j < guestCount - 1; j++) {
                guests[j] = guests[j + 1];
            }
            guestCount--;
            printf("Fare thee well, %s! We wish thee safe travels!\n", guestName);
            break;
        }
    }
    
    if (!found) {
        printf("Nay, we do not harbor a guest by that name.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n=== Welcome to the Medieval Inn ===\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Remove Guest\n");
        printf("4. Exit\n");
        printf("Choose thy fate (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                displayGuests();
                break;
            case 3:
                removeGuest();
                break;
            case 4:
                printf("Farewell, noble innkeeper! May thy endeavors flourish.\n");
                break;
            default:
                printf("I know not what thou means by that. Choose wisely!\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}