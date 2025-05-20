//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 20

// A struct to represent an appointment
typedef struct {
    char name[MAX_NAME_LENGTH];  // Name of the person who has the appointment
    int hour;  // Hour of the appointment (0-23)
    int minute;  // Minute of the appointment (0-59)
} Appointment;

// An array to store all appointments
Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;  // The number of appointments currently in the array

// Function to add a new appointment
void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Cannot add appointment - scheduler is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);
    num_appointments++;
    printf("Appointment added!\n");
}

// Function to remove an appointment by name
void remove_appointment() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to remove: ");
    scanf("%s", name);
    bool found = false;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            found = true;
            // Shift appointments after the removed appointment back one index
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            num_appointments--;
            printf("Appointment removed!\n");
            break;
        }
    }
    if (!found) {
        printf("Name not found in scheduler.\n");
    }
}

// Function to print all appointments
void print_appointments() {
    if (num_appointments == 0) {
        printf("Scheduler is empty.\n");
        return;
    }
    printf("----- Appointments -----\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %02d:%02d\n", appointments[i].name, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    printf("Welcome to the appointment scheduler!\n");

    // Main program loop
    while (true) {
        printf("Select an option:\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. Print appointments\n");
        printf("4. Exit program\n");
        char choice;
        scanf(" %c", &choice);  // Get first character of input
        switch(choice) {
            case '1':
                add_appointment();
                break;
            case '2':
                remove_appointment();
                break;
            case '3':
                print_appointments();
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}