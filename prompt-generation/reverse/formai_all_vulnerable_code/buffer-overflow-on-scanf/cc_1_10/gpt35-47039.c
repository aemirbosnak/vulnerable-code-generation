//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Structures for Hotel Management System
struct customer {
  char name[50];
  int room_number;
  int days;
  float rate;
};

struct employee {
  char name[50];
  int age;
  float salary;
};

// Functions
void add_customer();
void check_out();
void view_customers();
void view_employee();

// Global variables
struct customer customers[100];
int num_customers = 0;
struct employee employees[10];
int num_employees = 0;

int main() {
  int choice;

  printf("==================\n");
  printf("C Hotel Management System\n");
  printf("==================\n");

  while(1) {
    printf("\n\n");
    printf("1. Add Customer\n");
    printf("2. Check Out Customer\n");
    printf("3. View Customers\n");
    printf("4. View Employees\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_customer();
        break;
      case 2:
        check_out();
        break;
      case 3:
        view_customers();
        break;
      case 4:
        view_employee();
        break;
      case 5:
        printf("\nGoodbye!\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
    }
  }
}

// Add a customer to the hotel
void add_customer() {
  struct customer new_customer;

  printf("\nEnter customer name: ");
  scanf("%s", new_customer.name);

  printf("Enter room number: ");
  scanf("%d", &new_customer.room_number);

  printf("Enter number of days: ");
  scanf("%d", &new_customer.days);

  printf("Enter rate per day: ");
  scanf("%f", &new_customer.rate);

  // Add the customer to the global array
  customers[num_customers] = new_customer;
  num_customers++;

  printf("\nCustomer added successfully!\n");
}

// Check out a customer from the hotel
void check_out() {
  int room_num;
  int found = 0;

  printf("\nEnter room number to check out: ");
  scanf("%d", &room_num);

  // Find the customer with the given room number
  for(int i = 0; i < num_customers; i++) {
    if(customers[i].room_number == room_num) {
      found = 1;

      // Calculate total bill
      float total_bill = customers[i].days * customers[i].rate;

      printf("\nCustomer Details:\n");
      printf("Name: %s\n", customers[i].name);
      printf("Room Number: %d\n", customers[i].room_number);
      printf("Number of Days: %d\n", customers[i].days);
      printf("Rate per Day: %.2f\n", customers[i].rate);
      printf("Total Bill: %.2f\n", total_bill);

      // Remove the customer from the global array
      for(int j = i; j < num_customers - 1; j++) {
        customers[j] = customers[j+1];
      }
      num_customers--;
    }
  }
  if(found == 0) {
    printf("\nCustomer not found!\n");
  }
}

// View all the current customers in the hotel
void view_customers() {
  printf("\nCurrent Customers:\n");
  for(int i = 0; i < num_customers; i++) {
    printf("%d) Name: %s, Room Number: %d\n", i+1, customers[i].name, customers[i].room_number);
  }
}

// View all the employees of the hotel
void view_employee() {
  printf("\nCurrent Employees:\n");
  for(int i = 0; i < num_employees; i++) {
    printf("%d) Name: %s, Age: %d, Salary: %.2f\n", i+1, employees[i].name, employees[i].age, employees[i].salary);
  }
}