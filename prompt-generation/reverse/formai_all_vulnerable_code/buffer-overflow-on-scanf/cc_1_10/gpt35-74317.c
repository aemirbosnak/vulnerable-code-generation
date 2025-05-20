//FormAI DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
  char name[20];
  char username[20];
  char password[20];
  int age;
  int phone[11];
};

void file_write(struct User u1) {
  FILE *fPtr;
  fPtr = fopen("users.txt", "a");
  if (fPtr == NULL) {
    printf("Could not open the file\n");
    exit(1);
  }
  fprintf(fPtr, "%s %s %s %d %s\n", u1.name, u1.username, u1.password, u1.age, u1.phone);
  fclose(fPtr);
}

void display_users() {
  FILE *fPtr;
  fPtr = fopen("users.txt", "r");
  if (fPtr == NULL) {
    printf("Could not open the file\n");
    exit(1);
  }
  char buffer[255];
  while (fgets(buffer, 255, fPtr)) {
    printf("%s", buffer);
  }
  fclose(fPtr);
}

int main() {
  struct User user1;
  printf("Enter name: ");
  scanf("%s", user1.name);
  printf("Enter username: ");
  scanf("%s", user1.username);
  printf("Enter password: ");
  scanf("%s", user1.password);
  printf("Enter age: ");
  scanf("%d", &user1.age);
  printf("Enter phone number: ");
  scanf("%s", user1.phone);
  file_write(user1);
  printf("User saved successfully!\n");
  display_users();
  return 0;
}