//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct date{
    int day;
    int month;
    int year;
};

struct appointment{
    int appointmentId;
    struct date date;
    char time[5];
    char name[50];
};

void createAppointment(struct appointment a[], int *i, int appointmentId, struct date date, char time[], char name[]);
void displayAppointment(struct appointment a[], int n);
void cancelAppointment(struct appointment a[], int *n, int appointmentId);
void searchAppointment(struct appointment a[], int n, struct date date);

int main()
{
    int choice, appointmentId = 0, n = 0;
    struct date date;
    char time[5], name[50];
    struct appointment a[50];

    while(1){
        printf("\n******* Appointment Scheduler *******\n");
        printf("1. Create Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Search Appointment\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice){
            case 1:{
                printf("\nEnter date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &date.day, &date.month, &date.year);
                fflush(stdin);

                printf("Enter time (hh:mm): ");
                scanf("%s", time);
                fflush(stdin);

                printf("Enter name: ");
                gets(name);
                fflush(stdin);

                createAppointment(a, &n, ++appointmentId, date, time, name);

                printf("\nAppointment created successfully!\n");
                break;
            }

            case 2:{
                displayAppointment(a, n);
                break;
            }

            case 3:{
                printf("\nEnter the appointment ID to cancel: ");
                scanf("%d", &appointmentId);
                fflush(stdin);

                cancelAppointment(a, &n, appointmentId);

                break;
            }

            case 4:{
                printf("\nEnter date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &date.day, &date.month, &date.year);
                fflush(stdin);

                searchAppointment(a, n, date);

                break;
            }

            case 5:
                printf("\nThank you for using Appointment Scheduler!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createAppointment(struct appointment a[], int *n, int appointmentId, struct date date, char time[], char name[]){
    a[(*n)].appointmentId = appointmentId;
    a[(*n)].date = date;
    strcpy(a[(*n)].time, time);
    strcpy(a[(*n)].name, name);

    (*n)++;
}

void displayAppointment(struct appointment a[], int n){
    int i;
    if(n == 0){
        printf("\nNo appointments found!\n");
        return;
    }
    printf("\nAppointment Details:\n");
    printf("ID\tDATE\t\tTIME\tNAME\n");
    printf("----------------------------------------------\n");
    for(i=0; i<n; i++){
        printf("%d\t%02d/%02d/%04d\t%s\t%s\n", a[i].appointmentId, a[i].date.day, a[i].date.month, a[i].date.year, a[i].time, a[i].name);
    }
}

void cancelAppointment(struct appointment a[], int *n, int appointmentId){
    int i, j, flag = 0;
    for(i=0; i<(*n); i++){
        if(a[i].appointmentId == appointmentId){
            flag = 1;
            for(j=i+1; j<(*n); j++){
                a[j-1] = a[j];
            }
            (*n)--;
            printf("\nAppointment cancelled successfully!\n");
            break;
        }
    }
    if(flag == 0){
        printf("\nAppointment not found!\n");
        return;
    }
}

void searchAppointment(struct appointment a[], int n, struct date date){
    int i, flag = 0;
    if(n == 0){
        printf("\nNo appointments found on this date!\n");
        return;
    }
    printf("\nAppointment Details for %02d/%02d/%04d:\n", date.day, date.month, date.year);
    printf("ID\tTIME\tNAME\n");
    printf("----------------------------------------------\n");
    for(i=0; i<n; i++){
        if((a[i].date.day == date.day) && (a[i].date.month == date.month) && (a[i].date.year == date.year)){
            flag = 1;
            printf("%d\t%s\t%s\n", a[i].appointmentId, a[i].time, a[i].name);
        }
    }
    if(flag == 0){
        printf("\nNo appointments found on this date!\n");
        return;
    }
}