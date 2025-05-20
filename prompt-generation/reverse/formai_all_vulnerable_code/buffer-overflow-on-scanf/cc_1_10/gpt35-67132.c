//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

// Struct to represent an appointment
typedef struct {
    char date[20];
    char time[20];
    char name[50];
    char email[50];
} Appointment;

// Function to get available appointment slots for a particular date
void getAvailableSlots(char *date, char availableSlots[6][20]) {
    // Assuming the available slots for all dates are the same
    strcpy(availableSlots[0], "10:00 AM");
    strcpy(availableSlots[1], "11:00 AM");
    strcpy(availableSlots[2], "12:00 PM");
    strcpy(availableSlots[3], "2:00 PM");
    strcpy(availableSlots[4], "3:00 PM");
    strcpy(availableSlots[5], "4:00 PM");
}

// Function to display all the appointments
void displayAppointments(Appointment appointments[], int count) {
    printf("\nAll Appointments:");
    for (int i = 0; i < count; i++) {
        printf("\n%s %s %s %s", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].email);
    }
}

// Function to schedule an appointment
void scheduleAppointment(Appointment appointments[], int *count) {
    // Get inputs from user
    char date[20], time[20], name[50], email[50];
    printf("\nEnter the following details to schedule your appointment:\n");
    printf("Date (Format dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Time (Format hh:mm AM/PM): ");
    scanf("%s", time);
    printf("Name: ");
    scanf("%s", name);
    printf("Email: ");
    scanf("%s", email);
    
    // Check if the slot is available
    char availableSlots[6][20];
    getAvailableSlots(date, availableSlots);
    bool slotAvailable = false;
    for (int i = 0; i < 6; i++) {
        if (strcmp(availableSlots[i], time) == 0) {
            slotAvailable = true;
            break;
        }
    }
    
    // If slot is available, schedule the appointment
    if (slotAvailable) {
        Appointment newAppointment = {date, time, name, email};
        appointments[*count] = newAppointment;
        (*count)++;
        printf("\nAppointment scheduled successfully!");
    }
    else {
        printf("\nSorry, the slot is not available.");
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;
    
    do {
        // Display menu
        printf("\n\nChoose an option:");
        printf("\n1. Schedule appointment");
        printf("\n2. Display all appointments");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Perform the chosen operation
        switch (choice) {
            case 1:
                scheduleAppointment(appointments, &count);
                break;
            case 2:
                displayAppointments(appointments, count);
                break;
            case 3:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (true);

    return 0;
}