//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declare a struct for holding medicine information
struct medicine {
   char name[50];
   int quantity;
   float price;
}med;

// declare a function to add medicine in store
void add_medicine() {
   FILE *fp;
   fp = fopen("store.txt", "a");
   printf("\nEnter medicine name: ");
   scanf("%s", &med.name);
   printf("\nEnter medicine quantity: ");
   scanf("%d", &med.quantity);
   printf("\nEnter medicine price: ");
   scanf("%f", &med.price);
   fprintf(fp, "%s\t%d\t%f\n", med.name, med.quantity, med.price);
   fclose(fp);
}

// declare a function to search medicine in store
void search_medicine(char *name) {
   FILE *fp;
   int flag = 0;
   fp = fopen("store.txt", "r");
   while (fscanf(fp, "%s\t%d\t%f\n", med.name, &med.quantity, &med.price) != EOF) {
      if (strcmp(med.name, name) == 0) {
         printf("\nThe medicine %s is available in the store\n", name);
         printf("\n%s\t%d\t%f\n", med.name, med.quantity, med.price);
         flag = 1;
         break;
      }
   }
   if (flag == 0) {
      printf("\nThe medicine %s is not available in the store\n", name);
   }
   fclose(fp);
}

// main function
int main() {
   int choice;
   char name[50];
   do {
      printf("\n\nMedical Store Management System");
      printf("\n1. Add Medicine");
      printf("\n2. Search Medicine");
      printf("\n3. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            add_medicine();
            break;
         case 2:
            printf("\nEnter medicine name: ");
            scanf("%s", &name);
            search_medicine(name);
            break;
         case 3:
            exit(0);
            break;
         default:
            printf("\nInvalid choice. Try again!");
      }
   } while(choice != 3);
   return 0;
}