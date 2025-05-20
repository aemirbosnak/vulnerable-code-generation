//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   bool light_on = false;  //initialize the light as off
   int button_presses = 0; //initialize a counter to track how many times button has been pressed
   
   printf("Welcome to our Smart Home Light Control Program!\n");
   
   while(true)    //infinite loop to keep the program running
   {
      printf("\nPress the button to turn the lights %s. Press 0 to exit.\n", light_on ? "off" : "on");
      int button_input;
      scanf("%d", &button_input);   //get the input from user
      
      if(button_input == 0)    //exit the program when input is 0
      {
         printf("Exiting program...\n");
         break;
      }
      else if(button_input == 1)   //toggle the lights when button is pressed
      {
         light_on = !light_on;  //flip the value of the light_on variable
         button_presses++;     //increment the button press counter
         
         if(light_on)
         {
            printf("Turning the lights on!\n");
         }
         else
         {
            printf("Turning the lights off!\n");
         }
         
         if(button_presses % 10 == 0)   //every 10 button presses, tell a joke
         {
            printf("Knock, knock.\n");
            printf("Who's there?\n");
            printf("Boo.\n");
            printf("Boo who?\n");
            printf("Don't cry, the lights are still on!\n");
         }
      }
      else   //if the user inputs any other value, show an error message
      {
         printf("Invalid input! Please try again.\n");
      }
   }
   
   return 0;   //end of program
}