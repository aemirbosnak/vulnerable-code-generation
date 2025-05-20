//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    char name[50];
    int year;
    int month;
    int day;
    int hour;
};

void addAppointment(struct appointment* appointments, int* numAppointments);
void showAppointments(struct appointment* appointments, int numAppointments);
void searchAppointment(struct appointment* appointments, int numAppointments);

int main() {
    int choice, numAppointments = 0;
    struct appointment* appointments = NULL;

    do {
        printf("==== MENU ====\n");
        printf("1. Add Appointment\n");
        printf("2. Show Appointments\n");
        printf("3. Search Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAppointment(appointments, &numAppointments);
            break;
        case 2:
            showAppointments(appointments, numAppointments);
            break;
        case 3:
            searchAppointment(appointments, numAppointments);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    free(appointments);

    return 0;
}

void addAppointment(struct appointment* appointments, int* numAppointments) {
    int i;

    printf("Enter name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter year: ");
    scanf("%d", &appointments[*numAppointments].year);
    printf("Enter month (1-12): ");
    scanf("%d", &appointments[*numAppointments].month);
    printf("Enter day (1-31): ");
    scanf("%d", &appointments[*numAppointments].day);
    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[*numAppointments].hour);

    (*numAppointments)++;

    appointments = (struct appointment*)realloc(appointments, (*numAppointments + 1) * sizeof(struct appointment));
    if (appointments == NULL) {
        printf("Error: Memory allocation failed.\n");
    }
}

void showAppointments(struct appointment* appointments, int numAppointments) {
    int i;

    if (numAppointments == 0) {
        printf("There are no appointments to display.\n");
        return;
    }

    printf("==== APPOINTMENTS ====\n");

    for (i = 0; i < numAppointments; i++) {
        printf("%s at %02d/%02d/%04d %02d:00\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour);
    }
}

void searchAppointment(struct appointment* appointments, int numAppointments) {
    int i, year, month, day, hour;

    if (numAppointments == 0) {
        printf("There are no appointments to search.\n");
        return;
    }

    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    for (i = 0; i < numAppointments; i++) {
        if (appointments[i].year == year && appointments[i].month == month && appointments[i].day == day && appointments[i].hour == hour) {
            printf("Appointment found: %s at %02d/%02d/%04d %02d:00\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour);
            return;
        }
    }

    printf("Appointment not found.\n");
}