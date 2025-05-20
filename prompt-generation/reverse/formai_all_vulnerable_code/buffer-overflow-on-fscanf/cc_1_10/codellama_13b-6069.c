//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
// C Data Mining Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Data structure to store information about a customer
typedef struct {
  char name[100];
  int age;
  char gender;
  char occupation[100];
  double income;
} Customer;

// Function to read data from a file and store it in an array of Customer structs
int read_data(Customer *customers, int n) {
  FILE *fp = fopen("data.txt", "r");
  if (!fp) {
    printf("Error: unable to open file\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    fscanf(fp, "%s %d %c %s %lf", customers[i].name, &customers[i].age, &customers[i].gender, customers[i].occupation, &customers[i].income);
  }

  fclose(fp);
  return 0;
}

// Function to print data from an array of Customer structs
void print_data(Customer *customers, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s %d %c %s %lf\n", customers[i].name, customers[i].age, customers[i].gender, customers[i].occupation, customers[i].income);
  }
}

// Function to calculate the average income of a group of customers
double average_income(Customer *customers, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += customers[i].income;
  }
  return sum / n;
}

// Function to calculate the standard deviation of a group of customers
double std_deviation(Customer *customers, int n) {
  double average = average_income(customers, n);
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pow(customers[i].income - average, 2);
  }
  return sqrt(sum / n);
}

// Function to group customers based on their income
int group_customers(Customer *customers, int n, double income_threshold) {
  int group_1 = 0;
  int group_2 = 0;
  for (int i = 0; i < n; i++) {
    if (customers[i].income <= income_threshold) {
      group_1++;
    } else {
      group_2++;
    }
  }
  return group_1;
}

int main() {
  Customer customers[100];
  int n = read_data(customers, 100);
  print_data(customers, n);
  double average = average_income(customers, n);
  printf("Average income: %lf\n", average);
  double std_dev = std_deviation(customers, n);
  printf("Standard deviation: %lf\n", std_dev);
  int group_1 = group_customers(customers, n, average);
  int group_2 = n - group_1;
  printf("Group 1: %d\n", group_1);
  printf("Group 2: %d\n", group_2);
  return 0;
}