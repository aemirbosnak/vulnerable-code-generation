//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Medicine Information
struct medicine {
  int ID;
  char name[30];
  char manufacturer[30];
  char formula[20];
  float price;
  int quantity;
};

// Function prototypes
void AddMedicine();
void SearchMedicine();
void ListMedicine();
void UpdateMedicine();
void DeleteMedicine();

// Main function
int main() {
  int choice;

  while (1) {
    printf("\n----- Medical Store Management System -----");
    printf("\n1. Add New Medicine");
    printf("\n2. Search Medicine");
    printf("\n3. List All Medicine");
    printf("\n4. Update Medicine Information");
    printf("\n5. Delete Medicine");
    printf("\n6. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        AddMedicine();
        break;

      case 2:
        SearchMedicine();
        break;

      case 3:
        ListMedicine();
        break;

      case 4:
        UpdateMedicine();
        break;

      case 5:
        DeleteMedicine();
        break;

      case 6:
        printf("\nThank you for using the system. Goodbye!");
        exit(0);
        break;

      default:
        printf("\nInvalid choice. Try again!");
        break;
    }
  }

  return 0;
}

// Function to add new Medicine
void AddMedicine() {
  struct medicine med;
  FILE *fp;

  printf("\nEnter Medicine ID: ");
  scanf("%d", &med.ID);
  printf("Enter Medicine Name: ");
  scanf("%s", med.name);
  printf("Enter Medicine Manufacturer: ");
  scanf("%s", med.manufacturer);
  printf("Enter Medicine Formula: ");
  scanf("%s", med.formula);
  printf("Enter Medicine Price: ");
  scanf("%f", &med.price);
  printf("Enter Medicine Quantity: ");
  scanf("%d", &med.quantity);

  fp = fopen("med.store", "ab");
  fwrite(&med, sizeof(struct medicine), 1, fp);

  printf("\nMedicine added successfully!");
  fclose(fp);
}

// Function to search Medicine
void SearchMedicine() {
  FILE *fp;
  struct medicine med;
  int id;

  printf("\nEnter Medicine ID to search for: ");
  scanf("%d", &id);

  fp = fopen("med.store", "rb");

  while (fread(&med, sizeof(struct medicine), 1, fp)) {
    if (med.ID == id) {
      printf("\nMedicine Information:\n");
      printf("ID: %d\nName: %s\nManufacturer: %s\nFormula: %s\nPrice: %.2f\nQuantity: %d",
             med.ID, med.name, med.manufacturer, med.formula, med.price, med.quantity);
      fclose(fp);
      return;
    }
  }

  printf("\nMedicine not found!");
  fclose(fp);
}

// Function to list all Medicine
void ListMedicine() {
  FILE *fp;
  struct medicine med;

  printf("\nList of all Medicine:\n");
  printf("ID\tName\t\tManufacturer\tFormula\tPrice\tQuantity\n");

  fp = fopen("med.store", "rb");

  while (fread(&med, sizeof(struct medicine), 1, fp)) {
    printf("%d\t%-10s\t%-10s\t%-10s\t%.2f\t%d\n",
           med.ID, med.name, med.manufacturer, med.formula, med.price, med.quantity);
  }

  fclose(fp);
}

// Function to update Medicine Information
void UpdateMedicine() {
  FILE *fp;
  struct medicine med;
  int id, found = 0;

  printf("\nEnter Medicine ID to update: ");
  scanf("%d", &id);

  fp = fopen("med.store", "rb+");
  
  while (fread(&med, sizeof(struct medicine), 1, fp)) {
    if (med.ID == id) {
      printf("\nEnter new Medicine Name: ");
      scanf("%s", med.name);
      printf("Enter new Medicine Manufacturer: ");
      scanf("%s", med.manufacturer);
      printf("Enter new Medicine Formula: ");
      scanf("%s", med.formula);
      printf("Enter new Medicine Price: ");
      scanf("%f", &med.price);
      printf("Enter new Medicine Quantity: ");
      scanf("%d", &med.quantity);

      fseek(fp, -sizeof(struct medicine), SEEK_CUR);
      fwrite(&med, sizeof(struct medicine), 1, fp);

      printf("\nMedicine Information updated successfully!");
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("\nMedicine not found!");
  }

  fclose(fp);
}

// Function to delete Medicine
void DeleteMedicine() {
  FILE *fp, *fp1;
  struct medicine med;
  int id, found = 0;

  printf("\nEnter Medicine ID to delete: ");
  scanf("%d", &id);

  fp = fopen("med.store", "rb");
  fp1 = fopen("temp.store", "wb");

  while (fread(&med, sizeof(struct medicine), 1, fp)) {
    if (med.ID != id) {
      fwrite(&med, sizeof(struct medicine), 1, fp1);
    } else {
      found = 1;
    }
  }

  fclose(fp);
  fclose(fp1);

  remove("med.store");
  rename("temp.store", "med.store");

  if (found) {
    printf("\nMedicine information deleted successfully!");
  } else {
    printf("\nMedicine not found!");
  }
}