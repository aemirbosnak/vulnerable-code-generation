//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
  char name[50];
  int age;
  char gender;
  char blood_group[5];
  char contact_number[15];
  char address[100];
};

struct medication {
  char name[50];
  float price;
};

struct order {
  struct patient patient;
  struct medication medication;
  int quantity;
};

int main() {
  struct patient patient;
  struct medication medication;
  struct order order;

  printf("Welcome to our medical store management system!\n");

  printf("Please enter the patient's name: ");
  scanf("%s", patient.name);

  printf("Please enter the patient's age: ");
  scanf("%d", &patient.age);

  printf("Please enter the patient's gender: ");
  scanf(" %c", &patient.gender);

  printf("Please enter the patient's blood group: ");
  scanf("%s", patient.blood_group);

  printf("Please enter the patient's contact number: ");
  scanf("%s", patient.contact_number);

  printf("Please enter the patient's address: ");
  scanf("%s", patient.address);

  printf("Please enter the medication name: ");
  scanf("%s", medication.name);

  printf("Please enter the medication price: ");
  scanf("%f", &medication.price);

  printf("Please enter the quantity: ");
  scanf("%d", &order.quantity);

  printf("The patient information:\n");
  printf("Name: %s\n", patient.name);
  printf("Age: %d\n", patient.age);
  printf("Gender: %c\n", patient.gender);
  printf("Blood Group: %s\n", patient.blood_group);
  printf("Contact Number: %s\n", patient.contact_number);
  printf("Address: %s\n", patient.address);

  printf("The medication information:\n");
  printf("Name: %s\n", medication.name);
  printf("Price: %f\n", medication.price);

  printf("The order information:\n");
  printf("Patient: %s\n", patient.name);
  printf("Medication: %s\n", medication.name);
  printf("Quantity: %d\n", order.quantity);

  return 0;
}