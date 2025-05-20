//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached.\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter name for appointment: ");
    scanf("%s", new_appointment.name);

    printf("Enter date and time for appointment (YYYY-MM-DD HH:MM): ");
    struct tm appointment_time = {0};
    char datetime[20]; 
    scanf("%s", datetime);
    
    strptime(datetime, "%Y-%m-%d %H:%M", &appointment_time);
    new_appointment.date_time = mktime(&appointment_time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment for %s added successfully.\n", new_appointment.name);
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        char buffer[26];
        struct tm *tm_info = localtime(&appointments[i].date_time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", tm_info);
        printf("Appointment %d: %s at %s\n", i + 1, appointments[i].name, buffer);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment %d deleted successfully.\n", index);
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s %ld\n", appointments[i].name, appointments[i].date_time);
    }

    fclose(file);
    printf("Appointments saved to appointments.txt\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    appointment_count = 0;
    while (!feof(file) && appointment_count < MAX_APPOINTMENTS) {
        Appointment new_appointment;
        fscanf(file, "%s %ld\n", new_appointment.name, &new_appointment.date_time);
        appointments[appointment_count++] = new_appointment;
    }

    fclose(file);
    printf("Appointments loaded from appointments.txt\n");
}

void display_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Quit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Select an option: ");
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
                printf("Exiting the scheduler. Goodbye!\n"); 
                exit(0);
            default: 
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}