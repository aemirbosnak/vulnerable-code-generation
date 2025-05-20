//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

//Structure for an appointment
typedef struct{
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
    int priority;
}Appointment;

//Function to compare appointments based on their start time
int compare_appointments(const void *a, const void *b){
    const Appointment *appointment1 = (const Appointment *)a;
    const Appointment *appointment2 = (const Appointment *)b;
    if(appointment1->start_time < appointment2->start_time){
        return -1;
    }else if(appointment1->start_time > appointment2->start_time){
        return 1;
    }else{
        return 0;
    }
}

//Function to display the list of appointments
void display_appointments(Appointment appointments[], int num_appointments){
    printf("List of Appointments:\n");
    for(int i=0;i<num_appointments;i++){
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start Time: %s\n", ctime(&appointments[i].start_time));
        printf("End Time: %s\n", ctime(&appointments[i].end_time));
        printf("Priority: %d\n\n", appointments[i].priority);
    }
}

//Main function
int main(){
    int num_appointments, i;
    Appointment appointments[100];
    char filename[50];
    printf("Enter the name of the file containing the list of appointments: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: File not found!\n");
        exit(1);
    }
    fscanf(fp, "%d", &num_appointments);
    for(i=0;i<num_appointments;i++){
        fscanf(fp, "%s %s %ld %ld %d", appointments[i].name, appointments[i].description, &appointments[i].start_time, &appointments[i].end_time, &appointments[i].priority);
    }
    fclose(fp);
    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);
    display_appointments(appointments, num_appointments);
    return 0;
}