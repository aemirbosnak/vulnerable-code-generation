//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11 // Format: YYYY-MM-DD
#define TIME_LENGTH 6  // Format: HH:MM

typedef struct {
    char name[NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int count = 0;

void show_menu() {
    printf("\n----- Appointment Scheduler -----\n");
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Search Appointment\n");
    printf("5. Exit\n");
    printf("--------------------------------\n");
}

void add_appointment() {
    if (count >= MAX_APPOINTMENTS) {
        printf("Error: Maximum appointments reached!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", appointments[count].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[count].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[count].time);
    count++;
    printf("Appointment added successfully!\n");
}

void list_appointments() {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\n--- List of Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Error: Invalid appointment number!\n");
        return;
    }
    for (int i = index - 1; i < count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    count--;
    printf("Appointment deleted successfully!\n");
}

void search_appointment() {
    if (count == 0) {
        printf("No appointments to search.\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("%d. %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
            found = 1;
        }
    }
    if (!found) {
        printf("No appointments found for %s.\n", name);
    }
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                search_appointment();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Error: Invalid option!\n");
        }
    }

    return 0;
}