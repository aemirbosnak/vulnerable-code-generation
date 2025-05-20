//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("\nWelcome to the FunC Email Client!\n");
  printf("\nBe prepared for a wild ride!\n");
  int choice, valid_choice = 0;
  while (!valid_choice) {
    printf("\nWhat do you want to do?\n");
    printf("1. Compose an email\n");
    printf("2. Read your inbox\n");
    printf("3. Delete all emails (yikes!)\n");
    printf("4. Send an email to your worst enemy\n");
    printf("5. Quit the FunC Email Client\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("\nLet's compose an email. Who do you want to send it to?\n");
        char to[50];
        scanf("%s", to);
        printf("\nWhat is the subject of your email?\n");
        char subject[100];
        scanf("%s", subject);
        printf("\nWhat is the message you want to send?\n");
        char message[500];
        scanf("%s", message);
        printf("\nYour email has been composed and sent to %s\n", to);
        break;
      case 2:
        printf("\nThis is your inbox (just kidding)! There are no emails in the FunC Email Client... yet!\n");
        break;
      case 3:
        printf("\nAre you sure you want to delete all emails? (Please enter 'yes' if you're crazy enough to do this.)\n");
        char answer[5];
        scanf("%s", answer);
        if (strcmp(answer, "yes") == 0) {
          printf("\nAll emails have been deleted! I hope you didn't need any important information...\n");
        } else {
          printf("\nPhew, that was a close one! Your emails are safe... for now.\n");
        }
        break;
      case 4:
        printf("\nOh no, you're sending an email to your worst enemy?! This can't end well...\n");
        printf("What is their email address?\n");
        char enemy_email[50];
        scanf("%s", enemy_email);
        printf("What is the subject of your email?\n");
        char enemy_subject[100];
        scanf("%s", enemy_subject);
        printf("What message would you like to send to your worst enemy?\n");
        char enemy_message[500];
        scanf("%s", enemy_message);
        printf("\nYour email to your worst enemy has been sent and their reaction is... let's just say it's not good.\n");
        break;
      case 5:
        printf("\nGoodbye! Thanks for using the FunC Email Client! Remember to never send emails to your enemies... or maybe do, it's your call!\n");
        valid_choice = 1;
        break;
      default:
        printf("\nPlease enter a valid choice (1-5).\n");
        break;
    }
  }
  return 0;
}