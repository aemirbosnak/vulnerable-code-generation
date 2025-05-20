//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
// C Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store patient details
struct patient {
  char name[50];
  char age[3];
  char gender[6];
  char address[100];
};

// Structure to store medication details
struct medication {
  char name[50];
  char dosage[10];
  char frequency[10];
};

// Function to add a new patient
void add_patient(struct patient *patients, int *num_patients) {
  printf("Enter patient details:\n");
  printf("Name: ");
  scanf("%s", patients[*num_patients].name);
  printf("Age: ");
  scanf("%s", patients[*num_patients].age);
  printf("Gender: ");
  scanf("%s", patients[*num_patients].gender);
  printf("Address: ");
  scanf("%s", patients[*num_patients].address);
  (*num_patients)++;
}

// Function to display all patients
void display_patients(struct patient *patients, int num_patients) {
  for (int i = 0; i < num_patients; i++) {
    printf("%s\n", patients[i].name);
    printf("Age: %s\n", patients[i].age);
    printf("Gender: %s\n", patients[i].gender);
    printf("Address: %s\n", patients[i].address);
    printf("\n");
  }
}

// Function to add a new medication
void add_medication(struct medication *medications, int *num_medications) {
  printf("Enter medication details:\n");
  printf("Name: ");
  scanf("%s", medications[*num_medications].name);
  printf("Dosage: ");
  scanf("%s", medications[*num_medications].dosage);
  printf("Frequency: ");
  scanf("%s", medications[*num_medications].frequency);
  (*num_medications)++;
}

// Function to display all medications
void display_medications(struct medication *medications, int num_medications) {
  for (int i = 0; i < num_medications; i++) {
    printf("%s\n", medications[i].name);
    printf("Dosage: %s\n", medications[i].dosage);
    printf("Frequency: %s\n", medications[i].frequency);
    printf("\n");
  }
}

// Function to display patient medications
void display_patient_medications(struct medication *medications, int num_medications, char *patient_name) {
  for (int i = 0; i < num_medications; i++) {
    if (strcmp(medications[i].name, patient_name) == 0) {
      printf("%s\n", medications[i].name);
      printf("Dosage: %s\n", medications[i].dosage);
      printf("Frequency: %s\n", medications[i].frequency);
      printf("\n");
    }
  }
}

int main() {
  struct patient patients[100];
  int num_patients = 0;
  struct medication medications[100];
  int num_medications = 0;

  char option;
  char patient_name[50];

  while (1) {
    printf("Welcome to the Medical Store Management System\n");
    printf("1. Add a new patient\n");
    printf("2. Display all patients\n");
    printf("3. Add a new medication\n");
    printf("4. Display all medications\n");
    printf("5. Display patient medications\n");
    printf("6. Exit\n");

    printf("Enter your option: ");
    scanf(" %c", &option);

    switch (option) {
      case '1':
        add_patient(patients, &num_patients);
        break;
      case '2':
        display_patients(patients, num_patients);
        break;
      case '3':
        add_medication(medications, &num_medications);
        break;
      case '4':
        display_medications(medications, num_medications);
        break;
      case '5':
        printf("Enter patient name: ");
        scanf("%s", patient_name);
        display_patient_medications(medications, num_medications, patient_name);
        break;
      case '6':
        exit(0);
        break;
      default:
        printf("Invalid option\n");
    }
  }

  return 0;
}