//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <string.h>

struct appointment {
    char name[30];
    char date[15];
    char time[10];
};

void print_menu();
void add_appointment(struct appointment appointments[], int *index);
void display_appointments(struct appointment appointments[], int index);
void search_appointments(struct appointment appointments[], int index);
void delete_appointment(struct appointment appointments[], int *index);

int main() {
    int option, index = 0;
    struct appointment appointments[50];
    printf("Welcome to the Retro Appointment Scheduler!\n\n");
    do {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_appointment(appointments, &index);
                break;
            case 2:
                display_appointments(appointments, index);
                break;
            case 3:
                search_appointments(appointments, index);
                break;
            case 4:
                delete_appointment(appointments, &index);
                break;
            case 5:
                printf("Thanks for using the Retro Appointment Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
        printf("\n");
    } while (option != 5);
    return 0;
}

void print_menu() {
    printf("1. Add appointment\n");
    printf("2. Display all appointments\n");
    printf("3. Search for an appointment\n");
    printf("4. Delete an appointment\n");
    printf("5. Exit\n");
    printf("Please enter your option: ");
}

void add_appointment(struct appointment appointments[], int *index) {
    struct appointment new;
    printf("Please enter the name: ");
    scanf("%s", new.name);
    printf("Please enter the date (MM/DD/YYYY): ");
    scanf("%s", new.date);
    printf("Please enter the time (HH:MM): ");
    scanf("%s", new.time);
    appointments[*index] = new;
    (*index)++;
    printf("Appointment added.\n");
}

void display_appointments(struct appointment appointments[], int index) {
    printf("All appointments:\n");
    if (index == 0) {
        printf("No appointments found.\n");
    } else {
        printf("Name\tDate\tTime\n");
        for (int i = 0; i < index; i++) {
            printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

void search_appointments(struct appointment appointments[], int index) {
    char name[30];
    printf("Please enter the name: ");
    scanf("%s", name);
    int found = 0;
    printf("Name\tDate\tTime\n");
    for (int i = 0; i < index; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
            found = 1;
        }
    }
    if (!found) {
        printf("No appointments found for %s.\n", name);
    }
}

void delete_appointment(struct appointment appointments[], int *index) {
    char name[30];
    printf("Please enter the name: ");
    scanf("%s", name);
    int deleted = 0;
    for (int i = 0; i < *index; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            for (int j = i; j < *index - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*index)--;
            deleted = 1;
            printf("Appointment for %s on %s at %s deleted.\n", name, appointments[i].date, appointments[i].time);
        }
    }
    if (!deleted) {
        printf("No appointments found for %s.\n", name);
    }
}