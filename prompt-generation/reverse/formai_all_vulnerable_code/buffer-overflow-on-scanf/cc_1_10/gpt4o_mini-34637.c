//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define BUFFER_SIZE 256

typedef struct {
    char title[50];
    char description[100];
    struct tm start_time;
    struct tm end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    Appointment appt;
    printf("Enter title: ");
    fgets(appt.title, 50, stdin);
    strtok(appt.title, "\n"); // Remove newline character

    printf("Enter description: ");
    fgets(appt.description, 100, stdin);
    strtok(appt.description, "\n"); // Remove newline character

    printf("Enter start time (YYYY-MM-DD HH:MM): ");
    char start_time[20];
    fgets(start_time, 20, stdin);
    strptime(start_time, "%Y-%m-%d %H:%M", &appt.start_time);
    
    printf("Enter end time (YYYY-MM-DD HH:MM): ");
    char end_time[20];
    fgets(end_time, 20, stdin);
    strptime(end_time, "%Y-%m-%d %H:%M", &appt.end_time);

    appointments[appointment_count++] = appt;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment #%d\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        char start_buffer[BUFFER_SIZE], end_buffer[BUFFER_SIZE];
        strftime(start_buffer, sizeof(start_buffer), "%Y-%m-%d %H:%M", &appointments[i].start_time);
        strftime(end_buffer, sizeof(end_buffer), "%Y-%m-%d %H:%M", &appointments[i].end_time);
        printf("Start Time: %s\n", start_buffer);
        printf("End Time: %s\n\n", end_buffer);
    }
}

void deleteAppointment() {
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // clean buffer

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void menu() {
    printf("-------- Appointment Scheduler --------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("---------------------------------------\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // clean buffer

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
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}