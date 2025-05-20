//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char login[50], password[50], to[50], subject[200], message[2000];
  int choice, i, mails_count = 0;

  // Login
  printf("Enter your login: ");
  scanf("%s", login);
  printf("Enter your password: ");
  scanf("%s", password);
  printf("Welcome, %s!\n\n", login);

  // Display menu
  while (1) {
    printf("**********************************\n");
    printf("************* MENU **************\n");
    printf("**********************************\n");
    printf("1. Compose email\n");
    printf("2. Check inbox\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
      // Compose email
      printf("To: ");
      scanf("%s", to);
      printf("\nSubject: ");
      scanf("%s", subject);
      printf("\nMessage: ");
      scanf("%s", message);

      // Send email
      printf("\nSending email...");
      printf("\nEmail sent!\n\n");
    }
    else if (choice == 2) {
      // Check inbox
      printf("Checking inbox...\n");

      // Generate fake emails
      char* senders[] = {"John", "Sarah", "Tom", "Sam", "Lisa"};
      char* subjects[] = {
        "Urgent: Bring Food Supplies",
        "Report on Water Contaminant Levels",
        "Re: Emergency Broadcast",
        "Missing Persons Alert",
        "Re: Shelter Security Measures"
      };
      char* messages[] = {
        "We are starving and need immediate assistance.",
        "The water is contaminated and needs to be addressed.",
        "Stay put and wait for further instructions.",
        "Please keep an eye out for these individuals.",
        "The security measures are insufficient, we need to fortify our defenses."
      };

      // Display emails
      mails_count = rand() % 10 + 1;
      for (i = 0; i < mails_count; i++) {
        printf("From: %s\n", senders[rand() % 5]);
        printf("Subject: %s\n", subjects[rand() % 5]);
        printf("Message: %s\n\n", messages[rand() % 5]);
      }
    }
    else if (choice == 3) {
      // Exit
      printf("Exiting...\n\n");
      break;
    }
    else {
      // Invalid choice
      printf("Invalid choice. Try again...\n\n");
    }
  }

  return 0;
}