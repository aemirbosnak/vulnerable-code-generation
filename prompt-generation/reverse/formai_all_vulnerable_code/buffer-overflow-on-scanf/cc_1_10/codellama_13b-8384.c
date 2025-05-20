//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

// Struct to represent an appointment
typedef struct {
    char name[50];
    time_t date;
    char location[50];
    char notes[100];
} appointment_t;

// Function to display the appointment details
void display_appointment(appointment_t appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Date: %s", ctime(&appointment.date));
    printf("Location: %s\n", appointment.location);
    printf("Notes: %s\n", appointment.notes);
}

// Function to add a new appointment
void add_appointment(appointment_t *appointments, int *num_appointments) {
    if (*num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments\n", MAX_APPOINTMENTS);
        return;
    }

    printf("Enter appointment details:\n");
    printf("Name: ");
    scanf("%s", appointments[*num_appointments].name);
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", appointments[*num_appointments].date);
    printf("Location: ");
    scanf("%s", appointments[*num_appointments].location);
    printf("Notes: ");
    scanf("%s", appointments[*num_appointments].notes);

    *num_appointments += 1;
}

// Function to remove an appointment
void remove_appointment(appointment_t *appointments, int *num_appointments) {
    if (*num_appointments <= 0) {
        printf("Error: No appointments to remove\n");
        return;
    }

    int index;
    printf("Enter the index of the appointment to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_appointments) {
        printf("Error: Invalid index\n");
        return;
    }

    for (int i = index; i < *num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    *num_appointments -= 1;
}

// Function to edit an appointment
void edit_appointment(appointment_t *appointments, int *num_appointments) {
    if (*num_appointments <= 0) {
        printf("Error: No appointments to edit\n");
        return;
    }

    int index;
    printf("Enter the index of the appointment to edit: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_appointments) {
        printf("Error: Invalid index\n");
        return;
    }

    printf("Enter the new appointment details:\n");
    printf("Name: ");
    scanf("%s", appointments[index].name);
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", appointments[index].date);
    printf("Location: ");
    scanf("%s", appointments[index].location);
    printf("Notes: ");
    scanf("%s", appointments[index].notes);
}

int main() {
    int num_appointments = 0;
    appointment_t appointments[MAX_APPOINTMENTS];

    while (1) {
        int choice;
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. Edit appointment\n");
        printf("4. Display appointments\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                remove_appointment(appointments, &num_appointments);
                break;
            case 3:
                edit_appointment(appointments, &num_appointments);
                break;
            case 4:
                for (int i = 0; i < num_appointments; i++) {
                    display_appointment(appointments[i]);
                }
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}