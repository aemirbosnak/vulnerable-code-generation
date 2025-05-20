//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define STR_LEN 256

typedef struct {
    char title[STR_LEN];
    char description[STR_LEN];
    char datetime[STR_LEN];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void viewMenu();
void findAppointment();

int main() {
    int choice;

    while (1) {
        viewMenu();

        printf("\nChoose an option (1-5): ");
        scanf("%d", &choice);
        getchar();  // Capture the newline

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
                findAppointment();
                break;
            case 5:
                printf("Shutting down the Neural Scheduler... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}

void viewMenu() {
    printf("\n=========================\n");
    printf("  Cyberpunk Appointment  \n");
    printf("      Scheduler          \n");
    printf("=========================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Find Appointment\n");
    printf("5. Exit\n");
}

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Storage full.\n");
        return;
    }

    printf("Enter appointment title: ");
    fgets(appointments[appointment_count].title, STR_LEN, stdin);
    appointments[appointment_count].title[strcspn(appointments[appointment_count].title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appointments[appointment_count].description, STR_LEN, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = 0; // Remove newline

    printf("Enter appointment datetime (YYYY-MM-DD HH:MM): ");
    fgets(appointments[appointment_count].datetime, STR_LEN, stdin);
    appointments[appointment_count].datetime[strcspn(appointments[appointment_count].datetime, "\n")] = 0; // Remove newline

    printf("Appointment added successfully!\n");
    appointment_count++;
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("  Title: %s\n", appointments[i].title);
        printf("  Description: %s\n", appointments[i].description);
        printf("  Datetime: %s\n\n", appointments[i].datetime);
    }
}

void deleteAppointment() {
    int index;

    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // Capture the newline

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    appointment_count--;
    printf("Appointment %d deleted successfully.\n", index);
}

void findAppointment() {
    char search_title[STR_LEN];
    int found = 0;

    printf("Enter title of the appointment to find: ");
    fgets(search_title, STR_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0; // Remove newline

    for (int i = 0; i < appointment_count; i++) {
        if (strcasestr(appointments[i].title, search_title) != NULL) {
            printf("Appointment found:\n");
            printf("  Title: %s\n", appointments[i].title);
            printf("  Description: %s\n", appointments[i].description);
            printf("  Datetime: %s\n\n", appointments[i].datetime);
            found = 1;
        }
    }

    if (!found) {
        printf("No appointment found with the title: %s\n", search_title);
    }
}