//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
  int med_id, quantity;
  char med_name[50], comp_name[50], man_date[10], exp_date[10], category[20], rack_no[10];
  float price;
};

struct customer
{
  int id, age;
  char name[40], contact_no[15], email[50], address[100];
};

void add_medicine(struct medicine m[], int *count)
{
  printf("\n** Enter details of medicine **\n");

  printf("Enter Medicine ID: ");
  scanf("%d", &m[*count].med_id);

  printf("Enter Medicine Name: ");
  scanf("%s", m[*count].med_name);

  printf("Enter Company Name: ");
  scanf("%s", m[*count].comp_name);

  printf("Enter Manufacturing Date (mm/dd/yy): ");
  scanf("%s", m[*count].man_date);

  printf("Enter Expiry Date (mm/dd/yy): ");
  scanf("%s", m[*count].exp_date);

  printf("Enter Category: ");
  scanf("%s", m[*count].category);

  printf("Enter Price: ");
  scanf("%f", &m[*count].price);

  printf("Enter Quantity: ");
  scanf("%d", &m[*count].quantity);

  printf("Enter Rack No: ");
  scanf("%s", m[*count].rack_no);

  (*count)++;

  printf("\nMedicine added successfully!\n");
}

void display_medicine(struct medicine m[], int count)
{
  printf("\n** Medicine Details **\n");

  printf("%-10s %-20s %-20s %-15s %-15s %-15s %-10s %-10s %-10s\n", "ID", "Name", "Company", "Man. Date", "Exp. Date", 
																	"Category", "Price", "Quantity", "Rack No");
  for(int i=0; i<count; i++)
    printf("%-10d %-20s %-20s %-15s %-15s %-15s %-10.2f %-10d %-10s\n", m[i].med_id, m[i].med_name, m[i].comp_name, 
																								m[i].man_date, m[i].exp_date, m[i].category, 
																								m[i].price, m[i].quantity, m[i].rack_no);
}

void search_medicine(struct medicine m[], int count)
{
  int id, flag=0;

  printf("\nEnter Medicine ID to search: ");
  scanf("%d", &id);

  for(int i=0; i<count; i++)
  {
    if(m[i].med_id==id)
    {
      printf("\nMedicine found!\n");
      printf("%-10s %-20s %-20s %-15s %-15s %-15s %-10s %-10s %-10s\n", "ID", "Name", "Company", "Man. Date", "Exp. Date", 
																					"Category", "Price", "Quantity", "Rack No");
      printf("%-10d %-20s %-20s %-15s %-15s %-15s %-10.2f %-10d %-10s\n", m[i].med_id, m[i].med_name, m[i].comp_name, 
																								m[i].man_date, m[i].exp_date, m[i].category, 
																								m[i].price, m[i].quantity, m[i].rack_no);

      flag = 1;
      break;
    }
  }

  if(flag==0)
    printf("\nMedicine not found!\n");
}

void delete_medicine(struct medicine m[], int *count)
{
  int id, flag=0;

  printf("\nEnter Medicine ID to delete: ");
  scanf("%d", &id);

  for(int i=0; i<*count; i++)
  {
    if(m[i].med_id==id)
    {
      for(int j=i; j<*count-1; j++)
        m[j] = m[j+1];

      (*count)--;

      flag = 1;

      printf("\nMedicine deleted successfully!\n");
      break;
    }
  }

  if(flag==0)
    printf("\nMedicine not found!\n");
}

void add_customer(struct customer c[], int *count)
{
  printf("\n** Enter details of customer **\n");

  printf("Enter Customer ID: ");
  scanf("%d", &c[*count].id);

  printf("Enter Name: ");
  scanf("%s", c[*count].name);

  printf("Enter Age: ");
  scanf("%d", &c[*count].age);

  printf("Enter Contact No: ");
  scanf("%s", c[*count].contact_no);

  printf("Enter Email: ");
  scanf("%s", c[*count].email);

  printf("Enter Address: ");
  scanf("%s", c[*count].address);

  (*count)++;

  printf("\nCustomer added successfully!\n");
}

void display_customer(struct customer c[], int count)
{
  printf("\n** Customer Details **\n");

  printf("%-10s %-20s %-10s %-15s %-30s %-50s\n", "ID", "Name", "Age", "Contact No", "Email", "Address");
  for(int i=0; i<count; i++)
    printf("%-10d %-20s %-10d %-15s %-30s %-50s\n", c[i].id, c[i].name, c[i].age, c[i].contact_no, c[i].email, c[i].address);
}

void search_customer(struct customer c[], int count)
{
  int id, flag=0;

  printf("\nEnter Customer ID to search: ");
  scanf("%d", &id);

  for(int i=0; i<count; i++)
  {
    if(c[i].id==id)
    {
      printf("\nCustomer found!\n");
      printf("%-10s %-20s %-10s %-15s %-30s %-50s\n", "ID", "Name", "Age", "Contact No", "Email", "Address");
      printf("%-10d %-20s %-10d %-15s %-30s %-50s\n", c[i].id, c[i].name, c[i].age, c[i].contact_no, c[i].email, c[i].address);

      flag = 1;
      break;
    }
  }

  if(flag==0)
    printf("\nCustomer not found!\n");
}

void delete_customer(struct customer c[], int *count)
{
  int id, flag=0;

  printf("\nEnter Customer ID to delete: ");
  scanf("%d", &id);

  for(int i=0; i<*count; i++)
  {
    if(c[i].id==id)
    {
      for(int j=i; j<*count-1; j++)
        c[j] = c[j+1];

      (*count)--;

      flag = 1;

      printf("\nCustomer deleted successfully!\n");
      break;
    }
  }

  if(flag==0)
    printf("\nCustomer not found!\n");
}

int main()
{
  struct medicine medicines[1000];
  struct customer customers[1000];

  int med_count=0, cust_count=0, choice;

  while(1)
  {
    printf("\n************ MENU ************\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Add Customer\n");
    printf("6. Display Customer\n");
    printf("7. Search Customer\n");
    printf("8. Delete Customer\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1: add_medicine(medicines, &med_count);
              break;
      case 2: display_medicine(medicines, med_count);
              break;
      case 3: search_medicine(medicines, med_count);
              break;
      case 4: delete_medicine(medicines, &med_count);
              break;
      case 5: add_customer(customers, &cust_count);
              break;
      case 6: display_customer(customers, cust_count);
              break;
      case 7: search_customer(customers, cust_count);
              break;
      case 8: delete_customer(customers, &cust_count);
              break;
      case 9: exit(0);
              break;
      default: printf("\nInvalid choice. Please try again.\n");
    }
  }

  return 0;
}