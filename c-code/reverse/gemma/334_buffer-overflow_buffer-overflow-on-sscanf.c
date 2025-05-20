#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void send_email(char *email) {
  char buffer[1024];
  sprintf(buffer, "Subject: Test email to %s", email);
  // Send email using SMTP library
}

int main() {
  char email[256];
  printf("Enter your email address: ");
  scanf("%s", email);
  send_email(email);
  return 0;
}
