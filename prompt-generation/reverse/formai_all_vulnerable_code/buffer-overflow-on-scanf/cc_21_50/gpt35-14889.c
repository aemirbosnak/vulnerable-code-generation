//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    //Setting up the random seed
    srand(time(NULL));
    
    //Initializing data variables
    int playerChoice = 0;
    int spookyRoom[3] = {-1,-1,-1};
    int roomsVisited = 0;
    int ghosts = 0;
    int hasSilver = 0;
    int gameWon = 0;
    
    //Introduction message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your mission is to find the silver key that will unlock the door and get out of the house!\n");
    printf("You are now standing in front of the house, what do you want to do?\n");
    
    //Game loop
    while(!gameWon){
        
        //Printing options for player
        printf("\n1 - Enter the house.\n");
        printf("2 - Quit the game.\n");
        
        //Getting player choice
        scanf("%d", &playerChoice);
        
        //Processing player choice
        switch(playerChoice){
            
            //Entering the house
            case 1:
                printf("\nYou are now inside the house. It's dark and spooky...\n");
                printf("You see three doors in front of you, which one do you want to choose?\n");
                
                //Generating the random room with the key, the ghosts and the empty room
                int silverKey = rand()%3;
                int ghost1 = rand()%3;
                int ghost2 = rand()%3;
                while(ghost2==ghost1){
                    ghost2 = rand()%3;
                }
                spookyRoom[silverKey] = 1;
                spookyRoom[ghost1] = 2;
                spookyRoom[ghost2] = 2;
                
                //Rooms loop
                while(roomsVisited<3){
                    
                    //Printing options for the player
                    printf("\n1 - Open door 1.\n");
                    printf("2 - Open door 2.\n");
                    printf("3 - Open door 3.\n");
                    printf("4 - Leave the house.\n");
                    
                    //Getting player choice
                    scanf("%d",&playerChoice);
                    
                    //Processing player choice
                    switch(playerChoice){
                        
                        //Opening door 1
                        case 1:
                            if(spookyRoom[0]==-1){
                                printf("\nYou open the door and find an empty room!\n");
                                spookyRoom[0] = 0;
                                roomsVisited++;
                            }
                            else if(spookyRoom[0]==2){
                                printf("\nYou open the door and a ghost appears! You run back to the entrance...\n");
                                roomsVisited = 3;
                            }
                            else{
                                printf("\nYou open the door and find the silver key!\n");
                                spookyRoom[0] = 0;
                                hasSilver = 1;
                                roomsVisited++;
                            }
                            break;
                        
                        //Opening door 2
                        case 2:
                            if(spookyRoom[1]==-1){
                                printf("\nYou open the door and find an empty room!\n");
                                spookyRoom[1] = 0;
                                roomsVisited++;
                            }
                            else if(spookyRoom[1]==2){
                                printf("\nYou open the door and a ghost appears! You run back to the entrance...\n");
                                roomsVisited = 3;
                            }
                            else{
                                printf("\nYou open the door and find the silver key!\n");
                                spookyRoom[1] = 0;
                                hasSilver = 1;
                                roomsVisited++;
                            }
                            break;
                        
                        //Opening door 3
                        case 3:
                            if(spookyRoom[2]==-1){
                                printf("\nYou open the door and find an empty room!\n");
                                spookyRoom[2] = 0;
                                roomsVisited++;
                            }
                            else if(spookyRoom[2]==2){
                                printf("\nYou open the door and a ghost appears! You run back to the entrance...\n");
                                roomsVisited = 3;
                            }
                            else{
                                printf("\nYou open the door and find the silver key!\n");
                                spookyRoom[2] = 0;
                                hasSilver = 1;
                                roomsVisited++;
                            }
                            break;
                        
                        //Leaving the house
                        case 4:
                            printf("\nYou leave the house without the silver key... Game Over!\n");
                            return 0;
                        
                        //Invalid choice
                        default:
                            printf("\nInvalid choice, try again.\n");
                        
                    }
                    
                }
                
                //Checking if the player has survived the ghosts
                if(spookyRoom[ghost1]==2 && spookyRoom[ghost2]==2){
                    ghosts = 2;
                }
                else if(spookyRoom[ghost1]==2 || spookyRoom[ghost2]==2){
                    ghosts = 1;
                }
                
                //Printing final message and game status
                printf("\nYou leave the house and count your findings...");
                printf("\nYou have found %d silver keys.", hasSilver);
                printf("\nYou have survived %d ghost(s).", ghosts);
                if(hasSilver){
                    printf("\nYou have won the game! Congratulations!\n");
                    gameWon = 1;
                }
                else{
                    printf("\nYou have lost the game. Better luck next time!\n");
                    gameWon = 1;
                }
                
                break;
            
            //Quitting the game
            case 2:
                printf("\nYou quit the game. Goodbye!\n");
                return 0;
                
            //Invalid choice
            default:
                printf("\nInvalid choice, try again.\n");
            
        }
        
    }
    
    return 0;
}