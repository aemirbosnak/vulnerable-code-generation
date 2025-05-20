//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200
#define DATE_LENGTH 11 // Format: YYYY-MM-DD
#define TIME_LENGTH 6   // Format: HH:MM

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void add_appointment();
void view_appointments();
void delete_appointment();
void display_menu();

int main() {
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("We are grateful for your choice to manage your time wisely.\n");

    do {
        display_menu();
        printf("Please enter your choice: ");
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
                printf("Thank you for using the Appointment Scheduler! Have a great day!\n");
                break;
            default:
                printf("Thank you for your input, but that's not a valid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n--- Appointment Scheduler Menu ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------------\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("We are grateful for your enthusiasm, but we have reached the maximum number of appointments!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter name of appointment: ");
    getchar(); // consumes the newline character left by scanf
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    strtok(new_appointment.name, "\n"); // remove trailing newline

    printf("Enter description of appointment: ");
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
    strtok(new_appointment.description, "\n"); // remove trailing newline

    printf("Enter date of appointment (YYYY-MM-DD): ");
    fgets(new_appointment.date, DATE_LENGTH, stdin);
    strtok(new_appointment.date, "\n"); // remove trailing newline

    printf("Enter time of appointment (HH:MM): ");
    fgets(new_appointment.time, TIME_LENGTH, stdin);
    strtok(new_appointment.time, "\n"); // remove trailing newline

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("Your appointment has been successfully added! Thank you!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found. We appreciate your patience!\n");
        return;
    }

    printf("\n--- Your Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }
    printf("-------------------------\n");
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("We are sorry, but there are no appointments to delete. Thank you for your understanding!\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("We appreciate your attention to detail, but that's an invalid number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Your appointment was deleted successfully. We are grateful for your organization!\n");
}