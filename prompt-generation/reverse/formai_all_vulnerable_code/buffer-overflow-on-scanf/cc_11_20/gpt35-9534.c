//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100

// Define a struct to hold appointment information
typedef struct {
    char name[50];
    char date[20];
    char time[10];
} Appointment;

int main() {
    // Declare an array of Appointments with a maximum size
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    // Display menu and prompt user for input
    while (true) {
        printf("\n===== Appointment Scheduler =====\n");
        printf("1. View all Appointments\n");
        printf("2. Add an Appointment\n");
        printf("3. Remove an Appointment\n");
        printf("4. Exit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        // Handle user input
        switch (choice) {
            case 1:
                printf("\n===== All Appointments =====\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("Name: %s\n", appointments[i].name);
                    printf("Date: %s\n", appointments[i].date);
                    printf("Time: %s\n\n", appointments[i].time);
                }
                break;

            case 2:
                if (num_appointments == MAX_APPOINTMENTS) {
                    printf("\nScheduler is already full!\n");
                    break;
                }
                // Prompt user for Appointment information and add to array
                printf("\nEnter Name: ");
                scanf("%s", appointments[num_appointments].name);
                printf("Enter Date (MM/DD/YYYY): ");
                scanf("%s", appointments[num_appointments].date);
                printf("Enter Time (HH:MM AM/PM): ");
                scanf("%s", appointments[num_appointments].time);
                num_appointments++;
                printf("\nAppointment Added!\n");
                break;

            case 3:
                if (num_appointments == 0) {
                    printf("\nScheduler is already empty!\n");
                    break;
                }
                // Prompt user for Appointment to remove and shift array elements
                printf("\nEnter Name to remove Appointment: ");
                char remove_name[50];
                scanf("%s", remove_name);
                for (int i = 0; i < num_appointments; i++) {
                    if (strcmp(remove_name, appointments[i].name) == 0) {
                        for (int j = i; j < num_appointments - 1; j++) {
                            appointments[j] = appointments[j+1];
                        }
                        num_appointments--;
                        printf("\nAppointment Removed!\n");
                        break;
                    }
                }
                break;

            case 4:
                printf("\nExiting Scheduler...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("\nInvalid Input...\n");
                break;
        }
    }

    return 0;
}