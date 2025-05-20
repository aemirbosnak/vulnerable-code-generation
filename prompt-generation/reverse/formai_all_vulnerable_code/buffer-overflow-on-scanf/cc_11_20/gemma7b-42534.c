//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASS_LEN 255

int main() {
  char pass[MAX_PASS_LEN];
  int pass_len = 0;
  char strength[4] = {'W', 'A', 'S', 'S'};

  printf("Enter your password: ");
  scanf("%s", pass);
  pass_len = strlen(pass);

  if (pass_len < 8) {
    printf("Password too short. Minimum 8 characters required.\n");
  } else if (pass_len > MAX_PASS_LEN) {
    printf("Password too long. Maximum %d characters allowed.\n", MAX_PASS_LEN);
  } else {
    int strong = 0;
    for (int i = 0; i < pass_len; i++) {
      if (isupper(pass[i]) || islower(pass[i]) || isdigit(pass[i]) || pass[i] == '$' || pass[i] == '%') {
        strong++;
      }
    }

    switch (strong) {
      case 0:
        printf("Password is weak. Please use a stronger password.\n");
        break;
      case 1:
        printf("Password is fair. But could be improved.\n");
        break;
      case 2:
        printf("Password is good. It meets the minimum requirements.\n");
        break;
      case 3:
        printf("Password is strong. It has many special characters.\n");
        break;
      case 4:
        printf("Password is very strong. It has all the characters.\n");
        break;
    }

    printf("Strength: %s\n", strength[strong]);
  }

  return 0;
}