//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    int day; // 1-31
    int month; // 1-12
    int year; // e.g., 2023
    int hour; // 0-23
    int minute; // 0-59
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment(char* description, int day, int month, int year, int hour, int minute) {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Error: Appointment limit reached!\n");
        return;
    }
    strcpy(appointments[appointment_count].description, description);
    appointments[appointment_count].day = day;
    appointments[appointment_count].month = month;
    appointments[appointment_count].year = year;
    appointments[appointment_count].hour = hour;
    appointments[appointment_count].minute = minute;
    appointment_count++;
    printf("Appointment added: %s on %02d/%02d/%04d at %02d:%02d\n", 
           description, day, month, year, hour, minute);
}

void print_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d: %s on %02d/%02d/%04d at %02d:%02d\n",
               i + 1, appointments[i].description, 
               appointments[i].day, appointments[i].month, 
               appointments[i].year, appointments[i].hour, 
               appointments[i].minute);
    }
}

void delete_appointment(int index) {
    if (index < 1 || index > appointment_count) {
        printf("Error: Invalid appointment index!\n");
        return;
    }
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment %d deleted.\n", index);
}

void clear_appointments() {
    appointment_count = 0;
    printf("All appointments cleared.\n");
}

void show_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Clear All Appointments\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char description[MAX_DESC_LENGTH];
            int day, month, year, hour, minute;

            printf("Enter description: ");
            getchar(); // Consume newline
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline character

            printf("Enter day (1-31): ");
            scanf("%d", &day);
            printf("Enter month (1-12): ");
            scanf("%d", &month);
            printf("Enter year (e.g., 2023): ");
            scanf("%d", &year);
            printf("Enter hour (0-23): ");
            scanf("%d", &hour);
            printf("Enter minute (0-59): ");
            scanf("%d", &minute);

            add_appointment(description, day, month, year, hour, minute);
        } 
        else if (choice == 2) {
            print_appointments();
        } 
        else if (choice == 3) {
            int index;
            printf("Enter appointment number to delete: ");
            scanf("%d", &index);
            delete_appointment(index);
        } 
        else if (choice == 4) {
            clear_appointments();
        } 
        else if (choice == 5) {
            printf("Exiting the scheduler. Goodbye!\n");
            break;
        } 
        else {
            printf("Error: Invalid choice! Please try again.\n");
        }
    }

    return 0;
}