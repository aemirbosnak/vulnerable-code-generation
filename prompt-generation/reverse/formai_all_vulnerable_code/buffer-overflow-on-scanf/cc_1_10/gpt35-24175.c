//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// function prototypes
void addAppointment();
void viewAppointments();
void deleteAppointment();
void searchAppointment();
void updateAppointment();

// structure definition for appointment
struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[20];
    char reason[100];
};

// global variables
int count = 0;
struct Appointment data[100];

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Appointment\n2. View Appointments\n3. Delete Appointment\n4. Search Appointment\n5. Update Appointment\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // clears input buffer
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                updateAppointment();
                break;
            case 6:
                printf("\nExiting...");
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}

// function definition to add an appointment
void addAppointment() {
    int id;
    char name[50];
    char date[20];
    char time[20];
    char reason[100];
    
    fflush(stdin); // clears input buffer
    printf("\nEnter Patient Name: ");
    fgets(name, sizeof(name), stdin);
    printf("\nEnter Date of Appointment (dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);
    printf("\nEnter Time of Appointment (hh:mm AM/PM): ");
    fgets(time, sizeof(time), stdin);
    printf("\nEnter Reason for Appointment: ");
    fgets(reason, sizeof(reason), stdin);
    printf("\nAppointment added successfully.");

    // increment appointment count and set id
    count++;
    id = count;

    // store appointment details in global data array
    struct Appointment temp = {id};
    strncpy(temp.name, name, sizeof(temp.name));
    strncpy(temp.date, date, sizeof(temp.date));
    strncpy(temp.time, time, sizeof(temp.time));
    strncpy(temp.reason, reason, sizeof(temp.reason));
    data[count-1] = temp;
}

// function definition to view all appointments
void viewAppointments() {
    if(count == 0) {
        printf("\nNo appointments found.");
    }
    else {
        printf("\nAll Appointments:\n");
        printf("ID  Name\t\tDate\t\tTime\t\tReason\n");
        for(int i=0; i<count; i++) {
            printf("%d   %s\t%s\t%s\t%s", data[i].id, data[i].name, data[i].date, data[i].time, data[i].reason);
        }
    }
}

// function definition to delete an appointment
void deleteAppointment() {
    int id;
    int flag = 0;
    printf("\nEnter the ID of the appointment to be deleted: ");
    scanf("%d", &id);
    
    for(int i=0; i<count; i++) {
        if(data[i].id == id) {
            for(int j=i; j<count; j++) {
                data[j] = data[j+1];
            }
            count--;
            flag = 1;
            printf("\nAppointment deleted successfully.");
            break;
        }
    }

    if(flag == 0) {
        printf("\nAppointment not found.");
    }
}

// function definition to search for an appointment
void searchAppointment() {
    int choice;
    char key[50];
    printf("\n1. Search by ID\n2. Search by Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        int id, flag=0;
        printf("\nEnter the ID of the appointment: ");
        scanf("%d", &id);

        for(int i=0; i<count; i++) {
            if(data[i].id == id) {
                printf("\nAppointment Details:");
                printf("\nID: %d\nName: %sDate: %sTime: %sReason: %s", data[i].id, data[i].name, data[i].date, data[i].time, data[i].reason);
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            printf("\nAppointment not found.");
        }
    }
    else if(choice == 2) {
        getchar(); // clears input buffer
        printf("\nEnter the Name of the patient: ");
        fgets(key, sizeof(key), stdin);
        int flag = 0;

        for(int i=0; i<count; i++) {
            if(strcasecmp(data[i].name, key) == 0) {
                printf("\nAppointment Details:");
                printf("\nID: %d\nName: %sDate: %sTime: %sReason: %s", data[i].id, data[i].name, data[i].date, data[i].time, data[i].reason);
                flag = 1;
            }
        }

        if(flag == 0) {
            printf("\nAppointment not found.");
        }
    }
    else {
        printf("\nInvalid choice.");
    }
}

// function definition to update an appointment
void updateAppointment() {
    int id, choice;
    char newDate[20], newTime[20], newReason[100];
    printf("Enter the ID of the appointment to be updated: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++) {
        if(data[i].id == id) {
            printf("\n1. Update Date\n2. Update Time\n3. Update Reason\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("\nEnter new date (dd/mm/yyyy): ");
                scanf("%s", newDate);
                strncpy(data[i].date, newDate, sizeof(data[i].date));
                printf("\nAppointment updated successfully.");
            }
            else if(choice == 2) {
                printf("\nEnter new time (hh:mm AM/PM): ");
                scanf("%s", newTime);
                strncpy(data[i].time, newTime, sizeof(data[i].time));
                printf("\nAppointment updated successfully.");
            }
            else if(choice == 3) {
                printf("\nEnter new reason: ");
                getchar();
                fgets(newReason, sizeof(newReason), stdin);
                strncpy(data[i].reason, newReason, sizeof(data[i].reason));
                printf("\nAppointment updated successfully.");
            }
            else {
                printf("\nInvalid choice.");
            }
            break;
        }
    }
}