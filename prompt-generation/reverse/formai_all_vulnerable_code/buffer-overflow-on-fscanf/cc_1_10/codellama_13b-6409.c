//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: surprised
// Unique C Data Mining Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing information about a customer
struct customer {
  int id;
  char name[50];
  char address[100];
  int age;
  char gender[10];
  float income;
};

// Function for reading data from a file
void read_data(struct customer *customers, int num_customers, char *file_name) {
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for (int i = 0; i < num_customers; i++) {
    fscanf(fp, "%d %s %s %d %s %f", &customers[i].id, customers[i].name, customers[i].address, &customers[i].age, customers[i].gender, &customers[i].income);
  }

  fclose(fp);
}

// Function for clustering customers based on their income
void cluster_customers(struct customer *customers, int num_customers, int num_clusters) {
  // Initialize an array to store the cluster assignments for each customer
  int *cluster_assignments = malloc(num_customers * sizeof(int));

  // Loop through each customer and assign them to a cluster based on their income
  for (int i = 0; i < num_customers; i++) {
    // Calculate the income range for each cluster
    float min_income = (i * (num_customers / num_clusters)) * (customers[i].income / num_customers);
    float max_income = ((i + 1) * (num_customers / num_clusters)) * (customers[i].income / num_customers);

    // Assign the customer to the cluster with the closest income range
    if (customers[i].income >= min_income && customers[i].income <= max_income) {
      cluster_assignments[i] = i;
    } else {
      cluster_assignments[i] = (i + 1) % num_clusters;
    }
  }

  // Print the cluster assignments for each customer
  for (int i = 0; i < num_customers; i++) {
    printf("Customer %d: Cluster %d\n", customers[i].id, cluster_assignments[i]);
  }

  free(cluster_assignments);
}

int main() {
  // Declare an array to store the customer information
  struct customer customers[100];

  // Read data from a file
  read_data(customers, 100, "customers.txt");

  // Cluster customers based on their income
  cluster_customers(customers, 100, 3);

  return 0;
}