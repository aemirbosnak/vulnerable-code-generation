//FormAI DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int roomnumber;
    int checkin, checkout;
    int nights;
} Guest;

void printMenu() {
    printf("\n1. Add guest\n");
    printf("2. Search guest\n");
    printf("3. Modify guest\n");
    printf("4. Delete guest\n");
    printf("5. Display all guests\n");
    printf("6. Exit\n");
}

void addGuest(Guest *guests, int *numguests) {
    if (*numguests == 0) {
        *guests = (Guest) {
            .name = "",
            .roomnumber = 0,
            .checkin = 0,
            .checkout = 0,
            .nights = 0
        };
    }
    
    printf("\nEnter guest name: ");
    scanf("%s", guests->name);
    printf("Enter room number: ");
    scanf("%d", &guests->roomnumber);
    printf("Enter check-in date (DDMMYY): ");
    scanf("%d", &guests->checkin);
    printf("Enter check-out date (DDMMYY): ");
    scanf("%d", &guests->checkout);
    guests->nights = abs(guests->checkout - guests->checkin);
    
    (*numguests)++;
    guests++;
    
    printf("\nGuest added successfully!\n");
}

void searchGuest(Guest *guests, int numguests) {
    char name[50];
    printf("\nEnter guest name to search for: ");
    scanf("%s", name);
    
    for (int i = 0; i < numguests; i++, guests++) {
        if (strcmp(guests->name, name) == 0) {
            printf("\nGuest found!\n");
            printf("Name: %s\nRoom number: %d\nCheck-in date: %d\nCheck-out date: %d\nNumber of nights: %d\n", guests->name, guests->roomnumber, guests->checkin, guests->checkout, guests->nights);
            return;
        }
    }
    
    printf("\nGuest not found!\n");
}

void modifyGuest(Guest *guests, int numguests) {
    char name[50];
    printf("\nEnter guest name to modify: ");
    scanf("%s", name);
    
    for (int i = 0; i < numguests; i++, guests++) {
        if (strcmp(guests->name, name) == 0) {
            printf("\nGuest found!");
            printf("\nEnter new room number: ");
            scanf("%d", &guests->roomnumber);
            printf("Enter new check-in date (DDMMYY): ");
            scanf("%d", &guests->checkin);
            printf("Enter new check-out date (DDMMYY): ");
            scanf("%d", &guests->checkout);
            guests->nights = abs(guests->checkout - guests->checkin);
            printf("\nGuest modified successfully!\n");
            return;
        }
    }
    
    printf("\nGuest not found!\n");
}

void deleteGuest(Guest *guests, int *numguests) {
    char name[50];
    printf("\nEnter guest name to delete: ");
    scanf("%s", name);
    
    Guest *prev = guests - 1;
    
    for (int i = 0; i < *numguests; i++, guests++) {
        if (strcmp(guests->name, name) == 0) {
            printf("\nGuest found!");
            (*numguests)--;
            while (guests < guests + *numguests) {
                *guests = *(guests + 1);
                guests++;
            }
            guests = prev;
            printf("\nGuest deleted successfully!\n");
            return;
        }
        prev = guests;
    }
    
    printf("\nGuest not found!\n");
}

void displayGuests(Guest *guests, int numguests) {
    if (numguests == 0) {
        printf("\nNo guests found!\n");
        return;
    }
    
    printf("\nAll guests:\n");
    for (int i = 0; i < numguests; i++, guests++) {
        printf("Guest %d:\n", i+1);
        printf("Name: %s\nRoom number: %d\nCheck-in date: %d\nCheck-out date: %d\nNumber of nights: %d\n", guests->name, guests->roomnumber, guests->checkin, guests->checkout, guests->nights);
    }
}

int main(void) {
    Guest *guests = NULL;
    int numguests = 0;
    int choice;
    int exit = 0;
    
    while (!exit) {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addGuest(guests, &numguests);
                break;
            case 2:
                searchGuest(guests, numguests);
                break;
            case 3:
                modifyGuest(guests, numguests);
                break;
            case 4:
                deleteGuest(guests, &numguests);
                break;
            case 5:
                displayGuests(guests, numguests);
                break;
            case 6:
                printf("\nExiting program...");
                exit = 1;
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
    }
    
    return 0;
}