//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;
    
    printf("Enter title of appointment: ");
    getchar(); // Clear input buffer
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    strtok(new_appointment.title, "\n"); // Remove newline
    
    printf("Enter description of appointment: ");
    fgets(new_appointment.description, MAX_DESCRIPTION_LENGTH, stdin);
    strtok(new_appointment.description, "\n");
    
    printf("Enter date and time (YYYY MM DD HH MM): ");
    scanf("%d %d %d %d %d", &new_appointment.date_time.tm_year, 
           &new_appointment.date_time.tm_mon, &new_appointment.date_time.tm_mday,
           &new_appointment.date_time.tm_hour, &new_appointment.date_time.tm_min);
    
    // Adjust year and month for struct tm
    new_appointment.date_time.tm_year -= 1900; // tm_year is years since 1900
    new_appointment.date_time.tm_mon -= 1;      // tm_mon is months since January
    
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
        printf("\nAppointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        printf("Date & Time: %s", asctime(&appointments[i].date_time));
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    list_appointments();
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    
    printf("Appointment deleted successfully!\n");
}

void save_appointments(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s\n", appointments[i].title);
        fprintf(file, "%s\n", appointments[i].description);
        fprintf(file, "%d %d %d %d %d\n", appointments[i].date_time.tm_year + 1900,
                appointments[i].date_time.tm_mon + 1, appointments[i].date_time.tm_mday,
                appointments[i].date_time.tm_hour, appointments[i].date_time.tm_min);
    }

    fclose(file);
    printf("Appointments saved to %s successfully!\n", filename);
}

void load_appointments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fgets(appointments[appointment_count].title, MAX_TITLE_LENGTH, file)) {
        strtok(appointments[appointment_count].title, "\n"); // Remove newline
        fgets(appointments[appointment_count].description, MAX_DESCRIPTION_LENGTH, file);
        strtok(appointments[appointment_count].description, "\n");

        fscanf(file, "%d %d %d %d %d\n", &appointments[appointment_count].date_time.tm_year,
               &appointments[appointment_count].date_time.tm_mon,
               &appointments[appointment_count].date_time.tm_mday,
               &appointments[appointment_count].date_time.tm_hour,
               &appointments[appointment_count].date_time.tm_min);

        appointments[appointment_count].date_time.tm_year -= 1900;
        appointments[appointment_count].date_time.tm_mon -= 1;
        
        appointment_count++; 
    }

    fclose(file);
    printf("Appointments loaded from %s successfully!\n", filename);
}

void show_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    const char *filename = "appointments.txt";

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                save_appointments(filename);
                break;
            case 5:
                load_appointments(filename);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}