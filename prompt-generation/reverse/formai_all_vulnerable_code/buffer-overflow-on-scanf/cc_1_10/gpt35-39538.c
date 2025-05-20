//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 10

struct appointment {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
};

// Function prototype
void print_menu();

int main() {
    // Initialize array of appointments
    struct appointment appointments[MAX_APPOINTMENTS];
    int appointment_count = 0;

    // Keep running until user opts to exit
    int choice = -1;
    while (choice != 4) {
        // Print menu and get user choice
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add appointment
                if (appointment_count == MAX_APPOINTMENTS) {
                    printf("No more appointments can be added.\n");
                } else {
                    // Ask for name and time
                    printf("Enter name: ");
                    scanf("%s", appointments[appointment_count].name);
                    printf("Enter time: ");
                    scanf("%s", appointments[appointment_count].time);

                    // Increment appointment count
                    appointment_count++;
                }
                break;

            case 2:
                // View appointments
                if (appointment_count == 0) {
                    printf("No appointments found.\n");
                } else {
                    printf("Appointments:\n");

                    for (int i = 0; i < appointment_count; i++) {
                        printf("%d. Name: %s, Time: %s\n", i+1, appointments[i].name, appointments[i].time);
                    }
                }
                break;

            case 3:
                // Cancel appointment
                if (appointment_count == 0) {
                    printf("No appointments found.\n");
                } else {
                    char name[MAX_NAME_LENGTH];
                    printf("Enter name to cancel appointment: ");
                    scanf("%s", name);

                    // Use flag to indicate whether appointment was found and cancelled
                    int found = 0;

                    for (int i = 0; i < appointment_count; i++) {
                        if (strcmp(name, appointments[i].name) == 0) {
                            // Shift all appointments after the cancelled appointment up by one index
                            for (int j = i; j < appointment_count - 1; j++) {
                                strcpy(appointments[j].name, appointments[j+1].name);
                                strcpy(appointments[j].time, appointments[j+1].time);
                            }

                            // Decrement appointment count
                            appointment_count--;

                            // Set flag to indicate that appointment was found and cancelled
                            found = 1;

                            break;
                        }
                    }

                    if (found) {
                        printf("Appointment cancelled successfully.\n");
                    } else {
                        printf("Appointment not found.\n");
                    }
                }
                break;

            case 4:
                // Exit program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

// Prints menu for user to select option
void print_menu() {
    printf("\n\nAppointment Scheduler\n");
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}