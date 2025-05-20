//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11 // YYYY-MM-DD
#define TIME_LENGTH 6  // HH:MM

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void clear_console();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
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
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    clear_console();
    printf("===================================\n");
    printf("       Appointment Scheduler       \n");
    printf("===================================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

void clear_console() {
    printf("\033[H\033[J"); // ANSI Escape code to clear the console
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter the name for the appointment: ");
    getchar(); // to consume newline from previous input
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    strtok(new_appointment.name, "\n"); // remove newline character

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);

    printf("Enter the time (HH:MM): ");
    scanf("%s", new_appointment.time);

    appointments[appointment_count++] = new_appointment;

    printf("Appointment added successfully!\n");
    printf("Press Enter to continue...");
    getchar(); getchar(); // wait for user to press Enter
}

void view_appointments() {
    clear_console();
    printf("===================================\n");
    printf("         Scheduled Appointments    \n");
    printf("===================================\n");

    if (appointment_count == 0) {
        printf("No appointments scheduled!\n");
    } else {
        for (int i = 0; i < appointment_count; i++) {
            printf("Appointment %d:\n", i + 1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("-------------------------------\n");
        }
    }
    
    printf("Press Enter to continue...");
    getchar(); getchar(); // wait for user to press Enter
}

void delete_appointment() {
    int index;

    view_appointments();
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
    } else {
        // Shift appointments down
        for (int i = index - 1; i < appointment_count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointment_count--;
        printf("Appointment deleted successfully!\n");
    }

    printf("Press Enter to continue...");
    getchar(); getchar(); // wait for user to press Enter
}