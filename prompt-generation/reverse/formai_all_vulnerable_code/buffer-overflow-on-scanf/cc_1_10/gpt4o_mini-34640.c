//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t time; // Store time as a time_t for easier manipulations
} Appointment;

void add_appointment(Appointment appointments[], int *count);
void view_appointments(Appointment appointments[], int count);
void remove_appointment(Appointment appointments[], int *count);
void paranoid_print(const char *message);
time_t get_user_input_time();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    paranoid_print("Welcome to the Paranoid Appointment Scheduler.");
    
    while (1) {
        paranoid_print("Please choose an option:");
        paranoid_print("1. Add Appointment");
        paranoid_print("2. View Appointments");
        paranoid_print("3. Remove Appointment");
        paranoid_print("4. Quit");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(appointments, &count);
                break;
            case 2:
                view_appointments(appointments, count);
                break;
            case 3:
                remove_appointment(appointments, &count);
                break;
            case 4:
                paranoid_print("Exiting program.");
                exit(0);
            default:
                paranoid_print("Invalid choice, please try again.");
        }
    }
    return 0; // Never gets here due to infinite loop, but just to keep the compiler happy
}

void add_appointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        paranoid_print("Max appointments reached. Cannot add more.");
        return;
    }

    char name[MAX_NAME_LENGTH];
    time_t time;

    paranoid_print("Enter the name for the appointment:");
    scanf(" %[^\n]%*c", name);
    paranoid_print("Please specify the appointment time (YYYY-MM-DD HH:MM):");
    time = get_user_input_time();
    
    if (time == -1) {
        paranoid_print("Invalid time format. Appointment not added.");
        return;
    }

    strcpy(appointments[*count].name, name);
    appointments[*count].time = time;
    (*count)++;
    
    paranoid_print("Appointment added successfully!");
}

void view_appointments(Appointment appointments[], int count) {
    if (count == 0) {
        paranoid_print("No appointments to display.");
        return;
    }

    paranoid_print("Here are your appointments:");
    for (int i = 0; i < count; i++) {
        char time_str[100];
        struct tm *tm_info;

        tm_info = localtime(&appointments[i].time);
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M", tm_info);
        printf("%d: %s at %s\n", i + 1, appointments[i].name, time_str);
    }
}

void remove_appointment(Appointment appointments[], int *count) {
    view_appointments(appointments, *count);

    if (*count == 0) return;

    int index;
    paranoid_print("Enter the number of the appointment to remove:");
    scanf("%d", &index);

    if (index <= 0 || index > *count) {
        paranoid_print("Invalid number. No appointment deleted.");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;

    paranoid_print("Appointment removed successfully!");
}

void paranoid_print(const char *message) {
    printf("[PARANOID]: %s\n", message); // Overlay each print statement with paranoia
}

time_t get_user_input_time() {
    char input[20];
    struct tm tm;
    
    scanf("%s", input);
    if (strptime(input, "%Y-%m-%d %H:%M", &tm) == NULL) {
        return -1; // Invalid time input
    }
    
    return mktime(&tm);
}