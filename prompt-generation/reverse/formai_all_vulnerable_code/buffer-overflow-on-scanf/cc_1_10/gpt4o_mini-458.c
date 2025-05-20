//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100
#define FILENAME "appointments.txt"

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[11]; // format: YYYY-MM-DD
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void load_appointments() {
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s\n", appointments[appointment_count].date, appointments[appointment_count].description) == 2) {
            appointment_count++;
        }
        fclose(file);
    }
}

void save_appointments() {
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        for (int i = 0; i < appointment_count; i++) {
            fprintf(file, "%s %s\n", appointments[i].date, appointments[i].description);
        }
        fclose(file);
    }
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[appointment_count].date);
    printf("Enter description: ");
    scanf(" %[^\n]", appointments[appointment_count].description);

    appointment_count++;
    save_appointments();
    printf("Appointment added!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] %s\n", i + 1, appointments[i].date, appointments[i].description);
    }
}

void delete_appointment() {
    view_appointments();
    if (appointment_count == 0) return;
    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    save_appointments();
    printf("Appointment deleted!\n");
}

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    load_appointments();
    int choice;
    do {
        display_menu();
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}