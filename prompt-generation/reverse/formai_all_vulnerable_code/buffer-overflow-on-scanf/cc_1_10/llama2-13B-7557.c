//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Declare a structure to store user information
struct user {
  char name[MAX_NAME_LENGTH];
  int age;
};

// Declare an array to store multiple users
struct user users[5];

// Function to read user information from the console
void read_user_info() {
  int i;
  for (i = 0; i < 5; i++) {
    printf("Enter name: ");
    fgets(users[i].name, MAX_NAME_LENGTH, stdin);
    printf("Enter age: ");
    scanf("%d", &users[i].age);
  }
}

// Function to print a message and a list of users
void print_message() {
  printf("Relax, folks! It's time to take a break.\n");
  printf("Here are the users currently taking a break:\n");
  for (int i = 0; i < 5; i++) {
    printf("  - %s (%d years old)\n", users[i].name, users[i].age);
  }
}

int main() {
  // Initialize the array with some default values
  for (int i = 0; i < 5; i++) {
    users[i].name[0] = '\0';
    users[i].age = 0;
  }

  // Read user information from the console
  read_user_info();

  // Print a message and the list of users
  print_message();

  return 0;
}