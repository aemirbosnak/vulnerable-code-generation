//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

/* This program allows the user to create, delete and manipulate user accounts in a Linux system. */

void create_user() {
  char username[20];
  printf("Enter username: ");
  scanf("%s", username);
  
  char command[50];
  sprintf(command, "useradd %s", username);
  
  system(command);
}

void delete_user() {
  char username[20];
  printf("Enter username: ");
  scanf("%s", username);
  
  char command[50];
  sprintf(command, "userdel -r %s", username); // -r flag deletes the user's home directory as well
  
  system(command);
}

void change_password() {
  char username[20];
  printf("Enter username: ");
  scanf("%s", username);
  
  char command[50];
  sprintf(command, "passwd %s", username);
  
  system(command);
}

void show_users() {
  printf("List of all users:\n");
  system("cut -d: -f1 /etc/passwd");
}

int main() {
  int choice;
  
  printf("Welcome to User Management System!\n");
  
  while(1) {
    printf("\n1. Create a new user\n2. Delete an existing user\n3. Change a user's password\n4. Show list of all users\n5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: create_user(); break;
      case 2: delete_user(); break;
      case 3: change_password(); break;
      case 4: show_users(); break;
      case 5: printf("Exiting program...\n"); exit(0); break;
      default: printf("Invalid choice\n"); break;
    }
  }
  
  return 0;
}