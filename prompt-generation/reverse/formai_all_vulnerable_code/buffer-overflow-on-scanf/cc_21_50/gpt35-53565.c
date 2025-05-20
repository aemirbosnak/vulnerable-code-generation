//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have been dared to spend the night in a haunted house.\n");
    
    char response;
    printf("Do you accept this dare? (y/n): ");
    scanf("%c", &response);
    
    if(response != 'y' && response != 'Y'){
        printf("You're not brave enough for this game. Goodbye!\n");
        return 0;
    }
    
    printf("\n");
    
    //doors to different rooms
    int door1 = rand() % 3 + 1;
    int door2 = rand() % 3 + 1;
    while(door2 == door1)
        door2 = rand() % 3 + 1;
    int door3 = rand() % 3 + 1;
    while(door3 == door1 || door3 == door2)
        door3 = rand() % 3 + 1;
    
    //initialize room flags
    int room1Entered = 0;
    int room2Entered = 0;
    int room3Entered = 0;
    
    printf("You look around and see 3 doors.\n");
    printf("Door 1 leads to a dark room.\n");
    printf("Door 2 has a sign that says 'Do Not Enter'.\n");
    printf("Door 3 has a bit of light coming through the cracks around it.\n");
    
    while(!room1Entered || !room2Entered || !room3Entered) {
        printf("\nWhich door do you want to enter? (1, 2, or 3): ");
        scanf("%d", &response);
        
        if(response == 1){
            printf("You open the door to the dark room.\n");
            room1Entered = 1;
        }
        else if(response == 2){
            printf("You open the door to the forbidden room.\n");
            room2Entered = 1;
        }
        else if(response == 3){
            printf("You open the door to the dimly lit room.\n");
            room3Entered = 1;
        }
        else{
            printf("That isn't a valid door. Choose 1, 2, or 3.\n");
            continue;
        }
        
        if(room1Entered && room2Entered && room3Entered)
            break;
        
        printf("\nYou look around the room and notice the following objects:\n");
        int ghostAppears = rand() % 2;
        
        if(response == door1) {
            printf("- A candle on a table.\n");
            printf("- A bed with chains hanging from it.\n");
            if(ghostAppears)
                printf("Oh no! A ghost suddenly appears and chases you out of the room!\n");
        }
        else if(response == door2) {
            printf("- A ouija board on a small table.\n");
            printf("- A spooky painting with eyes that follow you.\n");
            if(ghostAppears)
                printf("Oh no! A ghost suddenly appears and chases you out of the room!\n");
        }
        else if(response == door3) {
            printf("- A diary on a shelf.\n");
            printf("- A rocking chair moving by itself.\n");
            if(ghostAppears)
                printf("Oh no! A ghost suddenly appears and chases you out of the room!\n");
        }
    }

    printf("\n");
    printf("Congratulations, you have explored all of the rooms!\n");
    printf("You have survived the haunted house simulator!\n");

    return 0;
}