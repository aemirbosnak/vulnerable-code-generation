//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Declare global variables
int num_people = 0;
char *names[10];
int ages[10];

// Define a function to read names and ages from the user
void read_data() {
  int i;

  for (i = 0; i < 10; i++) {
    printf("Enter a name: ");
    scanf("%19s", names[i]);
    printf("Enter an age: ");
    scanf("%d", &ages[i]);
  }
}

// Define a function to print the data
void print_data() {
  int i;

  for (i = 0; i < 10; i++) {
    printf("%d. %s is %d years old.\n", i + 1, names[i], ages[i]);
  }
}

// Define a function to calculate the average age
double calculate_average() {
  int i;
  double sum = 0;

  for (i = 0; i < 10; i++) {
    sum += ages[i];
  }

  return sum / 10;
}

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Call the function to read the data
  read_data();

  // Print the data
  print_data();

  // Calculate the average age
  double average = calculate_average();
  printf("The average age is: %f\n", average);

  return 0;
}