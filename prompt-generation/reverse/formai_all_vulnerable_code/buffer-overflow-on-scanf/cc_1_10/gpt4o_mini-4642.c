//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_HEALTH_DATA 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
} Appointment;

typedef struct {
    char date[11];
    char healthMetrics[MAX_HEALTH_DATA];
} HealthRecord;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount;
    HealthRecord healthHistory[MAX_HEALTH_DATA];
    int healthCount;
} AstralAssistant;

void displayMenu() {
    printf("\n== Welcome to Astral, Your Virtual Assistant for 3023 ==\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Add Health Record\n");
    printf("4. View Health Records\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addAppointment(AstralAssistant *assistant) {
    if (assistant->appointmentCount >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached!\n");
        return;
    }
    
    Appointment apt;
    printf("Enter appointment name: ");
    scanf("%s", apt.name);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", apt.date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", apt.time);
    
    assistant->appointments[assistant->appointmentCount++] = apt;
    printf("Appointment added successfully!\n");
}

void viewAppointments(const AstralAssistant *assistant) {
    if (assistant->appointmentCount == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    printf("\n== Appointment List ==\n");
    for (int i = 0; i < assistant->appointmentCount; i++) {
        printf("%d: %s on %s at %s\n", i + 1, 
               assistant->appointments[i].name,
               assistant->appointments[i].date, 
               assistant->appointments[i].time);
    }
}

void addHealthRecord(AstralAssistant *assistant) {
    if (assistant->healthCount >= MAX_HEALTH_DATA) {
        printf("Maximum health records limit reached!\n");
        return;
    }
    
    HealthRecord record;
    printf("Enter health record date (YYYY-MM-DD): ");
    scanf("%s", record.date);
    printf("Enter health metrics (e.g., blood pressure, heart rate): ");
    scanf(" %[^\n]", record.healthMetrics);  // Read string with spaces
    
    assistant->healthHistory[assistant->healthCount++] = record;
    printf("Health record added successfully!\n");
}

void viewHealthRecords(const AstralAssistant *assistant) {
    if (assistant->healthCount == 0) {
        printf("No health records found!\n");
        return;
    }
    
    printf("\n== Health Record History ==\n");
    for (int i = 0; i < assistant->healthCount; i++) {
        printf("%d: %s - %s\n", i + 1,
               assistant->healthHistory[i].date, 
               assistant->healthHistory[i].healthMetrics);
    }
}

int main() {
    AstralAssistant myAssistant = { .appointmentCount = 0, .healthCount = 0 };
    int option;
    
    do {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addAppointment(&myAssistant);
                break;
            case 2:
                viewAppointments(&myAssistant);
                break;
            case 3:
                addHealthRecord(&myAssistant);
                break;
            case 4:
                viewHealthRecords(&myAssistant);
                break;
            case 5:
                printf("Exiting Astral... Have a great day!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 5);
    
    return 0;
}