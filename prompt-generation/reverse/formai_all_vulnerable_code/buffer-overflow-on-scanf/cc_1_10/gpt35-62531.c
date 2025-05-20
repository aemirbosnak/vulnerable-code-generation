//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

#define MAX_NUM 100   // Maximum number for guessing 
#define MAX_TRIES 5   // Maximum number of tries 

int main() 
{ 
  int guessed_num, secret_num, num_tries = 0; 
  
  srand(time(NULL));   // Initialize random seed 
  
  secret_num = rand() % MAX_NUM + 1;   // Generate a random number
  
  printf("Welcome to the Number Guessing Game!\n"); 
  printf("I have chosen a number between 1 and %d\n", MAX_NUM); 
  
  while(num_tries < MAX_TRIES) 
  { 
    printf("\nYou have %d tries left.\n", MAX_TRIES - num_tries); 
    printf("Enter your guess between 1 and %d: ", MAX_NUM); 
    scanf("%d", &guessed_num); 
    
    if (guessed_num < 1 || guessed_num > MAX_NUM) 
    { 
      printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUM); 
      continue;   // Skip to next iteration of loop 
    } 
    
    num_tries++; 
    if (guessed_num == secret_num) 
    { 
      printf("\nCongratulations, you guessed the number in %d tries!\n", num_tries); 
      return 0;   // End program with success code 
    } 
    else 
    { 
      if (guessed_num < secret_num) 
        printf("Too low. "); 
      else 
        printf("Too high. "); 
      
      printf("Try again.\n"); 
    } 
  } 
  
  // If we reach here, the user has run out of tries 
  printf("\nSorry, you did not guess the number in time. The number was %d.\n", secret_num); 
  return 0;   // End program with success code 
}