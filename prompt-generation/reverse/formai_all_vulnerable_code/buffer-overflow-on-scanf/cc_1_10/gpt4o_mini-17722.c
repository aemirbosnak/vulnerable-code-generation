//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_LENGTH 50

typedef struct {
    char title[MAX_LENGTH];
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
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
    fgets(new_appointment.title, MAX_LENGTH, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline character

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, MAX_LENGTH, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // Remove newline character

    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, MAX_LENGTH, stdin);
    new_appointment.time[strcspn(new_appointment.time, "\n")] = 0; // Remove newline character

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] on %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    view_appointments();
    int index;

    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear the newline character from the buffer

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
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
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%s,%s\n", appointments[i].title, appointments[i].date, appointments[i].time);
    }

    fclose(file);
    printf("Appointments saved successfully.\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No previous appointments found.\n");
        return;
    }

    while (fscanf(file, "%49[^,],%49[^,],%49[^\n]\n", appointments[appointment_count].title, appointments[appointment_count].date, appointments[appointment_count].time) == 3) {
        appointment_count++;
        if (appointment_count >= MAX_APPOINTMENTS) {
            printf("Reached maximum appointment limit, stopping load.\n");
            break;
        }
    }

    fclose(file);
    printf("Previously scheduled appointments loaded successfully.\n");
}

void show_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Load Appointments\n");
    printf("6. Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    load_appointments();

    do {
        show_menu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}