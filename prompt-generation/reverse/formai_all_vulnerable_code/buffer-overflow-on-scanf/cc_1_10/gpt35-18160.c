//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char date[20];
    char time[20];
    char name[50];
    char contact[20];
};

void add_appointment(struct appointment *appointments, int *num_appointments);
void delete_appointment(struct appointment *appointments, int *num_appointments);
void show_appointments(struct appointment *appointments, int num_appointments);

int main() {
    struct appointment appointments[100];
    int num_appointments = 0;
    int choice;

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Show appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                delete_appointment(appointments, &num_appointments);
                break;
            case 3:
                show_appointments(appointments, num_appointments);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void add_appointment(struct appointment *appointments, int *num_appointments) {
    if (*num_appointments == 100) {
        printf("Cannot add more appointments\n");
        return;
    }

    struct appointment new_appointment;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", new_appointment.date);

    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", new_appointment.time);

    printf("Enter name: ");
    scanf("%s", new_appointment.name);

    printf("Enter contact number: ");
    scanf("%s", new_appointment.contact);

    appointments[*num_appointments] = new_appointment;
    *num_appointments = *num_appointments + 1;
}

void delete_appointment(struct appointment *appointments, int *num_appointments) {
    if (*num_appointments == 0) {
        printf("No appointments to delete\n");
        return;
    }

    char search_date[20];
    char search_time[20];
    char search_name[50];
    char search_contact[20];

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", search_date);

    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", search_time);

    printf("Enter name: ");
    scanf("%s", search_name);

    printf("Enter contact number: ");
    scanf("%s", search_contact);

    int index = -1;

    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].date, search_date) == 0 &&
            strcmp(appointments[i].time, search_time) == 0 &&
            strcmp(appointments[i].name, search_name) == 0 &&
            strcmp(appointments[i].contact, search_contact) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Appointment not found\n");
        return;
    }

    for (int i = index; i < *num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    *num_appointments = *num_appointments - 1;

    printf("Appointment deleted successfully\n");
}

void show_appointments(struct appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments to show\n");
        return;
    }

    printf("%-20s %-20s %-50s %-20s\n", "Date", "Time", "Name", "Contact");

    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-20s %-50s %-20s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].contact);
    }
}