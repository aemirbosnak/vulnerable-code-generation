//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50 // Maximum number of appointments that can be scheduled

// Appointment struct to store appointment details
typedef struct {
    char date[20];
    char time[20];
    char name[50];
    char phone[15];
} appointment;

// Initialize appointment array to NULL values
appointment appointments[MAX_APPOINTMENTS] = {0};

// Function to allow user to schedule a new appointment
void scheduleAppointment() {
    // Ask user for appointment details
    char date[20], time[20], name[50], phone[15];
    printf("Enter appointment date (mm/dd/yyyy): ");
    scanf("%s", date);
    printf("Enter appointment time (hh:mm AM/PM): ");
    scanf("%s", time);
    getchar(); // Consume newline character left in buffer by scanf
    printf("Enter patient name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character from name string
    printf("Enter patient phone number: ");
    scanf("%s", phone);
    
    // Find first available appointment slot
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] == '\0') {
            break;
        }
    }
    
    // Check if appointment array is full
    if (i == MAX_APPOINTMENTS) {
        printf("All appointment slots are full.\n");
        return;
    }
    
    // Add new appointment to array
    strcpy(appointments[i].date, date);
    strcpy(appointments[i].time, time);
    strcpy(appointments[i].name, name);
    strcpy(appointments[i].phone, phone);
    
    printf("Appointment scheduled successfully!\n");
}

// Function to print all scheduled appointments
void displayAppointments() {
    // Check if there are any appointments scheduled
    int i, hasAppointments = 0;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] != '\0') {
            hasAppointments = 1;
            break;
        }
    }
    if (!hasAppointments) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    // Print all scheduled appointments
    printf("Scheduled Appointments:\n");
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("%s at %s with %s (%s)\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].phone);
        }
    }
}

// Main function to display menu and handle user inputs
int main() {
    int option;
    
    do {
        // Display menu options
        printf("\nAppointment Scheduler\n");
        printf("---------------------\n");
        printf("1. Schedule Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        // Handle user choice
        switch (option) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 3);
    
    return 0;
}