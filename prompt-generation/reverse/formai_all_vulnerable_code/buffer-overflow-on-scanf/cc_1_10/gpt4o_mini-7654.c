//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char date[MAX_DATE_LENGTH];
    time_t timestamp;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter the name of the appointment: ");
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0; // remove newline
    
    printf("Enter the description: ");
    fgets(new_appointment.description, DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // remove newline
    
    printf("Enter the date (YYYY-MM-DD): ");
    fgets(new_appointment.date, MAX_DATE_LENGTH, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // remove newline

    // Save current timestamp
    new_appointment.timestamp = time(NULL);
    
    appointments[appointment_count++] = new_appointment;
    
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments available.\n");
        return;
    }

    printf("\nAppointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Timestamp: %s", ctime(&appointments[i].timestamp));
        printf("---------------------------\n");
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int id;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &id);
    getchar(); // consume newline left in buffer

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    appointment_count--;
    
    printf("Appointment deleted successfully!\n");
}

void save_appointments(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file for saving appointments.\n");
        return;
    }
    
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s\n%s\n%s\n%ld\n", 
            appointments[i].name,
            appointments[i].description,
            appointments[i].date,
            appointments[i].timestamp);
    }

    fclose(file);
    printf("Appointments saved to %s\n", filename);
}

void load_appointments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file for loading appointments.\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n%ld\n", 
            appointments[appointment_count].name,
            appointments[appointment_count].description,
            appointments[appointment_count].date,
            &appointments[appointment_count].timestamp) != EOF) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            break;
        }
    }
    
    fclose(file);
    printf("Appointments loaded successfully from %s\n", filename);
}

void display_menu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("=============================\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    const char *filename = "appointments.txt";

    load_appointments(filename);

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume newline left in buffer
        
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
                save_appointments(filename);
                break;
            case 5:
                load_appointments(filename);
                break;
            case 6:
                printf("Exiting scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}