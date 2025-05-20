//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_BATCH_LENGTH 10
#define MAX_MANU_LENGTH 50

/* Define structs */
struct Medicine {
  char name[MAX_NAME_LENGTH];
  char batch_no[MAX_BATCH_LENGTH];
  char manufacturer[MAX_MANU_LENGTH];
  float price;
  int quantity;
};

struct MedicineInventory {
  struct Medicine medicines[MAX_MEDICINES];
  int count;
};

/* Declare functions */
void displayMenu();
int addMedicine(struct MedicineInventory *);
int searchMedicine(struct MedicineInventory *);
void displayMedicine(struct Medicine *);
void displayAllMedicines(struct MedicineInventory *);
void deleteMedicine(struct MedicineInventory *);
void updateMedicine(struct MedicineInventory *);

/* Define global variables */
int menuChoice;

/* Create main function */
int main() {

  /* Define local variables */
  struct MedicineInventory inventory;
  int status;

  /* Initialize inventory count */
  inventory.count = 0;

  /* Display main menu */
  displayMenu();

  /* Execute based on user's choice */
  while (menuChoice != 6) {

    switch (menuChoice) {

      case 1:
        status = addMedicine(&inventory);
        if (status == 0) {
          printf("Medicine has been added\n\n");
        } else if (status == 1) {
          printf("Medicine already exists\n\n");
        } else {
          printf("Inventory is full\n\n");
        }
        break;

      case 2:
        status = searchMedicine(&inventory);
        if (status == -1) {
          printf("Medicine does not exist\n\n");
        }
        break;

      case 3:
        displayAllMedicines(&inventory);
        break;

      case 4:
        deleteMedicine(&inventory);
        break;

      case 5:
        updateMedicine(&inventory);
        break;

      default:
        printf("Invalid choice\n\n");
        break;
    }

    /* Display menu again */
    displayMenu();
  }

  /* Exit program */
  return 0;
}

/* Define function implementations */

void displayMenu() {
  /* Display menu options */
  printf("1. Add Medicine\n");
  printf("2. Search Medicine\n");
  printf("3. Display all Medicines\n");
  printf("4. Delete Medicine\n");
  printf("5. Update Medicine\n");
  printf("6. Exit\n\n");
  printf("Enter your choice: ");

  /* Take user input */
  scanf("%d", &menuChoice);
  printf("\n");
}

int addMedicine(struct MedicineInventory *inventory) {
  /* Check if inventory is full */
  if (inventory->count == MAX_MEDICINES) {
    return -1;
  }

  /* Ask for medicine details */
  struct Medicine newMedicine;
  printf("Enter Medicine details: \n\n");
  printf("Name: ");
  scanf("%s", newMedicine.name);
  printf("Batch No: ");
  scanf("%s", newMedicine.batch_no);
  printf("Manufacturer: ");
  scanf("%s", newMedicine.manufacturer);
  printf("Price: ");
  scanf("%f", &newMedicine.price);
  printf("Quantity: ");
  scanf("%d", &newMedicine.quantity);

  /* Check if medicine already exist */
  for (int i = 0; i < inventory->count; i++) {
    if (strcmp(inventory->medicines[i].name, newMedicine.name) == 0 && 
        strcmp(inventory->medicines[i].batch_no, newMedicine.batch_no) == 0 && 
        strcmp(inventory->medicines[i].manufacturer, newMedicine.manufacturer) == 0) {
      return 1;
    }
  }

  /* Add medicine to inventory */
  inventory->medicines[inventory->count] = newMedicine;
  inventory->count++;

  /* Return 0 if medicine is successfully added */
  return 0;
}

int searchMedicine(struct MedicineInventory *inventory) {
  /* Ask for medicine name */
  char searchName[MAX_NAME_LENGTH];
  printf("Enter medicine name: ");
  scanf("%s", searchName);

  /* Check if medicine exists */
  for (int i = 0; i < inventory->count; i++) {
    if (strcmp(inventory->medicines[i].name, searchName) == 0) {
      /* Display medicine details */
      displayMedicine(&inventory->medicines[i]);
      return 0;
    }
  }

  /* Return -1 if medicine does not exist */
  return -1;
}

void displayMedicine(struct Medicine *medicine) {
  /* Display medicine details */
  printf("Name: %s\n", medicine->name);
  printf("Batch No: %s\n", medicine->batch_no);
  printf("Manufacturer: %s\n", medicine->manufacturer);
  printf("Price: %f\n", medicine->price);
  printf("Quantity: %d\n\n", medicine->quantity);
}

void displayAllMedicines(struct MedicineInventory *inventory) {
  /* Display details of all medicines */
  if (inventory->count == 0) {
    printf("Inventory is empty\n\n");
  } else {
    for (int i = 0; i < inventory->count; i++) {
      displayMedicine(&inventory->medicines[i]);
    }
  }
}

void deleteMedicine(struct MedicineInventory *inventory) {
  /* Ask for medicine name */
  char deleteName[MAX_NAME_LENGTH];
  printf("Enter medicine name: ");
  scanf("%s", deleteName);

  /* Check if medicine exists */
  int medicineIndex = -1;
  for (int i = 0; i < inventory->count; i++) {
    if (strcmp(inventory->medicines[i].name, deleteName) == 0) {
      medicineIndex = i;
      break;
    }
  }

  if (medicineIndex > -1) {
    /* Shift array elements to delete medicine */
    for (int i = medicineIndex; i < inventory->count - 1; i++) {
      inventory->medicines[i] = inventory->medicines[i+1];
    }
    inventory->count--;
    printf("Medicine has been deleted\n\n");
  } else {
    printf("Medicine does not exist\n\n");
  }
}

void updateMedicine(struct MedicineInventory *inventory) {
  /* Ask for medicine name */
  char updateName[MAX_NAME_LENGTH];
  printf("Enter medicine name: ");
  scanf("%s", updateName);

  /* Check if medicine exists */
  int medicineIndex = -1;
  for (int i = 0; i < inventory->count; i++) {
    if (strcmp(inventory->medicines[i].name, updateName) == 0) {
      medicineIndex = i;
      break;
    }
  }

  if (medicineIndex > -1) {
    /* Ask for new medicine details */
    struct Medicine updatedMedicine;
    printf("Enter new Medicine details: \n");
    printf("Batch No: ");
    scanf("%s", updatedMedicine.batch_no);
    printf("Manufacturer: ");
    scanf("%s", updatedMedicine.manufacturer);
    printf("Price: ");
    scanf("%f", &updatedMedicine.price);
    printf("Quantity: ");
    scanf("%d", &updatedMedicine.quantity);

    /* Update medicine details */
    inventory->medicines[medicineIndex].price = updatedMedicine.price;
    inventory->medicines[medicineIndex].quantity = updatedMedicine.quantity;
    strcpy(inventory->medicines[medicineIndex].batch_no, updatedMedicine.batch_no);
    strcpy(inventory->medicines[medicineIndex].manufacturer, updatedMedicine.manufacturer);

    printf("Medicine details have been updated\n\n");
  } else {
    printf("Medicine does not exist\n\n");
  }
}