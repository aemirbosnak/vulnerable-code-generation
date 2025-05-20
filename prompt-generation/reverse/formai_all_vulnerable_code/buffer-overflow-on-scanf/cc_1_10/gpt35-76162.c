//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 30

// define a struct for appointments
typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int hour;
} Appointment;

// declare global variables
Appointment schedule[MAX_APPOINTMENTS];
int numAppointments = 0;

// function to add an appointment to the schedule
void addAppointment() {
    // check if schedule is already full
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full!\n");
        return;
    }

    // get appointment info from user
    printf("Enter name: ");
    scanf("%s", schedule[numAppointments].name);
    printf("Enter day (1-31): ");
    scanf("%d", &schedule[numAppointments].day);
    printf("Enter hour (0-23): ");
    scanf("%d", &schedule[numAppointments].hour);

    // increment number of appointments
    numAppointments++;

    printf("Appointment added!\n");
}

// function to print the schedule
void printSchedule() {
    // check if there are no appointments
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Schedule:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - Day %d, Hour %d\n", schedule[i].name, schedule[i].day, schedule[i].hour);
    }
}

// function to find an appointment by name
int findAppointment(char name[]) {
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(schedule[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// function to delete an appointment by name
void deleteAppointment() {
    // check if there are no appointments
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    // get name of appointment to delete
    char name[MAX_NAME_LENGTH];
    printf("Enter name of appointment to delete: ");
    scanf("%s", name);

    // find appointment index
    int index = findAppointment(name);

    // check if appointment not found
    if (index == -1) {
        printf("Appointment not found.\n");
        return;
    }

    // shift schedule to remove appointment
    for (int i = index; i < numAppointments - 1; i++) {
        schedule[i] = schedule[i+1];
    }

    // decrement number of appointments
    numAppointments--;

    printf("Appointment deleted!\n");
}

int main() {
    char choice;

    // main loop
    while (1) {
        printf("\nWelcome to the Appointment Scheduler!\n");
        printf("1. Add appointment\n");
        printf("2. View schedule\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        // switch based on user choice
        switch (choice) {
            case '1':
                addAppointment();
                break;
            case '2':
                printSchedule();
                break;
            case '3':
                deleteAppointment();
                break;
            case '4':
                printf("Thank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}