//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
   char name[100];
   int quantity;
   float price;
};

void displayMedicine(struct Medicine *med) {
   printf("Medicine Name: %s\n", med->name);
   printf("Medicine Quantity: %d\n", med->quantity);
   printf("Medicine Price: %.2f\n\n", med->price);
}

void addMedicine(struct Medicine *med) {
   printf("Enter Medicine Name: ");
   scanf("%s", med->name);
   printf("Enter Medicine Quantity: ");
   scanf("%d", &med->quantity);
   printf("Enter Medicine Price: ");
   scanf("%f", &med->price);
}

void updateMedicine(struct Medicine *med) {
   printf("Enter New Medicine Name: ");
   scanf("%s", med->name);
   printf("Enter New Medicine Quantity: ");
   scanf("%d", &med->quantity);
   printf("Enter New Medicine Price: ");
   scanf("%f", &med->price);
}

void deleteMedicine(struct Medicine *med) {
   med->name[0] = '\0';
   med->quantity = 0;
   med->price = 0.0;
}

void displayMenu() {
   printf("1. Add Medicine\n");
   printf("2. Update Medicine\n");
   printf("3. Delete Medicine\n");
   printf("4. Display All Medicines\n");
   printf("5. Exit\n");
}

int main() {
   int choice, i;
   struct Medicine *medicines;
   int maxMedicines = 10;
   int currentMedicines = 0;
   
   medicines = (struct Medicine*) malloc(maxMedicines* sizeof(struct Medicine));
   
   while (1) {
      displayMenu();
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            if (currentMedicines == maxMedicines) {
               maxMedicines *= 2;
               medicines = (struct Medicine*) realloc(medicines, maxMedicines * sizeof(struct Medicine));
            }
            addMedicine(&medicines[currentMedicines]);
            currentMedicines++;
            break;
         
         case 2:
            printf("Enter the index of medicine to update (0 - %d): ", currentMedicines-1);
            scanf("%d", &i);
            
            if (i>=0 && i<currentMedicines) {
               updateMedicine(&medicines[i]);
            } else {
               printf("Invalid Medicine Index!\n\n");
            }
            break;
         
         case 3:
            printf("Enter the index of medicine to delete (0 - %d): ", currentMedicines-1);
            scanf("%d", &i);
            
            if (i>=0 && i<currentMedicines) {
               deleteMedicine(&medicines[i]);
               
               for (int j=i; j<currentMedicines-1; j++) {
                  medicines[j] = medicines[j+1];
               }
               medicines[currentMedicines-1].name[0]='\0';
               medicines[currentMedicines-1].quantity=0;
               medicines[currentMedicines-1].price=0.0;
               currentMedicines--;
            } else {
               printf("Invalid Medicine Index!\n\n");
            }
            break;
           
         case 4:
            if (currentMedicines == 0) {
               printf("No Medicine Found!\n\n");
            } else {
               printf("All Medicines:\n");
               
               for (i=0; i<currentMedicines; i++) {
                  displayMedicine(&medicines[i]);
               }
            }
            break;
           
         case 5:
            printf("Terminating Program...\n");
            free(medicines);
            exit(EXIT_SUCCESS);
            
         default:
            printf("Invalid Choice!\n\n");
      }
   }
   
   return 0;
}