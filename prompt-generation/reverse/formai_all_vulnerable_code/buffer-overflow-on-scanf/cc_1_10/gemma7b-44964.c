//Gemma-7B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char name[20];
  char password[20];
  int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_password(Password *p) {
  p->used = 0;
  sprintf(p->name, "Password for %s", getlogin());
  printf("Enter a strong password: ");
  fgets(p->password, 20, stdin);
  printf("Password stored: %s\n", p->password);
}

void print_passwords() {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].used) {
      printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Last Hope Password Manager!\n");
  printf("1. Generate New Password\n");
  printf("2. Print Passwords\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      generate_password(passwords);
      break;
    case 2:
      print_passwords();
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}