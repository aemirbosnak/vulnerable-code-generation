//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
  int age;
  char name[MAX_NAME_LENGTH];

  // Ask for the user's name and age
  printf("What is your name? ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  printf("How old are you? ");
  scanf("%d", &age);

  // Check if the user's name is too long
  if (strlen(name) > MAX_NAME_LENGTH) {
    printf("Error: Name too long! 😱\n");
    return 1;
  }

  // Check if the user's age is valid
  if (age < 0 || age > MAX_AGE) {
    printf("Error: Age must be between 0 and %d! 😱\n", MAX_AGE);
    return 1;
  }

  // Create a ninja object
  struct ninja {
    char name[MAX_NAME_LENGTH];
    int age;
  } myNinja;

  // Assign the user's name and age to the ninja object
  strcpy(myNinja.name, name);
  myNinja.age = age;

  // Print the ninja's name and age
  printf("Your name is %s, and you are %d years old! 😎\n", myNinja.name, myNinja.age);

  // Create an array of ninjas
  struct ninja ninjas[5];

  // Add the user's ninja to the array
  ninjas[0] = myNinja;

  // Print the array of ninjas
  printf("Here are the ninjas:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d: %s, %d years old\n", i, ninjas[i].name, ninjas[i].age);
  }

  return 0;
}