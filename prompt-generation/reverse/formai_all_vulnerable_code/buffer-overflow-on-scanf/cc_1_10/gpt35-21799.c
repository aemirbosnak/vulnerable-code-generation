//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100 //Maximum size of message

int main() {
  char recipient[20]; //Stores recipient email address
  char subject[50]; //Stores email subject
  char message[MAX_SIZE]; //Stores email message
  char goBack[5]; //Stores choice to go back or exit
  int choice; //Stores choice of operation
  
  printf("\nWelcome to C Email Client!\n");
  
  do {
    printf("\nSelect an operation: \n");
    printf("1. Compose Email\n");
    printf("2. Exit\n");
    printf(">> ");
    
    scanf("%d", &choice); //Stores user choice
    
    switch(choice) {
      case 1:
        printf("Enter recipient email address: ");
        scanf("%s", recipient);
        printf("\nEnter email subject: ");
        scanf(" %[^\n]", subject); //Accepts spaces in the subject
        printf("\nEnter email message: ");
        scanf(" %[^\n]", message); //Accepts spaces in the message
        
        //Code to send email goes here
        printf("\nEmail sent to %s with subject '%s' and message '%s'!\n", recipient, subject, message);
        break;
          
      case 2:
        printf("\nThank you for using C Email Client!\n"); 
        return 0;
        
      default:
        printf("\nInvalid option chosen. Please try again.\n");
        break;
    }
    
    printf("\nWould you like to go back to the main menu or exit?\n");
    printf("Enter 'back' to go back or 'exit' to exit.\n");
    printf(">> ");
    
    scanf("%s", goBack); //Stores user choice
    
  } while(strcmp(goBack, "back") == 0); //Loop continues until user chooses to exit
  
  printf("\nThank you for using C Email Client!\n"); 
  return 0;
}