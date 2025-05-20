//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient_info {
  char name[50];
  char contact[15];
  char address[50];
  char diagnosis[50];
  char treatment[50];
  char doctor_name[50];
  char medication[50];
};

struct patient_info patients[100];

int add_patient() {
  int i;
  for (i = 0; i < 100; i++) {
    if (patients[i].name[0] == '\0') {
      break;
    }
  }
  if (i == 100) {
    printf("Error: Patient list is full.\n");
    return -1;
  }
  printf("Enter patient name: ");
  scanf("%s", patients[i].name);
  printf("Enter patient contact: ");
  scanf("%s", patients[i].contact);
  printf("Enter patient address: ");
  scanf("%s", patients[i].address);
  printf("Enter patient diagnosis: ");
  scanf("%s", patients[i].diagnosis);
  printf("Enter patient treatment: ");
  scanf("%s", patients[i].treatment);
  printf("Enter patient doctor name: ");
  scanf("%s", patients[i].doctor_name);
  printf("Enter patient medication: ");
  scanf("%s", patients[i].medication);
  return 0;
}

void print_patients() {
  int i;
  for (i = 0; i < 100; i++) {
    if (patients[i].name[0] == '\0') {
      break;
    }
    printf("Patient %d\n", i);
    printf("Name: %s\n", patients[i].name);
    printf("Contact: %s\n", patients[i].contact);
    printf("Address: %s\n", patients[i].address);
    printf("Diagnosis: %s\n", patients[i].diagnosis);
    printf("Treatment: %s\n", patients[i].treatment);
    printf("Doctor Name: %s\n", patients[i].doctor_name);
    printf("Medication: %s\n", patients[i].medication);
  }
}

int main() {
  int choice;
  do {
    printf("Enter your choice:\n");
    printf("1. Add patient\n");
    printf("2. Print patients\n");
    printf("3. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_patient();
        break;
      case 2:
        print_patients();
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  } while (1);
  return 0;
}