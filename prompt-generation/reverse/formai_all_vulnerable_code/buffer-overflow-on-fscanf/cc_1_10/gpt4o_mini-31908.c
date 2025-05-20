//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[6]; // HH:MM format
    int duration; // duration in minutes
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void saveAppointmentsToFile();
void loadAppointmentsFromFile();
void listAppointments();

int main() {
    int choice;
    loadAppointmentsFromFile();

    do {
        printf("\n=== Futuristic Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                saveAppointmentsToFile();
                break;
            case 5:
                printf("Exiting the scheduler. Thank you for using it!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Cannot add more.\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter name: ");
    getchar(); // clear newline left by previous input
    fgets(newAppointment.name, NAME_LENGTH, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove newline character

    printf("Enter date (YYYY-MM-DD): ");
    fgets(newAppointment.date, DATE_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline character

    printf("Enter time (HH:MM): ");
    fgets(newAppointment.time, 6, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // Remove newline character

    printf("Enter duration (in minutes): ");
    scanf("%d", &newAppointment.duration);

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully.\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    listAppointments();
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    listAppointments();
    int index;
    printf("Enter the index of the appointment to delete (0 to %d): ", appointmentCount - 1);
    scanf("%d", &index);

    if (index < 0 || index >= appointmentCount) {
        printf("Invalid index. Deletion canceled.\n");
        return;
    }

    for (int i = index; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void saveAppointmentsToFile() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error saving appointments.\n");
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s|%s|%s|%d\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
    }

    fclose(file);
    printf("Appointments saved to file successfully.\n");
}

void loadAppointmentsFromFile() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("No previous appointments found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%[^|]|%[^|]|%[^|]|%d\n", appointments[appointmentCount].name, appointments[appointmentCount].date, appointments[appointmentCount].time, &appointments[appointmentCount].duration) == 4) {
        appointmentCount++;
        if (appointmentCount >= MAX_APPOINTMENTS) {
            printf("Maximum appointment limit reached during loading. Some appointments may not be loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("Appointments loaded from file successfully.\n");
}

void listAppointments() {
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s at %s for %d minutes\n", i, appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
    }
}