//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DATE_LENGTH 11
#define TIME_LENGTH 6
#define DESCRIPTION_LENGTH 256

typedef struct {
    char date[DATE_LENGTH]; // Format: YYYY-MM-DD
    char time[TIME_LENGTH]; // Format: HH:MM
    char description[DESCRIPTION_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments, limit reached!\n");
        return;
    }
    
    Appointment new_appointment;

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment.date);
    
    printf("Enter the time (HH:MM): ");
    scanf("%5s", new_appointment.time);
    
    printf("Enter appointment description: ");
    getchar(); // to clear newline character left by previous input
    fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
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
        printf("%d. %s at %s: %s\n",
               i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

void remove_appointment() {
    list_appointments();

    if (appointment_count == 0) {
        return;
    }

    int index;
    printf("Enter the appointment number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment removed successfully!\n");
}

void save_appointments_to_file() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s\n", appointments[i].date, appointments[i].time, appointments[i].description);
    }

    fclose(file);
    printf("Appointments saved to file successfully!\n");
}

void load_appointments_from_file() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No appointments file found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%10[^,],%5[^,],%255[^\n]\n",
                  appointments[appointment_count].date,
                  appointments[appointment_count].time,
                  appointments[appointment_count].description) == 3) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) break;
    }
    
    fclose(file);
    printf("Appointments loaded successfully!\n");
}

int main() {
    load_appointments_from_file();
    
    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Remove Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Exit\n");
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
                remove_appointment();
                break;
            case 4:
                save_appointments_to_file();
                break;
            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                save_appointments_to_file();
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}