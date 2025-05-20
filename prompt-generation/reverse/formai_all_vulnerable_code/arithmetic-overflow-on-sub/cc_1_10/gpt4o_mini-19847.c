//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_FILE "appointments.txt"
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

void add_appointment() {
    Appointment appt;
    FILE *file = fopen(APPOINTMENT_FILE, "a+");
    if (file == NULL) {
        perror("Unable to open appointment file");
        return;
    }

    printf("Enter appointment title: ");
    fgets(appt.title, MAX_TITLE_LENGTH, stdin);
    appt.title[strcspn(appt.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appt.description, MAX_DESCRIPTION_LENGTH, stdin);
    appt.description[strcspn(appt.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date and time (YYYY MM DD HH MM): ");
    scanf("%d %d %d %d %d", &appt.date_time.tm_year, &appt.date_time.tm_mon, &appt.date_time.tm_mday, 
          &appt.date_time.tm_hour, &appt.date_time.tm_min);
    appt.date_time.tm_year -= 1900; // Adjust year to be Y years since 1900
    appt.date_time.tm_mon -= 1; // Adjust month to be 0-11

    fwrite(&appt, sizeof(Appointment), 1, file);
    fclose(file);
    
    printf("Appointment added!\n");
}

void view_appointments() {
    Appointment appt;
    FILE *file = fopen(APPOINTMENT_FILE, "r");
    if (file == NULL) {
        perror("Unable to open appointment file");
        return;
    }

    printf("Appointments:\n");
    while (fread(&appt, sizeof(Appointment), 1, file)) {
        printf("Title: %s\n", appt.title);
        printf("Description: %s\n", appt.description);
        printf("Date: %d-%02d-%02d %02d:%02d\n", 
               appt.date_time.tm_year + 1900, 
               appt.date_time.tm_mon + 1, 
               appt.date_time.tm_mday, 
               appt.date_time.tm_hour, 
               appt.date_time.tm_min);
        printf("\n");
    }
    fclose(file);
}

void delete_appointment() {
    int index, count = 0;
    Appointment appt;
    FILE *file = fopen(APPOINTMENT_FILE, "r");
    FILE *temp_file = fopen("temp.txt", "w");
    if (file == NULL || temp_file == NULL) {
        perror("Unable to open appointment file");
        return;
    }

    printf("Enter appointment index to delete: ");
    scanf("%d", &index);
    
    while (fread(&appt, sizeof(Appointment), 1, file)) {
        count++;
        if (count == index) continue; // Skip the appointment to delete
        fwrite(&appt, sizeof(Appointment), 1, temp_file); // Write to temp file
    }

    fclose(file);
    fclose(temp_file);

    remove(APPOINTMENT_FILE); // Remove original file
    rename("temp.txt", APPOINTMENT_FILE); // Rename temp file

    printf("Appointment deleted!\n");
}

int main() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}