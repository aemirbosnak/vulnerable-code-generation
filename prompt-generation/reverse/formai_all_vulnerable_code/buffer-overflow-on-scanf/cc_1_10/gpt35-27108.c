//FormAI DATASET v1.0 Category: System administration ; Style: immersive
//Welcome to The System Administration Example Program!
//Today, we will be creating a secure login system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//max length for username and password
#define MAX_LEN 20

//function declaration for login
int login();

int main(){
  //ask the user if they want to log in or exit
  char choice;
  printf("Welcome to the System Administration Example Program! Press 'l' to login or 'x' to exit.\n");
  scanf("%c", &choice);
  
  //loop to keep asking user until they choose to exit
  while(choice != 'x'){
    //if user chooses to log in, call the login function
    if(choice == 'l'){
      int success = login();
      //if login is successful, greet the user and give them access to the system
      if(success == 1){
        printf("Welcome back! You now have access to the system.\n");
        //code for system access goes here
      }
      //if login is unsuccessful, prompt user to try again or exit
      else{
        printf("Sorry, your login was unsuccessful. Press 'l' to try again or 'x' to exit.\n");
      }
    }
    //if user enters anything else, prompt them to try again or exit
    else{
      printf("Sorry, that was an invalid input. Press 'l' to login or 'x' to exit.\n");
    }
    //ask user again to choose to login or exit
    scanf(" %c", &choice);
  }
  printf("Thank you for using the System Administration Example Program!\n");
  return 0;
}

int login(){
  //declare variables for username and password
  char username[MAX_LEN];
  char password[MAX_LEN];
  
  //prompt user for username and password
  printf("Please enter your username (max length of %d): ", MAX_LEN);
  scanf("%s", username);
  
  printf("Please enter your password (max length of %d): ", MAX_LEN);
  scanf("%s", password);
  
  //check if username and password match the set credentials
  if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0){
    return 1; //login success
  }
  else{
    return 0; //login failure
  }
}