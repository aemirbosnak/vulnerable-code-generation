//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[MAX_DESC_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clear_buffer() {
    while (getchar() != '\n');
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &new_appointment.day, &new_appointment.month, &new_appointment.year);
    printf("Enter time (hh mm, 24-hour format): ");
    scanf("%d %d", &new_appointment.hour, &new_appointment.minute);
    clear_buffer();
    printf("Enter description: ");
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = '\0'; // Remove newline

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void list_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment ap = appointments[i];
        printf("%d. %02d/%02d/%04d %02d:%02d - %s\n", 
            i + 1, ap.day, ap.month, ap.year, ap.hour, ap.minute, ap.description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    list_appointments();
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    clear_buffer();

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

void save_appointments_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        Appointment ap = appointments[i];
        fprintf(file, "%02d/%02d/%04d %02d:%02d %s\n", 
            ap.day, ap.month, ap.year, ap.hour, ap.minute, ap.description);
    }
    fclose(file);
    printf("Appointments saved to %s\n", filename);
}

void load_appointments_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No saved appointments found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d/%d/%d %d:%d %[^\n]", 
                  &appointments[appointment_count].day,
                  &appointments[appointment_count].month,
                  &appointments[appointment_count].year,
                  &appointments[appointment_count].hour,
                  &appointments[appointment_count].minute,
                  appointments[appointment_count].description) == 6) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) break;
    }
    fclose(file);
    printf("Appointments loaded from %s\n", filename);
}

void show_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    const char *filename = "appointments.txt";
    load_appointments_from_file(filename);

    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                save_appointments_to_file(filename);
                break;
            case 5:
                load_appointments_from_file(filename);
                break;
            case 6:
                save_appointments_to_file(filename);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}