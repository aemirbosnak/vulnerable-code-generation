//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include<stdio.h>

//function to display spaceship movement
void move_spaceship(int x, int y){
  printf("Spaceship moved to position (%d,%d)\n",x,y);
}

int main(){
   //initializing spaceship position
   int spaceship_x = 0;
   int spaceship_y = 0;
   printf("Welcome to the Procedural Space Adventure!\n");
   printf("Your spaceship is currently at position (%d,%d)\n", spaceship_x, spaceship_y);
   
   char choice;
   while(1){
        printf("\nWhat would you like to do?\n");
        printf("a - Move spaceship to a new location\n");
        printf("b - Refuel your spaceship\n");
        printf("q - Quit game\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        
        switch(choice){
            case 'a':{
                int new_x, new_y;
                printf("Enter new x-coordinate: ");
                scanf("%d", &new_x);
                printf("Enter new y-coordinate: ");
                scanf("%d", &new_y);
                move_spaceship(new_x,new_y);
                spaceship_x = new_x;
                spaceship_y = new_y;
                break;
            }
            case 'b':{
                printf("Refueling spaceship...\n");
                printf("Spaceship fully refueled!\n");
                break;
            }
            case 'q':{
                printf("Thank you for playing Procedural Space Adventure!\n");
                return 0;
            }
            default:{
                printf("Invalid choice. Please enter a, b, or q.\n");
                break;
            }
        }
        
        printf("Your spaceship is currently at position (%d,%d)\n", spaceship_x, spaceship_y);
   }
   return 0;
}