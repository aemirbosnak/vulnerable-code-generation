//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the available time slots
void displaySlots(int slots[], int n) {
    printf("\nAvailable time slots for the day:\n");
    for(int i=0; i<n; i++) {
        if(slots[i] == 0) {
            printf("%d- %d, ", i+9, i+10);
        }
    }
    printf("\n");
}

// function to check the availability of the selected time slot
int checkAvailability(int slots[], int n, int slot) {
    if(slot<9 || slot>18) {
        return 0;
    }
    if(slots[slot-9] == 1) {
        return 0;
    }
    return 1;
}

int main() {
    int slots[10] = {0}; // available slots from 9-18
    int choice;
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Press 1 to display available slots for the day.\n");
    printf("Press 2 to book an appointment.\n");
    printf("Press 3 to cancel an appointment.\n");
    printf("Press 4 to exit.\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                displaySlots(slots, 10);
                break;

            case 2: {
                int slot;
                printf("\nEnter the time slot you would like to book (9-18): ");
                scanf("%d", &slot);

                if(checkAvailability(slots, 10, slot)) {
                    printf("Your appointment has been confirmed for %d-%d.\n", slot, slot+1);
                    slots[slot-9] = 1;
                }
                else {
                    printf("Sorry, the selected time slot is not available.\n");
                }
                break;
            }
            
            case 3: {
                int slot;
                printf("\nEnter the time slot you would like to cancel (9-18): ");
                scanf("%d", &slot);

                if(slot<9 || slot>18) {
                    printf("Invalid time slot.\n");
                    break;
                }

                if(slots[slot-9] == 0) {
                    printf("There is no appointment scheduled for this time slot.\n");
                    break;
                }

                printf("Your appointment for %d-%d has been cancelled.\n", slot, slot+1);
                slots[slot-9] = 0;
                break;
            }
            
            case 4:
                printf("Thank you for using the Appointment Scheduler.\n");
                exit(0);
            
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}