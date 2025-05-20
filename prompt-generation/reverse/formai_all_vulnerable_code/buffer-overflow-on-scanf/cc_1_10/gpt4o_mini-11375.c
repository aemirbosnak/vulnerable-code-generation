//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_SIZE 100

typedef struct {
    char description[DESCRIPTION_SIZE];
    int day;
    int month;
    int year;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void display_menu();

int main() {
    int choice;

    do {
        display_menu();
        printf("Choose wisely (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("The end of our riddle... until next time!\n");
                break;
            default:
                printf("Beware, a wrong choice can cause a time twist!\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Alas! The calendar is full, no more appointments can be added.\n");
        return;
    }

    Appointment new_appointment;
    printf("What shall the appointment be? (Riddle me the description!) ");
    getchar(); // Consume the newline character
    fgets(new_appointment.description, DESCRIPTION_SIZE, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("When will it occur? Tell me the day (1-31): ");
    scanf("%d", &new_appointment.day);
    printf("What month shall it grace? (1-12): ");
    scanf("%d", &new_appointment.month);
    printf("And the year? (e.g. 2023): ");
    scanf("%d", &new_appointment.year);

    appointments[appointment_count++] = new_appointment;
    printf("A new appointment has been carved in the fabric of time!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("The void is empty, no appointments to view...\n");
        return;
    }

    printf("\n=== Your Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %02d/%02d/%04d\n", 
            i + 1, 
            appointments[i].description, 
            appointments[i].day, 
            appointments[i].month, 
            appointments[i].year);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("You cannot erase what does not exist!\n");
        return;
    }

    int index;
    printf("Which appointment shall vanish (1 to %d)? ", appointment_count);
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Beware! That choice is out of bounds!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("The appointment has indeed vanished into the ether!\n");
}