//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LEN 50
#define DESC_LEN 100

typedef struct {
    char name[NAME_LEN];
    char description[DESC_LEN];
    time_t startTime;
    time_t endTime;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment(const char* name, const char* description, time_t startTime, time_t endTime) {
    if (appointmentCount < MAX_APPOINTMENTS) {
        strncpy(appointments[appointmentCount].name, name, NAME_LEN);
        strncpy(appointments[appointmentCount].description, description, DESC_LEN);
        appointments[appointmentCount].startTime = startTime;
        appointments[appointmentCount].endTime = endTime;
        appointmentCount++;
        printf("Appointment added successfully.\n");
    } else {
        printf("Maximum appointment limit reached.\n");
    }
}

void listAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        struct tm *startTm = localtime(&appointments[i].startTime);
        struct tm *endTm = localtime(&appointments[i].endTime);
        printf("--------------------------------------------------\n");
        printf("Appointment #%d\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start Time: %s", asctime(startTm));
        printf("End Time: %s", asctime(endTm));
    }
    printf("--------------------------------------------------\n");
}

void deleteAppointment(int index) {
    if (index < 0 || index >= appointmentCount) {
        printf("Invalid appointment index.\n");
        return;
    }

    for (int i = index; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCount--;
    printf("Appointment deleted successfully.\n");
}

void saveToFile(const char* filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&appointmentCount, sizeof(int), 1, file);
    fwrite(appointments, sizeof(Appointment), appointmentCount, file);
    fclose(file);
    printf("Appointments saved to %s\n", filename);
}

void loadFromFile(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(&appointmentCount, sizeof(int), 1, file);
    fread(appointments, sizeof(Appointment), appointmentCount, file);
    fclose(file);
    printf("Appointments loaded from %s\n", filename);
}

void displayMenu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[NAME_LEN], description[DESC_LEN];
    time_t startTime, endTime;
    struct tm tm;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter appointment name: ");
                scanf(" %[^\n]", name);
                printf("Enter appointment description: ");
                scanf(" %[^\n]", description);
                
                printf("Enter start time (YYYY MM DD HH MM): ");
                scanf("%d %d %d %d %d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
                tm.tm_year -= 1900; // years since 1900
                tm.tm_mon -= 1; // months are zero-indexed
                tm.tm_isdst = -1; // determine whether daylight saving time is in effect
                startTime = mktime(&tm);
                
                printf("Enter end time (YYYY MM DD HH MM): ");
                scanf("%d %d %d %d %d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);
                tm.tm_year -= 1900; // years since 1900
                tm.tm_mon -= 1; // months are zero-indexed
                tm.tm_isdst = -1; // determine whether daylight saving time is in effect
                endTime = mktime(&tm);
                
                addAppointment(name, description, startTime, endTime);
                break;

            case 2:
                listAppointments();
                break;

            case 3:
                printf("Enter appointment index to delete: ");
                int index;
                scanf("%d", &index);
                deleteAppointment(index - 1);
                break;

            case 4:
                saveToFile("appointments.dat");
                break;

            case 5:
                loadFromFile("appointments.dat");
                break;

            case 6:
                printf("Exiting... Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}