//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  struct patient {
    char name[50];
    int age;
    char gender[6];
    char address[50];
    int mobile_number;
    char symptoms[50];
    char medication[50];
  };

  int main() {
    struct patient patients[100];
    int n_patients = 0;
    char choice;

    while (1) {
      printf("Welcome to the Medical Store Management System\n");
      printf("Please enter your choice:\n");
      printf("1. Add a new patient\n");
      printf("2. View all patients\n");
      printf("3. View patient by name\n");
      printf("4. View patient by age\n");
      printf("5. Exit\n");
      scanf("%c", &choice);

      switch (choice) {
        case '1':
          printf("Enter patient name: ");
          scanf("%s", patients[n_patients].name);
          printf("Enter patient age: ");
          scanf("%d", &patients[n_patients].age);
          printf("Enter patient gender: ");
          scanf("%s", patients[n_patients].gender);
          printf("Enter patient address: ");
          scanf("%s", patients[n_patients].address);
          printf("Enter patient mobile number: ");
          scanf("%d", &patients[n_patients].mobile_number);
          printf("Enter patient symptoms: ");
          scanf("%s", patients[n_patients].symptoms);
          printf("Enter patient medication: ");
          scanf("%s", patients[n_patients].medication);
          n_patients++;
          break;
        case '2':
          for (int i = 0; i < n_patients; i++) {
            printf("%s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Address: %s\n", patients[i].address);
            printf("Mobile Number: %d\n", patients[i].mobile_number);
            printf("Symptoms: %s\n", patients[i].symptoms);
            printf("Medication: %s\n", patients[i].medication);
            printf("\n");
          }
          break;
        case '3':
          printf("Enter patient name: ");
          char name[50];
          scanf("%s", name);
          for (int i = 0; i < n_patients; i++) {
            if (strcmp(name, patients[i].name) == 0) {
              printf("%s\n", patients[i].name);
              printf("Age: %d\n", patients[i].age);
              printf("Gender: %s\n", patients[i].gender);
              printf("Address: %s\n", patients[i].address);
              printf("Mobile Number: %d\n", patients[i].mobile_number);
              printf("Symptoms: %s\n", patients[i].symptoms);
              printf("Medication: %s\n", patients[i].medication);
              break;
            }
          }
          break;
        case '4':
          printf("Enter patient age: ");
          int age;
          scanf("%d", &age);
          for (int i = 0; i < n_patients; i++) {
            if (age == patients[i].age) {
              printf("%s\n", patients[i].name);
              printf("Age: %d\n", patients[i].age);
              printf("Gender: %s\n", patients[i].gender);
              printf("Address: %s\n", patients[i].address);
              printf("Mobile Number: %d\n", patients[i].mobile_number);
              printf("Symptoms: %s\n", patients[i].symptoms);
              printf("Medication: %s\n", patients[i].medication);
              break;
            }
          }
          break;
        case '5':
          exit(0);
          break;
        default:
          printf("Invalid choice.\n");
          break;
      }
    }

    return 0;
  }