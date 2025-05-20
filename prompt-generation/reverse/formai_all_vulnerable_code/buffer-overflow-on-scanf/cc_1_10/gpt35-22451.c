//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct appointment{
    char date[20];
    char time[20];
    char name[50];
    char email[50];
    char phone[20];
};

int main(){
    FILE *fp;
    int choice;
    char buffer[100];
    char filename[50], date[20], tmp[50];
    struct appointment a;

    printf("Welcome to My Appointment Scheduler\n");

    printf("\nEnter date(dd/mm/yyyy): ");
    scanf("%s", date);
    strcpy(filename, strcat(date, ".txt"));

    fp = fopen(filename, "r");
    if (fp == NULL){
        fp = fopen(filename, "w");
        printf("\nFile doesn't exist! New file created.\n");
        fclose(fp);
    }
    else{
        printf("\nFile exists! All appointments on this day:\n");
        while(fgets(buffer, 100, fp) != NULL){
            printf("%s", buffer);
        }
        fclose(fp);
    }

    fp = fopen(filename, "a");
    printf("\nWant to schedule a new appointment? (1/0): ");
    scanf("%d", &choice);
    while(choice){
        printf("\nEnter the following details: ");
        printf("\nDate(dd/mm/yyyy): %s", date);
        strcpy(a.date, date);

        printf("\nTime(hh:mm): ");
        scanf("%s", a.time);

        printf("\nName: ");
        scanf("%s", a.name);

        printf("\nEmail: ");
        scanf("%s", a.email);

        printf("\nPhone: ");
        scanf("%s", a.phone);

        fprintf(fp, "%s %s %s %s %s\n", a.time, a.name, a.email, a.phone, a.date);

        printf("\nWant to schedule another appointment? (1/0): ");
        scanf("%d", &choice);
    }

    printf("\nThank you for using the scheduler!\n");
    fclose(fp);

    return 0;
}