#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1024

int main() {
  char email[MAX_EMAIL_LENGTH];
  int email_length = 0;
  char sender[MAX_EMAIL_LENGTH];
  char subject[MAX_EMAIL_LENGTH];

  printf("Enter sender's email:");
  scanf("%s", sender);

  printf("Enter subject:");
  scanf("%s", subject);

  printf("Enter email content:");
  while (email_length < MAX_EMAIL_LENGTH - 1) {
    char character = getchar();
    if (character == '\n') {
      email[email_length] = '\0';
      email_length++;
    } else {
      email[email_length] = character;
      email_length++;
    }
  }

  FILE *fp = fopen("emails.txt", "a");
  fprintf(fp, "%s\n", email);
  fclose(fp);

  printf("Email sent successfully!\n");

  return 0;
}
