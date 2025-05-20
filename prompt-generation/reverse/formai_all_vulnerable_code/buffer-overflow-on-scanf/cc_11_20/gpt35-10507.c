//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
  char name[50];
  int account_number;
  float balance;
};

int main() {
  int choice, i, n=0;
  char name[50];
  FILE *fp;
  struct customer c;

  printf("Welcome to the Banking Record System!\n");

  while(1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add a new customer\n");
    printf("2. Update customer information\n");
    printf("3. Delete a customer\n");
    printf("4. View all customers\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // Add a new customer
        fp = fopen("customers.dat", "a");
        printf("\nEnter name: ");
        scanf("%s", c.name);
        printf("Enter account number: ");
        scanf("%d", &c.account_number);
        printf("Enter balance: ");
        scanf("%f", &c.balance);
        fwrite(&c, sizeof(c), 1, fp);
        printf("\nNew customer (%s, %d, %.2f) added successfully!\n", c.name, c.account_number, c.balance);
        fclose(fp);
        break;

      case 2: // Update customer information
        fp = fopen("customers.dat", "r+");
        printf("\nEnter name of customer: ");
        scanf("%s", name);
        while(fread(&c, sizeof(c), 1, fp)) {
          if(strcmp(name, c.name) == 0) {
            printf("Enter new account number: ");
            scanf("%d", &c.account_number);
            printf("Enter new balance: ");
            scanf("%f", &c.balance);
            fseek(fp, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, fp);
            printf("Customer information updated successfully!\n");
            break;
          }
        }
        if(strcmp(name, c.name) != 0) {
          printf("Customer not found...\n");
        }
        fclose(fp);
        break;

      case 3: // Delete a customer
        fp = fopen("customers.dat", "r");
        FILE *temp = fopen("temp.dat", "w");
        printf("\nEnter name of customer: ");
        scanf("%s", name);
        while(fread(&c, sizeof(c), 1, fp)) {
          if(strcmp(name, c.name) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
          }
        }
        fclose(fp);
        fclose(temp);
        remove("customers.dat");
        rename("temp.dat", "customers.dat");
        printf("Customer deleted successfully!\n");
        break;

      case 4: // View all customers
        fp = fopen("customers.dat", "r");
        if(fp == NULL) {
          printf("No customers found...\n");
        }
        else {
          printf("\nList of all customers:\n");
          printf("Name\tAccount Number\tBalance\n");
          while(fread(&c, sizeof(c), 1, fp)) {
            printf("%s\t%d\t\t%.2f\n", c.name, c.account_number, c.balance);
          }
          fclose(fp);
        }
        break;

      case 5: // Exit
        printf("Thank you for using the Banking Record System!\n");
        exit(0);
        break;

      default:
        printf("Invalid choice...\n");
        break;
    }
  }

  return 0;
}