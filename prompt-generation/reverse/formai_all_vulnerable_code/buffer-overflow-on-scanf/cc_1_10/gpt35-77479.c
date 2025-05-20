//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
   int id;
   char name[50];
   int quantity;
   float price;
};

void displayMedicine(struct medicine med);

int main() {
   struct medicine med;
   FILE *fp;

   int ch, medId, found = 0, quantity;

   while(1) {
      printf("\n\n1. Add medicine\n2. Update medicine\n3. Remove medicine\n4. View all medicine\n5. Search medicine\n6. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);

      switch(ch) {
         case 1:
            fp = fopen("medicines.txt", "a+");
            printf("\nEnter the medicine ID: ");
            scanf("%d", &med.id);
            printf("Enter the medicine name: ");
            scanf("%s", med.name);
            printf("Enter the quantity of medicine: ");
            scanf("%d", &med.quantity);
            printf("Enter the price of medicine: ");
            scanf("%f", &med.price);

            fwrite(&med, sizeof(med), 1, fp);

            printf("\nMedicine added successfully!");
            fclose(fp);
            break;
         case 2:
            fp = fopen("medicines.txt", "r+");
            printf("\nEnter the medicine ID to update: ");
            scanf("%d", &medId);

            while(fread(&med, sizeof(med), 1, fp)) {
               if(med.id == medId) {
                  found = 1;
                  printf("Enter new quantity of medicine: ");
                  scanf("%d", &quantity);
                  med.quantity = quantity;

                  fseek(fp, -sizeof(med), SEEK_CUR);
                  fwrite(&med, sizeof(med), 1, fp);
                  fclose(fp);
                  break;
               }
            }

            if(!found)
               printf("\nMedicine not found!");

            printf("\nMedicine updated successfully!");
            break;
         case 3:
            fp = fopen("medicines.txt", "r+");
            FILE *temp = fopen("temp.txt", "w+");
            printf("\nEnter the medicine ID to remove: ");
            scanf("%d", &medId);

            while(fread(&med, sizeof(med), 1, fp)) {
               if(med.id != medId)
                  fwrite(&med, sizeof(med), 1, temp);
               else
                  found = 1;
            }

            fclose(fp);
            fclose(temp);

            remove("medicines.txt");
            rename("temp.txt", "medicines.txt");

            if(!found)
               printf("\nMedicine not found!");

            printf("\nMedicine removed successfully!");
            break;
         case 4:
            fp = fopen("medicines.txt", "r");

            printf("\nAll medicines:\n");
            while(fread(&med, sizeof(med), 1, fp))
               displayMedicine(med);

            fclose(fp);
            break;
         case 5:
            fp = fopen("medicines.txt", "r");

            printf("\nEnter the medicine ID to search for: ");
            scanf("%d", &medId);

            while(fread(&med, sizeof(med), 1, fp)) {
               if(med.id == medId) {
                  found = 1;
                  displayMedicine(med);
                  break;
               }
            }

            if(!found)
               printf("\nMedicine not found!");

            fclose(fp);
            break;
         case 6:
            exit(0);
         default:
            printf("\nInvalid choice!");
      }
   }

   return 0;
}

void displayMedicine(struct medicine med) {
   printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", med.id, med.name, med.quantity, med.price);
}