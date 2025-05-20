//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new medicine.
void add_medicine() {
  char name[50];
  int quantity, price;
  FILE *fp;

  fp = fopen("medicine.txt", "a");
  if(fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  printf("Enter medicine name: ");
  scanf("%s", name);

  printf("Enter quantity: ");
  scanf("%d", &quantity);

  printf("Enter price: ");
  scanf("%d", &price);

  fprintf(fp, "%s %d %d\n", name, quantity, price);

  fclose(fp);
}

// Function to view all medicines in stock.
void view_medicines() {
  char ch;
  FILE *fp;

  fp = fopen("medicine.txt", "r");
  if(fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  printf("Medicines in stock:\n");

  while((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  fclose(fp);
}

// Function to search for a medicine by name.
void search_medicine() {
  char name[50], ch;
  int quantity, price;
  FILE *fp;

  fp = fopen("medicine.txt", "r");
  if(fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  printf("Enter medicine name: ");
  scanf("%s", name);

  while(fscanf(fp, "%s %d %d\n", name, &quantity, &price) != EOF) {
    if(strcmp(name, name) == 0) {
      printf("Name: %s\n", name);
      printf("Quantity: %d\n", quantity);
      printf("Price: %d\n", price);
      break;
    }
  }

  fclose(fp);
}

// Main function
void main() {
  int choice;

  while(1) {
    printf("\n\nC Medical Store\n");
    printf("1. Add a medicine.\n");
    printf("2. View all medicines in stock.\n");
    printf("3. Search for a medicine by name.\n");
    printf("4. Exit.\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_medicine();
        break;
      case 2:
        view_medicines();
        break;
      case 3:
        search_medicine();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
}