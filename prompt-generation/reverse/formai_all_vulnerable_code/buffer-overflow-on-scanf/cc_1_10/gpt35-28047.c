//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_APPTS 100
#define MAX_NAME_LEN 30
#define MAX_TIME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char time[MAX_TIME_LEN];
} Appointment;

void print_appointments(Appointment appts[], int size) {
    printf("Appointments:\n");
    for (int i = 0; i < size; i++) {
        printf("%s @ %s\n", appts[i].name, appts[i].time);
    }
    printf("\n");
}

bool add_appointment(Appointment appts[], int* size, char name[], char time[]) {
    if (*size == MAX_APPTS) {
        return false;
    }
    
    strcpy(appts[*size].name, name);
    strcpy(appts[*size].time, time);
    (*size)++;
    
    return true;
}

void remove_appointment(Appointment appts[], int* size, char time[]) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(appts[i].time, time) == 0) {
            for (int j = i + 1; j < *size; j++) {
                strcpy(appts[j - 1].name, appts[j].name);
                strcpy(appts[j - 1].time, appts[j].time);
            }
            (*size)--;
            break;
        }
    }
}

int main() {
    Appointment appts[MAX_APPTS];
    int size = 0;

    bool isRunning = true;
    while (isRunning) {
        printf("Options:\n");
        printf("\ta - add appointment\n");
        printf("\tr - remove appointment\n");
        printf("\tp - print appointments\n");
        printf("\tq - quit\n");
        
        char option;
        char name[MAX_NAME_LEN];
        char time[MAX_TIME_LEN];

        printf("Enter option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                
                printf("Enter time (HH:MM): ");
                scanf(" %s", time);
                
                if (add_appointment(appts, &size, name, time)) {
                    printf("Appointment added successfully.\n");
                } else {
                    printf("Appointment list is full.\n");
                }
                break;
            case 'r':
                printf("Enter time (HH:MM) to remove: ");
                scanf(" %s", time);
                
                remove_appointment(appts, &size, time);
                printf("Appointment removed successfully.\n");
                break;
            case 'p':
                print_appointments(appts, size);
                break;
            case 'q':
                isRunning = false;
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    printf("Goodbye.\n");
    return 0;
}