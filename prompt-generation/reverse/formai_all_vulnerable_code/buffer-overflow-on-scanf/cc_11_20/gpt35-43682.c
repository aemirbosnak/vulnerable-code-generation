//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Appointment {
    char name[30];
    char date[10];
    char time[10];
    char status[15];
};

int main() {
    int choice, n;
    struct Appointment apt[100];
    printf("**********APPOINTMENT SCHEDULER**********\n");
    do {
        printf("\n1. Create Appointment \n2. View Appointment\n3. Edit Appointment\n4. Cancel Appointment \n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the number of appointments you want to create: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++) {
                    printf("\nEnter Name of the patient: ");
                    scanf("%s", apt[i].name);
                    printf("Enter Date of Appointment (DD-MM-YYYY): ");
                    scanf("%s", apt[i].date);
                    printf("Enter Time of Appointment (HH:MM): ");
                    scanf("%s", apt[i].time);
                    strcpy(apt[i].status, "Upcoming");
                    printf("\nAppointment created successfully!\n");
                }
                break;
            case 2:
                printf("\nEnter the Date of the appointment you want to view (DD-MM-YYYY) : ");
                char date_view[10];
                scanf("%s", date_view);
                int flag=0;
                for(int i=0; i<n; i++) {
                    if(strcmp(apt[i].date, date_view)==0) {
                        printf("\nName of the Patient: %s\nDate of Appointment: %s\nTime of Appointment: %s\nAppointment Status: %s\n", apt[i].name, apt[i].date, apt[i].time, apt[i].status);
                        flag=1;
                    }
                }
                if(flag==0) {
                    printf("\nNo appointments found for the given Date\n");
                }
                break;
            case 3:
                printf("\nEnter the Date of the appointment you want to edit (DD-MM-YYYY) : ");
                char date_edit[10];
                scanf("%s", date_edit);
                flag=0;
                for(int i=0; i<n; i++) {
                    if(strcmp(apt[i].date, date_edit)==0) {
                        printf("\nName of the Patient: %s\nDate of Appointment: %s\nTime of Appointment: %s\nAppointment Status: %s\n", apt[i].name, apt[i].date, apt[i].time, apt[i].status);
                        printf("\nUpdate the details of this Appointment: \n");
                        printf("Enter Name of the patient: ");
                        scanf("%s", apt[i].name);
                        printf("Enter Date of Appointment (DD-MM-YYYY): ");
                        scanf("%s", apt[i].date);
                        printf("Enter Time of Appointment (HH:MM): ");
                        scanf("%s", apt[i].time);
                        printf("\nAppointment updated successfully!\n");
                        flag=1;
                    }
                }
                if(flag==0) {
                    printf("\nNo appointments found for the given Date\n");
                }
                break;
            case 4:
                printf("\nEnter the Date of the appointment you want to cancel (DD-MM-YYYY) : ");
                char date_cancel[10];
                scanf("%s", date_cancel);
                flag=0;
                for(int i=0; i<n; i++) {
                    if(strcmp(apt[i].date, date_cancel)==0) {
                        printf("\nName of the Patient: %s\nDate of Appointment: %s\nTime of Appointment: %s\nAppointment Status: %s\n", apt[i].name, apt[i].date, apt[i].time, apt[i].status);
                        strcpy(apt[i].status, "Cancelled");
                        printf("\nAppointment Cancelled successfully!\n");
                        flag=1;
                    }
                }
                if(flag==0) {
                    printf("\nNo appointments found for the given Date\n");
                }
                break;
            case 5:
                printf("\nThank you for using the Appointment scheduler!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    }while(choice!=5);
    return 0;
}