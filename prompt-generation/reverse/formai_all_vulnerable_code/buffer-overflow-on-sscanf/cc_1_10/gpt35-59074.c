//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
  int room_num;
  char name[50];
  int days_stayed;
  int total_cost;
};

int main() {
  int option = 0;

  while (option != 4) {
    printf("Select an option:\n");
    printf("1. Check in a customer\n");
    printf("2. Check out a customer\n");
    printf("3. View all customers checked in\n");
    printf("4. Exit program\n");

    scanf("%d", &option);

    if (option == 1) {
      struct customer new_customer;

      printf("Enter room number: ");
      scanf("%d", &new_customer.room_num);

      printf("Enter customer name: ");
      scanf("%s", new_customer.name);

      printf("Enter number of days stayed: ");
      scanf("%d", &new_customer.days_stayed);

      new_customer.total_cost = 100 * new_customer.days_stayed;

      FILE *fp;
      fp = fopen("customers.txt", "a");

      fprintf(fp, "%d %s %d %d\n", new_customer.room_num, new_customer.name, new_customer.days_stayed, new_customer.total_cost);
      fclose(fp);

      printf("\nCustomer checked in successfully!\n\n");

    } else if (option == 2) {
      int room_num;
      printf("Enter room number to check out: ");
      scanf("%d", &room_num);

      FILE *fp, *fp2;
      fp = fopen("customers.txt", "r");
      fp2 = fopen("temp_file.txt", "w");

      char line[1000];
      int found = 0;
      while (fgets(line, 1000, fp)) {
        int current_room_num;
        char current_name[50];
        int days_stayed;
        int total_cost;
        sscanf(line, "%d %s %d %d", &current_room_num, current_name, &days_stayed, &total_cost);

        if (current_room_num == room_num) {
          printf("\nCustomer checked out successfully!\n\n");
          found = 1;
        } else {
          fprintf(fp2, "%d %s %d %d\n", current_room_num, current_name, days_stayed, total_cost);
        }
      }

      fclose(fp);
      fclose(fp2);

      if (found == 0) {
        printf("\nCustomer with that room number not found.\n\n");
      } else {
        remove("customers.txt");
        rename("temp_file.txt", "customers.txt");
      }

    } else if (option == 3) {
      FILE *fp;
      fp = fopen("customers.txt", "r");

      printf("Room Number\tName\tDays Stayed\tTotal Cost\n");

      char line[1000];
      while (fgets(line, 1000, fp)) {
        int current_room_num;
        char current_name[50];
        int days_stayed;
        int total_cost;
        sscanf(line, "%d %s %d %d", &current_room_num, current_name, &days_stayed, &total_cost);

        printf("%d\t\t%s\t%d\t\t$%d.00\n", current_room_num, current_name, days_stayed, total_cost);
      }

      fclose(fp);

      printf("\n");

    } else if (option == 4) {
      printf("Exiting program...\n\n");
      exit(0);

    } else {
      printf("Invalid option, please try again.\n\n");
    }
  }

  return 0;
}