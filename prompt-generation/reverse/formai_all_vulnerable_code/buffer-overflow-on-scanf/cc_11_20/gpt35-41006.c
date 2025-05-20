//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int room = 1, choice = 0, i; 
    char response; 

    srand(time(0)); 

    while ( room != 9 ) 
    { 
        // Print the current room
        printf("You are in room %d.\n\n", room); 

        // Check if this is the haunted room
        if ( room == 6 ) 
        { 
            printf("You enter the haunted room... \n"); 

            if ( rand() % 2 == 0) 
            { 
              printf("Suddenly you see a ghost! \n"); 
              printf("What would you like to do? \n"); 
              printf("1. Scream and run away \n"); 
              printf("2. Try to fight the ghost \n"); 
              printf("3. Stay calm and try to talk with the ghost \n\n"); 

              printf("Enter your choice: "); 
              scanf("%d", &choice); 

              switch (choice) 
              { 
                 case 1: 
                    printf("You scream and run away! \n\n"); 
                    room = 1; 
                    break; 

                 case 2: 
                    printf("You try to fight the ghost, but it goes right through you! \n\n"); 
                    break; 

                 case 3: 
                    printf("You stay calm and try to talk with the ghost... It seems to be friendly! \n\n"); 
                    break; 

                 default: 
                    printf("Invalid choice! \n\n"); 
                    break; 
              } 
            } 
            else 
            { 
                printf("You breathe a sigh of relief... There's no ghost here after all. \n\n"); 
            } 
        } 

        // Print the options
        printf("Which direction would you like to go? \n"); 
        printf("1. North \n"); 
        printf("2. East \n"); 
        printf("3. South \n"); 
        printf("4. West \n"); 
        printf("5. Stay in current room \n"); 
        printf("Enter your choice: "); 

        scanf("%d", &choice); 

        if (choice < 1 || choice > 5) 
        { 
            printf("Invalid choice! \n\n"); 
            continue; 
        } 

        // Check if the door is locked
        if (room == 4 && choice == 2) 
        { 
            printf("The door is locked! \n\n"); 
            continue; 
        } 

        // Move to the new room
        switch (choice) 
        { 
            case 1: 
                room -= 3; 
                break; 

            case 2: 
                room += 1; 
                break; 

            case 3: 
                room += 3; 
                break; 

            case 4: 
                room -= 1; 
                break; 

            default: 
                break; 
        } 
    } 

    // Print the final message
    printf("Congratulations, you have escaped the haunted house! Play again soon! \n"); 

    return 0; 
}