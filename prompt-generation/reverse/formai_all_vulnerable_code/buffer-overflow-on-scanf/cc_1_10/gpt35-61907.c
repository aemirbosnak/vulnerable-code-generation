//FormAI DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

/* Structures to hold information about guests */

struct Guest {
    char name[30];
    int roomNumber;
    int numNights;
    float pricePerNight;
};

/* Functions to handle guest data */

void addGuest(struct Guest guests[], int *numGuests) {
    printf("Enter guest name: ");
    scanf("%s", guests[*numGuests].name);
    printf("Enter room number: ");
    scanf("%d", &guests[*numGuests].roomNumber);
    printf("Enter number of nights: ");
    scanf("%d", &guests[*numGuests].numNights);
    printf("Enter price per night: ");
    scanf("%f", &guests[*numGuests].pricePerNight);
    (*numGuests)++;
}

void printGuests(struct Guest guests[], int numGuests) {
    printf("Guests:\n");
    for (int i = 0; i < numGuests; i++) {
        printf("%s (Room %d) - %d nights for $%.2f per night\n",
               guests[i].name, guests[i].roomNumber, guests[i].numNights,
               guests[i].pricePerNight);
    }
}

int main() {
    struct Guest guests[100];
    int numGuests = 0;
    int choice;
    
    do {
        /* Display options */
        printf("1. Add guest\n");
        printf("2. Print guests\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addGuest(guests, &numGuests);
                break;
            case 2:
                printGuests(guests, numGuests);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}