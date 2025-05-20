//Gemma-7B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define PASS_LENGTH 20

typedef struct Password {
  char *name;
  char *password;
  time_t timestamp;
} Password;

void generate_password(Password *passwords, int index) {
  passwords[index].name = malloc(20);
  passwords[index].password = malloc(PASS_LENGTH);
  passwords[index].timestamp = time(NULL);

  printf("Enter the name for the password: ");
  scanf("%s", passwords[index].name);

  printf("Enter the password: ");
  scanf("%s", passwords[index].password);

  passwords[index].timestamp = time(NULL);
}

void print_passwords(Password *passwords, int num_passwords) {
  for (int i = 0; i < num_passwords; i++) {
    printf("Name: %s\n", passwords[i].name);
    printf("Password: %s\n", passwords[i].password);
    printf("Timestamp: %ld\n", passwords[i].timestamp);
    printf("\n");
  }
}

int main() {
  Password passwords[MAX_PASSWORDS];
  int num_passwords = 0;

  while (1) {
    int option;

    printf("1. Generate Password\n");
    printf("2. Print Passwords\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        generate_password(passwords, num_passwords);
        num_passwords++;
        break;
      case 2:
        print_passwords(passwords, num_passwords);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}