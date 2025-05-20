//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int player_choice;
    int items_collected = 0;
    int ghosts_encountered = 0;
    int game_over = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your objective is to collect as many items as possible without getting caught by the ghosts.\n");

    while(!game_over){
        printf("\nYou find yourself in a dimly lit hallway. You can see three doors in front of you.\n");
        printf("Which door do you choose? (1, 2, or 3)\n");
        scanf("%d", &player_choice);

        switch(player_choice){
            case 1:
                printf("\nYou enter a room filled with cobwebs and dust. You notice a rusty key in the corner of the room.\n");
                printf("Do you want to take it? (1 = Yes, 0 = No)\n");
                int take_key;
                scanf("%d", &take_key);
                if(take_key){
                    printf("You took the key and added it to your collection.\n");
                    items_collected++;
                }
                else{
                    printf("You left the key and continued exploring.\n");
                }
                break;

            case 2:
                printf("\nYou enter a room with broken furniture and shattered glass on the floor. You see a ghost hovering in the corner of the room.\n");
                printf("What do you want to do? (1 = Run, 2 = Hide, 3 = Fight)\n");
                int ghost_action;
                scanf("%d", &ghost_action);
                if(ghost_action == 1){
                    printf("You try to run away but the ghost catches up to you and drags you to the underworld.\n");
                    game_over = 1;
                }
                else if(ghost_action == 2){
                    printf("You try to hide behind a bookshelf but the ghost sees you and chases you out of the room.\n");
                    ghosts_encountered++;
                }
                else{
                    printf("You try to fight the ghost with your bare hands but it passes right through you. You run out of the room in terror.\n");
                    ghosts_encountered++;
                }
                break;

            case 3:
                printf("\nYou enter a room with a single candle burning in the center. You hear strange whispers coming from the walls.\n");
                printf("Do you want to investigate? (1 = Yes, 0 = No)\n");
                int investigate;
                scanf("%d", &investigate);
                if(investigate){
                    int chance_to_find_item = rand() % 2;
                    if(chance_to_find_item){
                        printf("You found a rare artifact and added it to your collection.\n");
                        items_collected++;
                    }
                    else{
                        printf("You don't find anything of interest and leave the room.\n");
                    }
                }
                else{
                    printf("You don't want to risk it and leave the room.\n");
                }
                break;

            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }

        if(ghosts_encountered >= 3){
            printf("\nYou have been caught by too many ghosts. Game over.\n");
            game_over = 1;
        }
        else if(items_collected >= 5){
            printf("\nYou have collected all the items and won the game!\n");
            game_over = 1;
        }
        else{
            printf("\nItems collected: %d\n", items_collected);
            printf("Ghosts encountered: %d\n", ghosts_encountered);
        }
    }

    return 0;
}