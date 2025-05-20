//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for storing appointment details
struct appointment {
    char name[100];
    int day;
    int time;
};

// Function for scheduling a new appointment
void scheduleAppointment(struct appointment *appointments, int *numAppointments) {
    char name[100];
    int day, time;
    
    // Prompt user for name, day, and time of appointment
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter day (1-30): ");
    scanf("%d", &day);
    printf("Enter time (1-12): ");
    scanf("%d", &time);
    
    // Check if appointment slot is already taken
    for (int i = 0; i < *numAppointments; i++) {
        if (appointments[i].day == day && appointments[i].time == time) {
            printf("Sorry, that appointment slot is already taken.\n");
            return;
        }
    }
    
    // Save new appointment to array and increment appointment counter
    strcpy(appointments[*numAppointments].name, name);
    appointments[*numAppointments].day = day;
    appointments[*numAppointments].time = time;
    (*numAppointments)++;
    
    printf("Appointment scheduled successfully.\n");
}

// Function for cancelling an existing appointment
void cancelAppointment(struct appointment *appointments, int *numAppointments) {
    char name[100];
    int day, time;
    
    // Prompt user for name, day, and time of appointment to cancel
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter day (1-30): ");
    scanf("%d", &day);
    printf("Enter time (1-12): ");
    scanf("%d", &time);
    
    // Check if appointment exists and remove it from array
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && appointments[i].day == day && appointments[i].time == time) {
            for (int j = i; j < *numAppointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            (*numAppointments)--;
            printf("Appointment cancelled successfully.\n");
            return;
        }
    }
    
    printf("Sorry, no appointment was found with that name, day, and time.\n");
}

// Function for printing all scheduled appointments
void printAppointments(struct appointment *appointments, int *numAppointments) {
    if (*numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Name", "Day", "Time");
    for (int i = 0; i < *numAppointments; i++) {
        printf("%-20s %-10d %-10d\n", appointments[i].name, appointments[i].day, appointments[i].time);
    }
}

int main() {
    int option, numAppointments = 0;
    struct appointment appointments[100];
    
    // Seed srand with current time to generate random appointment requests
    srand(time(NULL));
    
    do {
        printf("\n====== Appointment Scheduler ======\n");
        printf("1. Schedule new appointment\n");
        printf("2. Cancel existing appointment\n");
        printf("3. Print all appointments\n");
        printf("4. Generate random appointment request\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                break;
            case 2:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 3:
                printAppointments(appointments, &numAppointments);
                break;
            case 4:
                // Generate random appointment request
                strcpy(appointments[numAppointments].name, "John Doe");
                appointments[numAppointments].day = rand() % 30 + 1;
                appointments[numAppointments].time = rand() % 12 + 1;
                numAppointments++;
                printf("Random appointment request generated.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
        
    } while (option != 5);
    
    return 0;
}