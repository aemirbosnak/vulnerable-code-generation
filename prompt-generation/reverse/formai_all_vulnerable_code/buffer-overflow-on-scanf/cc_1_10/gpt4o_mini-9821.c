//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_SLOTS 32 // Define total number of parking slots (0 to 31)
#define PARKING_FULL   (1 << TOTAL_SLOTS) - 1 // All slots occupied (binary 111...111)

// Function to display the parking lot status
void displayParkingStatus(unsigned int parkingLot) {
    printf("Parking Lot Status:\n");
    for (int i = 0; i < TOTAL_SLOTS; ++i) {
        if (parkingLot & (1 << i)) {
            printf("Slot %d: Occupied\n", i);
        } else {
            printf("Slot %d: Available\n", i);
        }
    }
}

// Function to park a vehicle, returns 1 if successful, 0 if full
int parkVehicle(unsigned int *parkingLot, int slot) {
    if (slot < 0 || slot >= TOTAL_SLOTS) {
        printf("Invalid slot number.\n");
        return 0;
    }
    if (*parkingLot & (1 << slot)) {
        printf("Slot %d is already occupied.\n", slot);
        return 0;
    }
    *parkingLot |= (1 << slot); // Mark the slot as occupied
    printf("Vehicle parked in slot %d.\n", slot);
    return 1;
}

// Function to remove a vehicle from a specific slot
int removeVehicle(unsigned int *parkingLot, int slot) {
    if (slot < 0 || slot >= TOTAL_SLOTS) {
        printf("Invalid slot number.\n");
        return 0;
    }
    if (!(*parkingLot & (1 << slot))) {
        printf("Slot %d is already vacant.\n", slot);
        return 0;
    }
    *parkingLot &= ~(1 << slot); // Mark the slot as vacant
    printf("Vehicle removed from slot %d.\n", slot);
    return 1;
}

// Function to check for available slots
void checkAvailableSlots(unsigned int parkingLot) {
    int availableSlotsCount = 0;
    for (int i = 0; i < TOTAL_SLOTS; ++i) {
        if (!(parkingLot & (1 << i))) {
            availableSlotsCount++;
        }
    }
    printf("Total available slots: %d\n", availableSlotsCount);
}

// Main function to demonstrate the parking system
int main() {
    unsigned int parkingLot = 0; // Binary representation of parking slots (0 = vacant, 1 = occupied)
    int choice, slot;

    while (1) {
        printf("\nParking System Menu:\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Check Available Slots\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter slot number to park (0 to %d): ", TOTAL_SLOTS - 1);
                scanf("%d", &slot);
                parkVehicle(&parkingLot, slot);
                break;
            case 2:
                printf("Enter slot number to remove vehicle from (0 to %d): ", TOTAL_SLOTS - 1);
                scanf("%d", &slot);
                removeVehicle(&parkingLot, slot);
                break;
            case 3:
                displayParkingStatus(parkingLot);
                break;
            case 4:
                checkAvailableSlots(parkingLot);
                break;
            case 5:
                printf("Exiting the parking system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}