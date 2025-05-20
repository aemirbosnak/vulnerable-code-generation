//FormAI DATASET v1.0 Category: Smart home light control ; Style: surprised
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
  //Welcome message
  printf("Welcome to the Smart Home Light Control!\n"); 
  printf("All the lights in your home are connected to this Smart House System and can be operated from here\n");
  printf("\n");

  //Prompt user for the input
  printf("Please enter a command to control the lights in your home:\n");
  printf("Enter 1 to turn the lights on.\n");
  printf("Enter 2 to turn the lights off.\n");
  printf("Enter 3 to change the brightness of your lights.\n");

  int input;
  scanf("%d", &input);
  printf("\n");

  //Switch statement
  switch(input) {
    case 1:
      printf("Turning all the lights on...\n");
      sleep(1);
      printf("Lights are on! Enjoy!\n");
      printf("\n");
      break;

    case 2:
      printf("Turning all the lights off...\n");
      sleep(1);
      printf("Lights are off! Good night!\n");
      printf("\n");
      break;

    case 3:
      printf("Please enter the required brightness level (between 1 to 10):\n");
      int brightness;
      scanf("%d", &brightness);

      if(brightness < 1 || brightness > 10) {
        printf("Invalid brightness level entered. Please enter between 1 to 10.\n");
        printf("Program terminated.\n");
        exit(0);
      } else {
        printf("Changing brightness to level %d...\n", brightness);
        sleep(1);
        printf("Brightness level has been changed! Enjoy!\n");
        printf("\n");
      }
      break;

    default:
      printf("Invalid command entered. Please try again.\n");
      printf("\n");
      break;
   }

   //Exiting message
   printf("Thank you for using Smart Home Light Control System!\n");
   printf("Hope your experience was great! Have a nice day :)\n");

   return 0;
}