//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 20 // Maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 50 // Maximum length of each person's name

typedef struct {
    int day;
    int hour;
    char name[MAX_NAME_LENGTH];
} Appointment;

int num_appointments = 0; // Number of currently scheduled appointments
Appointment appointments[MAX_APPOINTMENTS]; // Array of scheduled appointments

// Function to print all currently scheduled appointments
void printAppointments() {
    printf("Current Appointments:\n");
    printf("---------------------\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d/%d @ %d:00 - %s\n", appointments[i].day, i+1, appointments[i].hour, appointments[i].name);
    }
    printf("\n");
}

// Function to check if a provided appointment slot is already occupied
int isSlotOccupied(int day, int hour) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].day == day && appointments[i].hour == hour) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int choice = 0, day = 0, hour = 0;
    char name[MAX_NAME_LENGTH];

    while (choice != 4) {
        // Print menu options and get user choice
        printf("C Appointment Scheduler\n");
        printf("1. Schedule Appointment\n");
        printf("2. Cancel Appointment\n");
        printf("3. View Appointments\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Schedule an appointment
                printf("Enter a day (1-31): ");
                scanf("%d", &day);
                printf("Enter an hour (0-23): ");
                scanf("%d", &hour);
                
                // Check if slot is already occupied
                if (isSlotOccupied(day, hour)) {
                    printf("This appointment slot is already occupied.\n\n");
                    break;
                }
                
                // Get name of person
                printf("Enter your name: ");
                scanf("%s", name);
                strcpy(appointments[num_appointments].name, name);
                appointments[num_appointments].day = day;
                appointments[num_appointments].hour = hour;
                num_appointments++;
                printf("Appointment scheduled!\n\n");
                break;
            case 2:
                // Cancel an appointment
                printf("Enter a day (1-31): ");
                scanf("%d", &day);
                printf("Enter an hour (0-23): ");
                scanf("%d", &hour);

                // Find appointment and remove from array
                for (int i = 0; i < num_appointments; i++) {
                    if (appointments[i].day == day && appointments[i].hour == hour) {
                        for (int j = i; j < num_appointments-1; j++) {
                            appointments[j] = appointments[j+1];
                        }
                        num_appointments--;
                        printf("Appointment canceled.\n\n");
                        break;
                    }
                }
                break;
            case 3:
                // View all currently scheduled appointments
                printAppointments();
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}