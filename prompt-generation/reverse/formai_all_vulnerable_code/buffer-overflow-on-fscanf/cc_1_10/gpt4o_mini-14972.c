//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define STRING_LENGTH 50

typedef struct {
    char name[STRING_LENGTH];
    char date[STRING_LENGTH];
    char time[STRING_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void displayAppointments() {
    printf("\n---- Your Appointments ----\n");
    if (appointmentCount == 0) {
        printf("No appointments scheduled! What a disaster!\n");
        return;
    }
    
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Whoa! You can't fit in any more appointments! Try to cancel some!\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter appointment name: ");
    fgets(newAppointment.name, STRING_LENGTH, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(newAppointment.date, STRING_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(newAppointment.time, STRING_LENGTH, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // remove newline

    appointments[appointmentCount] = newAppointment;
    appointmentCount++;

    printf("Wow! You've successfully added an appointment!\n");
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("You have no appointments to delete. What a pitiful situation!\n");
        return;
    }

    displayAppointments();
    
    int indexToDelete;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &indexToDelete);
    getchar(); // consume newline

    if (indexToDelete < 1 || indexToDelete > appointmentCount) {
        printf("Oops! Number out of range!\n");
        return;
    }

    for (int i = indexToDelete - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointmentCount--;
    printf("Yikes! You've deleted an appointment!\n");
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("A catastrophe! Couldn't open the file for saving!\n");
        return;
    }
    
    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s;%s;%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    fclose(file);
    printf("Success! Your appointments have been saved safely!\n");
}

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No file found! Awful luck, huh?\n");
        return;
    }

    while (fscanf(file, "%[^;];%[^;];%[^\n]\n", appointments[appointmentCount].name, appointments[appointmentCount].date, appointments[appointmentCount].time) != EOF) {
        appointmentCount++;
    }

    fclose(file);
    printf("Phew! Appointments loaded successfully!\n");
}

int main() {
    int choice;

    loadAppointments();
    
    do {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. View Appointments\n");
        printf("2. Add Appointment\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                displayAppointments();
                break;
            case 2:
                addAppointment();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                saveAppointments();
                break;
            case 5:
                printf("Exiting... Hope to see you again!\n");
                break;
            default:
                printf("Whoa! That's not a valid choice!\n");
        }
    } while (choice != 5);

    return 0;
}