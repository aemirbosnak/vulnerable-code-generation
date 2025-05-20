//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LEN 20

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[MAX_NAME_LEN];
    Time time;
} Appointment;

void print_menu(void) {
    printf("\n\n1. Add appointment\n");
    printf("2. Remove appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit\n\n");
}

int add_appointment(Appointment appointments[], int count) {
    char name[MAX_NAME_LEN];
    Time time;
    
    if (count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return count;
    }
    
    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline
    
    printf("Enter time (HH:MM): ");
    scanf("%d:%d", &time.hour, &time.minute);
    getchar(); // consume trailing newline
    
    Appointment new_appointment = {0};
    strcpy(new_appointment.name, name);
    new_appointment.time = time;
    
    appointments[count] = new_appointment;
    printf("Appointment added successfully.\n");
    
    return count+1;
}

int remove_appointment(Appointment appointments[], int count) {
    char name[MAX_NAME_LEN];
    int i, j, found = 0;
    
    printf("Enter name of appointment to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline
    
    for (i = 0; i < count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Appointment not found.\n");
        return count;
    }
    
    // remove appointment by shifting all subsequent appointments to the left
    for (j = i+1; j < count; j++) {
        appointments[j-1] = appointments[j];
    }
    
    printf("Appointment removed successfully.\n");
    
    return count-1;
}

void view_appointments(Appointment appointments[], int count) {
    int i;
    
    printf("     Name     |     Time\n");
    printf("---------------|-----------\n");
    
    for (i = 0; i < count; i++) {
        printf("%-15s|%02d:%02d\n", appointments[i].name, appointments[i].time.hour, appointments[i].time.minute);
    }
}

int main(void) {
    int choice, count = 0;
    Appointment appointments[MAX_APPOINTMENTS] = {{0}};
    
    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume trailing newline
        
        switch (choice) {
            case 1:
                count = add_appointment(appointments, count);
                break;
            case 2:
                count = remove_appointment(appointments, count);
                break;
            case 3:
                view_appointments(appointments, count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}