//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH]; // Format: YYYY-MM-DD
    char time[6]; // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment newAppointment;

    printf("Enter appointment name: ");
    fgets(newAppointment.name, NAME_LENGTH, stdin);
    newAppointment.name[strcspn(newAppointment.name, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(newAppointment.date, DATE_LENGTH, stdin);
    newAppointment.date[strcspn(newAppointment.date, "\n")] = 0; // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(newAppointment.time, 6, stdin);
    newAppointment.time[strcspn(newAppointment.time, "\n")] = 0; // Remove newline

    appointments[appointmentCount++] = newAppointment;
    printf("Appointment added successfully!\n\n");
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void deleteAppointment() {
    if (appointmentCount == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment index to delete (1-%d): ", appointmentCount);
    scanf("%d", &index);
    getchar(); // Clear newline

    if (index < 1 || index > appointmentCount) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully!\n\n");
}

void saveAppointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        printf("Error saving appointments!\n");
        return;
    }

    for (int i = 0; i < appointmentCount; i++) {
        fprintf(file, "%s\n%s\n%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
    
    fclose(file);
    printf("Appointments saved to appointments.txt\n\n");
}

void loadAppointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        printf("No saved appointments found.\n\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n%[^\n]\n%[^\n]\n", appointments[appointmentCount].name,
                                       appointments[appointmentCount].date,
                                       appointments[appointmentCount].time) == 3) {
        appointmentCount++;
        if (appointmentCount >= MAX_APPOINTMENTS) {
            printf("Reached maximum appointment limit! Not all appointments loaded.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Appointments loaded successfully!\n\n");
}

int main() {
    int choice;

    loadAppointments();

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch(choice) {
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
                saveAppointments();
                break;
            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}