//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LEN 50
#define DESC_LEN 200

typedef struct {
    char name[NAME_LEN];
    char description[DESC_LEN];
    time_t appointment_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Paranoia sets in: Maximum appointment limit reached!\n");
        return;
    }

    Appointment new_appointment;
    printf("Securely enter the name of the person for the appointment: ");
    scanf(" %[^\n]", new_appointment.name);

    printf("Securely enter a description for the appointment: ");
    scanf(" %[^\n]", new_appointment.description);
    
    printf("Securely enter the date and time for the appointment (YYYY-MM-DD HH:MM): ");
    char date_time[20];
    scanf(" %[^\n]", date_time);
    
    struct tm tm;
    strptime(date_time, "%Y-%m-%d %H:%M", &tm);
    new_appointment.appointment_time = mktime(&tm);
    
    if (new_appointment.appointment_time == -1) {
        printf("Paranoia alert: Invalid date-time input!\n");
        return;
    }

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully (but can I trust this?)!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("Paranoid moment: No appointments stored!\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf(" %d: %s | %s | %s", i + 1, appointments[i].name, appointments[i].description, ctime(&(appointments[i].appointment_time)));
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("Paranoia haunting me: No appointments to delete!\n");
        return;
    }

    int index;
    printf("Provide the appointment number to delete (be certain!): ");
    scanf("%d", &index);
    if (index < 1 || index > appointment_count) {
        printf("A tinge of paranoia: Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment successfully deleted (I hope it was the right one!)\n");
}

void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Quit safely\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Choose an option (but can I trust my own choice?): ");
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
                printf("Quitting... but always double-checking!\n");
                break;
            default:
                printf("Paranoia strikes again: Invalid option selected!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}