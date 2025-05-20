//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
// Donald Knuth Style Appointment Scheduler Example Program


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Structure to hold the details of an appointment
struct appointment {
    char date[20];
    char time[12];
    char name[50];
    char phone[20];
};

// Function to add a new appointment
void addAppointment(struct appointment *ap) {
    printf("\nEnter Appointment Details:\n");
    printf("Date (dd/mm/yyyy)   : ");
    fflush(stdin);
    gets(ap->date);
    printf("Time (hh:mm AM/PM)  : ");
    fflush(stdin);
    gets(ap->time);
    printf("Name                : ");
    fflush(stdin);
    gets(ap->name);
    printf("Phone               : ");
    fflush(stdin);
    gets(ap->phone);
    printf("\nAppointment Added Successfully!\n");
}

// Function to view all appointments
void viewAppointments(struct appointment *ap, int count) {
    if(count == 0) {
        printf("\nNo Appointments Found!\n");
    }
    else {
        printf("\nAll Appointments:\n");
        printf("------------------\n");
        for(int i = 0; i < count; i++) {
            printf("\nDate    : %s\n", ap[i].date);
            printf("Time    : %s\n", ap[i].time);
            printf("Name    : %s\n", ap[i].name);
            printf("Phone   : %s\n", ap[i].phone);
            printf("------------------");
        }
    }
}

// Function to search for a specific appointment
void searchAppointment(struct appointment *ap, int count) {
    char searchDate[20];
    int found = 0;
    printf("\nEnter Date to Search (dd/mm/yyyy) : ");
    fflush(stdin);
    gets(searchDate);
    for(int i = 0; i < count; i++) {
        if(strcmp(ap[i].date, searchDate) == 0) {
            found = 1;
            printf("\nAppointment Found!\n");
            printf("-------------------\n");
            printf("Date    : %s\n", ap[i].date);
            printf("Time    : %s\n", ap[i].time);
            printf("Name    : %s\n", ap[i].name);
            printf("Phone   : %s\n", ap[i].phone);
            printf("-------------------\n");
            break;
        }
    }
    if(!found) {
        printf("\nAppointment Not Found!\n");
    }
}

int main() {
    int choice, count = 0;
    struct appointment *ap;
    ap = (struct appointment*) malloc(sizeof(struct appointment) * 50);
    while(1) {
        printf("\nAppointment Scheduler\n");
        printf("----------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Search for Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Add a new appointment
                addAppointment(&ap[count]);
                count++;
                break;
            case 2:
                // View all appointments
                viewAppointments(ap, count);
                break;
            case 3:
                // Search for a specific appointment
                searchAppointment(ap, count);
                break;
            case 4:
                // Exit program
                free(ap);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
    return 0;
}