//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    char description[APPOINTMENT_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file) {
        while (fscanf(file, "%10s %5s %[^\n]", appointments[appointment_count].date, 
                appointments[appointment_count].time, appointments[appointment_count].description) != EOF) {
            appointment_count++;
        }
        fclose(file);
    }
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s %s %s\n", appointments[i].date, appointments[i].time, appointments[i].description);
    }
    fclose(file);
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%10s", new_appointment.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%5s", new_appointment.time);
    printf("Enter appointment description: ");
    getchar(); // Consume newline character left by previous scanf
    fgets(new_appointment.description, APPOINTMENT_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    save_appointments();
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] [%s] %s\n", i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
    printf("\n");
}

void delete_appointment() {
    printf("Enter the appointment number to delete: ");
    int index;
    scanf("%d", &index);
    index--; // Adjust for zero-based index

    if (index < 0 || index >= appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    save_appointments();
    printf("Appointment deleted successfully!\n");
}

int main() {
    load_appointments();
    int choice;

    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}