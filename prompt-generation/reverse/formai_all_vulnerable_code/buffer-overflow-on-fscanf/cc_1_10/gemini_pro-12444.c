//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
// Ava's Automaton: An Appointment Scheduler Inspired by Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 255

// Data Structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t startTime;
    time_t endTime;
} Appointment;

// Global Variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

// Function Declarations
void addAppointment(char* name, char* description, time_t startTime, time_t endTime);
void removeAppointment(int index);
void editAppointment(int index, char* name, char* description, time_t startTime, time_t endTime);
void printAppointments();
void saveAppointments();
void loadAppointments();

// Main Function
int main() {
    printf("Greetings, user. I am Ava, your automated appointment scheduler.\n");
    printf("May I inquire as to your name?\n");

    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    printf("Well met, %s. How may I serve you today?\n", name);

    // Main loop
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. Edit appointment\n");
        printf("4. Print appointments\n");
        printf("5. Save appointments\n");
        printf("6. Load appointments\n");
        printf("7. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[MAX_NAME_LENGTH];
                    printf("Appointment name: ");
                    scanf(" %[^\n]", name);

                    char description[MAX_DESCRIPTION_LENGTH];
                    printf("Appointment description: ");
                    scanf(" %[^\n]", description);

                    time_t startTime;
                    printf("Appointment start time (YYYY-MM-DD HH:MM): ");
                    scanf(" %lld", &startTime);

                    time_t endTime;
                    printf("Appointment end time (YYYY-MM-DD HH:MM): ");
                    scanf(" %lld", &endTime);

                    addAppointment(name, description, startTime, endTime);
                    printf("Appointment added.\n");
                }
                break;
            case 2:
                {
                    int index;
                    printf("Appointment index to remove: ");
                    scanf(" %d", &index);

                    removeAppointment(index);
                    printf("Appointment removed.\n");
                }
                break;
            case 3:
                {
                    int index;
                    printf("Appointment index to edit: ");
                    scanf(" %d", &index);

                    char name[MAX_NAME_LENGTH];
                    printf("New appointment name: ");
                    scanf(" %[^\n]", name);

                    char description[MAX_DESCRIPTION_LENGTH];
                    printf("New appointment description: ");
                    scanf(" %[^\n]", description);

                    time_t startTime;
                    printf("New appointment start time (YYYY-MM-DD HH:MM): ");
                    scanf(" %lld", &startTime);

                    time_t endTime;
                    printf("New appointment end time (YYYY-MM-DD HH:MM): ");
                    scanf(" %lld", &endTime);

                    editAppointment(index, name, description, startTime, endTime);
                    printf("Appointment edited.\n");
                }
                break;
            case 4:
                printAppointments();
                break;
            case 5:
                saveAppointments();
                printf("Appointments saved.\n");
                break;
            case 6:
                loadAppointments();
                printf("Appointments loaded.\n");
                break;
            case 7:
                printf("Farewell, %s. May your appointments be fruitful.\n", name);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

// Function Definitions
void addAppointment(char* name, char* description, time_t startTime, time_t endTime) {
    if (numAppointments < MAX_APPOINTMENTS) {
        strcpy(appointments[numAppointments].name, name);
        strcpy(appointments[numAppointments].description, description);
        appointments[numAppointments].startTime = startTime;
        appointments[numAppointments].endTime = endTime;
        numAppointments++;
    } else {
        printf("Error: Maximum number of appointments reached.\n");
    }
}

void removeAppointment(int index) {
    if (index >= 0 && index < numAppointments) {
        for (int i = index; i < numAppointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        numAppointments--;
    } else {
        printf("Error: Invalid appointment index.\n");
    }
}

void editAppointment(int index, char* name, char* description, time_t startTime, time_t endTime) {
    if (index >= 0 && index < numAppointments) {
        strcpy(appointments[index].name, name);
        strcpy(appointments[index].description, description);
        appointments[index].startTime = startTime;
        appointments[index].endTime = endTime;
    } else {
        printf("Error: Invalid appointment index.\n");
    }
}

void printAppointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s: %s\n", i + 1, appointments[i].name, appointments[i].description);
        printf("    Start time: %s\n", ctime(&appointments[i].startTime));
        printf("    End time: %s\n", ctime(&appointments[i].endTime));
    }
}

void saveAppointments() {
    FILE* file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
    } else {
        for (int i = 0; i < numAppointments; i++) {
            fprintf(file, "%s\n", appointments[i].name);
            fprintf(file, "%s\n", appointments[i].description);
            fprintf(file, "%lld\n", appointments[i].startTime);
            fprintf(file, "%lld\n", appointments[i].endTime);
        }
        fclose(file);
    }
}

void loadAppointments() {
    FILE* file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
    } else {
        numAppointments = 0;
        while (!feof(file)) {
            char name[MAX_NAME_LENGTH];
            fscanf(file, "%s\n", name);

            char description[MAX_DESCRIPTION_LENGTH];
            fscanf(file, "%s\n", description);

            time_t startTime;
            fscanf(file, "%lld\n", &startTime);

            time_t endTime;
            fscanf(file, "%lld\n", &endTime);

            addAppointment(name, description, startTime, endTime);
        }
        fclose(file);
    }
}