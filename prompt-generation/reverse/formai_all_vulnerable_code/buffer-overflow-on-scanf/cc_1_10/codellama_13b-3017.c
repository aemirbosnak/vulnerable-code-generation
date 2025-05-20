//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Structure to store appointment details
struct appointment {
    int id;
    char name[50];
    char date[11];
    char time[6];
    char location[50];
};

// Function to create a new appointment
void create_appointment(struct appointment *appointment) {
    appointment->id = 0;
    strcpy(appointment->name, "");
    strcpy(appointment->date, "");
    strcpy(appointment->time, "");
    strcpy(appointment->location, "");
}

// Function to add a new appointment
void add_appointment(struct appointment *appointment) {
    appointment->id++;
    printf("Enter appointment name: ");
    scanf("%s", appointment->name);
    printf("Enter appointment date (DD-MM-YYYY): ");
    scanf("%s", appointment->date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appointment->time);
    printf("Enter appointment location: ");
    scanf("%s", appointment->location);
}

// Function to display all appointments
void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointment Scheduler\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s (%s %s) at %s\n", appointments[i].id, appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].location);
    }
}

// Function to delete an appointment
void delete_appointment(struct appointment *appointments, int num_appointments, int id) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].id == id) {
            appointments[i].id = 0;
            strcpy(appointments[i].name, "");
            strcpy(appointments[i].date, "");
            strcpy(appointments[i].time, "");
            strcpy(appointments[i].location, "");
            break;
        }
    }
}

int main() {
    struct appointment appointments[50];
    int num_appointments = 0;

    // Create a new appointment
    create_appointment(&appointments[num_appointments]);

    // Add a new appointment
    add_appointment(&appointments[num_appointments]);
    num_appointments++;

    // Display all appointments
    display_appointments(appointments, num_appointments);

    // Delete an appointment
    int id;
    printf("Enter appointment id to delete: ");
    scanf("%d", &id);
    delete_appointment(appointments, num_appointments, id);

    // Display all appointments
    display_appointments(appointments, num_appointments);

    return 0;
}