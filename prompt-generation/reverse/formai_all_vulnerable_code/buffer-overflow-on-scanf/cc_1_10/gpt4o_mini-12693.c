//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DATE_LENGTH 11
#define TIME_LENGTH 6
#define DESCRIPTION_LENGTH 100

typedef struct {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    char description[DESCRIPTION_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("\n🎉 Welcome to the Happy Appointment Scheduler! 🎉\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete an Appointment\n");
    printf("4. Exit\n");
    printf("What would you like to do? (Enter a number): ");
}

void schedule_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("🎈 Oh no! The appointment list is full! 🎈\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", new_appointment.time);
    printf("Enter appointment description: ");
    getchar(); // Consume newline
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("🎉 Appointment scheduled successfully! 🎉\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("😢 No appointments found! 😢\n");
        return;
    }

    printf("\n📅 Your Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] at [%s] - %s\n", i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("😢 No appointments to delete! 😢\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("🚫 Invalid appointment number! 🚫\n");
        return;
    }

    // Shift appointments down to fill the gap
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("🎉 Appointment deleted successfully! 🎉\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("🎈 Thank you for using the Happy Appointment Scheduler! Goodbye! 🎈\n");
                return 0;
            default:
                printf("🚫 Please choose a valid option! 🚫\n");
                break;
        }
    }

    return 0;
}