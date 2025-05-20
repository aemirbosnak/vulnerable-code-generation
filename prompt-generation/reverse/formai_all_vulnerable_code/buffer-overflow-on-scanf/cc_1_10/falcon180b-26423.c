//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 10
#define MAX_APPOINTMENTS 1000
#define MAX_SLOTS 10
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int duration;
} Appointment;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int available_slots[MAX_SLOTS];
} Doctor;

void print_menu() {
    printf("1. Login as patient\n");
    printf("2. Login as doctor\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                // TODO: Validate user credentials and login
                break;

            case 2:
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                // TODO: Validate user credentials and login
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}