//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11 // Format: YYYY-MM-DD
#define TIME_LENGTH 6  // Format: HH:MM

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    char notes[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more appointments.\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter the name of the person: ");
    scanf(" %[^\n]", new_appointment.name);
    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf(" %s", new_appointment.date);
    printf("Enter the appointment time (HH:MM): ");
    scanf(" %s", new_appointment.time);
    printf("Enter any notes for the appointment: ");
    scanf(" %[^\n]", new_appointment.notes);
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n",
               i + 1,
               appointments[i].name,
               appointments[i].date,
               appointments[i].time);
        if (strlen(appointments[i].notes) > 0) {
            printf("   Notes: %s\n", appointments[i].notes);
        }
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
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
    printf("Appointment deleted successfully.\n");
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error saving appointments.\n");
        return;
    }
    
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s,%s\n", 
                appointments[i].name, 
                appointments[i].date, 
                appointments[i].time, 
                appointments[i].notes);
    }
    
    fclose(file);
    printf("Appointments saved successfully.\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No saved appointments found.\n");
        return;
    }
    
    while (!feof(file) && appointment_count < MAX_APPOINTMENTS) {
        Appointment appt;
        fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", 
               appt.name, 
               appt.date, 
               appt.time, 
               appt.notes);
        appointments[appointment_count++] = appt;
    }

    fclose(file);
    printf("Appointments loaded successfully.\n");
}

void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    load_appointments();
    
    int choice;
    do {
        display_menu();
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
                save_appointments();
                break;
            case 5:
                load_appointments();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}