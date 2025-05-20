//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold appointment details
typedef struct appointment {
    char time[10];
    char date[11];
    char name[100];
    char purpose[500];
} Appointment;

int main() {
    // Declare variables
    int choice;
    char temp[100];
    Appointment appointments[10];
    int num_appointments = 0;
    
    // Display main menu and get user's choice
    do {
        printf("\n=============== MENU ===============");
        printf("\n1. Schedule an Appointment");
        printf("\n2. View Appointments");
        printf("\n3. Exit");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer
        
        // Handle user's choice
        switch (choice) {
            case 1:
                // Check if there is space to add another appointment
                if (num_appointments < 10) {
                    // Get appointment details from user
                    printf("\nEnter the appointment date (yyyy-mm-dd): ");
                    fgets(appointments[num_appointments].date, 11, stdin);
                    appointments[num_appointments].date[strcspn(appointments[num_appointments].date, "\n")] = '\0';  // Remove trailing newline
                    
                    printf("Enter the appointment time (hh:mm AM/PM): ");
                    fgets(appointments[num_appointments].time, 10, stdin);
                    appointments[num_appointments].time[strcspn(appointments[num_appointments].time, "\n")] = '\0';  // Remove trailing newline
                    
                    printf("Enter the patient's name: ");
                    fgets(appointments[num_appointments].name, 100, stdin);
                    appointments[num_appointments].name[strcspn(appointments[num_appointments].name, "\n")] = '\0';  // Remove trailing newline
                    
                    printf("Enter the purpose of the appointment: ");
                    fgets(appointments[num_appointments].purpose, 500, stdin);
                    appointments[num_appointments].purpose[strcspn(appointments[num_appointments].purpose, "\n")] = '\0';  // Remove trailing newline
                    
                    printf("\nAppointment has been scheduled successfully!\n");
                    num_appointments++;
                } else {
                    printf("\nSorry, you cannot schedule more than 10 appointments.\n");
                }
                break;
            
            case 2:
                // Check if there are any appointments to view
                if (num_appointments == 0) {
                    printf("\nThere are no appointments scheduled.\n");
                } else {
                    // Display all scheduled appointments
                    printf("\n================ SCHEDULED APPOINTMENTS ================\n");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("\nAppointment %d\n", i+1);
                        printf("Date: %s\n", appointments[i].date);
                        printf("Time: %s\n", appointments[i].time);
                        printf("Patient Name: %s\n", appointments[i].name);
                        printf("Purpose: %s\n", appointments[i].purpose);
                    }
                }
                break;
            
            case 3:
                printf("\nThank you for using the Appointment Scheduler. Goodbye!\n");
                break;
            
            default:
                printf("\nInvalid choice, please try again.\n");
        }
        
    } while (choice != 3);
    
    return 0;
}