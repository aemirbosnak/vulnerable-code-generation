//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10
#define NAME_LEN 50
#define DATE_LEN 15
#define TIME_LEN 10

typedef struct appointment {
    char name[NAME_LEN];
    char date[DATE_LEN];
    char time[TIME_LEN];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Exit\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment scheduler is full! Please cancel an existing appointment to add a new one.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", appointments[appointment_count].name);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", appointments[appointment_count].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[appointment_count].time);
    appointment_count++;
    printf("Appointment added successfully!\n");
}

void cancel_appointment() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Enter appointment number to cancel (1-%d): ", appointment_count);
    int appointment_number;
    scanf("%d", &appointment_number);
    if (appointment_number < 1 || appointment_number > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }
    for (int i = appointment_number - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment cancelled successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("List of Appointments\n");
    printf("Appointment Number\tName\tDate\tTime\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    bool exit_program = false;
    while (!exit_program) {
        display_menu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                cancel_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                exit_program = true;
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}