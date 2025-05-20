//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50
#define TITLE_LEN 50
#define DESC_LEN 100

typedef struct {
    char title[TITLE_LEN];
    char description[DESC_LEN];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    printf("Enter appointment title: ");
    scanf(" %[^\n]", appointments[*count].title);
    
    printf("Enter appointment description: ");
    scanf(" %[^\n]", appointments[*count].description);
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]", appointments[*count].date);

    printf("Enter appointment time (HH:MM): ");
    scanf(" %[^\n]", appointments[*count].time);

    (*count)++;
    printf("\nAppointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled!\n");
        return;
    }

    printf("\nYour Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("\nAppointment %d:\n", i + 1);
        printf("Title: %s\n", appointments[i].title);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete!\n");
        return;
    }
    
    int index;
    printf("Enter the appointment number to delete (1-%d): ", *count);
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    (*count)--;
    printf("Appointment %d deleted successfully!\n", index);
}

void displayMenu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("============================\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}