//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the main function
int main() {
  // Declare the variables
  char email[100], password[100], message[1000];
  int choice;

  // Display a welcome message
  printf("Welcome to the Email Client 1.0!\n");

  // Prompt the user to enter their email address
  printf("Enter your email address: ");
  scanf("%s", email);

  // Prompt the user to enter their password
  printf("Enter your password: ");
  scanf("%s", password);

  // Verify the user's credentials
  if (strcmp(email, "test@example.com") == 0 && strcmp(password, "password") == 0) {
    // Display a success message
    printf("Login successful!\n");

    // Display the menu
    printf("1. Compose a new email\n");
    printf("2. Read an email\n");
    printf("3. Delete an email\n");
    printf("4. Exit\n");

    // Prompt the user to enter their choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice) {
      case 1:
        // Compose a new email
        printf("Enter the recipient's email address: ");
        scanf("%s", message);

        printf("Enter the subject of the email: ");
        scanf("%s", message);

        printf("Enter the body of the email: ");
        scanf("%s", message);

        // Send the email
        printf("Email sent successfully!\n");
        break;
      case 2:
        // Read an email
        printf("Enter the ID of the email you want to read: ");
        scanf("%d", &choice);

        // Display the email
        printf("Email:\n");
        printf("From: %s\n", message);
        printf("To: %s\n", message);
        printf("Subject: %s\n", message);
        printf("Body: %s\n", message);
        break;
      case 3:
        // Delete an email
        printf("Enter the ID of the email you want to delete: ");
        scanf("%d", &choice);

        // Delete the email
        printf("Email deleted successfully!\n");
        break;
      case 4:
        // Exit the program
        printf("Thank you for using the Email Client 1.0!\n");
        exit(0);
        break;
      default:
        // Display an error message
        printf("Invalid choice!\n");
        break;
    }
  } else {
    // Display an error message
    printf("Login failed!\n");
  }

  return 0;
}