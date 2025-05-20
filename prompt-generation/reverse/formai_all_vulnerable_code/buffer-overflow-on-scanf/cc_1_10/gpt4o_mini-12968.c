//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define DATE_LENGTH 11 // Format "YYYY-MM-DD"
#define TIME_LENGTH 6  // Format "HH:MM"

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Cannot add more appointments.\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter appointment name: ");
    scanf(" %[^\n]", new_appointment.name);
    printf("Enter appointment description: ");
    scanf(" %[^\n]", new_appointment.description);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", new_appointment.time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s (%s) on %s at %s\n", 
               i + 1, appointments[i].name, 
               appointments[i].description, 
               appointments[i].date, 
               appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void edit_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to edit.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the appointment number to edit: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    Appointment *appt = &appointments[index - 1];
    printf("Editing appointment: %s\n", appt->name);
    printf("Enter new name (or press enter to keep current): ");
    char temp[NAME_LENGTH];
    scanf(" %[^\n]", temp);
    if (strlen(temp) > 0) {
        strcpy(appt->name, temp);
    }
    
    printf("Enter new description (or press enter to keep current): ");
    scanf(" %[^\n]", temp);
    if (strlen(temp) > 0) {
        strcpy(appt->description, temp);
    }

    printf("Enter new date (YYYY-MM-DD) (or press enter to keep current): ");
    scanf("%s", temp);
    if (strlen(temp) > 0) {
        strcpy(appt->date, temp);
    }

    printf("Enter new time (HH:MM) (or press enter to keep current): ");
    scanf("%s", temp);
    if (strlen(temp) > 0) {
        strcpy(appt->time, temp);
    }

    printf("Appointment updated successfully!\n");
}

void show_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    do {
        show_menu();
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
                edit_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}