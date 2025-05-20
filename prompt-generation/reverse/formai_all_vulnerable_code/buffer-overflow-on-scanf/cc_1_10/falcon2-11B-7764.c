//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[100];
    int age;
    char gender;
    char phone[20];
    char address[200];
};

void add_patient(struct patient* patients, int num_patients) {
    char name[100], gender, phone[20], address[200];
    int age;

    printf("Enter patient name: ");
    scanf("%s", name);

    printf("Enter patient age: ");
    scanf("%d", &age);

    printf("Enter patient gender (M/F): ");
    scanf(" %c", &gender);

    printf("Enter patient phone number: ");
    scanf(" %s", phone);

    printf("Enter patient address: ");
    scanf(" %s", address);

    struct patient* new_patient = (struct patient*)malloc(sizeof(struct patient));

    strcpy(new_patient->name, name);
    new_patient->age = age;
    new_patient->gender = gender;
    strcpy(new_patient->phone, phone);
    strcpy(new_patient->address, address);

    patients = realloc(patients, (num_patients + 1) * sizeof(struct patient));
    patients[num_patients] = *new_patient;
}

void print_patients(struct patient* patients, int num_patients) {
    int i;

    printf("Patient\tAge\tGender\tPhone\tAddress\n");
    for (i = 0; i < num_patients; i++) {
        printf("%s\t%d\t%c\t%s\t%s\n", patients[i].name, patients[i].age, patients[i].gender, patients[i].phone, patients[i].address);
    }
}

int main() {
    struct patient* patients = (struct patient*)malloc(100 * sizeof(struct patient));
    int num_patients = 0;

    while (1) {
        printf("1. Add patient\n2. Print patients\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient(patients, num_patients);
                break;
            case 2:
                print_patients(patients, num_patients);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}