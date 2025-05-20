//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct email {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} email_t;

typedef struct mailing_list {
  email_t emails[MAX_EMAILS];
  int num_emails;
} mailing_list_t;

void add_email(mailing_list_t *mailing_list, char *name, char *email) {
  strcpy(mailing_list->emails[mailing_list->num_emails].name, name);
  strcpy(mailing_list->emails[mailing_list->num_emails].email, email);
  mailing_list->num_emails++;
}

void send_email(mailing_list_t *mailing_list, char *subject, char *body) {
  for (int i = 0; i < mailing_list->num_emails; i++) {
    printf("To: %s <%s>\n", mailing_list->emails[i].name, mailing_list->emails[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
    printf("\n");
  }
}

void load_mailing_list(mailing_list_t *mailing_list, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  while (fscanf(fp, "%s %s", name, email) != EOF) {
    add_email(mailing_list, name, email);
  }

  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <filename> <subject> <body>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  mailing_list_t mailing_list;
  mailing_list.num_emails = 0;

  load_mailing_list(&mailing_list, argv[1]);
  send_email(&mailing_list, argv[2], argv[3]);

  return EXIT_SUCCESS;
}