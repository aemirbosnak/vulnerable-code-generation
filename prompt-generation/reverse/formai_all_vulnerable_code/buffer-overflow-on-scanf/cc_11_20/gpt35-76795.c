//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a large, old mansion.\n");
    printf("Do you want to go inside? (y/n)\n");

    char response;
    scanf("%c", &response);

    if(response == 'y' || response == 'Y'){
        printf("You have entered the house.\n");
        printf("Suddenly, the door slams shut and the room goes dark.\n");
        printf("You hear footsteps approaching.\n");
        printf("Do you want to hide (h) or fight (f)?\n");

        scanf(" %c", &response);

        if(response == 'h' || response == 'H'){
            printf("You hide behind a curtain.\n");
            printf("The footsteps become louder and louder.\n");
            printf("You feel a cold breath on your neck.\n");
            printf("Suddenly, you hear a scream and everything goes quiet.\n");
            printf("You wait for a few moments before peeking out from behind the curtain.\n");
            printf("There's a bloody handprint on the wall, but no sign of anyone else.\n");
        }
        else if(response == 'f' || response == 'F'){
            printf("You pick up a nearby candlestick and prepare to fight.\n");
            printf("The footsteps become louder and louder.\n");
            printf("You swing the candlestick, but there's nothing there.\n");
            printf("Suddenly, you hear a scream and everything goes quiet.\n");
            printf("You wait for a few moments before exploring the room.\n");
            printf("You find a secret passage behind a bookcase - maybe that's where the scream came from.\n");
        }
        else{
            printf("You didn't choose a valid option. You have been eaten by a grue.\n");
            exit(0);
        }

        printf("You continue exploring the house.\n");
        printf("You hear strange noises and see fleeting shadows out of the corner of your eye.\n");
        printf("Do you want to keep going (y/n)?\n");

        scanf(" %c", &response);

        if(response == 'y' || response == 'Y'){
            printf("You climb a winding staircase.\n");
            printf("At the top, you find a dusty old library.\n");
            printf("A book falls off the shelf and opens to a page displaying an occult ritual.\n");
            printf("Do you want to perform the ritual (p) or leave the room (l)?\n");

            scanf(" %c", &response);

            if(response == 'p' || response == 'P'){
                srand(time(0));
                int roll = rand() % 100 + 1;
                if(roll > 50){
                    printf("You successfully perform the ritual and gain magical powers!\n");
                }
                else{
                    printf("You botched the ritual and open a portal to the underworld.\n");
                    printf("You are dragged down into hell screaming.\n");
                    exit(0);
                }
            }
            else{
                printf("You leave the library and continue exploring the house.\n");
            }
        }
        else{
            printf("You decide to leave the house. You trip and fall down the stairs, dying instantly.\n");
            exit(0);
        }
    }
    else{
        printf("You decide not to enter the house. You hear a ghostly voice whispering your name...\n");
        exit(0);
    }

    printf("You have successfully navigated the haunted house simulator! Congratulations!\n");

    return 0;
}