//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment struct
struct appointment {
    char name[50];
    char date[10];
    char time[10];
    char duration[5];
};

// Define the appointment list struct
struct appointment_list {
    struct appointment *appointments;
    int num_appointments;
};

// Function to add an appointment to the list
void add_appointment(struct appointment_list *appointment_list, struct appointment appointment) {
    appointment_list->appointments = realloc(appointment_list->appointments, (appointment_list->num_appointments + 1) * sizeof(struct appointment));
    appointment_list->appointments[appointment_list->num_appointments] = appointment;
    appointment_list->num_appointments++;
}

// Function to remove an appointment from the list
void remove_appointment(struct appointment_list *appointment_list, int index) {
    if (index >= 0 && index < appointment_list->num_appointments) {
        for (int i = index; i < appointment_list->num_appointments - 1; i++) {
            appointment_list->appointments[i] = appointment_list->appointments[i + 1];
        }
        appointment_list->num_appointments--;
    }
}

// Function to print the appointment list
void print_appointment_list(struct appointment_list *appointment_list) {
    printf("Appointment List:\n");
    for (int i = 0; i < appointment_list->num_appointments; i++) {
        printf("%s, %s, %s, %s\n", appointment_list->appointments[i].name, appointment_list->appointments[i].date, appointment_list->appointments[i].time, appointment_list->appointments[i].duration);
    }
}

int main() {
    // Create an appointment list
    struct appointment_list appointment_list;
    appointment_list.appointments = NULL;
    appointment_list.num_appointments = 0;

    // Add appointments to the list
    struct appointment appointment1;
    strcpy(appointment1.name, "John Doe");
    strcpy(appointment1.date, "2022-03-01");
    strcpy(appointment1.time, "10:00");
    strcpy(appointment1.duration, "30");
    add_appointment(&appointment_list, appointment1);

    struct appointment appointment2;
    strcpy(appointment2.name, "Jane Doe");
    strcpy(appointment2.date, "2022-03-02");
    strcpy(appointment2.time, "12:00");
    strcpy(appointment2.duration, "60");
    add_appointment(&appointment_list, appointment2);

    // Remove an appointment from the list
    remove_appointment(&appointment_list, 0);

    // Print the appointment list
    print_appointment_list(&appointment_list);

    return 0;
}