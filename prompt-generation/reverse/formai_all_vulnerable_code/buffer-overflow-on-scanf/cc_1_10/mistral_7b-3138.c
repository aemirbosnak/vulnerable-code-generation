//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATIENTS 100

typedef struct {
    int patient_id;
    char name[50];
    char gender;
    char contact[20];
    char address[100];
    char medical_history[200];
    bool is_active;
} Patient;

Patient patients[MAX_PATIENTS];
int num_patients = 0;

void add_patient(Patient new_patient) {
    if (num_patients >= MAX_PATIENTS) {
        printf("Maximum number of patients reached.\n");
        return;
    }

    patients[num_patients] = new_patient;
    num_patients++;

    printf("New patient added successfully.\n");
}

bool validate_contact(char contact[]) {
    int len = strlen(contact);

    if (len < 10 || len > 15) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit(contact[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    char name[50], contact[20], address[100], medical_history[200];
    char gender;
    int patient_id;

    while (true) {
        printf("\nEnter patient details:\n");
        printf("Name: ");
        scanf("%s", name);
        getchar(); // consume newline

        printf("Gender (M/F): ");
        scanf("%c", &gender);

        printf("Contact: ");
        scanf("%s", contact);
        if (!validate_contact(contact)) {
            printf("Invalid contact number.\n");
            continue;
        }

        printf("Address: ");
        fgets(address, sizeof(address), stdin);
        address[strlen(address) - 1] = '\0'; // remove newline character

        printf("Medical History: ");
        fgets(medical_history, sizeof(medical_history), stdin);

        Patient new_patient = {
            .patient_id = num_patients + 1,
            .name = name,
            .gender = gender,
            .contact = contact,
            .address = address,
            .medical_history = medical_history,
            .is_active = true
        };

        add_patient(new_patient);

        printf("\nDo you want to add another patient? (Y/N): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'N') {
            break;
        }
    }

    return 0;
}