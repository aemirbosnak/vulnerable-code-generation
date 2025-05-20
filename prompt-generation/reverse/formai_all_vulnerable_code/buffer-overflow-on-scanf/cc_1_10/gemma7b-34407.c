//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define the database structure
typedef struct MedicalRecord {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  char medical_history[200];
} MedicalRecord;

// Define the medical store management system
int main() {
  // Create an array of medical records
  MedicalRecord records[100];

  // Initialize the medical records
  for (int i = 0; i < 100; i++) {
    records[i].name[0] = '\0';
    records[i].address[0] = '\0';
    records[i].phone[0] = '\0';
    records[i].email[0] = '\0';
    records[i].medical_history[0] = '\0';
  }

  // Loop over the medical records
  for (int i = 0; i < 100; i++) {
    // Get the patient's name
    printf("Enter the patient's name: ");
    scanf("%s", records[i].name);

    // Get the patient's address
    printf("Enter the patient's address: ");
    scanf("%s", records[i].address);

    // Get the patient's phone number
    printf("Enter the patient's phone number: ");
    scanf("%s", records[i].phone);

    // Get the patient's email address
    printf("Enter the patient's email address: ");
    scanf("%s", records[i].email);

    // Get the patient's medical history
    printf("Enter the patient's medical history: ");
    scanf("%s", records[i].medical_history);
  }

  // Print the medical records
  for (int i = 0; i < 100; i++) {
    // Print the patient's name
    printf("Name: %s\n", records[i].name);

    // Print the patient's address
    printf("Address: %s\n", records[i].address);

    // Print the patient's phone number
    printf("Phone Number: %s\n", records[i].phone);

    // Print the patient's email address
    printf("Email Address: %s\n", records[i].email);

    // Print the patient's medical history
    printf("Medical History: %s\n", records[i].medical_history);

    printf("\n");
  }

  return 0;
}