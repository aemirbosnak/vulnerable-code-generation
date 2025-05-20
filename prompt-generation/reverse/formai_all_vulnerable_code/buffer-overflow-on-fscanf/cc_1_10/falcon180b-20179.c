//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 10
#define MAX_PASS 20
#define MAX_NAME 50
#define MAX_EMAIL 100

typedef struct {
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  char username[MAX_USER];
  char password[MAX_PASS];
} user;

int main() {
  int count = 0;
  user users[MAX_USER];
  char filename[MAX_NAME];

  printf("Enter the filename: ");
  scanf("%s", filename);

  FILE* fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("File not found.\n");
    return 0;
  }

  while (fscanf(fp, "%s %s %s %s", users[count].name, users[count].email, users[count].username, users[count].password)!= EOF) {
    count++;
  }

  fclose(fp);

  printf("Enter the username: ");
  scanf("%s", users[0].username);

  if (strcmp(users[0].username, "admin") == 0) {
    printf("Enter the password: ");
    scanf("%s", users[0].password);

    if (strcmp(users[0].password, "password") == 0) {
      printf("Login successful.\n");
    } else {
      printf("Login failed.\n");
    }
  } else {
    printf("User not found.\n");
  }

  return 0;
}