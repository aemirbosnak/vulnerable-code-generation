//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
    char name[50];
    char date[20];
    char time[20];
} appointment;

void view_appointments(appointment **appointments, int num_appointments);
void add_appointment(appointment **appointments, int *num_appointments);
void delete_appointment(appointment **appointments, int *num_appointments);
void sort_appointments(appointment **appointments, int num_appointments);

int main() {
    int num_appointments = 0;
    appointment **appointments = malloc(sizeof(appointment *));

    if (!appointments) {
        printf("ERROR: Could not allocate memory!\n");
        return 1;
    }

    printf("Welcome to the appointment scheduler!\n\n");

    while (1) {
        printf("1 - View Appointments\n2 - Add Appointment\n3 - Delete Appointment\n4 - Sort Appointments\n5 - Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_appointments(appointments, num_appointments);
                break;
            case 2:
                add_appointment(appointments, &num_appointments);
                break;
            case 3:
                delete_appointment(appointments, &num_appointments);
                break;
            case 4:
                sort_appointments(appointments, num_appointments);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    }

    free(appointments);
    return 0;
}

void view_appointments(appointment **appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\nDate: %s\nTime: %s\n\n", appointments[i]->name, appointments[i]->date, appointments[i]->time);
    }
}

void add_appointment(appointment **appointments, int *num_appointments) {
    *num_appointments += 1;
    appointments = realloc(appointments, (*num_appointments) * sizeof(appointment *));

    if (!appointments) {
        printf("ERROR: Could not reallocate memory!\n");
        return;
    }

    appointments[*num_appointments - 1] = malloc(sizeof(appointment));
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments - 1]->name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointments[*num_appointments - 1]->date);
    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", appointments[*num_appointments - 1]->time);
}

void delete_appointment(appointment **appointments, int *num_appointments) {
    if (*num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    char name[50];
    printf("Enter name of appointment to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            free(appointments[i]);

            for (int j = i; j < *num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }

            *num_appointments -= 1;
            appointments = realloc(appointments, (*num_appointments) * sizeof(appointment *));

            if (!appointments && *num_appointments > 0) {
                printf("ERROR: Could not reallocate memory!\n");
                return;
            }

            printf("Appointment deleted.\n");
            return;
        }
    }

    printf("Could not find appointment.\n");
}

void sort_appointments(appointment **appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < num_appointments; i++) {
        for (int j = i + 1; j < num_appointments; j++) {
            struct tm date1 = {0};
            struct tm date2 = {0};

            strptime(appointments[i]->date, "%d/%m/%Y", &date1);
            strptime(appointments[j]->date, "%d/%m/%Y", &date2);

            if (mktime(&date1) > mktime(&date2)) {
                appointment *temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }

    printf("Appointments sorted by date.\n");
}