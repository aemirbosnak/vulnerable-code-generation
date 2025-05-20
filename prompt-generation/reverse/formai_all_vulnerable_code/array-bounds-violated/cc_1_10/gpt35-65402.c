//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Variables to store game properties
    int lighting = 0;
    char sound[50] = "Silence";
    srand(time(0));
    
    // Array to store each room of the haunted house
    char* rooms[5] = {"The Foyer", "The Library", "The Attic", "The Cellar", "The Dining Room"};
    
    int currentRoom = 0;
    printf("\nWelcome to the Haunted House Simulator!\n");
    
    // Game loop
    while(1){
        printf("\nYou are now in %s\n", rooms[currentRoom]);
        switch(currentRoom){
            case 0:
                lighting = 30;
                strcpy(sound, "Creaky floorboards");
                break;
            case 1:
                lighting = 25;
                strcpy(sound, "Whispers");
                break;
            case 2:
                lighting = 15;
                strcpy(sound, "Ghostly moans");
                break;
            case 3:
                lighting = 10;
                strcpy(sound, "Scratching sounds");
                break;
            case 4:
                lighting = 20;
                strcpy(sound, "Facial expressions");
                break;
            default:
                break;
        }
        
        // Jump scares
        if(rand()%10 == 0){
            printf("\nBoo! A ghostly figure appears out of nowhere!\n");
        }
        printf("\n%s can be heard in the background\n", sound);
        printf("The room is dimly lit with a level of %d\n", lighting);
        printf("Where do you want to go next? (Enter a number between 1 and 5)\n");
        
        scanf("%d", &currentRoom);
        while(currentRoom < 1 || currentRoom > 5){
            printf("Sorry, invalid input. Please enter a number between 1 and 5.\n");
            scanf("%d", &currentRoom);
        }
    }
    return 0;
}