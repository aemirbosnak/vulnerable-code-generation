//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} appointment_t;

// Function to compare two appointments by their start time
int compare_appointments(const void *a, const void *b) {
    const appointment_t *appt1 = (const appointment_t *)a;
    const appointment_t *appt2 = (const appointment_t *)b;

    return appt1->start_time - appt2->start_time;
}

// Function to print an appointment
void print_appointment(const appointment_t *appt) {
    printf("%s\n", appt->name);
    printf("%s\n", appt->description);
    printf("Start time: %s", ctime(&appt->start_time));
    printf("End time: %s", ctime(&appt->end_time));
}

// Function to get an appointment from the user
void get_appointment(appointment_t *appt) {
    printf("Enter appointment name: ");
    scanf("%s", appt->name);

    printf("Enter appointment description: ");
    scanf("%s", appt->description);

    printf("Enter appointment start time (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", appt->start_time);

    printf("Enter appointment end time (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", appt->end_time);
}

// Function to add an appointment to the schedule
void add_appointment(appointment_t *schedule, int *num_appointments) {
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("Error: Schedule is full.\n");
        return;
    }

    get_appointment(&schedule[*num_appointments]);
    (*num_appointments)++;
}

// Function to remove an appointment from the schedule
void remove_appointment(appointment_t *schedule, int *num_appointments) {
    int i;

    printf("Enter the name of the appointment to remove: ");
    char name[50];
    scanf("%s", name);

    for (i = 0; i < *num_appointments; i++) {
        if (strcmp(schedule[i].name, name) == 0) {
            break;
        }
    }

    if (i == *num_appointments) {
        printf("Error: Appointment not found.\n");
        return;
    }

    for (i; i < *num_appointments - 1; i++) {
        schedule[i] = schedule[i + 1];
    }

    (*num_appointments)--;
}

// Function to print the schedule
void print_schedule(const appointment_t *schedule, int num_appointments) {
    int i;

    printf("Schedule:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(&schedule[i]);
        printf("\n");
    }
}

// Function to main menu
void main_menu() {
    printf("1. Add an appointment\n");
    printf("2. Remove an appointment\n");
    printf("3. Print the schedule\n");
    printf("4. Quit\n");
}

// Main function
int main() {
    int choice;
    int num_appointments = 0;
    appointment_t schedule[MAX_APPOINTMENTS];

    while (1) {
        main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(schedule, &num_appointments);
                break;
            case 2:
                remove_appointment(schedule, &num_appointments);
                break;
            case 3:
                print_schedule(schedule, num_appointments);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}