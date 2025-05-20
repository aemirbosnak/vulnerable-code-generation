//FormAI DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main()
{
   //Smart home devices status
   bool lights = false;
   bool television = false;
   bool fan = false;
   bool doorLock = false;
 
   int option;
   
   //Welcome message
   printf("Welcome to Smart Home Automation System!\n");

   do {
      //Display the menu
      printf("\nSelect an option:\n");
      printf("1. Turn on/off lights\n");
      printf("2. Turn on/off television\n");
      printf("3. Turn on/off fan\n");
      printf("4. Lock/unlock the door\n");
      printf("5. Exit the program\n");
      printf("\nEnter your choice: ");
      
      scanf("%d", &option);
      
      switch(option) {
         case 1:
            lights = !lights;
            if(lights) printf("Lights turned on.\n");
            else printf("Lights turned off.\n");
            break;
         
         case 2:
            television = !television;
            if(television) printf("Television turned on.\n");
            else printf("Television turned off.\n");
            break;
         
         case 3:
            fan = !fan;
            if(fan) printf("Fan turned on.\n");
            else printf("Fan turned off.\n");
            break;
         
         case 4:
            doorLock = !doorLock;
            if(doorLock) printf("Door locked.\n");
            else printf("Door unlocked.\n");
            break;
         
         case 5:
            printf("Exiting the program.\n");
            exit(0);
         
         default:
            printf("Invalid input. Please enter a number between 1 and 5.\n");
      }
      
   } while(option != 5);
   
   return 0;
}