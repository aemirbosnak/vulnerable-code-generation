//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define MAX_DESC_LENGTH 255

typedef struct {
    char name[NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    time_t timestamp;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("System overload! Cannot accept more appointments.\n");
        return;
    }
    
    printf("Enter appointment name: ");
    fgets(appointments[appointment_count].name, NAME_LENGTH, stdin);
    appointments[appointment_count].name[strcspn(appointments[appointment_count].name, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(appointments[appointment_count].description, MAX_DESC_LENGTH, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = 0; // Remove newline

    printf("Enter appointment timestamp (format: YYYY-MM-DD HH:MM): ");
    struct tm tm;
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);
    strptime(buffer, "%Y-%m-%d %H:%M", &tm);
    appointments[appointment_count].timestamp = mktime(&tm);

    appointment_count++;
    printf("Appointment added to the Neon Grid!\n");
}

void list_appointments() {
    printf("Listing Appointments in the Grid...\n");
    for (int i = 0; i < appointment_count; i++) {
        char time_buffer[26];
        struct tm *tm_info;

        tm_info = localtime(&appointments[i].timestamp);
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M", tm_info);
        
        printf("%d. [%s] %s - %s\n", i + 1, time_buffer, appointments[i].name, appointments[i].description);
    }
}

void remove_appointment() {
    int index;
    printf("Enter appointment number to remove: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }
    
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;

    printf("Appointment removed. The Grid feels lighter!\n");
}

void display_menu() {
    printf("\n=== Neon City Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
    printf("=======================================\n");
    printf("Choose an action: ");
}

int main() {
    char choice;
    while (1) {
        display_menu();
        choice = getchar();
        while (getchar() != '\n'); // Clear buffer
        
        switch (choice) {
            case '1':
                add_appointment();
                break;
            case '2':
                list_appointments();
                break;
            case '3':
                remove_appointment();
                break;
            case '4':
                printf("Exiting the Neon Grid...\n");
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}