//FormAI DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_SUBJECT 50
#define MAX_LEN_BODY 500
#define MAX_LEN_SENDER 30
#define MAX_LEN_RECIPIENT 30

enum mail_protocol {
  SMTP,
  POP3,
  IMAP
};

struct mail_config {
  char username[MAX_LEN_SENDER];
  char password[MAX_LEN_SENDER];
  char server_address[MAX_LEN_RECIPIENT];
  enum mail_protocol protocol;
  int port;
};

struct email {
  char subject[MAX_LEN_SUBJECT];
  char body[MAX_LEN_BODY];
  char sender[MAX_LEN_SENDER];
  char recipient[MAX_LEN_RECIPIENT];
};

void configure_mail(struct mail_config *cfg) {
  printf("Enter your email address: ");
  scanf("%s", cfg->username);
  printf("Enter your email password: ");
  scanf("%s", cfg->password);
  printf("Enter the mail server address: ");
  scanf("%s", cfg->server_address);
  printf("Enter the mail protocol (0 for SMTP, 1 for POP3, 2 for IMAP): ");
  scanf("%d", &cfg->protocol);
  printf("Enter the port number to use: ");
  scanf("%d", &cfg->port);
}

void send_mail(struct email *mail, struct mail_config cfg) {
  printf("Sending email...\n");
  printf("From: %s\n", mail->sender);
  printf("To: %s\n", mail->recipient);
  printf("Subject: %s\n", mail->subject);
  printf("Body:\n%s\n", mail->body);
  printf("Using protocol %d to connect to server %s on port %d\n", cfg.protocol, cfg.server_address, cfg.port);
  printf("Authentication credentials: %s:%s\n", cfg.username, cfg.password);
}

int main() {
  struct mail_config config;
  struct email mail;

  configure_mail(&config);

  printf("Enter sender email address: ");
  scanf("%s", mail.sender);
  printf("Enter recipient email address: ");
  scanf("%s", mail.recipient);
  printf("Enter email subject: ");
  scanf("%s", mail.subject);
  printf("Enter email body: ");
  scanf("%s", mail.body);

  send_mail(&mail, config);

  return 0;
}