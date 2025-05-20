//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    // A starry night in deep space
    printf("Welcome to the starship Scrappy Doo! \n");
    
    // Let's explore the galaxy
    printf("You are in the control room. \n");
    
    // You can go to the bridge, the engine room, or the cafeteria.
    printf("What would you like to do? \n");
    
    char choice;
    scanf("%c", &choice);
    
    switch (choice) {
        case 'b':
            printf("You have arrived at the bridge. \n");
            printf("You are greeted by a holographic representation of Captain Kirk. \n");
            printf("He says, 'Set course for the Andromeda Galaxy!' \n");
            break;
        case 'e':
            printf("You have arrived at the engine room. \n");
            printf("The engines are making a strange noise. \n");
            printf("You decide to investigate further. \n");
            break;
        case 'c':
            printf("You have arrived at the cafeteria. \n");
            printf("The food replicator is malfunctioning. \n");
            printf("You decide to fix it. \n");
            break;
        default:
            printf("Invalid choice. \n");
    }
    
    // Once you have finished your task, return to the control room.
    printf("You have completed your task. \n");
    printf("Return to the control room. \n");
    
    // Back in the control room, you can continue your journey.
    printf("You are back in the control room. \n");
    printf("What would you like to do? \n");
    
    // Repeat the loop until you reach the end of the galaxy.
    int loop = 1;
    while (loop < 10) {
        char choice;
        scanf("%c", &choice);
        
        switch (choice) {
            case 'b':
                printf("You have arrived at the bridge. \n");
                printf("You are greeted by a holographic representation of Captain Kirk. \n");
                printf("He says, 'Set course for the Andromeda Galaxy!' \n");
                break;
            case 'e':
                printf("You have arrived at the engine room. \n");
                printf("The engines are making a strange noise. \n");
                printf("You decide to investigate further. \n");
                break;
            case 'c':
                printf("You have arrived at the cafeteria. \n");
                printf("The food replicator is malfunctioning. \n");
                printf("You decide to fix it. \n");
                break;
            default:
                printf("Invalid choice. \n");
        }
        
        if (loop == 9) {
            printf("Congratulations! You have reached the end of the galaxy! \n");
            break;
        }
        
        printf("You have completed your task. \n");
        printf("Return to the control room. \n");
        
        printf("You are back in the control room. \n");
        printf("What would you like to do? \n");
        
        loop++;
    }
    
    return 0;
}