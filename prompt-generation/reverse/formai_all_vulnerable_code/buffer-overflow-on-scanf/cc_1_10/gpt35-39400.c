//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of subscribers
#define MAX_SUBSCRIBERS 1000

// Define maximum length of subscriber name and email
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Define struct to hold subscriber data
typedef struct Subscriber {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Declare global variables
Subscriber subscribers[MAX_SUBSCRIBERS];
int numSubscribers = 0;

// Function to add a new subscriber
void addSubscriber() {
  if (numSubscribers >= MAX_SUBSCRIBERS) {
    printf("Max subscribers reached. Cannot add new subscriber.\n");
    return;
  }

  printf("Enter subscriber name: ");
  scanf(" %[^\n]s", subscribers[numSubscribers].name);

  printf("Enter subscriber email: ");
  scanf(" %[^\n]s", subscribers[numSubscribers].email);

  printf("Subscriber added successfully.\n");

  numSubscribers++;
}

// Function to remove a subscriber
void removeSubscriber() {
  if (numSubscribers == 0) {
    printf("No subscribers to remove.\n");
    return;
  }

  char email[MAX_EMAIL_LENGTH];
  printf("Enter subscriber email to remove: ");
  scanf(" %[^\n]s", email);

  int foundIndex = -1;
  for (int i = 0; i < numSubscribers; i++) {
    if (strcmp(subscribers[i].email, email) == 0) {
      foundIndex = i;
      break;
    }
  }

  if (foundIndex == -1) {
    printf("Subscriber not found.\n");
    return;
  }

  for (int i = foundIndex; i < numSubscribers - 1; i++) {
    subscribers[i] = subscribers[i + 1];
  }

  printf("Subscriber removed successfully.\n");

  numSubscribers--;
}

// Function to print all subscribers
void printSubscribers() {
  for (int i = 0; i < numSubscribers; i++) {
    printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
  }
}

int main() {
  char password[20];

  printf("Please enter password: ");
  scanf("%s", password);

  if (strcmp(password, "mypassword") != 0) {
    printf("Incorrect password. Terminating program.\n");
    return 1;
  }

  printf("Welcome to the paranoid mailing list manager.\n");

  int choice = 0;
  while (choice != 4) {
    printf("\n1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Print subscribers\n");
    printf("4. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addSubscriber();
        break;

      case 2:
        removeSubscriber();
        break;

      case 3:
        printSubscribers();
        break;

      case 4:
        printf("Exiting program.\n");
        return 0;

      default:
        printf("Invalid input. Please try again.\n");
    }
  }

  return 0;
}