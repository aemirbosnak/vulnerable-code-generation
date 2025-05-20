//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define SMTP_PORT 25

int main() {
  // Greeting
  printf("Greetings, intrepid email adventurer! Prepare to embark on a voyage through the vast digital seas of email.\n\n");

  // Get the sender's address
  char sender[100];
  printf("From whence do your words take flight, fair voyager? Enter your email address: ");
  scanf("%s", sender);

  // Get the recipient's address
  char recipient[100];
  printf("Unto whom shall your missive soar? Enter the recipient's email address: ");
  scanf("%s", recipient);

  // Get the subject line
  char subject[100];
  printf("Craft a subject line that captures the essence of your message: ");
  scanf(" %[^\n]%*c", subject);

  // Get the message body
  char body[1000];
  printf("Compose your message, pouring your words into this digital parchment: ");
  scanf(" %[^\n]%*c", body);

  // Connect to the SMTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Alas, our vessel could not set sail! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
    printf("Our connection attempt foundered! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the HELO command
  char helo[] = "HELO localhost\r\n";
  if (send(sock, helo, strlen(helo), 0) == -1) {
    printf("Our initial greeting was lost at sea! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command
  char mail_from[200];
  sprintf(mail_from, "MAIL FROM: <%s>\r\n", sender);
  if (send(sock, mail_from, strlen(mail_from), 0) == -1) {
    printf("Our attempt to declare our origins failed! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command
  char rcpt_to[200];
  sprintf(rcpt_to, "RCPT TO: <%s>\r\n", recipient);
  if (send(sock, rcpt_to, strlen(rcpt_to), 0) == -1) {
    printf("Our efforts to designate the recipient were met with resistance! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the DATA command
  char data[] = "DATA\r\n";
  if (send(sock, data, strlen(data), 0) == -1) {
    printf("Our request to begin transmitting the message was lost in the ether! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the subject line
  char subject_line[200];
  sprintf(subject_line, "Subject: %s\r\n", subject);
  if (send(sock, subject_line, strlen(subject_line), 0) == -1) {
    printf("Our subject line was swallowed by the unforgiving network! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the message body
  strcat(body, "\r\n.\r\n");
  if (send(sock, body, strlen(body), 0) == -1) {
    printf("Our message met a watery grave before reaching its destination! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  char quit[] = "QUIT\r\n";
  if (send(sock, quit, strlen(quit), 0) == -1) {
    printf("Our attempt to bid farewell was thwarted! Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Close the connection
  close(sock);

  // Farewell
  printf("\nYour message has embarked on its epic journey. May it reach its destination and bring joy to its recipient!\n\n");
  printf("Fare thee well, intrepid email adventurer. May your future voyages be filled with success and inspiration.\n");

  return EXIT_SUCCESS;
}