//FormAI DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
  int account_number;
  char name[30];
  int age;
  float balance;
  char address[50];
};

struct bank_record bank[10];

int main() {
  int choice = 0;
  int count = 0;
  
  while (choice != 6) {
    printf("Welcome to the Unique Banking Record System!\n");
    printf("--------------------------------------------\n");
    printf("1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Search for a record\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        //Add a new record
        printf("Enter the account number: ");
        scanf("%d", &bank[count].account_number);
        printf("Enter the name: ");
        scanf("%s", bank[count].name);
        printf("Enter the age: ");
        scanf("%d", &bank[count].age);
        printf("Enter the balance: ");
        scanf("%f", &bank[count].balance);
        printf("Enter the address: ");
        scanf("%s", bank[count].address);
        printf("Record added successfully!\n");
        count++;
        break;
        
      case 2:
        //Display all records
        printf("Account Number\tName\tAge\tBalance\tAddress\n");
        printf("------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
          printf("%d\t\t%s\t%d\t%.2f\t%s\n", bank[i].account_number, bank[i].name, bank[i].age, bank[i].balance, bank[i].address);
        }
        break;
        
      case 3:
        //Search for a record
        printf("Enter the account number to search for: ");
        int search_number;
        scanf("%d", &search_number);
        for (int i = 0; i < count; i++) {
          if (bank[i].account_number == search_number) {
            printf("Account Number\tName\tAge\tBalance\tAddress\n");
            printf("------------------------------------------------\n");
            printf("%d\t\t%s\t%d\t%.2f\t%s\n", bank[i].account_number, bank[i].name, bank[i].age, bank[i].balance, bank[i].address);
            break;
          }
          else if (i == count - 1) {
            printf("Record not found!\n");
          }
        }
        break;
        
      case 4:
        //Update a record
        printf("Enter the account number to update: ");
        int update_number;
        scanf("%d", &update_number);
        for (int i = 0; i < count; i++) {
          if (bank[i].account_number == update_number) {
            printf("Enter the new name (or type '-' to skip): ");
            char new_name[30];
            scanf("%s", new_name);
            if (strcmp(new_name, "-") != 0) {
              strcpy(bank[i].name, new_name);
            }
            printf("Enter the new age (or type 0 to skip): ");
            int new_age;
            scanf("%d", &new_age);
            if (new_age != 0) {
              bank[i].age = new_age;
            }
            printf("Enter the new balance (or type 0 to skip): ");
            float new_balance;
            scanf("%f", &new_balance);
            if (new_balance != 0) {
              bank[i].balance = new_balance;
            }
            printf("Enter the new address (or type '-' to skip): ");
            char new_address[50];
            scanf("%s", new_address);
            if (strcmp(new_address, "-") != 0) {
              strcpy(bank[i].address, new_address);
            }
            printf("Record updated successfully!\n");
            break;
          }
          else if (i == count - 1) {
            printf("Record not found!\n");
          }
        }
        break;
        
      case 5:
        //Delete a record
        printf("Enter the account number to delete: ");
        int delete_number;
        scanf("%d", &delete_number);
        for (int i = 0; i < count; i++) {
          if (bank[i].account_number == delete_number) {
            for (int j = i; j < count - 1; j++) {
              bank[j] = bank[j+1];
            }
            count--;
            printf("Record deleted successfully!\n");
            break;
          }
          else if (i == count - 1) {
            printf("Record not found!\n");
          }
        }
        break;
        
      case 6:
        //Exit
        printf("Goodbye!\n");
        break;
        
      default:
        printf("Invalid choice! Please try again.\n");
    }
    
    printf("\n");
  }
  
  return 0;
}