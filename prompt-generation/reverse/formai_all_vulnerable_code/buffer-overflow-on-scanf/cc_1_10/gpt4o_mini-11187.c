//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    getchar();  // to consume the newline character left by previous input
    fgets(new_appointment.title, MAX_TITLE_LENGTH, stdin);
    strtok(new_appointment.title, "\n"); // Remove newline character

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, sizeof(new_appointment.date), stdin);
    strtok(new_appointment.date, "\n"); // Remove newline character

    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, sizeof(new_appointment.time), stdin);
    strtok(new_appointment.time, "\n"); // Remove newline character

    appointments[appointment_count] = new_appointment;
    appointment_count++;
    printf("Appointment added!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s on %s at %s\n", 
                i + 1, 
                appointments[i].title, 
                appointments[i].date, 
                appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    view_appointments();
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted!\n");
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error opening file to save appointments.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s\n", 
                appointments[i].title, 
                appointments[i].date, 
                appointments[i].time);
    }
    fclose(file);
    printf("Appointments saved to appointments.txt.\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No saved appointments found.\n");
        return;
    }

    while (fscanf(file, "%99[^,],%10[^,],%5[^\n]\n", 
                  appointments[appointment_count].title, 
                  appointments[appointment_count].date, 
                  appointments[appointment_count].time) == 3) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            printf("Reached maximum appointment limit while loading.\n");
            break;
        }
    }
    fclose(file);
    printf("Appointments loaded from appointments.txt.\n");
}

int main() {
    int choice;
    load_appointments();

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Load Appointments\n");
        printf("0. Exit\n");
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
                delete_appointment();
                break;
            case 4:
                save_appointments();
                break;
            case 5:
                load_appointments();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}