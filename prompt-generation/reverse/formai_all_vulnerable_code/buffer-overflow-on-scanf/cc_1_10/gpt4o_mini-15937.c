//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_CLIENT_NAME 50
#define MAX_DESC 100

typedef struct {
    char client_name[MAX_CLIENT_NAME];
    time_t appointment_time;
    char description[MAX_DESC];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter client's name: ");
    fgets(new_appointment.client_name, MAX_CLIENT_NAME, stdin);
    new_appointment.client_name[strcspn(new_appointment.client_name, "\n")] = 0; // Remove newline

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM): ");
    struct tm tm = {0};
    char date_time[20];
    fgets(date_time, 20, stdin);
    strptime(date_time, "%Y-%m-%d %H:%M", &tm);
    new_appointment.appointment_time = mktime(&tm);

    printf("Enter appointment description: ");
    fgets(new_appointment.description, MAX_DESC, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

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
        struct tm *tm_info = localtime(&appointments[i].appointment_time);
        char buffer[26];
        strftime(buffer, 26, "%Y-%m-%d %H:%M", tm_info);
        printf("Client: %s | Date & Time: %s | Description: %s\n", 
                appointments[i].client_name, buffer, appointments[i].description);
    }
}

void remove_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to remove.\n");
        return;
    }

    view_appointments();
    int index;
    printf("Enter the index of the appointment to remove (0 to %d): ", appointment_count - 1);
    scanf("%d", &index);
    getchar(); // Consume leftover newline

    if (index < 0 || index >= appointment_count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment removed successfully!\n");
}

void menu() {
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Remove Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                remove_appointment();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");
    menu();
    return 0;
}