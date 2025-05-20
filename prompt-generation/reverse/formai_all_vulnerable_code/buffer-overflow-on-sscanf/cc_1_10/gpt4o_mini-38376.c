//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    struct tm date;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_appointments() {
    printf("\n---- List of Appointments ----\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("ID: %d\n", appointments[i].id);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %02d-%02d-%4d %02d:%02d\n", 
               appointments[i].date.tm_mday, 
               appointments[i].date.tm_mon + 1, 
               appointments[i].date.tm_year + 1900, 
               appointments[i].date.tm_hour, 
               appointments[i].date.tm_min);
        printf("-----------------------------\n");
    }
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached!\n");
        return;
    }
    
    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter name: ");
    scanf(" %[^\n]%*c", new_appointment.name);
    
    printf("Enter description: ");
    scanf(" %[^\n]%*c", new_appointment.description);
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    char date_input[11];
    scanf("%s", date_input);
    
    printf("Enter appointment time (HH:MM, 24-hour format): ");
    char time_input[6];
    scanf("%s", time_input);

    sscanf(date_input, "%d-%d-%d", 
           &new_appointment.date.tm_year, 
           &new_appointment.date.tm_mon, 
           &new_appointment.date.tm_mday);
    sscanf(time_input, "%d:%d", 
           &new_appointment.date.tm_hour, 
           &new_appointment.date.tm_min);

    new_appointment.date.tm_year -= 1900; // Adjust year
    new_appointment.date.tm_mon -= 1;      // Adjust month

    appointments[appointment_count] = new_appointment;
    appointment_count++;

    printf("Appointment added successfully!\n");
}

void delete_appointment() {
    int id;
    printf("Enter the appointment ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > appointment_count) {
        printf("Invalid appointment ID!\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void find_appointment() {
    char name[NAME_LENGTH];
    printf("Enter the name to search for: ");
    scanf(" %[^\n]%*c", name);

    printf("\n---- Search Results ----\n");
    int found = 0;
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            printf("ID: %d\n", appointments[i].id);
            printf("Description: %s\n", appointments[i].description);
            printf("Date: %02d-%02d-%4d %02d:%02d\n", 
                   appointments[i].date.tm_mday,
                   appointments[i].date.tm_mon + 1,
                   appointments[i].date.tm_year + 1900,
                   appointments[i].date.tm_hour,
                   appointments[i].date.tm_min);
            printf("-----------------------------\n");
        }
    }
    if (!found) {
        printf("No appointments found for the name: %s\n", name);
    }
}

void print_menu() {
    printf("\n---- Appointment Scheduler ----\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. Display All Appointments\n");
    printf("4. Find Appointment by Name\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                delete_appointment();
                break;
            case 3:
                display_appointments();
                break;
            case 4:
                find_appointment();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}