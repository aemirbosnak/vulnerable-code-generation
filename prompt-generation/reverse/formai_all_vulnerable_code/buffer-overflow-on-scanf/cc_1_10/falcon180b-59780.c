//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int appointment_id;
    time_t appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter email: ");
    scanf("%s", appointments[num_appointments].email);
    appointments[num_appointments].appointment_id = num_appointments + 1;
    appointments[num_appointments].appointment_time = time(NULL);
    num_appointments++;
}

void view_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s (%s) at %s\n", appointments[i].appointment_id, appointments[i].name, appointments[i].email, ctime(&appointments[i].appointment_time));
    }
}

void remove_appointment(appointment* appointments, int num_appointments) {
    printf("Enter appointment ID: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].appointment_id == id) {
            num_appointments--;
            for (int j = i; j < num_appointments; j++) {
                appointments[j] = appointments[j + 1];
            }
            break;
        }
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. View appointments\n3. Remove appointment\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                remove_appointment(appointments, num_appointments);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}