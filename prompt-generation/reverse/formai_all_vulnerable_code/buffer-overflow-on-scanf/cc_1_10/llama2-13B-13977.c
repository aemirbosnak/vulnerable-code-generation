//LLAMA2-13B DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Function to generate a random name
void generate_name(char *name) {
  srand(time(NULL));
  int i, j;
  for (i = 0; i < MAX_NAME_LENGTH; i++) {
    j = rand() % 26 + 1; // Generate a random letter between A and Z
    name[i] = j + 'A'; // Convert letter to uppercase
  }
  name[MAX_NAME_LENGTH] = '\0';
}

// Function to generate a random age
int generate_age() {
  return rand() % MAX_AGE + 1;
}

int main() {
  // Declare variables
  char name[MAX_NAME_LENGTH];
  int age;

  // Generate a random name and age
  generate_name(name);
  age = generate_age();

  // Print the name and age
  printf("Hello, my name is %s and I am %d years old.\n", name, age);

  // Ask the user for their name and age
  printf("What is your name? ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  printf("How old are you? ");
  scanf("%d", &age);

  // Compare the user's name and age to the generated name and age
  if (strcmp(name, "Alice") == 0 && age == 25) {
    printf("Ah, a fine choice! You are Alice, 25 years young.\n");
  } else if (strcmp(name, "Bob") == 0 && age == 30) {
    printf("Ah, a classic choice! You are Bob, 30 years wise.\n");
  } else {
    printf("Hmm, that's an interesting name and age combination. What brings you here today?\n");
  }

  return 0;
}