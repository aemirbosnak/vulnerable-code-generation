//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_USERS 10
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100
#define FILENAME "appointments.txt"

typedef struct {
    char username[MAX_NAME_LEN];
    char date[11]; // format: YYYY-MM-DD
    char time[6];  // format: HH:MM
    char description[MAX_DESC_LEN];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void loadAppointments(const char *username) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return;
    }

    while (fscanf(file, "%s %s %s %[^\n]", appointments[appointmentCount].username, 
           appointments[appointmentCount].date, appointments[appointmentCount].time, 
           appointments[appointmentCount].description) != EOF) {
        if (strcmp(appointments[appointmentCount].username, username) == 0) {
            appointmentCount++;
        }
    }

    fclose(file);
}

void saveAppointment(Appointment *appt) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s %s %s %s\n", appt->username, appt->date, appt->time, appt->description);
    fclose(file);
}

void addAppointment(const char *username) {
    Appointment newAppt;
    strcpy(newAppt.username, username);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", newAppt.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", newAppt.time);
    getchar(); // clear newline from input buffer
    printf("Enter appointment description: ");
    fgets(newAppt.description, MAX_DESC_LEN, stdin);
    newAppt.description[strcspn(newAppt.description, "\n")] = 0; // remove newline

    appointments[appointmentCount++] = newAppt;
    saveAppointment(&newAppt);
    printf("Appointment added successfully!\n");
}

void viewAppointments(const char *username) {
    printf("\nAppointments for %s:\n", username);
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].username, username) == 0) {
            printf("[%s] %s: %s\n", appointments[i].date, appointments[i].time, appointments[i].description);
        }
    }
}

int main() {
    char username[MAX_NAME_LEN];
    printf("Enter your username: ");
    scanf("%s", username);
    loadAppointments(username);

    int choice;
    do {
        printf("\n1. Add Appointment\n2. View Appointments\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(username);
                break;
            case 2:
                viewAppointments(username);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}