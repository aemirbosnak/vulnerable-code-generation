//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient's information
typedef struct {
  char name[256];
  char address[256];
  int age;
  char gender[8];
  char disease[256];
  char medication[256];
  char symptoms[256];
  char diagnosis[256];
  char prescription[256];
} Patient;

// Structure to represent a pharmacy's information
typedef struct {
  char name[256];
  char address[256];
  char phone[256];
  char email[256];
  char hours[256];
} Pharmacy;

// Function to display the menu options
void display_menu() {
  printf("Welcome to the Medical Store Management System!\n");
  printf("Please select an option:\n");
  printf("1. Add new patient\n");
  printf("2. Add new pharmacy\n");
  printf("3. Display all patients\n");
  printf("4. Display all pharmacies\n");
  printf("5. Exit\n");
}

// Function to add a new patient
void add_patient(Patient *patient) {
  printf("Enter the patient's name: ");
  scanf("%s", patient->name);
  printf("Enter the patient's address: ");
  scanf("%s", patient->address);
  printf("Enter the patient's age: ");
  scanf("%d", &patient->age);
  printf("Enter the patient's gender: ");
  scanf("%s", patient->gender);
  printf("Enter the patient's disease: ");
  scanf("%s", patient->disease);
  printf("Enter the patient's medication: ");
  scanf("%s", patient->medication);
  printf("Enter the patient's symptoms: ");
  scanf("%s", patient->symptoms);
  printf("Enter the patient's diagnosis: ");
  scanf("%s", patient->diagnosis);
  printf("Enter the patient's prescription: ");
  scanf("%s", patient->prescription);
}

// Function to add a new pharmacy
void add_pharmacy(Pharmacy *pharmacy) {
  printf("Enter the pharmacy's name: ");
  scanf("%s", pharmacy->name);
  printf("Enter the pharmacy's address: ");
  scanf("%s", pharmacy->address);
  printf("Enter the pharmacy's phone number: ");
  scanf("%s", pharmacy->phone);
  printf("Enter the pharmacy's email: ");
  scanf("%s", pharmacy->email);
  printf("Enter the pharmacy's hours: ");
  scanf("%s", pharmacy->hours);
}

// Function to display all patients
void display_patients(Patient *patients, int num_patients) {
  printf("Here is a list of all patients:\n");
  for (int i = 0; i < num_patients; i++) {
    printf("%s\n", patients[i].name);
    printf("%s\n", patients[i].address);
    printf("%d\n", patients[i].age);
    printf("%s\n", patients[i].gender);
    printf("%s\n", patients[i].disease);
    printf("%s\n", patients[i].medication);
    printf("%s\n", patients[i].symptoms);
    printf("%s\n", patients[i].diagnosis);
    printf("%s\n", patients[i].prescription);
  }
}

// Function to display all pharmacies
void display_pharmacies(Pharmacy *pharmacies, int num_pharmacies) {
  printf("Here is a list of all pharmacies:\n");
  for (int i = 0; i < num_pharmacies; i++) {
    printf("%s\n", pharmacies[i].name);
    printf("%s\n", pharmacies[i].address);
    printf("%s\n", pharmacies[i].phone);
    printf("%s\n", pharmacies[i].email);
    printf("%s\n", pharmacies[i].hours);
  }
}

int main() {
  // Declare an array of patients and pharmacies
  Patient patients[100];
  Pharmacy pharmacies[100];
  int num_patients = 0;
  int num_pharmacies = 0;

  // Initialize the menu
  int option;
  do {
    display_menu();
    scanf("%d", &option);

    // Add a new patient
    if (option == 1) {
      add_patient(&patients[num_patients]);
      num_patients++;
    }

    // Add a new pharmacy
    if (option == 2) {
      add_pharmacy(&pharmacies[num_pharmacies]);
      num_pharmacies++;
    }

    // Display all patients
    if (option == 3) {
      display_patients(patients, num_patients);
    }

    // Display all pharmacies
    if (option == 4) {
      display_pharmacies(pharmacies, num_pharmacies);
    }

    // Exit
    if (option == 5) {
      break;
    }
  } while (option != 5);

  return 0;
}