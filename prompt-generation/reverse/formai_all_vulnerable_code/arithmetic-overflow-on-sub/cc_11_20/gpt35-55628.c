//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  // Initializing the variables 
  int speed = 0;
  int direction_angle = 0;
  int altitude = 0;
  int power = 0; 
  
  // Printing the starting message 
  printf("Welcome to the C Drone Remote Control! \n");
  printf("Initializing the drone... \n");
  printf("Please enter the speed, direction angle, altitude and power level. \n");
  
  // Reading the input values 
  scanf("%d", &speed);
  scanf("%d", &direction_angle);
  scanf("%d", &altitude);
  scanf("%d", &power);
  
  // Printing the entered values 
  printf("The drone is now flying at %d km/h at a direction angle of %d degrees and altitude of %d metres with a power level of %d. \n", speed, direction_angle, altitude, power);
  
  // Looping until the user wants to quit the program 
  while(1) {
    
    // Defining the action variable 
    int action = 0;
    
    // Printing the user options 
    printf("\n ==== User Options ==== \n");
    printf("1. Increase speed by 10 km/h \n");
    printf("2. Decrease speed by 10 km/h \n");
    printf("3. Turn right by 10 degrees \n");
    printf("4. Turn left by 10 degrees \n");
    printf("5. Increase altitude by 10 metres \n");
    printf("6. Decrease altitude by 10 metres \n");
    printf("7. Increase power level \n");
    printf("8. Decrease power level \n");
    printf("9. Autopilot \n");
    printf("10. Quit \n");
    
    // Reading the user choice 
    scanf("%d", &action);
    
    // Taking the action based on user choice 
    switch(action) {
      
      case 1: 
        printf("Increasing speed by 10 km/h... \n");
        speed += 10;
        printf("The drone is now flying at %d km/h. \n", speed);
        break;
        
      case 2: 
        printf("Decreasing speed by 10 km/h... \n");
        speed -= 10;
        printf("The drone is now flying at %d km/h. \n", speed);
        break;
        
      case 3: 
        printf("Turning right by 10 degrees... \n");
        direction_angle += 10;
        printf("The drone is now flying in the direction angle of %d degrees. \n", direction_angle);
        break;
        
      case 4: 
        printf("Turning left by 10 degrees... \n");
        direction_angle -= 10;
        printf("The drone is now flying in the direction angle of %d degrees. \n", direction_angle);
        break;
        
      case 5: 
        printf("Increasing altitude by 10 metres... \n");
        altitude += 10;
        printf("The drone is now flying at the altitude of %d metres. \n", altitude);
        break;
        
      case 6: 
        printf("Decreasing altitude by 10 metres... \n");
        altitude -= 10;
        printf("The drone is now flying at the altitude of %d metres. \n", altitude);
        break;
        
      case 7: 
        printf("Increasing power level... \n");
        power += 1;
        printf("The power level is now %d. \n", power);
        break;
        
      case 8: 
        printf("Decreasing power level... \n");
        power -= 1;
        printf("The power level is now %d. \n", power);
        break;
        
      case 9: 
        printf("Activating autopilot! Please wait... \n");
        speed = 100;
        direction_angle = 180;
        altitude = 50;
        power = 2;
        printf("The drone is now flying at %d km/h at a direction angle of %d degrees and altitude of %d metres with a power level of %d. \n", speed, direction_angle, altitude, power);
        break;
        
      case 10: 
        printf("Quitting the C Drone Remote Control... \n");
        exit(0);
        break;
        
      default: 
        printf("Invalid choice! Please try again. \n");
        break;
    }
  }
  
  return 0;
}