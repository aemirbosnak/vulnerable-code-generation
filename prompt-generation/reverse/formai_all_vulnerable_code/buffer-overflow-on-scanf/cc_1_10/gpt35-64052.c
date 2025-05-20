//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
   int id;
   char name[50];
   float price;
   int quantity;
};

void printMenu() {
   printf("\n==============================\n");
   printf(" MEDICAL STORE MANAGEMENT SYSTEM \n");
   printf("==============================\n");
   printf("1. Add Medicine\n");
   printf("2. Update Medicine\n");
   printf("3. Delete Medicine\n");
   printf("4. Search Medicine\n");
   printf("5. List All Medicines\n");
   printf("6. Exit\n");
}

void addMedicine(struct medicine meds[], int *numMeds) {
   printf("Enter medicine ID: ");
   scanf("%d", &meds[*numMeds].id);
   printf("Enter medicine name: ");
   scanf("%s", meds[*numMeds].name);
   printf("Enter medicine price: ");
   scanf("%f", &meds[*numMeds].price);
   printf("Enter quantity: ");
   scanf("%d", &meds[*numMeds].quantity);
   (*numMeds)++;
   printf("\nMedicine added successfully!\n");
}

void updateMedicine(struct medicine meds[], int numMeds) {
   int id, i, choice, quantity;
   float price;
   char name[50];
   printf("Enter medicine ID to update: ");
   scanf("%d", &id);
   for (i=0; i<numMeds; i++) {
      if (meds[i].id == id) {
         printf("\nEnter field to update:\n");
         printf("1. Name\n");
         printf("2. Price\n");
         printf("3. Quantity\n");
         scanf("%d", &choice);
         switch (choice) {
            case 1:
               printf("Enter new name: ");
               scanf("%s", name);
               strcpy(meds[i].name, name);
               break;
            case 2:
               printf("Enter new price: ");
               scanf("%f", &price);
               meds[i].price = price;
               break;
            case 3:
               printf("Enter new quantity: ");
               scanf("%d", &quantity);
               meds[i].quantity = quantity;
               break;
            default:
               printf("Invalid choice!\n");
         }
         printf("Medicine updated successfully!\n");
         return;
      }
   }
   printf("Medicine not found!\n");
}

void deleteMedicine(struct medicine meds[], int *numMeds) {
   int id, i, j;
   printf("Enter medicine ID to delete: ");
   scanf("%d", &id);
   for (i=0; i<*numMeds; i++) {
      if (meds[i].id == id) {
         for (j=i; j<*numMeds-1; j++) {
            meds[j] = meds[j+1];
         }
         (*numMeds)--;
         printf("Medicine deleted successfully!\n");
         return;
      }
   }
   printf("Medicine not found!\n");
}

void searchMedicine(struct medicine meds[], int numMeds) {
   int id, i;
   printf("Enter medicine ID to search: ");
   scanf("%d", &id);
   for (i=0; i<numMeds; i++) {
      if (meds[i].id == id) {
         printf("\nMedicine found!\n");
         printf("ID: %d\n", meds[i].id);
         printf("Name: %s\n", meds[i].name);
         printf("Price: %.2f\n", meds[i].price);
         printf("Quantity: %d\n", meds[i].quantity);
         return;
      }
   }
   printf("Medicine not found!\n");
}

void listAllMedicines(struct medicine meds[], int numMeds) {
   int i;
   printf("\n===============================================================================\n");
   printf(" MEDICINE ID        MEDICINE NAME         PRICE         QUANTITY  \n");
   printf("===============================================================================\n");
   for (i=0; i<numMeds; i++) {
      printf(" %-15d\t%-20s\t%-10.2f\t%-15d\n", meds[i].id, meds[i].name, meds[i].price, meds[i].quantity);
   }
   printf("\n");
}

int main() {
   struct medicine meds[50];
   int choice, numMeds=0;
   do {
      printMenu();
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            addMedicine(meds, &numMeds);
            break;
         case 2:
            updateMedicine(meds, numMeds);
            break;
         case 3:
            deleteMedicine(meds, &numMeds);
            break;
         case 4:
            searchMedicine(meds, numMeds);
            break;
         case 5:
            listAllMedicines(meds, numMeds);
            break;
         case 6:
            printf("\nExiting...\n");
            return 0;
         default:
            printf("\nInvalid choice!\n");
      }
   } while (1);
   return 0;
}