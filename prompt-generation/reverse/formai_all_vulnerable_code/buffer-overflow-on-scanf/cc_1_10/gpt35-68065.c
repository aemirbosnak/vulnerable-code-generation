//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
  float total_amount = 0.0, discount = 0.0, net_amount = 0.0, service_tax = 0.0, vat = 0.0, grand_total = 0.0;
  int num_items = 0, i = 0;
  char choice;

  printf("=============================================================\n");
  printf("                  WELCOME TO C CAFE BILLING SYSTEM            \n");
  printf("=============================================================\n");

  do {
    float price = 0.0;
    printf("\nEnter the price of item %d: ", i+1);
    scanf("%f", &price);
    
    // Add the price to the total amount
    total_amount += price;

    // Increment the number of items
    num_items++;

    printf("Do you want to add another item (Y/N)? ");
    scanf(" %c", &choice);
    i++;
  } while (choice == 'y' || choice == 'Y');

  printf("\nTotal amount of the items purchased: %.2f\n", total_amount);

  // Determine the discount based on the total amount
  if (total_amount >= 1000) {
    discount = 0.1 * total_amount;
  } else if (total_amount >= 500) {
    discount = 0.05 * total_amount;
  }

  printf("Discount applied: %.2f\n", discount);

  // Calculate the net amount
  net_amount = total_amount - discount;

  printf("Net amount: %.2f\n", net_amount);

  // Calculate the service tax
  service_tax = 0.14 * net_amount;

  printf("Service tax (14%% of net amount): %.2f\n", service_tax);

  // Calculate the VAT
  vat = 0.05 * net_amount;

  printf("VAT (5%% of net amount): %.2f\n", vat);

  // Calculate the grand total
  grand_total = net_amount + service_tax + vat;

  printf("Grand total: %.2f\n", grand_total);

  printf("\nThank you for dining with us. Please come again!\n");

  return 0;
}