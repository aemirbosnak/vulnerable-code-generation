//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialization
char username[30];
char password[30];
char recipient[30];
char subject[30];
char body[1000];
char filename[50];
char buffer[1000];
char line[100];

// function prototypes
void initialize();
void login();
void compose();
void send();
void view();
void save();
void help();

int main() {
  char choice;

  initialize();

  // main menu loop
  do {
    printf("\n==C EMAIL CLIENT==\n");
    printf("1. Compose\n");
    printf("2. View\n");
    printf("3. Help\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf(" %c", &choice);

    switch(choice) {
      case '1': compose(); break;
      case '2': view(); break;
      case '3': help(); break;
      case '4': printf("\nGoodbye!\n"); break;
      default: printf("\nInvalid choice.\n"); break;
    }
  } while(choice != '4');

  return 0;
}

// function definitions

void initialize() {
  printf("==C EMAIL CLIENT INITIALIZATION==\n");
  printf("Enter your email username: ");
  scanf("%s", username);
  printf("Enter your email password: ");
  scanf("%s", password);
  printf("\n");
}

void login() {
  printf("Email Login Successful!\n");
}

void compose() {
  printf("==COMPOSE EMAIL==\n");
  printf("Recipient: ");
  scanf("%s", recipient);
  printf("Subject: ");
  scanf("%s", subject);
  printf("Body: ");
  scanf(" %[^\n]s", body);
  printf("Attachment Filename: ");
  scanf("%s", filename);
  printf("\nEmail composed successfully!\n");

  send();
}

void send() {
  printf("\n==SEND EMAIL==\n");
  printf("From: %s\n", username);
  printf("To: %s\n", recipient);
  printf("Subject: %s\n", subject);
  printf("Body: %s\n", body);
  printf("Attachment: %s\n", filename);
  printf("\nEmail sent successfully!\n");
}

void view() {
  printf("==VIEW EMAIL==\n");
  printf("Enter email filename: ");
  scanf("%s", filename);

  // read email file
  FILE *fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("Error: File not found\n");
    return;
  }
  printf("\n");
  while(fgets(line, 100, fp) != NULL) {
    printf("%s", line);
  }
  printf("\n");

  fclose(fp);
}

void save() {
  // write email to file
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "From: %s\n", username);
  fprintf(fp, "To: %s\n", recipient);
  fprintf(fp, "Subject: %s\n", subject);
  fprintf(fp, "Body: %s\n", body);
  fclose(fp);
}

void help() {
  printf("==HELP==\n");
  printf("Compose: Write and send an email\n");
  printf("View: View an email from a file\n");
  printf("Help: Display this help message\n");
  printf("Exit: Exit the program\n");
}