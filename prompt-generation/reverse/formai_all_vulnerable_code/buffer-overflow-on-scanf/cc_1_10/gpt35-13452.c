//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

struct Medicine{
  char name[50];
  int id;
  int quantity;
  float price;
};

void AddMedicine();
void ViewMedicine();
void RemoveMedicine();
void ModifyMedicine();
void GenerateBill();

int main(){
  int choice;
  while(1){
    printf("\n----Medical Store Management System----\n");
    printf("1. Add Medicine\n2. View Medicine\n3. Remove Medicine\n4. Modify Medicine\n5. Generate Bill\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1: AddMedicine();
              break;
      case 2: ViewMedicine();
              break;
      case 3: RemoveMedicine();
              break;
      case 4: ModifyMedicine();
              break;
      case 5: GenerateBill();
              break;
      case 6: printf("Exiting program..\n");
              exit(0);
      default: printf("Invalid choice!\n");
    }
  }
  return 0;
}

void AddMedicine(){
  //add medicine to database
}

void ViewMedicine(){
  //view medicine from database
}

void RemoveMedicine(){
  //remove medicine from database
}

void ModifyMedicine(){
  //modify medicine details in database
}

void GenerateBill(){
  //generate bill based on medicine purchase
}