//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define a customer structure
typedef struct {
  int id;
  char *name;
  int age;
  char *gender;
  char *occupation;
  double income;
  char *marital_status;
  char *education_level;
} customer;

// Define a function to read customer data from a file
void read_customer_data(customer *customers, int num_customers, char *filename) {
  FILE *fp;
  int i;

  // Open the file for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the customer data from the file
  for (i = 0; i < num_customers; i++) {
    fscanf(fp, "%d %s %d %s %s %lf %s %s", &customers[i].id, customers[i].name, &customers[i].age, customers[i].gender, customers[i].occupation, &customers[i].income, customers[i].marital_status, customers[i].education_level);
  }

  // Close the file
  fclose(fp);
}

// Define a function to print customer data
void print_customer_data(customer *customers, int num_customers) {
  int i;

  // Print the customer data
  for (i = 0; i < num_customers; i++) {
    printf("%d %s %d %s %s %lf %s %s\n", customers[i].id, customers[i].name, customers[i].age, customers[i].gender, customers[i].occupation, customers[i].income, customers[i].marital_status, customers[i].education_level);
  }
}

// Define a function to find the most frequent occupation
char *find_most_frequent_occupation(customer *customers, int num_customers) {
  int i, j;
  int max_count = 0;
  char *most_frequent_occupation = NULL;

  // Create a hash table to store the occupations and their counts
  char *occupations[num_customers];
  int counts[num_customers];
  for (i = 0; i < num_customers; i++) {
    occupations[i] = customers[i].occupation;
    counts[i] = 0;
  }

  // Count the occurrences of each occupation
  for (i = 0; i < num_customers; i++) {
    for (j = 0; j < num_customers; j++) {
      if (strcmp(occupations[i], occupations[j]) == 0) {
        counts[i]++;
      }
    }
  }

  // Find the occupation with the maximum count
  for (i = 0; i < num_customers; i++) {
    if (counts[i] > max_count) {
      max_count = counts[i];
      most_frequent_occupation = occupations[i];
    }
  }

  // Return the most frequent occupation
  return most_frequent_occupation;
}

int main() {
  int num_customers = 1000;
  customer customers[num_customers];

  // Read the customer data from the file
  read_customer_data(customers, num_customers, "customers.txt");

  // Print the customer data
  print_customer_data(customers, num_customers);

  // Find the most frequent occupation
  char *most_frequent_occupation = find_most_frequent_occupation(customers, num_customers);

  // Print the most frequent occupation
  printf("The most frequent occupation is %s\n", most_frequent_occupation);

  return 0;
}