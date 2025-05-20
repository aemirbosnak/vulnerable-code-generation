//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int date;
    int time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name of appointment: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter description of appointment: ");
    scanf("%s", appointments[num_appointments].description);
    printf("Enter date of appointment (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &appointments[num_appointments].date, &appointments[num_appointments].date+1, &appointments[num_appointments].date+2);
    printf("Enter time of appointment (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].time, &appointments[num_appointments].time+1);
    num_appointments++;
}

void view_appointments() {
    printf("Name\t\tDescription\tDate\t\tTime\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t\t%s\t\t%d-%d-%d\t\t%d:%d\n", appointments[i].name, appointments[i].description, appointments[i].date, appointments[i].date+1, appointments[i].date+2, appointments[i].time, appointments[i].time+1);
    }
}

void search_appointment() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, search_name) == 0) {
            printf("Name: %s\nDescription: %s\nDate: %d-%d-%d\nTime: %d:%d\n", appointments[i].name, appointments[i].description, appointments[i].date, appointments[i].date+1, appointments[i].date+2, appointments[i].time, appointments[i].time+1);
        }
    }
}

void delete_appointment() {
    char delete_name[MAX_NAME_LENGTH];
    printf("Enter name of appointment to delete: ");
    scanf("%s", delete_name);
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, delete_name) == 0) {
            for (int j = i; j < num_appointments-1; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                strcpy(appointments[j].description, appointments[j+1].description);
                appointments[j].date = appointments[j+1].date;
                appointments[j].time = appointments[j+1].time;
            }
            num_appointments--;
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Search appointment\n4. Delete appointment\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                search_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}