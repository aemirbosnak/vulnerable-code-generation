//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 11

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int start_hour, start_minute;
    int end_hour, end_minute;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_menu() {
    printf("\n---- Appointment Scheduler ----\n");
    printf("1. Add an appointment\n");
    printf("2. Delete an appointment\n");
    printf("3. List all appointments\n");
    printf("4. Search for an appointment\n");
    printf("5. Exit\n");
}

int add_appointment(struct Appointment *appointment) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return 0;
    }

    strcpy(appointments[num_appointments].name, appointment->name);
    appointments[num_appointments].start_hour = appointment->start_hour;
    appointments[num_appointments].start_minute = appointment->start_minute;
    appointments[num_appointments].end_hour = appointment->end_hour;
    appointments[num_appointments].end_minute = appointment->end_minute;

    num_appointments++;

    return 1;
}

void delete_appointment(int index) {
    if (index < 0 || index >= num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }

    memmove(&appointments[index], &appointments[index + 1], (num_appointments - index - 1) * sizeof(struct Appointment));
    num_appointments--;

    printf("Appointment deleted successfully.\n");
}

void list_appointments() {
    int i;

    printf("\n---- List of Appointments ----\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s: %d:%02d - %d:%02d\n", appointments[i].name, appointments[i].start_hour, appointments[i].start_minute, appointments[i].end_hour, appointments[i].end_minute);
    }
}

void search_appointment(char *name) {
    int i;

    for (i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("\nAppointment found:\n");
            printf("%s: %d:%02d - %d:%02d\n", appointments[i].name, appointments[i].start_hour, appointments[i].start_minute, appointments[i].end_hour, appointments[i].end_minute);
            return;
        }
    }

    printf("Appointment not found.\n");
}

int main() {
    int choice;
    struct Appointment new_appointment;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment name: ");
                scanf("%s", new_appointment.name);
                printf("Enter start hour: ");
                scanf("%d", &new_appointment.start_hour);
                printf("Enter start minute: ");
                scanf("%d", &new_appointment.start_minute);
                printf("Enter end hour: ");
                scanf("%d", &new_appointment.end_hour);
                printf("Enter end minute: ");
                scanf("%d", &new_appointment.end_minute);

                add_appointment(&new_appointment);
                break;
            case 2:
                if (num_appointments > 0) {
                    printf("Enter appointment index to delete: ");
                    int index;
                    scanf("%d", &index);
                    delete_appointment(index);
                } else {
                    printf("No appointments to delete.\n");
                }
                break;
            case 3:
                list_appointments();
                break;
            case 4:
                printf("Enter appointment name to search: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                search_appointment(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}