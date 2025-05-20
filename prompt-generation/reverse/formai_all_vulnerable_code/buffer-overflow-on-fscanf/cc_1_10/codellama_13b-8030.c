//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: curious
// C Data Mining Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a data point
typedef struct {
  int id;
  char name[100];
  char email[100];
  int age;
  char gender;
} DataPoint;

// Function to read data from a file
void read_data(DataPoint *data, int n) {
  FILE *file = fopen("data.txt", "r");
  for (int i = 0; i < n; i++) {
    fscanf(file, "%d %s %s %d %c", &data[i].id, data[i].name, data[i].email, &data[i].age, &data[i].gender);
  }
  fclose(file);
}

// Function to print data
void print_data(DataPoint *data, int n) {
  for (int i = 0; i < n; i++) {
    printf("ID: %d\nName: %s\nEmail: %s\nAge: %d\nGender: %c\n\n", data[i].id, data[i].name, data[i].email, data[i].age, data[i].gender);
  }
}

// Function to perform data mining
void data_mining(DataPoint *data, int n) {
  // Calculate average age
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += data[i].age;
  }
  int avg = sum / n;
  printf("Average age: %d\n", avg);

  // Calculate average age by gender
  int male_sum = 0;
  int female_sum = 0;
  for (int i = 0; i < n; i++) {
    if (data[i].gender == 'M') {
      male_sum += data[i].age;
    } else {
      female_sum += data[i].age;
    }
  }
  int male_avg = male_sum / n;
  int female_avg = female_sum / n;
  printf("Male average age: %d\nFemale average age: %d\n", male_avg, female_avg);

  // Find oldest and youngest person
  int oldest_id = 0;
  int youngest_id = 0;
  int oldest_age = 0;
  int youngest_age = 100;
  for (int i = 0; i < n; i++) {
    if (data[i].age > oldest_age) {
      oldest_id = data[i].id;
      oldest_age = data[i].age;
    }
    if (data[i].age < youngest_age) {
      youngest_id = data[i].id;
      youngest_age = data[i].age;
    }
  }
  printf("Oldest person: %d (%d years old)\nYoungest person: %d (%d years old)\n", oldest_id, oldest_age, youngest_id, youngest_age);
}

int main() {
  // Read data from file
  DataPoint data[100];
  int n = 100;
  read_data(data, n);

  // Print data
  print_data(data, n);

  // Perform data mining
  data_mining(data, n);

  return 0;
}