//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Wow! You've reached the maximum number of appointments!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment description: ");
    scanf(" %[^\n]", new_appointment.description); // Reads a line with spaces

    printf("Enter date (YYYY-MM-DD): ");
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);

    printf("Enter time (HH MM, 24-hour format): ");
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    new_appointment.date_time.tm_year = year - 1900; // tm_year is year since 1900
    new_appointment.date_time.tm_mon = month - 1; // tm_mon is 0-11
    new_appointment.date_time.tm_mday = day;
    new_appointment.date_time.tm_hour = hour;
    new_appointment.date_time.tm_min = minute;
    new_appointment.date_time.tm_sec = 0;
    new_appointment.date_time.tm_isdst = -1; // Let the system determine if DST is in effect

    appointments[appointment_count++] = new_appointment;
    printf("Surprise! Appointment added successfully!\n");
}

void display_appointments() {
    if (appointment_count == 0) {
        printf("Oh no! No appointments scheduled!\n");
        return;
    }

    printf("Here are your scheduled appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &appointments[i].date_time);
        printf("%d. [%s] - %s\n", i + 1, buffer, appointments[i].description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("Oh dear! No appointments to delete!\n");
        return;
    }

    display_appointments();
    printf("Enter appointment number to delete: ");
    int index;
    scanf("%d", &index);
    index--; // To convert to 0-based index

    if (index < 0 || index >= appointment_count) {
        printf("Yikes! Invalid appointment number!\n");
        return;
    }

    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Voila! Appointment deleted successfully!\n");
}

void save_appointments() {
    FILE *file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Oh no! Could not save appointments.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        fprintf(file, "%s,%d-%d-%d %d:%d\n",
                appointments[i].description,
                appointments[i].date_time.tm_year + 1900,
                appointments[i].date_time.tm_mon + 1,
                appointments[i].date_time.tm_mday,
                appointments[i].date_time.tm_hour,
                appointments[i].date_time.tm_min);
    }
    fclose(file);
    printf("Hooray! Appointments saved to 'appointments.txt'\n");
}

void load_appointments() {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Oh no! Could not load appointments.\n");
        return;
    }

    while (fscanf(file, " %[^\n],%d-%d-%d %d:%d\n",
                  appointments[appointment_count].description,
                  &appointments[appointment_count].date_time.tm_year,
                  &appointments[appointment_count].date_time.tm_mon,
                  &appointments[appointment_count].date_time.tm_mday,
                  &appointments[appointment_count].date_time.tm_hour,
                  &appointments[appointment_count].date_time.tm_min) != EOF) {
        
        appointments[appointment_count].date_time.tm_year -= 1900; // Adjust year
        appointments[appointment_count].date_time.tm_mon -= 1; // Adjust month
        appointments[appointment_count].date_time.tm_isdst = -1; // Let the system determine if DST is in effect
        appointment_count++;
    }
    fclose(file);
    printf("Fantastic! Appointments loaded successfully!\n");
}

int main() {
    load_appointments();
    int option;
    
    do {
        printf("\n==== Appointment Scheduler ====\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("5. Load Appointments\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                save_appointments();
                break;
            case 5:
                load_appointments();
                break;
            case 0:
                printf("Exiting… Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Whoa! Invalid option! Try again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}