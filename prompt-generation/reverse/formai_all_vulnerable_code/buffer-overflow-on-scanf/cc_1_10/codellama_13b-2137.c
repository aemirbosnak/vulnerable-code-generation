//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a patient
typedef struct {
  char name[50];
  int age;
  char gender[10];
  char medical_history[200];
  char medication[50];
} patient_t;

// Struct to represent a medical test
typedef struct {
  char name[50];
  char description[100];
  float price;
} test_t;

// Struct to represent a medical procedure
typedef struct {
  char name[50];
  char description[100];
  float price;
} procedure_t;

// Function to add a patient
void add_patient(patient_t* patients, int* num_patients) {
  printf("Enter patient name: ");
  scanf("%s", patients[*num_patients].name);
  printf("Enter patient age: ");
  scanf("%d", &patients[*num_patients].age);
  printf("Enter patient gender: ");
  scanf("%s", patients[*num_patients].gender);
  printf("Enter patient medical history: ");
  scanf("%s", patients[*num_patients].medical_history);
  printf("Enter patient medication: ");
  scanf("%s", patients[*num_patients].medication);
  *num_patients += 1;
}

// Function to add a medical test
void add_test(test_t* tests, int* num_tests) {
  printf("Enter test name: ");
  scanf("%s", tests[*num_tests].name);
  printf("Enter test description: ");
  scanf("%s", tests[*num_tests].description);
  printf("Enter test price: ");
  scanf("%f", &tests[*num_tests].price);
  *num_tests += 1;
}

// Function to add a medical procedure
void add_procedure(procedure_t* procedures, int* num_procedures) {
  printf("Enter procedure name: ");
  scanf("%s", procedures[*num_procedures].name);
  printf("Enter procedure description: ");
  scanf("%s", procedures[*num_procedures].description);
  printf("Enter procedure price: ");
  scanf("%f", &procedures[*num_procedures].price);
  *num_procedures += 1;
}

// Function to display all patients
void display_patients(patient_t* patients, int num_patients) {
  for (int i = 0; i < num_patients; i++) {
    printf("Patient %d:\n", i + 1);
    printf("Name: %s\n", patients[i].name);
    printf("Age: %d\n", patients[i].age);
    printf("Gender: %s\n", patients[i].gender);
    printf("Medical History: %s\n", patients[i].medical_history);
    printf("Medication: %s\n", patients[i].medication);
    printf("\n");
  }
}

// Function to display all medical tests
void display_tests(test_t* tests, int num_tests) {
  for (int i = 0; i < num_tests; i++) {
    printf("Test %d:\n", i + 1);
    printf("Name: %s\n", tests[i].name);
    printf("Description: %s\n", tests[i].description);
    printf("Price: %f\n", tests[i].price);
    printf("\n");
  }
}

// Function to display all medical procedures
void display_procedures(procedure_t* procedures, int num_procedures) {
  for (int i = 0; i < num_procedures; i++) {
    printf("Procedure %d:\n", i + 1);
    printf("Name: %s\n", procedures[i].name);
    printf("Description: %s\n", procedures[i].description);
    printf("Price: %f\n", procedures[i].price);
    printf("\n");
  }
}

int main() {
  patient_t patients[100];
  int num_patients = 0;

  test_t tests[100];
  int num_tests = 0;

  procedure_t procedures[100];
  int num_procedures = 0;

  while (1) {
    printf("Enter your choice:\n");
    printf("1. Add a patient\n");
    printf("2. Add a medical test\n");
    printf("3. Add a medical procedure\n");
    printf("4. Display all patients\n");
    printf("5. Display all medical tests\n");
    printf("6. Display all medical procedures\n");
    printf("7. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_patient(patients, &num_patients);
        break;
      case 2:
        add_test(tests, &num_tests);
        break;
      case 3:
        add_procedure(procedures, &num_procedures);
        break;
      case 4:
        display_patients(patients, num_patients);
        break;
      case 5:
        display_tests(tests, num_tests);
        break;
      case 6:
        display_procedures(procedures, num_procedures);
        break;
      case 7:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}