//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
// medieval_appointment_scheduler.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
struct Appointment {
    char* name;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

// Define the appointment list structure
struct AppointmentList {
    struct Appointment* appointments;
    int num_appointments;
};

// Function to add an appointment to the list
void add_appointment(struct AppointmentList* list, char* name, int day, int month, int year, int hour, int minute) {
    // Allocate memory for the new appointment
    struct Appointment* appointment = malloc(sizeof(struct Appointment));
    appointment->name = name;
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;

    // Add the appointment to the list
    list->appointments = realloc(list->appointments, (list->num_appointments + 1) * sizeof(struct Appointment));
    list->appointments[list->num_appointments] = *appointment;
    list->num_appointments++;
}

// Function to remove an appointment from the list
void remove_appointment(struct AppointmentList* list, char* name, int day, int month, int year, int hour, int minute) {
    // Find the index of the appointment to remove
    int index = -1;
    for (int i = 0; i < list->num_appointments; i++) {
        if (strcmp(list->appointments[i].name, name) == 0 &&
            list->appointments[i].day == day &&
            list->appointments[i].month == month &&
            list->appointments[i].year == year &&
            list->appointments[i].hour == hour &&
            list->appointments[i].minute == minute) {
            index = i;
            break;
        }
    }

    // Remove the appointment from the list
    if (index != -1) {
        // Move all appointments after the removed appointment one position to the left
        for (int i = index; i < list->num_appointments - 1; i++) {
            list->appointments[i] = list->appointments[i + 1];
        }
        list->num_appointments--;
    }
}

// Function to print the appointment list
void print_appointment_list(struct AppointmentList* list) {
    printf("Appointment List:\n");
    for (int i = 0; i < list->num_appointments; i++) {
        printf("%d/%d/%d %d:%d - %s\n", list->appointments[i].day, list->appointments[i].month, list->appointments[i].year, list->appointments[i].hour, list->appointments[i].minute, list->appointments[i].name);
    }
}

int main() {
    // Create an appointment list
    struct AppointmentList list;
    list.appointments = malloc(0);
    list.num_appointments = 0;

    // Add some appointments to the list
    add_appointment(&list, "Meeting", 15, 12, 2022, 14, 30);
    add_appointment(&list, "Conference", 16, 12, 2022, 10, 0);
    add_appointment(&list, "Lunch", 16, 12, 2022, 12, 0);
    add_appointment(&list, "Dinner", 16, 12, 2022, 18, 0);

    // Print the appointment list
    print_appointment_list(&list);

    // Remove an appointment from the list
    remove_appointment(&list, "Meeting", 15, 12, 2022, 14, 30);

    // Print the appointment list again
    print_appointment_list(&list);

    // Free the appointment list
    free(list.appointments);

    return 0;
}