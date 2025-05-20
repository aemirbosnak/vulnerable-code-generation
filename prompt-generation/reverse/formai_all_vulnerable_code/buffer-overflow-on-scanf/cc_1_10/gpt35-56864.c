//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment {
    int id;
    char name[20];
    char date[10];
    char time[10];
};

// global variables
struct appointment allAppointments[20];
static int count = 0;

// function prototypes
void addAppointment();
void viewAppointments();
void searchAppointment();
void deleteAppointment();

int main() {
    int choice;
    do {
        printf("\n---APPOINTMENT SCHEDULER---\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Search appointment\n");
        printf("4. Delete appointment\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}

void addAppointment() {
    struct appointment newAppointment;

    printf("\nEnter ID: ");
    scanf("%d", &newAppointment.id);

    printf("Enter Name: ");
    scanf("%s", newAppointment.name);

    printf("Enter Date (dd-mm-yyyy): ");
    scanf("%s", newAppointment.date);

    printf("Enter Time (hh:mm): ");
    scanf("%s", newAppointment.time);

    allAppointments[count++] = newAppointment;
    printf("\nAppointment added successfully!\n");
}

void viewAppointments() {
    if(count == 0) {
        printf("\nNo appointments to display!\n");
        return;
    }

    printf("\nAll Appointments:\n");
    printf("ID\t   NAME\t   DATE\t TIME\n");

    for(int i=0; i<count; i++) {
        printf("%d\t", allAppointments[i].id);
        printf("%s\t   ", allAppointments[i].name);
        printf("%s\t ", allAppointments[i].date);
        printf("%s\n", allAppointments[i].time);
    }
}

void searchAppointment() {
    if(count == 0) {
        printf("\nNo appointments to search!\n");
        return;
    }

    int id, found=0;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(allAppointments[i].id == id) {
            found = 1;
            printf("\nAppointment found!\n");
            printf("ID\t   NAME\t   DATE\t TIME\n");
            printf("%d\t", allAppointments[i].id);
            printf("%s\t   ", allAppointments[i].name);
            printf("%s\t ", allAppointments[i].date);
            printf("%s\n", allAppointments[i].time);
            break;
        }
    }

    if(found == 0)
        printf("\nAppointment not found!\n");
}

void deleteAppointment() {
    if(count == 0) {
        printf("\nNo appointments to delete!\n");
        return;
    }

    int id, found=0;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(allAppointments[i].id == id) {
            found = 1;

            // shift the array by 1 towards left
            for(int j=i; j<count-1; j++) {
                allAppointments[j] = allAppointments[j+1];
            }

            count--;
            printf("\nAppointment deleted successfully!\n");
            break;
        }
    }

    if(found == 0)
        printf("\nAppointment not found!\n");
}