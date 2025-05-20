//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void display_room(int room){
// functions for displaying each room of the haunted house
    switch(room){
        case 0:
            printf("\nYou are standing at the entrance of the haunted mansion.");
            printf("\nIt is dark and eerie. You can just sense that this place is not ordinary.");
            printf("\nYou see a door in front of you. You walk towards it and open the door.");
            printf("\nYou enter the mansion.");
            break;
        case 1:
            printf("\nYou are in the living room.");
            printf("\nThere are cobwebs and dust everywhere.");
            printf("\nYou notice an old painting hanging on one of the walls - it catches your attention.");
            printf("\nAs you walk closer, you see that the painting is of a person who looks like they are staring right back at you.");
            break;
        case 2:
            printf("\nYou are in the dining room.");
            printf("\nThe table is set for a feast but no one is there.");
            printf("\nAs you walk towards the table, you hear whispers coming from the walls.");
            printf("\nYou realize that you are not alone in this room.");
            break;
        case 3:
            printf("\nYou are in the library.");
            printf("\nThere are rows and rows of old books.");
            printf("\nAs you walk through the library, you get the feeling that someone or something is watching you.");
            printf("\nYou hear a sound coming from behind one of the bookshelves.");
            break;
        case 4:
            printf("\nYou are in the kitchen.");
            printf("\nIt looks like it hasn't been used in years.");
            printf("\nAs you walk towards the pantry, you see shadows moving on the walls.");
            printf("\nThe door to the pantry is slightly open, and you hear strange noises coming from inside it.");
            break;
        case 5:
            printf("\nYou are in the bedroom.");
            printf("\nThe bed is unmade and there is a chill in the air.");
            printf("\nAs you walk towards the window, you see a figure standing outside.");
            printf("\nIt looks like a woman, but she is transparent and disappears before your eyes.");
            break;
        case 6:
            printf("\nYou are in the attic.");
            printf("\nIt is dark and musty.");
            printf("\nAs you walk towards a trunk, you hear footsteps on the floorboards behind you.");
            printf("\nYou turn around but no one is there.");
            break;
        case 7:
            printf("\nYou have escaped from the haunted mansion.");
            printf("\nYou survived the night, but you know you will never forget what you experienced.");
            break;
    }
}

int main(){
    // initialize random number generator
    srand((unsigned)time(NULL));
    int current_room = 0;
    int next_room;
    bool game_over = false;
    char choice;
    display_room(current_room);
    
    while(!game_over){
        // roll dice to determine next room
        next_room = rand() % 7 + 1;

        printf("\nYou have entered the next room. ");
        current_room = next_room;
        display_room(current_room);
        
        // player has escaped from the haunted house
        if (current_room == 7){
            game_over = true;
            continue;
        }

        // player has a chance to continue or leave
        printf("\nDo you wish to proceed to the next room? [y/n]: ");
        scanf("%c", &choice);
        if (choice == 'n' || choice == 'N'){
            game_over = true;
        }
        
    }
    printf("\nGame over!");
    return 0;
}