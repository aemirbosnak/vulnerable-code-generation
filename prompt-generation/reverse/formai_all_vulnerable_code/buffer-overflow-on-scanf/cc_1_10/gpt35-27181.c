//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Define maximum number of appointments
#define MAX_APPOINTMENTS 20

// Struct for an appointment
typedef struct {
    char name[50];
    int hour;
    int minute;
} Appointment;

// Function to check if a given hour and minute is valid or not
int isValidTime(int hour, int minute) {
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return 0;
    }
    return 1;
}

// Function to display all appointments
void displayAppointments(Appointment appointments[], int count) {
    printf("Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s at %02d:%02d\n", i+1, appointments[i].name, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    // Array to store appointments
    Appointment appointments[MAX_APPOINTMENTS];
    // Count of appointments
    int count = 0;
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            if (count == MAX_APPOINTMENTS) {
                printf("Maximum number of appointments reached!\n");
                continue;
            }
            printf("\nEnter name of appointment: ");
            scanf("%s", appointments[count].name);
            int hour, minute;
            printf("Enter hour of appointment: ");
            scanf("%d", &hour);
            printf("Enter minute of appointment: ");
            scanf("%d", &minute);
            if (!isValidTime(hour, minute)) {
                printf("Invalid time!\n");
                continue;
            }
            appointments[count].hour = hour;
            appointments[count].minute = minute;
            count++;
            printf("Appointment added successfully!\n");
        } else if (choice == 2) {
            if (count == 0) {
                printf("No appointments found!\n");
                continue;
            }
            displayAppointments(appointments, count);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}