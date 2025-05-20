//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int day; // Appointment day in the month (1-31)
    int month; // Appointment month (1-12)
    int year; // Appointment year (e.g. 2022)
    int hour; // Appointment hour (0-23)
    int minute; // Appointment minute (0-59)
    char clientName[50]; // Name of the client
    char service[50]; // Description of the service requested
} Appointment;

Appointment appointments[MAX_APPOINTMENTS]; // Array of appointments
int numAppointments = 0; // Number of appointments in the array

void displayMenu() {
    printf("\nWelcome to the Futuristic Appointment Scheduler\n");
    printf("1. Make an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. List all appointments\n");
    printf("4. Exit\n");
}

void makeAppointment() {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments (%d) has been reached.\n", MAX_APPOINTMENTS);
        return;
    }
    Appointment newAppointment;
    printf("Enter the date of the appointment (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &newAppointment.day, &newAppointment.month, &newAppointment.year);
    printf("Enter the time of the appointment (hh:mm): ");
    scanf("%d:%d", &newAppointment.hour, &newAppointment.minute);
    printf("Enter the client's name: ");
    scanf("%s", newAppointment.clientName);
    printf("Enter a brief description of the service requested: ");
    scanf("%s", newAppointment.service);
    appointments[numAppointments] = newAppointment;
    numAppointments++;
    printf("Appointment successfully scheduled.\n");
}

void cancelAppointment() {
    if (numAppointments == 0) {
        printf("There are no appointments to cancel.\n");
        return;
    }
    printf("Enter the date of the appointment to cancel (dd/mm/yyyy): ");
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);
    int indexToDelete = -1;
    for (int i = 0; i < numAppointments; i++) {
        if (day == appointments[i].day && month == appointments[i].month && year == appointments[i].year) {
            printf("Appointment found: %02d/%02d/%4d at %02d:%02d with %s. Service requested: %s.\n",
                day, month, year, appointments[i].hour, appointments[i].minute, appointments[i].clientName, appointments[i].service);
            printf("Do you want to cancel this appointment? (Y/N)");
            char answer;
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y') {
                indexToDelete = i;
                printf("Appointment successfully cancelled.\n");
                break;
            }
        }
    }
    if (indexToDelete != -1) {
        for (int i = indexToDelete + 1; i < numAppointments; i++) {
            appointments[i - 1] = appointments[i];
        }
        numAppointments--;
    } else {
        printf("No appointment was cancelled.\n");
    }
}

void listAppointments() {
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    printf("\nList of all appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%02d/%02d/%4d at %02d:%02d with %s. Service requested: %s.\n",
            appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].clientName, appointments[i].service);
    }
}

int main() {
    int option;
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                makeAppointment();
                break;
            case 2:
                cancelAppointment();
                break;
            case 3:
                listAppointments();
                break;
            case 4:
                printf("Thank you for using the Futuristic Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 4);
    return 0;
}