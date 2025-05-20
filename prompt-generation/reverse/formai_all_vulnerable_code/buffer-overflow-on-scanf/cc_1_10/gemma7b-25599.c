//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Patient {
    char name[50];
    int age;
    char address[100];
    int contact_number;
    char illness[50];
} Patient;

Patient patients[MAX];

void add_patient() {
    printf("Enter patient's name: ");
    scanf("%s", patients[MAX - 1].name);

    printf("Enter patient's age: ");
    scanf("%d", &patients[MAX - 1].age);

    printf("Enter patient's address: ");
    scanf("%s", patients[MAX - 1].address);

    printf("Enter patient's contact number: ");
    scanf("%d", &patients[MAX - 1].contact_number);

    printf("Enter patient's illness: ");
    scanf("%s", patients[MAX - 1].illness);
}

void view_patient() {
    printf("List of patients:\n");
    for (int i = 0; i < MAX; i++) {
        if (patients[i].name[0] != '\0') {
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Address: %s\n", patients[i].address);
            printf("Contact number: %d\n", patients[i].contact_number);
            printf("Illness: %s\n", patients[i].illness);
            printf("\n");
        }
    }
}

void search_patient() {
    char search_name[50];

    printf("Enter patient's name: ");
    scanf("%s", search_name);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(patients[i].name, search_name) == 0) {
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Address: %s\n", patients[i].address);
            printf("Contact number: %d\n", patients[i].contact_number);
            printf("Illness: %s\n", patients[i].illness);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("Enter 1 to add a patient, 2 to view patients, 3 to search for a patient, or 4 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                view_patient();
                break;
            case 3:
                search_patient();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}