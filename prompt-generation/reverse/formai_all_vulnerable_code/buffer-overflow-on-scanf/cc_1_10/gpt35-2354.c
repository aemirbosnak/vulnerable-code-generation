//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include<stdio.h>

int main(){
  // Initializing variables for the drone's current position
  int x = 0;
  int y = 0;
  
  // Welcome message for the user
  printf("Welcome to the C Drone Remote Control program! \n");
  printf("Use the following commands to navigate the drone: \n");
  printf("\t- 'u' to move upwards \n");
  printf("\t- 'd' to move downwards \n");
  printf("\t- 'l' to move left \n");
  printf("\t- 'r' to move right \n");
  printf("\t- 's' to stop the drone \n");
  
  // Taking input from the user for drone control
  char input;
  do {
    printf("Enter your command: ");
    scanf("%c", &input);
    
    switch(input){
      case 'u':
        y++;
        printf("Drone moved up! Current position: x=%d, y=%d \n", x, y);
        break;
        
      case 'd':
        y--;
        printf("Drone moved down! Current position: x=%d, y=%d \n", x, y);
        break;
        
      case 'l':
        x--;
        printf("Drone moved left! Current position: x=%d, y=%d \n", x, y);
        break;
        
      case 'r':
        x++;
        printf("Drone moved right! Current position: x=%d, y=%d \n", x, y);
        break;
        
      case 's':
        printf("Drone stopped! Current position: x=%d, y=%d \n", x, y);
        break;
        
      default:
        printf("Invalid command! Please enter u, d, l, r, or s. \n");
        break;
    }
    
    // Clearing the input buffer
    fflush(stdin);
    
  } while(input != 's');
  
  // Goodbye message for the user
  printf("Thank you for using the C Drone Remote Control program! Goodbye. \n");
  
  return 0;
}