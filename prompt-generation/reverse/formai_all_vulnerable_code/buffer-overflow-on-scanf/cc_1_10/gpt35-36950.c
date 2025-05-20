//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 20

// Structure for appointment data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

// Function declarations
void addAppointment(Appointment appointments[], int *numAppointments);
void listAppointments(Appointment appointments[], int numAppointments);
void checkAppointments(Appointment appointments[], int numAppointments);

int main(void) {
    // Define variables
    int choice = 0;
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    // Seed random generator
    srand(time(NULL));

    // Display menu and handle user input
    while (choice != 4) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Check Appointments\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                listAppointments(appointments, numAppointments);
                break;
            case 3:
                checkAppointments(appointments, numAppointments);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addAppointment(Appointment appointments[], int *numAppointments) {
    // Check if appointment list is full
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment list is full. Please try again later.\n");
        return;
    }

    // Get user input for appointment name and date
    printf("Enter appointment name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter appointment date (yyyy-mm-dd): ");
    scanf("%s", appointments[*numAppointments].date);

    printf("Appointment added for %s on %s.\n", appointments[*numAppointments].name, appointments[*numAppointments].date);

    *numAppointments += 1;
}

void listAppointments(Appointment appointments[], int numAppointments) {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");

    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s on %s\n", i+1, appointments[i].name, appointments[i].date);
    }
}

void checkAppointments(Appointment appointments[], int numAppointments) {
    // Check if there are no appointments
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    // Get current date and time
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    // Convert current date and time to string
    char currentDate[MAX_DATE_LENGTH];
    strftime(currentDate, MAX_DATE_LENGTH, "%Y-%m-%d", currentTime);

    // Check for upcoming appointments
    printf("Upcoming Appointments:\n");

    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(currentDate, appointments[i].date) <= 0) { // Appointment is today or later
            printf("%d. %s on %s\n", i+1, appointments[i].name, appointments[i].date);
        }
    }
}