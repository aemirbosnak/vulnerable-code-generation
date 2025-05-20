//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Medicine{
  int id;
  char name[MAX];
  int quantity;
  float price;
};

struct Bill{
  int id;
  char name[MAX];
  int quantity;
  float price;
  float total;
};

struct Medicine stock[MAX];
struct Bill cart[MAX];

int countMedicine = 0, countCart = 0;

void addMedicine(){
  int id, qty;
  float price;
  char name[MAX];
  printf("\nEnter Medicine ID: ");
  scanf("%d",&id);
  printf("Enter Medicine Name: ");
  scanf("%s",name);
  printf("Enter Medicine Quantity: ");
  scanf("%d",&qty);
  printf("Enter Medicine Price: ");
  scanf("%f",&price);
  stock[countMedicine].id = id;
  strcpy(stock[countMedicine].name,name);
  stock[countMedicine].quantity = qty;
  stock[countMedicine].price = price;
  countMedicine++;
  printf("\nMedicine Added to the Stock Successfully!\n");
}

void searchMedicine(){
  int id, i;
  printf("\nEnter Medicine ID to Search: ");
  scanf("%d",&id);
  for(i=0; i<countMedicine; i++){
    if(stock[i].id == id){
      printf("Medicine ID: %d\n",stock[i].id);
      printf("Medicine Name: %s\n",stock[i].name);
      printf("Medicine Quantity: %d\n",stock[i].quantity);
      printf("Medicine Price: %.2f\n",stock[i].price);
      break;
    }
  }
  if(i == countMedicine){
    printf("Medicine not Found in the Stock!\n");
  }
}

void deleteMedicine(){
  int id, i, j;
  printf("\nEnter Medicine ID to Delete: ");
  scanf("%d",&id);
  for(i=0; i<countMedicine; i++){
    if(stock[i].id == id){
      for(j=i; j<countMedicine-1; j++){
        stock[j] = stock[j+1];
      }
      countMedicine--;
      printf("\nMedicine Deleted from the Stock Successfully!\n");
      break;
    }
  }
  if(i == countMedicine){
    printf("Medicine not Found in the Stock!\n");
  }
}

void purchaseMedicine(){
  int id, qty, i, index;
  printf("\nEnter Medicine ID to Purchase: ");
  scanf("%d",&id);
  for(i=0; i<countMedicine; i++){
    if(stock[i].id == id){
      printf("Enter Medicine Quantity to Purchase: ");
      scanf("%d",&qty);
      if(qty>stock[i].quantity){
        printf("\nSorry! Only %d Quantity is Available in the Stock!\n",stock[i].quantity);
        return;
      }
      cart[countCart].id = id;
      cart[countCart].quantity = qty;
      strcpy(cart[countCart].name,stock[i].name);
      cart[countCart].price = stock[i].price;
      cart[countCart].total = qty * stock[i].price;
      stock[i].quantity -= qty;
      countCart++;
      printf("\nMedicine Added to the Cart Successfully!\n");
      break;
    }
  }
  if(i == countMedicine){
    printf("Medicine not Found in the Stock!\n");
  }
}

void viewCart(){
  int i;
  float grandTotal = 0;
  printf("\nYour Cart:\n");
  printf("\nID\tName\tQuantity\tPrice\t\tTotal\n");
  for(i=0; i<countCart; i++){
    printf("%d\t%s\t%d\t\t%.2f\t\t%.2f\n",cart[i].id,cart[i].name,cart[i].quantity,cart[i].price,cart[i].total);
    grandTotal += cart[i].total;
  }
  printf("\nGrand Total: %.2f\n",grandTotal);
}

void deleteCart(){
  int id, i, j;
  printf("\nEnter Medicine ID to Delete from the Cart: ");
  scanf("%d",&id);
  for(i=0; i<countCart; i++){
    if(cart[i].id == id){
      for(j=i; j<countCart-1; j++){
        cart[j] = cart[j+1];
      }
      countCart--;
      printf("\nMedicine Deleted from the Cart Successfully!\n");
      break;
    }
  }
  if(i == countCart){
    printf("Medicine not Found in the Cart!\n");
  }
}

void printBill(){
  int i;
  float grandTotal = 0;
  printf("\nYour Bill:\n");
  printf("\nID\tName\tQuantity\tPrice\t\tTotal\n");
  for(i=0; i<countCart; i++){
    printf("%d\t%s\t%d\t\t%.2f\t\t%.2f\n",cart[i].id,cart[i].name,cart[i].quantity,cart[i].price,cart[i].total);
    grandTotal += cart[i].total;
  }
  printf("\nGrand Total: %.2f\n",grandTotal);
}

int main(){
  int ch;
  do{
    printf("\n-----Medical Store Management System-----\n");
    printf("\n1. Add Medicine to the Stock");
    printf("\n2. Search for a Medicine from the Stock");
    printf("\n3. Delete a Medicine from the Stock");
    printf("\n4. Purchase Medicine and Add to the Cart");
    printf("\n5. View Cart");
    printf("\n6. Delete Medicine from the Cart");
    printf("\n7. Generate and Print the Bill");
    printf("\n8. Exit");
    printf("\n\nEnter Your Choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1: addMedicine();
              break;
      case 2: searchMedicine();
              break;
      case 3: deleteMedicine();
              break;
      case 4: purchaseMedicine();
              break;
      case 5: viewCart();
              break;
      case 6: deleteCart();
              break;
      case 7: printBill();
              break;
      case 8: exit(0);
      default: printf("\nInvalid Choice! Try again...");
    }
  }while(ch!=8);
  return 0;
}