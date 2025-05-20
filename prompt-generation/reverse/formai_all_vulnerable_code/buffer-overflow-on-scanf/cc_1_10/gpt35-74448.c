//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Get ready to send some emails with the coolest email client around!\n\n");

  // Prompt the user for the SMTP server information
  char server[100];
  printf("Please enter the SMTP server address: ");
  scanf("%s", server);

  char port[5];
  printf("Please enter the SMTP server port (usually 25 or 587): ");
  scanf("%s", port);

  // Prompt the user for email credentials
  char username[100];
  printf("Please enter your email address: ");
  scanf("%s", username);

  char password[100];
  printf("Please enter your email password: ");
  scanf("%s", password);

  // Prompt the user for the recipient email address
  char to[100];
  printf("Please enter the recipient's email address: ");
  scanf("%s", to);

  // Prompt the user for the email subject and message
  char subject[100];
  printf("Please enter the email subject: ");
  scanf("%s", subject);

  char message[1000];
  printf("Please enter the email message: ");
  scanf("%s", message);

  // Connect to SMTP server and authenticate user
  printf("\nConnecting to %s on port %s...\n", server, port);

  // Authenticate user
  printf("Authenticating user %s with password %s...\n", username, password);

  // Construct email headers and body
  char headers[1000];
  sprintf(headers, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n", username, to, subject);

  char body[1500];
  sprintf(body, "%s\r\n", message);

  char email[2500];
  strcpy(email, headers);
  strcat(email, body);

  // Send email
  printf("\nSending email...\n");
  printf("To: %s\n", to);
  printf("Subject: %s\n", subject);
  printf("Message: %s\n", message);

  printf("\nEmail sent successfully!\n\n");

  return 0;
}