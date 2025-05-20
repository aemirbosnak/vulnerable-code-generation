//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MEDS 1000
#define MAX_NAME 50

// Wraps a single medicine entity
struct Medicine {
  int id; // medicine id
  char name[MAX_NAME]; // medicine name
  int quantity; // medicine quantity in stock
  float price; // medicine price per unit
};

// Database of medicines
struct Medicine medicines[MAX_MEDS];

// Track current number of medicines
int num_medicines = 0;

// Utility function to trim leading/trailing whitespace of a string
char * trim_whitespace(char * str) {
  char * end;

  // Trim leading whitespace
  while (isspace(*str)) str++;

  if (*str == 0) return str;

  // Trim trailing whitespace
  end = str + strlen(str) - 1;
  while (end > str && isspace(*end)) end--;

  // Terminate trimmed string
  *(end + 1) = 0;

  return str;
}

// Add a new medicine to the database
void add_medicine() {
  int id = num_medicines + 1;
  char name[MAX_NAME];
  int quantity;
  float price;

  // Get medicine name from user
  printf("Enter medicine name: ");
  fgets(name, MAX_NAME, stdin);
  strcpy(medicines[num_medicines].name, trim_whitespace(name));

  // Get medicine quantity from user
  printf("Enter medicine quantity in stock: ");
  scanf("%d", &quantity);
  medicines[num_medicines].quantity = quantity;

  // Get medicine price from user
  printf("Enter medicine price per unit: ");
  scanf("%f", &price);
  medicines[num_medicines].price = price;

  // Assign unique ID to medicine and increment num_medicines
  medicines[num_medicines].id = id;
  num_medicines++;

  printf("\nMedicine added successfully!\n\n");
}

// List all medicines in the database
void list_medicines() {
  printf("%-5s%-20s%-20s%-20s\n", "ID", "Name", "Quantity", "Price");

  for (int i = 0; i < num_medicines; i++) {
    printf("%-5d%-20s%-20d%-20.2f\n",
      medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
  }

  printf("\n");
}

// Search for a medicine by name in the database
int search_medicine_by_name(char * name) {
  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(trim_whitespace(medicines[i].name), trim_whitespace(name)) == 0) {
      return i;
    }
  }

  return -1;
}

// Sell a medicine to a customer
void sell_medicine() {
  char name[MAX_NAME];
  int quantity;

  // Get medicine name from user
  printf("Enter medicine name: ");
  fgets(name, MAX_NAME, stdin);
  name[strlen(name) - 1] = '\0';

  // Check if medicine exists in database
  int index = search_medicine_by_name(name);
  if (index == -1) {
    printf("\nMedicine not found in database!\n\n");
    return;
  }

  // Get quantity to sell from user
  printf("Enter quantity: ");
  scanf("%d", &quantity);

  // Check if sufficient stock available
  if (quantity > medicines[index].quantity) {
    printf("\nInsufficient stock available!\n\n");
    return;
  }

  // Calculate total price and update stock
  float price = quantity * medicines[index].price;
  medicines[index].quantity -= quantity;

  printf("\nMedicine sold successfully for %.2f!\n\n", price);
}

int main() {
  while (1) {
    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add a new medicine\n");
    printf("2. List all medicines\n");
    printf("3. Sell a medicine\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline character

    switch (choice) {
      case 1:
        add_medicine();
        break;
      case 2:
        list_medicines();
        break;
      case 3:
        sell_medicine();
        break;
      case 4:
        printf("\nGoodbye!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice! Please try again.\n\n");
        break;
    }
  }

  return 0;
}