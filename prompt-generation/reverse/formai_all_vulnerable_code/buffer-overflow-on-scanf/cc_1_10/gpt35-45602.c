//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 100
//define the email structure
struct Email {
  char sender[MAX_SIZE];
  char receiver[MAX_SIZE];
  char subject[MAX_SIZE];
  char body[MAX_SIZE];
};

int main() {
  //declare variables
  int fd, choice, i, n = 0;
  char email[MAX_SIZE], buffer[MAX_SIZE], filename[MAX_SIZE];
  struct Email emails[MAX_SIZE];

  //create email folder if it doesn't exist
  system("mkdir -p email_folder");

  //display menu
  do {
    printf("\nWelcome to the C Email Client\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      //send email
      case 1:
        printf("\nEnter sender email address: ");
        scanf("%s", emails[n].sender);
        printf("Enter receiver email address: ");
        scanf("%s", emails[n].receiver);
        printf("Enter subject: ");
        scanf("%s", emails[n].subject);
        printf("Enter body: ");
        scanf("%s", emails[n].body);

        //generate email filename based on current time
        sprintf(filename, "email_folder/%d.txt", time(NULL));

        //write email to file
        fd = open(filename, O_CREAT | O_WRONLY, 0600);
        sprintf(buffer, "Sender: %s\nReceiver: %s\nSubject: %s\n\n%s", emails[n].sender, emails[n].receiver, emails[n].subject, emails[n].body);
        write(fd, buffer, strlen(buffer));
        close(fd);

        printf("\nEmail sent successfully!\n");
        n++;
        break;

      //view inbox
      case 2:
        printf("\nInbox\n");
        printf("--------------------------------------------------\n");

        //read all emails in email folder
        system("ls email_folder/ > email_folder/files.txt");
        fd = open("email_folder/files.txt", O_RDONLY);
        read(fd, buffer, MAX_SIZE);
        close(fd);

        //parse email filenames and display email details
        char *token = strtok(buffer, "\n");
        while(token != NULL) {
          strcpy(email, "email_folder/");
          strcat(email, token);
          fd = open(email, O_RDONLY);
          read(fd, buffer, MAX_SIZE);
          close(fd);

          printf("\nEmail %d\n", i+1);
          printf("--------------------------------------------------\n");
          printf("%s\n", buffer);

          token = strtok(NULL, "\n");
          i++;
        }

        //delete files.txt
        system("rm -f email_folder/files.txt");

        break;

      //exit
      case 3:
        printf("\nExiting C Email Client. Goodbye!\n");
        break;

      //invalid input
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 3);

  return 0;
}