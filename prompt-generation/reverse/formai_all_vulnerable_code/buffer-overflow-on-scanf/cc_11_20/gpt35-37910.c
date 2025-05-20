//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){

  int choice;
  char name[20];
  char password[20];

  printf("Welcome to our system administration program!\n");
  printf("Please enter your name: ");
  scanf("%s", &name);
  printf("Enter your password: ");
  scanf("%s", &password);

  if(strcmp(name, "admin") != 0 || strcmp(password, "password123") != 0){
    printf("Access denied!\n");
    exit(1);
  }

  printf("Access granted!\n");
  printf("What would you like to do?\n");
  printf("1. Display system information\n");
  printf("2. Shutdown system\n");
  printf("3. Restart system\n");
  printf("4. Exit program\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice){
    case 1:
      printf("System information:\n");
      system("uname -a");
      break;
    case 2:
      printf("Are you sure you want to shutdown the system? (y/n)\n");
      char response;
      scanf(" %c", &response);
      if(response == 'y' || response == 'Y'){
        printf("Shutting down system...\n");
        system("sudo shutdown -h now");
      }
      else{
        printf("System not shutdown.\n");
      }
      break;
    case 3:
      printf("Are you sure you want to restart the system? (y/n)\n");
      scanf(" %c", &response);
      if(response == 'y' || response == 'Y'){
        printf("Restarting system...\n");
        system("sudo shutdown -r now");
      }
      else{
        printf("System not restarted.\n");
      }
      break;
    case 4:
      printf("Exiting program...\n");
      exit(0);
    default:
      printf("Invalid choice!\n");
      break;
  }

  return 0;
}