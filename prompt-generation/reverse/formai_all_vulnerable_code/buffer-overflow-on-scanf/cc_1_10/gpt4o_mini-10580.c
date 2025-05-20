//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LENGTH 50
#define DATE_LENGTH 15
#define TIME_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];
int count = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void listMenu();
void clearBuffer();

int main() {
    int choice;
    
    do {
        listMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        clearBuffer();  // Clear input buffer

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }

    } while (choice != 4);

    return 0;
}

void addAppointment() {
    if (count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached!\n");
        return;
    }
    
    Appointment appt;
    printf("Enter title (max %d chars): ", TITLE_LENGTH-1);
    fgets(appt.title, TITLE_LENGTH, stdin);
    appt.title[strcspn(appt.title, "\n")] = 0;  // Remove newline

    printf("Enter date (YYYY-MM-DD): ");
    fgets(appt.date, DATE_LENGTH, stdin);
    appt.date[strcspn(appt.date, "\n")] = 0;  // Remove newline

    printf("Enter time (HH:MM): ");
    fgets(appt.time, TIME_LENGTH, stdin);
    appt.time[strcspn(appt.time, "\n")] = 0;  // Remove newline

    schedule[count] = appt;
    count++;
    
    printf("Appointment added!\n");
}

void viewAppointments() {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, schedule[i].title, schedule[i].date, schedule[i].time);
    }
    printf("\n");
}

void deleteAppointment() {
    if (count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1 to %d): ", count);
    scanf("%d", &index);
    clearBuffer();  // Clear input buffer

    if (index < 1 || index > count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        schedule[i] = schedule[i + 1];
    }

    count--;
    printf("Appointment deleted!\n");
}

void listMenu() {
    printf("\n*** Appointment Scheduler ***\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}