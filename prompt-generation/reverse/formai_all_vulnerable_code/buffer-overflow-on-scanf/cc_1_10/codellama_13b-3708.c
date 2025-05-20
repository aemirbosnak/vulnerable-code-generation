//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 32
#define MAX_PHONE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;
    bool is_registered;
} Patient;

void init_patient(Patient *p) {
    strcpy(p->name, "");
    strcpy(p->phone, "");
    p->age = 0;
    p->is_registered = false;
}

void register_patient(Patient *p) {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;

    printf("Enter the patient's name: ");
    scanf("%s", name);
    printf("Enter the patient's phone number: ");
    scanf("%s", phone);
    printf("Enter the patient's age: ");
    scanf("%d", &age);

    strcpy(p->name, name);
    strcpy(p->phone, phone);
    p->age = age;
    p->is_registered = true;
}

void display_patient_info(Patient *p) {
    printf("Patient's name: %s\n", p->name);
    printf("Patient's phone number: %s\n", p->phone);
    printf("Patient's age: %d\n", p->age);
    printf("Is registered: %s\n", p->is_registered ? "Yes" : "No");
}

void edit_patient_info(Patient *p) {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int age;

    printf("Enter the patient's name: ");
    scanf("%s", name);
    printf("Enter the patient's phone number: ");
    scanf("%s", phone);
    printf("Enter the patient's age: ");
    scanf("%d", &age);

    strcpy(p->name, name);
    strcpy(p->phone, phone);
    p->age = age;
}

void delete_patient(Patient *p) {
    p->is_registered = false;
}

int main() {
    Patient patient;

    init_patient(&patient);
    register_patient(&patient);
    display_patient_info(&patient);
    edit_patient_info(&patient);
    delete_patient(&patient);

    return 0;
}