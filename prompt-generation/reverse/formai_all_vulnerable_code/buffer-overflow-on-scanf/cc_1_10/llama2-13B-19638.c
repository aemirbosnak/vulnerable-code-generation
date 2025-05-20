//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Global variables
int num_people = 0;
char names[10][MAX_NAME_LEN];
int ages[10];

// Function to read names and ages from the user
void get_data() {
  int i;
  for (i = 0; i < 10; i++) {
    printf("Enter name: ");
    scanf("%19s", names[i]);
    printf("Enter age: ");
    scanf("%d", &ages[i]);
  }
}

// Function to display the data
void display_data() {
  int i;
  for (i = 0; i < 10; i++) {
    printf("%d. %s is %d years old\n", i + 1, names[i], ages[i]);
  }
}

// Main program
int main() {
  srand(time(NULL)); // initialize the random number generator

  // Call the function to read the data
  get_data();

  // Display the data
  display_data();

  // Add some randomness to the ages
  for (int i = 0; i < 10; i++) {
    ages[i] = rand() % 100 + 1; // add a random value between 1 and 100 to each age
  }

  // Display the data again
  display_data();

  return 0;
}