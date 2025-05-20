//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    int day;
    int hour;
    char description[50];
};

void add_appointment(struct appointment *appointments, int *n) {
    if (*n == 10) {
        printf("Sorry, you have reached the maximum number of appointments.\n");
        return;
    }
    
    int day, hour;
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return;
    }
    
    printf("Enter the hour (0-23): ");
    scanf("%d", &hour);
    if (hour < 0 || hour > 23) {
        printf("Invalid hour.\n");
        return;
    }
    
    char description[50];
    printf("Enter the description: ");
    scanf("%s", description);
    
    appointments[*n].day = day;
    appointments[*n].hour = hour;
    strcpy(appointments[*n].description, description);
    *n += 1;
    
    printf("Appointment added successfully.\n");
}

void view_appointments(struct appointment *appointments, int n) {
    if (n == 0) {
        printf("You have no appointments.\n");
        return;
    }
    
    printf("Your appointments:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d - %02d:00 - %s\n", appointments[i].day, 10, appointments[i].hour, appointments[i].description);
    }
}

int main() {
    struct appointment appointments[10];
    int n = 0;
    
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("--------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_appointment(&appointments[0], &n); break;
            case 2: view_appointments(&appointments[0], n); break;
            case 3: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid choice.\n"); break;
        }
    }
}