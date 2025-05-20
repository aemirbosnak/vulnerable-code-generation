//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>

// Define constants for the number of customers and products
#define NUM_CUSTOMERS 1000
#define NUM_PRODUCTS 50

// Define an array to hold the purchase data
int purchases[NUM_CUSTOMERS][NUM_PRODUCTS];

int main() {
  // Read in the purchase data from a file
  FILE *fp;
  fp = fopen("purchase_data.txt", "r");
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    for (int j = 0; j < NUM_PRODUCTS; j++) {
      fscanf(fp, "%d", &purchases[i][j]);
    }
  }

  // Calculate the average number of products purchased per customer
  float avg_products = 0;
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    int total_products = 0;
    for (int j = 0; j < NUM_PRODUCTS; j++) {
      total_products += purchases[i][j];
    }
    avg_products += ((float)total_products)/NUM_CUSTOMERS;
  }
  printf("Average number of products per customer: %f\n", avg_products);

  // Identify the top 5 best-selling products
  int best_selling[NUM_PRODUCTS];
  for (int i = 0; i < NUM_PRODUCTS; i++) {
    int total_sales = 0;
    for (int j = 0; j < NUM_CUSTOMERS; j++) {
      total_sales += purchases[j][i];
    }
    best_selling[i] = total_sales;
  }
  for (int i = 0; i < 5; i++) {
    int max_index = 0;
    int max_value = best_selling[0];
    for (int j = 1; j < NUM_PRODUCTS; j++) {
      if (best_selling[j] > max_value) {
        max_index = j;
        max_value = best_selling[j];
      }
    }
    printf("Best-selling product #%d: %d\n", i+1, max_index);
    best_selling[max_index] = 0;
  }

  // Identify customers who make frequent purchases
  int frequent_customers[NUM_CUSTOMERS];
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    int num_purchases = 0;
    for (int j = 0; j < NUM_PRODUCTS; j++) {
      if (purchases[i][j] > 0) {
        num_purchases++;
      }
    }
    if (num_purchases > 40) {
      frequent_customers[i] = 1;
    } else {
      frequent_customers[i] = 0;
    }
  }
  int num_frequent_customers = 0;
  for (int i = 0; i < NUM_CUSTOMERS; i++) {
    if (frequent_customers[i]) {
      num_frequent_customers++;
    }
  }
  printf("Number of frequent customers: %d\n", num_frequent_customers);

  return 0;
}