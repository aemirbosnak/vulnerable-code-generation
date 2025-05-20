//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100
#define MAX_DATE_LENGTH 11

typedef struct {
    char description[MAX_DESC_LENGTH];
    char date[MAX_DATE_LENGTH];
    time_t timestamp;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void delete_appointment();
void clear_screen();

void clear_screen() {
    // Clear console for a cleaner interface
    printf("\033[H\033[J");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter appointment description: ");
    getchar(); // to capture newline after previous input
    fgets(new_appointment.description, MAX_DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, MAX_DATE_LENGTH, stdin);
    new_appointment.date[strcspn(new_appointment.date, "\n")] = 0; // remove newline

    // Convert date string to timestamp
    struct tm tm = {0};
    strptime(new_appointment.date, "%Y-%m-%d", &tm); 
    new_appointment.timestamp = mktime(&tm);

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
        printf("%d. %s on %s\n", i + 1, appointments[i].description, appointments[i].date);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

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
    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        clear_screen();
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        printf("Press Enter to continue...");
        getchar(); // to capture newline after choice input
        getchar(); // to wait for user input
    }

    return 0;
}