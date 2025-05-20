//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Time {
    int hour;
    int minute;
};

struct Appointment {
    char name[50];
    struct Time start_time;
    struct Time end_time;
};

int num_appointments = 0;
struct Appointment appointments[MAX_APPOINTMENTS];

// Function to add a new appointment to the list
void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached!\n");
        return;
    }
    printf("Enter the name of the appointment:\n");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter the start time (hh:mm):\n");
    scanf("%d:%d", &appointments[num_appointments].start_time.hour,
        &appointments[num_appointments].start_time.minute);
    printf("Enter the end time (hh:mm):\n");
    scanf("%d:%d", &appointments[num_appointments].end_time.hour,
        &appointments[num_appointments].end_time.minute);
    num_appointments++;
    printf("Appointment added successfully!\n");
}

// Function to print all the appointments
void print_appointments() {
    printf("List of appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %02d:%02d to %02d:%02d\n",
            appointments[i].name, appointments[i].start_time.hour,
            appointments[i].start_time.minute, appointments[i].end_time.hour,
            appointments[i].end_time.minute);
    }
}

// Function to check for overlapping time slots
bool check_overlap(struct Appointment* new_appointment) {
    for (int i = 0; i < num_appointments; i++) {
        if (new_appointment->start_time.hour < appointments[i].end_time.hour ||
            (new_appointment->start_time.hour == appointments[i].end_time.hour &&
            new_appointment->start_time.minute < appointments[i].end_time.minute)) {
            printf("Error! Overlapping time slot with %s.\n", appointments[i].name);
            return true;
        }
    }
    return false;
}

// Function to remove an appointment by name
void remove_appointment(char* name) {
    int index = -1;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Appointment not found!\n");
        return;
    }
    for (int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i+1];
    }
    num_appointments--;
    printf("Appointment removed successfully!\n");
}

int main() {
    int input;
    do {
        printf("Appointment Scheduler Menu:\n");
        printf("1. Add a new appointment\n");
        printf("2. Print all appointments\n");
        printf("3. Remove an appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice:\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                // Add a new appointment
                printf("\n");
                struct Appointment new_appointment;
                add_appointment(&new_appointment);
                if (!check_overlap(&new_appointment)) {
                    appointments[num_appointments++] = new_appointment;
                    printf("Appointment added successfully!\n");
                }
                break;
            case 2:
                // Print all appointments
                printf("\n");
                print_appointments();
                break;
            case 3:
                // Remove an appointment
                printf("\n");
                char name[50];
                printf("Enter the name of the appointment to remove:\n");
                scanf("%s", name);
                remove_appointment(name);
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    } while (input != 4);
    return 0;
}