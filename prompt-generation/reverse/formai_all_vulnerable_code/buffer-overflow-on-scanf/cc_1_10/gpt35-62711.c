//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold appointments
struct appointment {
    char date[20];
    char time[10];
    char name[50];
    char description[100];
};

// Function prototypes
void addAppointment(struct appointment *appts, int *numAppts);
void viewAppointments(struct appointment *appts, int numAppts);

int main() {
    // Declare variables
    struct appointment appts[100];
    int numAppts = 0;
    int choice;

    // Loop through menu options until user quits
    do {
        // Print menu options
        printf("\nAppointment Scheduler");
        printf("\n=====================");
        printf("\n1. Add Appointment");
        printf("\n2. View Appointments");
        printf("\n3. Quit");
        
        // Ask user for input
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);
        
        // Process user input
        switch(choice) {
            case 1:
                addAppointment(appts, &numAppts);
                break;
            case 2:
                viewAppointments(appts, numAppts);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to add appointment to array
void addAppointment(struct appointment *appts, int *numAppts) {
    // Check if array is full
    if (*numAppts >= 100) {
        printf("\nError: Maximum number of appointments reached.\n");
        return;
    }
    
    // Ask user for input
    printf("\nEnter date (MM/DD/YYYY): ");
    scanf("%s", appts[*numAppts].date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appts[*numAppts].time);
    printf("Enter name: ");
    scanf("%s", appts[*numAppts].name);
    printf("Enter description: ");
    scanf("%s", appts[*numAppts].description);
    
    // Increment number of appointments
    *numAppts += 1;
    
    printf("\nAppointment added successfully!\n");
}

// Function to view appointments from array
void viewAppointments(struct appointment *appts, int numAppts) {
    // Check if array is empty
    if (numAppts == 0) {
        printf("\nNo appointments to display.\n");
        return;
    }
    
    // Loop through appointments and print information
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppts; i++) {
        printf("\nDate: %s", appts[i].date);
        printf("\nTime: %s", appts[i].time);
        printf("\nName: %s", appts[i].name);
        printf("\nDescription: %s\n", appts[i].description);
    }
}