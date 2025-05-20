//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A unique C Mailing list manager example program in a Sherlock Holmes style

// The main function
int main() {
  // Declare the variables
  char *name, *email;
  int choice;

  // Create the mailing list
  printf("Welcome to the Mailing List Manager, dear Watson.\n");
  printf("Enter the name of the mailing list: ");
  name = (char *)malloc(sizeof(char) * 100);
  scanf("%s", name);

  //Get the sender data
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your email: ");
  scanf("%s", email);
  
  // Open the mailing list file
  FILE *fp = fopen(name, "w");
  if (fp == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }
  
  // Write the sender data to the file
  fprintf(fp, "%s,%s\n", name, email);
 
  //Get the reciver data
  printf("Enter the recipient's name: ");
  scanf("%s", name);
  printf("Enter the recipient's email: ");
  scanf("%s", email);
  
  // Write the reciever data to the file
  fprintf(fp, "%s,%s\n", name, email);
  
  // Close the mailing list file
  fclose(fp);

  // Display the menu
  while (1) {
    printf("\n1. Add a subscriber\n");
    printf("2. Remove a subscriber\n");
    printf("3. Send a message\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the selected action
    switch (choice) {
      case 1:
        // Add a subscriber
        printf("Enter the name of the subscriber: ");
        name = (char *)malloc(sizeof(char) * 100);
        scanf("%s", name);
        printf("Enter the email of the subscriber: ");
        email = (char *)malloc(sizeof(char) * 100);
        scanf("%s", email);
        fp = fopen(name, "a");
        if (fp == NULL) {
          printf("Error opening the file.\n");
          return 1;
        }
        fprintf(fp, "%s,%s\n", name, email);
        fclose(fp);
        break;
      case 2:
        // Remove a subscriber
        printf("Enter the name of the subscriber: ");
        name = (char *)malloc(sizeof(char) * 100);
        scanf("%s", name);
        fp = fopen(name, "r");
        if (fp == NULL) {
          printf("Error opening the file.\n");
          return 1;
        }
        FILE *fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL) {
          printf("Error opening the file.\n");
          return 1;
        }
        while (!feof(fp)) {
          fscanf(fp, "%s,%s\n", name, email);
          if (strcmp(name, name) != 0) {
            fprintf(fp2, "%s,%s\n", name, email);
          }
        }
        fclose(fp);
        fclose(fp2);
        remove(name);
        rename("temp.txt", name);
        break;
      case 3:
        // Send a message
        printf("Enter the message: ");
        char *message = (char *)malloc(sizeof(char) * 100);
        scanf("%s", message);
        fp = fopen(name, "r");
        if (fp == NULL) {
          printf("Error opening the file.\n");
          return 1;
        }
        while (!feof(fp)) {
          fscanf(fp, "%s,%s\n", name, email);
          //Send the email
          printf("Sending email to %s (%s)...\n", name, email);
        }
        fclose(fp);
        break;
      case 4:
        // Quit
        return 0;
    }
  }

  return 0;
}