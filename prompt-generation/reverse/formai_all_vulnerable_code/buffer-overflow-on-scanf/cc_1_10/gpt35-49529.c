//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an appointment
struct appointment {
    int day, month, year;
    char time[10];
    char name[50];
    char description[100];
};

// A function to create a new appointment
struct appointment create_appointment() {
    struct appointment apt;
    printf("Enter name: ");
    scanf("%s", apt.name);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &apt.day, &apt.month, &apt.year);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", apt.time);
    printf("Enter description: ");
    scanf("%s", apt.description);
    return apt;
}

// A function to display an appointment
void display_appointment(struct appointment apt) {
    printf("Name: %s\n", apt.name);
    printf("Date: %d/%d/%d\n", apt.day, apt.month, apt.year);
    printf("Time: %s\n", apt.time);
    printf("Description: %s\n", apt.description);
}

// A function to compare two dates
int compare_dates(struct appointment apt1, struct appointment apt2) {
    if (apt1.year < apt2.year)
        return -1;
    else if (apt1.year > apt2.year)
        return 1;
    else {
        if (apt1.month < apt2.month)
            return -1;
        else if (apt1.month > apt2.month)
            return 1;
        else {
            if (apt1.day < apt2.day)
                return -1;
            else if (apt1.day > apt2.day)
                return 1;
            else
                return 0;
        }
    }
}

// A function to sort the appointments in ascending order of dates
void sort_appointments(struct appointment *apts, int n) {
    int i, j;
    struct appointment temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (compare_dates(apts[j], apts[j+1]) > 0) {
                temp = apts[j];
                apts[j] = apts[j+1];
                apts[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i, ch;
    printf("Enter number of appointments: ");
    scanf("%d", &n);
    struct appointment *apts = malloc(n * sizeof(struct appointment));
    for (i = 0; i < n; i++) {
        printf("Enter details of appointment %d:\n", i+1);
        apts[i] = create_appointment();
    }
    do {
        printf("\n1. Display all appointments\n2. Sort appointments\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("All appointments:\n");
                for (i = 0; i < n; i++) {
                    printf("\nAppointment %d:\n", i+1);
                    display_appointment(apts[i]);
                }
                break;
            case 2:
                sort_appointments(apts, n);
                printf("Appointments sorted in ascending order of dates:\n");
                for (i = 0; i < n; i++) {
                    printf("\nAppointment %d:\n", i+1);
                    display_appointment(apts[i]);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (ch != 3);
    free(apts);
    return 0;
}