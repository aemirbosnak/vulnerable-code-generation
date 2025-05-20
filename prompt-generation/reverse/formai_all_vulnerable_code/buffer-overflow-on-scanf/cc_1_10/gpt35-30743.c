//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    int id;
    char date[20];
    char time[20];
    char description[100];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int next_id = 1;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_appointment() {
    if (next_id > MAX_APPOINTMENTS) {
        printf("Cannot add more appointments.\n");
        return;
    }
    printf("\nEnter appointment date: ");
    scanf("%19s", appointments[next_id - 1].date);
    clear_buffer();
    
    printf("Enter appointment time: ");
    scanf("%19s", appointments[next_id - 1].time);
    clear_buffer();
    
    printf("Enter appointment description: ");
    scanf("%99[^\n]", appointments[next_id - 1].description);
    clear_buffer();
    
    appointments[next_id - 1].id = next_id;
    next_id++;
    printf("Appointment added successfully.\n");
}

void update_appointment() {
    printf("\nEnter appointment ID to update: ");
    int id;
    scanf("%d", &id);
    clear_buffer();
    
    bool found = false;
    for (int i = 0; i < next_id - 1; i++) {
        if (appointments[i].id == id) {
            found = true;
            printf("Enter new appointment date (current: %s): ", appointments[i].date);
            scanf("%19s", appointments[i].date);
            clear_buffer();
            
            printf("Enter new appointment time (current: %s): ", appointments[i].time);
            scanf("%19s", appointments[i].time);
            clear_buffer();
            
            printf("Enter new appointment description (current: %s): ", appointments[i].description);
            scanf("%99[^\n]", appointments[i].description);
            clear_buffer();
            
            printf("Appointment updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Appointment with ID %d not found.\n", id);
    }
}

void delete_appointment() {
    printf("\nEnter appointment ID to delete: ");
    int id;
    scanf("%d", &id);
    clear_buffer();
    
    bool found = false;
    for (int i = 0; i < next_id - 1; i++) {
        if (appointments[i].id == id) {
            found = true;
            for (int j = i; j < next_id - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            next_id--;
            printf("Appointment deleted successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Appointment with ID %d not found.\n", id);
    }
}

void view_appointments() {
    if (next_id == 1) {
        printf("No appointments. \n");
        return;
    }
    
    printf("\nAll appointments:\n");
    printf("ID\tDate\tTime\tDescription\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < next_id - 1; i++) {
        printf("%d\t%s\t%s\t%s\n", appointments[i].id, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

int main() {
    int choice;
    
    while (true) {
        printf("\nAPPOINTMENT SCHEDULER\n");
        printf("Please choose an option:\n");
        printf("1. Add appointment\n");
        printf("2. Update appointment\n");
        printf("3. Delete appointment\n");
        printf("4. View all appointments\n");
        printf("5. Exit\n");
        printf("Choice (1-5): ");
        scanf("%d", &choice);
        clear_buffer();
        
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                update_appointment();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                view_appointments();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}