//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Struct for appointment
struct Appointment {
    int appointment_id;
    char* name;
    char* email;
    int start_time;
    int end_time;
    int duration;
};

// Function to print appointment details
void print_appointment(struct Appointment appointment) {
    printf("Appointment ID: %d\n", appointment.appointment_id);
    printf("Name: %s\n", appointment.name);
    printf("Email: %s\n", appointment.email);
    printf("Start Time: %d\n", appointment.start_time);
    printf("End Time: %d\n", appointment.end_time);
    printf("Duration: %d\n", appointment.duration);
}

// Function to create appointment
void create_appointment(struct Appointment* appointment) {
    printf("Enter appointment details:\n");
    printf("Appointment ID: ");
    scanf("%d", &appointment->appointment_id);
    printf("Name: ");
    scanf("%s", appointment->name);
    printf("Email: ");
    scanf("%s", appointment->email);
    printf("Start Time: ");
    scanf("%d", &appointment->start_time);
    printf("End Time: ");
    scanf("%d", &appointment->end_time);
    printf("Duration: ");
    scanf("%d", &appointment->duration);
}

// Function to display appointment
void display_appointment(struct Appointment appointment) {
    printf("Appointment Details:\n");
    printf("Appointment ID: %d\n", appointment.appointment_id);
    printf("Name: %s\n", appointment.name);
    printf("Email: %s\n", appointment.email);
    printf("Start Time: %d\n", appointment.start_time);
    printf("End Time: %d\n", appointment.end_time);
    printf("Duration: %d\n", appointment.duration);
}

// Function to update appointment
void update_appointment(struct Appointment* appointment) {
    printf("Enter updated appointment details:\n");
    printf("Appointment ID: ");
    scanf("%d", &appointment->appointment_id);
    printf("Name: ");
    scanf("%s", appointment->name);
    printf("Email: ");
    scanf("%s", appointment->email);
    printf("Start Time: ");
    scanf("%d", &appointment->start_time);
    printf("End Time: ");
    scanf("%d", &appointment->end_time);
    printf("Duration: ");
    scanf("%d", &appointment->duration);
}

// Function to delete appointment
void delete_appointment(struct Appointment* appointment) {
    printf("Enter appointment ID to delete: ");
    int appointment_id;
    scanf("%d", &appointment_id);
    for (int i = 0; i < appointment_id; i++) {
        if (appointment[i].appointment_id == appointment_id) {
            appointment[i].appointment_id = 0;
            appointment[i].name = NULL;
            appointment[i].email = NULL;
            appointment[i].start_time = 0;
            appointment[i].end_time = 0;
            appointment[i].duration = 0;
            break;
        }
    }
}

int main() {
    // Create an appointment
    struct Appointment appointment;
    create_appointment(&appointment);

    // Display the appointment
    display_appointment(appointment);

    // Update the appointment
    update_appointment(&appointment);

    // Display the updated appointment
    display_appointment(appointment);

    // Delete the appointment
    delete_appointment(&appointment);

    return 0;
}