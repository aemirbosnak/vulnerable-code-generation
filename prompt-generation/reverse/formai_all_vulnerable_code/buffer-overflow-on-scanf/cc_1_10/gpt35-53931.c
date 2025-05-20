//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char date[25];
    char time[15];
    char description[100];
};

void addAppointment(struct appointment *appointments, int count);
void printAppointments(struct appointment *appointments, int count);
void deleteAppointment(struct appointment *appointments, int *count, int index);

int main() {
    int choice, count = 0, index;
    struct appointment *appointments = NULL;

    do {
        printf("Welcome to the Appointment Scheduler!\n");
        printf("1. Add an Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete an Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, count);
                count++;
                break;
            case 2:
                printAppointments(appointments, count);
                break;
            case 3:
                printf("Enter the index of the appointment to delete: ");
                scanf("%d", &index);
                deleteAppointment(appointments, &count, index);
                break;
            case 4:
                printf("Exiting Appointment Scheduler...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(appointments);
    return 0;
}

void addAppointment(struct appointment *appointments, int count) {
    appointments = (struct appointment*)realloc(appointments, (count+1) * sizeof(struct appointment));

    printf("\nEnter the date of the appointment (dd/mm/yyyy): ");
    scanf("%s", appointments[count].date);

    printf("Enter the time of the appointment (hh:mm AM/PM): ");
    scanf("%s", appointments[count].time);

    printf("Enter the description of the appointment: ");
    scanf("%s", appointments[count].description);

    printf("\nAppointment added successfully!\n");
}

void printAppointments(struct appointment *appointments, int count) {
    if (count == 0) {
        printf("\nNo appointments found.\n");
        return;
    }

    printf("\nAppointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s at %s: %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

void deleteAppointment(struct appointment *appointments, int *count, int index) {
    if (index < 1 || index > *count) {
        printf("\nInvalid index. Please try again.\n");
        return;
    }

    for (int i = index-1; i < *count-1; i++) {
        strcpy(appointments[i].date, appointments[i+1].date);
        strcpy(appointments[i].time, appointments[i+1].time);
        strcpy(appointments[i].description, appointments[i+1].description);
    }

    *count -= 1;
    appointments = (struct appointment*)realloc(appointments, (*count) * sizeof(struct appointment));

    printf("\nAppointment deleted successfully!\n");
}