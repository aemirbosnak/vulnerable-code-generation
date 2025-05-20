//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_FORMAT "YYYY-MM-DD HH:MM"

typedef struct {
    char title[50];
    char date[20];
    char time[10];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_input_buffer() {
    while (getchar() != '\n');
}

void print_appointments() {
    printf("\n=== Scheduled Appointments ===\n");
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
    } else {
        for (int i = 0; i < appointment_count; i++) {
            printf("%d. [%s] - %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
        }
    }
    printf("==============================\n");
}

int find_appointment(const char *title) {
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(appointments[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Uh-oh! Maximum appointment limit reached!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    fgets(new_appointment.title, sizeof(new_appointment.title), stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0;  // Remove newline

    printf("Enter appointment date (format: YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0;

    printf("Enter appointment time (format: HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0;

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Appointment Added Successfully! Amazing!!\n");
}

void remove_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to remove! What a bummer!\n");
        return;
    }

    char title[50];
    printf("Enter appointment title to remove: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;

    int index = find_appointment(title);
    if (index == -1) {
        printf("No appointment found with title '%s'. Are you kidding me?\n", title);
    } else {
        for (int i = index; i < appointment_count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointment_count--;
        printf("Appointment '%s' removed successfully! Can you believe it?\n", title);
    }
}

void menu() {
    int choice;

    do {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. View Appointments\n");
        printf("0. Exit\n");
        printf("==============================\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clear_input_buffer();  // Clear the buffer after reading integer

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                remove_appointment();
                break;
            case 3:
                print_appointments();
                break;
            case 0:
                printf("Exiting... What an eventful day!\n");
                break;
            default:
                printf("Invalid option, please try again! Oh no!\n");
        }
    } while (choice != 0);
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Prepare yourself for a world of organized chaos!\n");
    menu();

    return 0;
}