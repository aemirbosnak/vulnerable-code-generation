//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct medicine {
  char name[50];
  char manufacturer[50];
  int id;
  float price;
  int quantity;
};

int main() {
  struct medicine med_list[100];
  int num_meds = 0;
  char input[50];
  int choice;

  while (true) {
    printf("Enter 1 to add a new medicine.\n");
    printf("Enter 2 to view all medicines.\n");
    printf("Enter 3 to search for a medicine by id.\n");
    printf("Enter 4 to update the quantity of a medicine.\n");
    printf("Enter 5 to exit.\n");
    scanf("%s", input);
    choice = atoi(input);

    if (choice == 1) {
      struct medicine new_med;
      printf("Enter the name of the medicine: ");
      scanf("%s", new_med.name);
      printf("Enter the manufacturer of the medicine: ");
      scanf("%s", new_med.manufacturer);
      printf("Enter the id of the medicine: ");
      scanf("%d", &new_med.id);
      printf("Enter the price of the medicine: ");
      scanf("%f", &new_med.price);
      printf("Enter the quantity of the medicine: ");
      scanf("%d", &new_med.quantity);
      med_list[num_meds] = new_med;
      num_meds++;
      printf("Medicine added.\n");
    }
    else if (choice == 2) {
      printf("All medicines:\n");
      for (int i = 0; i < num_meds; i++) {
        printf("%d. %s\n", i+1, med_list[i].name);
      }
    }
    else if (choice == 3) {
      printf("Enter the id of the medicine you would like to search for: ");
      int search_id;
      scanf("%d", &search_id);
      for (int i = 0; i < num_meds; i++) {
        if (med_list[i].id == search_id) {
          printf("Medicine found:\n");
          printf("Name: %s\n", med_list[i].name);
          printf("Manufacturer: %s\n", med_list[i].manufacturer);
          printf("Price: %.2f\n", med_list[i].price);
          printf("Quantity: %d\n", med_list[i].quantity);
          break;
        }
        if (i == num_meds - 1) {
          printf("Medicine not found.\n");
        }
      }
    }
    else if (choice == 4) {
      printf("Enter the id of the medicine you would like to update: ");
      int update_id;
      scanf("%d", &update_id);
      for (int i = 0; i < num_meds; i++) {
        if (med_list[i].id == update_id) {
          printf("Enter the new quantity: ");
          scanf("%d", &med_list[i].quantity);
          printf("Quantity updated.\n");
          break;
        }
        if (i == num_meds - 1) {
          printf("Medicine not found.\n");
        }
      }
    }
    else if (choice == 5) {
      printf("Exiting program.\n");
      break;
    }
    else {
      printf("Invalid input. Try again.\n");
    }
  }

  return 0;
}