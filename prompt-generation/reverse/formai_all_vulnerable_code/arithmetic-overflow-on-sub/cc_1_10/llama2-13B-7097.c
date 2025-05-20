//LLAMA2-13B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to generate a random name
void generate_name() {
  char name[MAX_NAME_LENGTH];
  int i;

  for (i = 0; i < MAX_NAME_LENGTH; i++) {
    name[i] = 'a' + (rand() % 26);
  }

  printf("Your name is: %s\n", name);
}

// Function to calculate and print the age
void calculate_age() {
  int today = time(NULL);
  int birth_date;

  printf("Your age is: ");

  // Check if the user's birth date is before 1900
  if (getdate(&birth_date, "birthdate", "1900-01-01") == -1) {
    printf("I'm not sure how to calculate your age...\n");
    return;
  }

  // Calculate the age
  int age = today - birth_date;

  // Print the age
  if (age < 0) {
    printf("You are not yet born...\n");
  } else {
    printf("%d years old\n", age);
  }
}

int main() {
  generate_name();
  calculate_age();

  return 0;
}