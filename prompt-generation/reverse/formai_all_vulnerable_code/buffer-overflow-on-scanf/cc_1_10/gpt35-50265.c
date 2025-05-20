//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

void print_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. List appointments\n");
    printf("2. Add appointment\n");
    printf("3. Remove appointment\n");
    printf("4. Exit\n");
}

void list_appointments(Appointment appointments[], int count) {
    printf("Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %02d:%02d %s\n", i + 1, appointments[i].hour, appointments[i].minute, appointments[i].name);
    }
}

void add_appointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Cannot add appointment, maximum number of appointments reached.\n");
        return;
    }
    Appointment new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter hour (0-23): ");
    scanf("%d", &new_appointment.hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &new_appointment.minute);
    appointments[*count] = new_appointment;
    (*count)++;
}

void remove_appointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("Appointment list is empty.\n");
        return;
    }
    int selection;
    list_appointments(appointments, *count);
    printf("Select appointment to remove: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > *count) {
        printf("Invalid selection.\n");
        return;
    }
    for (int i = selection - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;
    while (true) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_appointments(appointments, count);
                break;
            case 2:
                add_appointment(appointments, &count);
                break;
            case 3:
                remove_appointment(appointments, &count);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}