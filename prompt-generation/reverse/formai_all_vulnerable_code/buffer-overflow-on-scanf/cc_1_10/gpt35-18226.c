//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures and variables
typedef struct {
    char name[20];
    char date[10];
    char time[5];
} appointment;

appointment appts[50];
int count = 0;

// Function prototypes
void print_menu();
void add_appt();
void view_appts();
void search_appts();
void delete_appt();

// Main function
int main() {
    int choice;
    while(1) {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_appt();
                break;
            case 2:
                view_appts();
                break;
            case 3:
                search_appts();
                break;
            case 4:
                delete_appt();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Print menu function
void print_menu() {
    printf("\n\nAPPOINTMENT SCHEDULER\n\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Search Appointments\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Add appointment function
void add_appt() {
    if(count == 50) {
        printf("Maximum limit reached. Cannot add new appointment.\n");
        return;
    }
    printf("Enter appointment name: ");
    scanf("%s", appts[count].name);
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", appts[count].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appts[count].time);
    printf("Appointment added successfully.\n");
    count++;
}

// View appointments function
void view_appts() {
    if(count == 0) {
        printf("No appointments found.\n");
        return;
    }
    printf("APPOINTMENT LIST\n\n");
    printf("%-20s%-10s%-5s\n", "Name", "Date", "Time");
    for(int i=0; i<count; i++) {
        printf("%-20s%-10s%-5s\n", appts[i].name, appts[i].date, appts[i].time);
    }
}

// Search appointments function
void search_appts() {
    if(count == 0) {
        printf("No appointments found.\n");
        return;
    }
    char search_name[20];
    printf("Enter appointment name to search: ");
    scanf("%s", search_name);
    for(int i=0; i<count; i++) {
        if(strcmp(search_name, appts[i].name) == 0) {
            printf("APPOINTMENT FOUND\n");
            printf("%-20s%-10s%-5s\n", "Name", "Date", "Time");
            printf("%-20s%-10s%-5s\n", appts[i].name, appts[i].date, appts[i].time);
            return;
        }
    }
    printf("No appointments found with the given name.\n");
}

// Delete appointment function
void delete_appt() {
    if(count == 0) {
        printf("No appointments found.\n");
        return;
    }
    char del_name[20];
    printf("Enter appointment name to delete: ");
    scanf("%s", del_name);
    for(int i=0; i<count; i++) {
        if(strcmp(del_name, appts[i].name) == 0) {
            for(int j=i; j<count-1; j++) {
                strcpy(appts[j].name, appts[j+1].name);
                strcpy(appts[j].date, appts[j+1].date);
                strcpy(appts[j].time, appts[j+1].time);
            }
            strcpy(appts[count-1].name, "");
            strcpy(appts[count-1].date, "");
            strcpy(appts[count-1].time, "");
            count--;
            printf("Appointment deleted successfully.\n");
            return;
        }
    }
    printf("No appointments found with the given name.\n");
}