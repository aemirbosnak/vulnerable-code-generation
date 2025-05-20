//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
/*
*  Medical Store Management System
*  Cryptic style
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char address[100];
} Patient;

// Functions
void print_menu() {
    printf("1. Add medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Add patient\n");
    printf("4. Remove patient\n");
    printf("5. View medicine\n");
    printf("6. View patient\n");
    printf("7. Exit\n");
}

void add_medicine(Medicine *medicine, int num_medicine) {
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine[num_medicine].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine[num_medicine].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine[num_medicine].price);
}

void remove_medicine(Medicine *medicine, int num_medicine) {
    printf("Enter the name of the medicine to remove: ");
    scanf("%s", medicine[num_medicine].name);
    printf("Enter the quantity of the medicine to remove: ");
    scanf("%d", &medicine[num_medicine].quantity);
}

void add_patient(Patient *patient, int num_patient) {
    printf("Enter the ID of the patient: ");
    scanf("%d", &patient[num_patient].id);
    printf("Enter the name of the patient: ");
    scanf("%s", patient[num_patient].name);
    printf("Enter the age of the patient: ");
    scanf("%d", &patient[num_patient].age);
    printf("Enter the gender of the patient: ");
    scanf("%s", patient[num_patient].gender);
    printf("Enter the address of the patient: ");
    scanf("%s", patient[num_patient].address);
}

void remove_patient(Patient *patient, int num_patient) {
    printf("Enter the ID of the patient to remove: ");
    scanf("%d", &patient[num_patient].id);
}

void view_medicine(Medicine *medicine, int num_medicine) {
    printf("List of medicines:\n");
    for (int i = 0; i < num_medicine; i++) {
        printf("%s\n", medicine[i].name);
    }
}

void view_patient(Patient *patient, int num_patient) {
    printf("List of patients:\n");
    for (int i = 0; i < num_patient; i++) {
        printf("%s\n", patient[i].name);
    }
}

int main() {
    Medicine medicine[10];
    int num_medicine = 0;
    Patient patient[10];
    int num_patient = 0;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(medicine, num_medicine++);
                break;
            case 2:
                remove_medicine(medicine, num_medicine--);
                break;
            case 3:
                add_patient(patient, num_patient++);
                break;
            case 4:
                remove_patient(patient, num_patient--);
                break;
            case 5:
                view_medicine(medicine, num_medicine);
                break;
            case 6:
                view_patient(patient, num_patient);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}