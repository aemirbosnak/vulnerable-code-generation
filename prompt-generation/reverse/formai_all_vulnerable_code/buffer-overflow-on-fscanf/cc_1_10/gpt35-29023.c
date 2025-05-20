//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>

  typedef struct{
      int id;
      char name[25];
      float price;
      int qty;
  }product;

  void menu();
  void add();
  void list();
  void edit();
  void del();
  void saveFile();
  void readFile();

  int choice;
  int num = 0;
  int id = 1001;
  product inventory[100];

  int main(){
      printf("Warehouse Management System");
      printf("\n\n");
      readFile();
      while(1){
          menu();
          switch(choice){
             case 1:
                  add();
                  break;
             case 2:
                  list();
                  break;
             case 3:
                  edit();
                  break;
             case 4:
                  del();
                  break;
             case 0:
                  saveFile();
                  printf("\nThank you for using this program!\n");
                  return 0;
                  break;
             default:
                  printf("\nInvalid option, please choose from the menu\n");
                  break;
          }
      }
   }

   void menu(){
      printf("\nMenu:\n");
      printf("1. Add new product\n");
      printf("2. List all products\n");
      printf("3. Edit a product\n");
      printf("4. Delete a product\n");
      printf("0. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
   }

   void add(){
      product p;
      p.id = id++;
      printf("\nEnter product name: ");
      scanf("%s", &p.name);
      printf("Enter product price: ");
      scanf("%f", &p.price);
      printf("Enter product quantity: ");
      scanf("%d", &p.qty);
      inventory[num++] = p;
      printf("\nProduct added successfully!\n");
   }

   void list(){
      printf("\nID\tName\tPrice\tQuantity\n");
      for(int i=0; i<num; i++){
          printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].qty);
      }
   }

   void edit(){
      int tempid;
      printf("\nEnter the ID of the product to edit: ");
      scanf("%d", &tempid);
      for(int i=0; i<num; i++){
          if(inventory[i].id == tempid){
             printf("\nEnter new product name: ");
             scanf("%s", &inventory[i].name);
             printf("Enter new product price: ");
             scanf("%f", &inventory[i].price);
             printf("Enter new product quantity: ");
             scanf("%d", &inventory[i].qty);
             printf("\nProduct details updated successfully!\n");
             return;
          }
      }
      printf("\nProduct with ID %d not found\n", tempid);
   }

   void del(){
      int tempid, flag = 0;
      printf("\nEnter the ID of the product to delete: ");
      scanf("%d", &tempid);
      for(int i=0; i<num; i++){
          if(inventory[i].id == tempid){
             flag = 1;
             for(int j=i; j<num-1; j++){
                 inventory[j] = inventory[j+1];
             }
             num--;
             printf("\nProduct with ID %d deleted successfully!\n", tempid);
             break;
          }
      }
      if(flag == 0){
         printf("\nProduct with ID %d not found\n", tempid);
      }
   }

   void saveFile(){
      FILE *file;
      file = fopen("inventory.txt", "w");
      for(int i=0; i<num; i++){
          fprintf(file, "%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].qty);
      }
      fclose(file);
      printf("\nData saved to file successfully!\n");
   }

   void readFile(){
       FILE *file;
       file = fopen("inventory.txt", "r");
       if(file == NULL){
          printf("\nFile not found\n");
          return;
       }
       while(fscanf(file, "%d %s %f %d", &inventory[num].id, inventory[num].name, &inventory[num].price, &inventory[num].qty) == 4){
           num++;
       }
       fclose(file);
   }