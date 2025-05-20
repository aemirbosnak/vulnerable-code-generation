//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define DATE_FORMAT "%Y-%m-%d %H:%M"

// Structure to hold appointment information
typedef struct {
    char title[100];
    char date[20]; // YYYY-MM-DD HH:MM format
} Appointment;

// Global array to hold appointments
Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function declarations
void add_appointment();
void view_appointments();
void delete_appointment();
void save_appointments();
void load_appointments();
void clear_buffer();

// Main function
int main() {
    load_appointments();
    int choice;

    do {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save and Exit\n");
        printf("5. Exit without Saving\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_buffer(); // To clear the newline character

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
                save_appointments();
                printf("Appointments saved successfully!\n");
                return 0;
            case 5:
                printf("Exiting without saving. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}

// Function to add an appointment
void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter the title of the appointment: ");
    fgets(new_appointment.title, sizeof(new_appointment.title), stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline character

    printf("Enter the date and time (YYYY-MM-DD HH:MM): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline character

    // Validate date format
    struct tm tm;
    if (strptime(new_appointment.date, DATE_FORMAT, &tm) == NULL) {
        printf("Invalid date format. Please use YYYY-MM-DD HH:MM.\n");
        return;
    }

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n=== Appointments ===\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s at %s\n", i + 1, appointments[i].title, appointments[i].date);
    }
}

// Function to delete an appointment
void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    view_appointments();
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);
    clear_buffer(); // To clear the newline character

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    // Shift appointments to delete
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

// Function to save appointments to a file
void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s\n", appointments[i].title, appointments[i].date);
    }
    fclose(file);
}

// Function to load appointments from a file
void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No previous appointments found.\n");
        return;
    }

    while (fscanf(file, "%99[^,],%19[^\n]\n", appointments[appointment_count].title, appointments[appointment_count].date) == 2) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            break;
        }
    }
    fclose(file);
}

// Function to clear input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}