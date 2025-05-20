//Gemma-7B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_Recipients 10

typedef struct Message {
  char sender[50];
  char recipients[MAX_Recipients][50];
  char subject[50];
  char message[2000];
} Message;

Message messages[100];

int main() {
  int i = 0;
  int numMessages = 0;
  char input[200];

  // Create a new message
  Message newMessage;
  memset(&newMessage, 0, sizeof(newMessage));

  // Get the sender's name
  printf("Enter your name: ");
  scanf("%s", newMessage.sender);

  // Get the recipients' names
  printf("Enter the recipients' names, separated by commas: ");
  scanf("%s", newMessage.recipients);

  // Get the subject
  printf("Enter the subject: ");
  scanf("%s", newMessage.subject);

  // Get the message
  printf("Enter your message: ");
  scanf("%s", newMessage.message);

  // Add the message to the list
  messages[numMessages++] = newMessage;

  // Display the list of messages
  for (i = 0; i < numMessages; i++) {
    printf("From: %s\n", messages[i].sender);
    printf("To: ", messages[i].recipients);
    for (int j = 0; j < MAX_Recipients && messages[i].recipients[j][0] != '\0'; j++) {
      printf("%s, ", messages[i].recipients[j]);
    }
    printf("\nSubject: %s\n", messages[i].subject);
    printf("Message: %s\n", messages[i].message);
    printf("\n");
  }

  return 0;
}