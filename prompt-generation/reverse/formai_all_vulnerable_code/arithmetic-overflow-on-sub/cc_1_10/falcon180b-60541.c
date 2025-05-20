//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int phone;
} patient;

void create_patient(patient *p) {
    printf("Enter patient name: ");
    scanf("%s", p->name);
    printf("Enter patient age: ");
    scanf("%d", &p->age);
    printf("Enter patient phone number: ");
    scanf("%d", &p->phone);
}

void display_patient(patient p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Phone: %d\n", p.phone);
}

int compare_patients(patient *p1, patient *p2) {
    if (p1->age > p2->age)
        return 1;
    else if (p1->age < p2->age)
        return -1;
    else
        return 0;
}

void bubble_sort(patient *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compare_patients(&arr[j], &arr[j + 1]) > 0) {
                patient temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void appointment_scheduler() {
    int n;
    printf("Enter number of patients: ");
    scanf("%d", &n);

    patient *arr = (patient *)malloc(n * sizeof(patient));

    for (int i = 0; i < n; i++) {
        create_patient(&arr[i]);
    }

    bubble_sort(arr, n);

    printf("Sorted patients by age:\n");
    for (int i = 0; i < n; i++) {
        display_patient(arr[i]);
    }
}

int main() {
    appointment_scheduler();
    return 0;
}