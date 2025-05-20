//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#define SIZE 50
char warehouse[MAX][SIZE];
int count = 0;
void addProduct() {
  int i;
  printf("\nEnter Product Name:\n");
  fflush(stdin);
  gets(warehouse[count]); //accepting the data
  count++; //incrementing the count variable
  printf("\nProduct Added Successfully!!!\n");
}
void deleteProduct() {
  int i, pos;
  char item[SIZE];
  printf("\nEnter the product name to be deleted:\n");
  fflush(stdin);
  gets(item);
  for (i = 0; i < count; i++) {
    if (strcmp(item, warehouse[i]) == 0) //comparing the input name with existing names
    {
      pos = i;
      break;
    }
  }
  if (pos == count) //if specified product is not there
    printf("\nProduct not found!!!");
  else {
    for (i = pos; i < count - 1; i++)
      strcpy(warehouse[i], warehouse[i + 1]); //if found ,deleting
    count--;
    printf("\nProduct Deleted Successfully!!!\n");
  }
}

void displayProduct() {
  int i;
  if(count==0) //checking if there is any product available
      printf("\nNo Products added yet!!!\n");
  else{
  printf("\nAll the Products in the Warehouse are:\n");
  for (i = 0; i < count; i++)
    printf("\n%d.%s", i + 1, warehouse[i]); 
  }
}

void main() {
  int ch, i;
  printf("\nWelcome to our Warehouse Management System!!!\n");
  while (1) {
    printf("\nEnter 1 to add product:\n");
    printf("Enter 2 to delete product:\n");
    printf("Enter 3 to display all products:\n");
    printf("Enter 4 to exit:\n");
    scanf("%d", & ch);
    fflush(stdin);
    switch (ch) {
    case 1:
      addProduct(); //calling the addProduct function
      break;
    case 2:
      deleteProduct(); //calling the deleteProduct function
      break;
    case 3:
      displayProduct(); //calling the displayProduct function
      break;
    case 4:
      printf("\nThank You for using our Warehouse Management System!!!\n");
      exit(0); //exiting the program
    default:
      printf("\nInvalid Choice!!!\n");
    }
  }
}