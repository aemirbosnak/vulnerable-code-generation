//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

  // initializing variables
  int length;
  char password[100];
  int i;
  int random_number;

  // adding some humor
  printf("Welcome to the Super Secured Password Generator Automated Device (SSPGAD)!\n");
  printf("I'm your personal password-generating robot assistant. Call me RoboPassword! \n");
  printf("Please enter the length of your desired password (the longer the better and more secure, but don't overdo it!)\n");

  // getting user input
  scanf("%d", &length);

  // verifying input
  if(length < 6) { // sorry not sorry
    printf("Hey, come on! I don\'t think a %d-character password is going to cut it. Try something longer!\n", length);
    main(); // calling the function again to start over
  }
  else if(length > 40) { // whoa there buddy
    printf("Whoa there, cowboy! You really need a %d-character password? I don\'t think so. Try something shorter!\n", length);
    main(); // calling the function again to start over
  }
  else { // let's go!

    srand(time(NULL)); // seeding the random number generator with current time

    printf("Alrighty, let me work my magic...\n");

    for(i = 0; i < length; i++) { // for each character in the password

      random_number = rand() % 94 + 33; // generating a random number between 33 and 126

      password[i] = (char) random_number; // converting the number to its corresponding ASCII character

    }

    password[length] = '\0'; // adding null terminator

    printf("Here it is! Your super-secured password is: %s\n", password);
    printf("Now write it down on a piece of paper and keep it safe! Or, even better, forget it and use a password manager. \n");
    printf("Thanks for using SSPGAD, your favorite password-generating robot assistant, until the robots take over the world! *evil laugh* \n");

    return; // ending the program

  }
}