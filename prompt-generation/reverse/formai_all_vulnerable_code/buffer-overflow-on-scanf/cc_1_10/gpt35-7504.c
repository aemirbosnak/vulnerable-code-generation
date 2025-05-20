//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Date date;
} Appointment;

bool validate_date(Date date) {
    // Check if day is valid
    if (date.day < 1 || date.day > 31) {
        return false;
    }

    // Check if month is valid
    if (date.month < 1 || date.month > 12) {
        return false;
    }

    // Check if year is valid
    if (date.year < 1900 || date.year > 2100) {
        return false;
    }

    // Check if day is valid for given month
    if (date.month == 2 && (date.day < 1 || date.day > 28)) {
        return false;
    } else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && (date.day < 1 || date.day > 30)) {
        return false;
    }

    // All checks passed
    return true;
}

void print_appointment(Appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Date: %d/%d/%d\n", appt.date.day, appt.date.month, appt.date.year);
}

int main() {
    Appointment appts[MAX_APPOINTMENTS];
    int num_appts = 0;

    while (true) {
        // Print menu
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");

        // Get user choice
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add appointment
                if (num_appts < MAX_APPOINTMENTS) {
                    // Get name
                    printf("Enter name: ");
                    scanf("%s", appts[num_appts].name);

                    // Get date
                    printf("Enter date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d", &appts[num_appts].date.day, &appts[num_appts].date.month, &appts[num_appts].date.year);

                    // Validate date
                    if (!validate_date(appts[num_appts].date)) {
                        printf("Invalid date entered. Please try again.\n");
                        break;
                    }

                    // Increment number of appointments
                    num_appts++;
                } else {
                    printf("Maximum number of appointments reached.\n");
                }

                break;

            case 2:
                // Print all appointments
                if (num_appts > 0) {
                    printf("\nAll Appointments:\n");

                    for (int i = 0; i < num_appts; i++) {
                        print_appointment(appts[i]);
                        printf("\n");
                    }
                } else {
                    printf("No appointments to display.\n");
                }

                break;

            case 3:
                // Exit program
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}