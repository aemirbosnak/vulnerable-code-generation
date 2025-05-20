//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MED 100
#define MAX_PURCHASE 1000

struct medical_store {
  char med_name[50];
  int med_code;
  float med_price;
  int med_stock;
};

struct purchase_order {
  char med_name[50];
  int quantity;
  float total_price;
};

struct medical_store medicine[MAX_MED];
struct purchase_order purchase[MAX_PURCHASE];

int total_medicines = 0, total_purchases = 0;

void add_medicine() {
  printf("Enter the medicine name: ");
  scanf("%s", &medicine[total_medicines].med_name);
  printf("Enter the medicine code: ");
  scanf("%d", &medicine[total_medicines].med_code);
  printf("Enter the medicine price: ");
  scanf("%f", &medicine[total_medicines].med_price);
  printf("Enter the medicine stock: ");
  scanf("%d", &medicine[total_medicines].med_stock);

  total_medicines++;
}

void add_purchase() {
  printf("Enter the medicine name: ");
  scanf("%s", &purchase[total_purchases].med_name);
  printf("Enter the quantity: ");
  scanf("%d", &purchase[total_purchases].quantity);

  for(int i = 0; i < total_medicines; i++) {
    if(strcmp(purchase[total_purchases].med_name, medicine[i].med_name) == 0) {
      purchase[total_purchases].total_price = medicine[i].med_price * purchase[total_purchases].quantity;
      medicine[i].med_stock += purchase[total_purchases].quantity;
      total_purchases++;
      return;
    }
  }

  printf("Sorry, we do not have that medicine in stock.\n");
}

void display_stock() {
  printf("Medicine Name | Medicine Code | Price | Stock\n");
  printf("=============================================\n");
  for(int i = 0; i < total_medicines; i++) {
    printf("%-12s | %-12d | %-5.2f | %-5d\n", medicine[i].med_name, medicine[i].med_code, medicine[i].med_price, medicine[i].med_stock);
  }
}

void display_purchases() {
  printf("Medicine Name | Quantity | Total Price\n");
  printf("======================================\n");
  for(int i = 0; i < total_purchases ; i++) {
    printf("%-12s | %-8d | %-10.2f\n", purchase[i].med_name, purchase[i].quantity, purchase[i].total_price);
  }
}

int main() {
  int choice;

  printf("Welcome to the Medical Store Management System.\n");

  while(1) {
    printf("\n");
    printf("1. Add medicine.\n");
    printf("2. Add purchase to the stock.\n");
    printf("3. Display medicine stock.\n");
    printf("4. Display purchase history.\n");
    printf("5. Exit.\n");
    printf("Please enter your choice: ");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_medicine();
        break;
      case 2:
        add_purchase();
        break;
      case 3:
        display_stock();
        break;
      case 4:
        display_purchases();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  }

  return 0;
}