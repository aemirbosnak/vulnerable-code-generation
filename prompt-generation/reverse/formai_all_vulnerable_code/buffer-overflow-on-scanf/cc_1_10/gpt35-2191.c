//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display available appointment slots
void displayAvailableSlots(int* availableSlots, int numSlots) {
    printf("\n\nAVAILABLE APPOINTMENT SLOTS\n");
    for(int i=0;i<numSlots;i++) {
        printf("Slot %d: %d\n", i+1, *(availableSlots+i));
    }
}

// Function to book an appointment slot
void bookAppointment(int* availableSlots, int numSlots, int chosenSlot) {
    if(*(availableSlots+chosenSlot-1) == 0) {
        printf("\nSorry, Slot %d is already booked. Please choose another slot!\n", chosenSlot);
    } else {
        printf("\nCongratulations! Slot %d has been booked!\n", chosenSlot);
        *(availableSlots+chosenSlot-1) = 0;
    }
}

int main() {

    // Initializing available appointment slots
    int availableSlots[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 1 represents available, 0 represents booked

    printf("Welcome to the Appointment Scheduler!\n");
    printf("We offer top notch appointments for anyone who is sick, or anyone who just wants to say hello to the doctor (we don't judge).\n");
    printf("Our current available slots are:\n");
    displayAvailableSlots(availableSlots, 10);

    while(1) {

        // User input for booking an appointment
        printf("\nPlease enter 'book' to book an appointment or 'quit' to exit: ");
        char userInput[10];
        scanf("%s", userInput);

        if(strcmp(userInput, "book")==0) {
            // User input for the chosen slot
            printf("\nPlease choose an available slot (1-10): ");
            int chosenSlot;
            scanf("%d", &chosenSlot);

            if(chosenSlot<1 || chosenSlot>10) {
                printf("\nSorry, invalid slot chosen. Please choose again!\n");
            } else {
                bookAppointment(availableSlots, 10, chosenSlot);
                displayAvailableSlots(availableSlots, 10);
            }
        } else if(strcmp(userInput, "quit")==0) {
            // Exiting the program
            printf("\nThank you for using our Appointment Scheduler. Goodbye!\n");
            exit(0);
        } else {
            printf("\nSorry, invalid input. Please try again!\n");
        }
    }

    return 0;
}