//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100 // Maximum number of appointments the scheduler can handle at once.

struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
};

struct Scheduler {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int count; // Number of appointments currently set.
};

void menu();
void createAppointment(struct Scheduler *scheduler);
void listAppointments(struct Scheduler *scheduler);
void editAppointment(struct Scheduler *scheduler);
void deleteAppointment(struct Scheduler *scheduler);
void searchAppointment(struct Scheduler *scheduler);

int main() {
    struct Scheduler scheduler;
    scheduler.count = 0;
    
    while (true) {
        menu();
        
        int option;
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createAppointment(&scheduler);
                break;
            case 2:
                listAppointments(&scheduler);
                break;
            case 3:
                editAppointment(&scheduler);
                break;
            case 4:
                deleteAppointment(&scheduler);
                break;
            case 5:
                searchAppointment(&scheduler);
                break;
            case 6:
                printf("Exiting scheduler...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void menu() {
    printf("---------------------\n");
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Create Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Search Appointment\n");
    printf("6. Exit Scheduler\n");
}

void createAppointment(struct Scheduler *scheduler) {
    if (scheduler->count >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached. Cannot create more.\n");
        return;
    }
    
    struct Appointment newAppointment;
    
    printf("Enter name: ");
    scanf(" %[^\n]s", newAppointment.name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", newAppointment.date);
    printf("Enter time (hh:mm): ");
    scanf("%s", newAppointment.time);
    newAppointment.id = scheduler->count + 1;
    
    scheduler->appointments[scheduler->count++] = newAppointment;
    
    printf("Appointment created successfully.\n");
}

void listAppointments(struct Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    printf("ID\tName\t\tDate\t\tTime\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("%d\t%-15s\t%s\t%s\n", scheduler->appointments[i].id, 
        scheduler->appointments[i].name, scheduler->appointments[i].date, 
        scheduler->appointments[i].time);
    }
}

void editAppointment(struct Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    int id;
    printf("Enter ID of appointment to edit: ");
    scanf("%d", &id);
    
    for (int i = 0; i < scheduler->count; i++) {
        if (scheduler->appointments[i].id == id) {
            struct Appointment editedAppointment;
            
            printf("Enter new name (or enter - to skip): ");
            scanf(" %[^\n]s", editedAppointment.name);
            if (strcmp(editedAppointment.name, "-") != 0) {
                strcpy(scheduler->appointments[i].name, editedAppointment.name);
            }
            
            printf("Enter new date (dd/mm/yyyy) (or enter - to skip): ");
            scanf("%s", editedAppointment.date);
            if (strcmp(editedAppointment.date, "-") != 0) {
                strcpy(scheduler->appointments[i].date, editedAppointment.date);
            }
            
            printf("Enter new time (hh:mm) (or enter - to skip): ");
            scanf("%s", editedAppointment.time);
            if (strcmp(editedAppointment.time, "-") != 0) {
                strcpy(scheduler->appointments[i].time, editedAppointment.time);
            }
            
            printf("Appointment edited successfully.\n");
            return;
        }
    }
    
    printf("No appointment found with ID %d.\n", id);
}

void deleteAppointment(struct Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    int id;
    printf("Enter ID of appointment to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < scheduler->count; i++) {
        if (scheduler->appointments[i].id == id) {
            for (int j = i; j < (scheduler->count - 1); j++) {
                scheduler->appointments[j] = scheduler->appointments[j+1];
            }
            
            scheduler->count--;
            printf("Appointment deleted successfully.\n");
            return;
        }
    }
    
    printf("No appointment found with ID %d.\n", id);
}

void searchAppointment(struct Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    char searchTerm[50];
    printf("Enter name to search for: ");
    scanf(" %[^\n]s", searchTerm);
    
    bool found = false;
    printf("ID\tName\t\tDate\t\tTime\n");
    for (int i = 0; i < scheduler->count; i++) {
        if (strcmp(scheduler->appointments[i].name, searchTerm) == 0) {
            printf("%d\t%-15s\t%s\t%s\n", scheduler->appointments[i].id, 
            scheduler->appointments[i].name, scheduler->appointments[i].date, 
            scheduler->appointments[i].time);
            found = true;
        }
    }
    
    if (!found) {
        printf("No appointments found with name %s.\n", searchTerm);
    }
}