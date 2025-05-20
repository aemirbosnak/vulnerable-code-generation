//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store appointment information
struct appointment {
    char name[50];
    int hour;
    int minute;
};

// Define an array of appointments
struct appointment appointments[10];

// Define a function to create a new appointment
void createAppointment(int index) {
    char name[50];
    int hour, minute;
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter Minute (0-59): ");
    scanf("%d", &minute);
    strcpy(appointments[index].name, name);
    appointments[index].hour = hour;
    appointments[index].minute = minute;
}

// Define a function to display all appointments
void displayAppointments() {
    printf("Appointments for Today:\n");
    for (int i = 0; i < 10; i++) {
        if (strlen(appointments[i].name) > 0) {
            printf("%d:%02d - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].name);
        }
    }
}

int main() {
    char input;
    int index = 0;
    // Main loop
    do {
        printf("---------------\nAppointment Scheduler\n---------------\n");
        printf("1. Create Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &input);
        switch (input) {
            case '1':
                if (index < 10) {
                    createAppointment(index);
                    index++;
                } else {
                    printf("Sorry, you have reached the maximum number of appointments.\n");
                }
                break;
            case '2':
                displayAppointments();
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    } while (input != '3');
    return 0;
}