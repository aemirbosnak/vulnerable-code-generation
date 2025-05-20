//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int room1 = rand() % 10 + 1; // generates a random number between 1 and 10
    int room2 = rand() % 10 + 1;
    int room3 = rand() % 10 + 1;
    
    printf("You find yourself in a haunted house. There are three rooms ahead of you. Which one do you enter?\n");
    printf("Room 1\n");
    printf("Room 2\n");
    printf("Room 3\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("You enter room 1 and see a ghostly figure standing in the corner. It points to the north wall and disappears.\n");
            printf("Behind the wall, you find a key.\n");
            break;
        case 2:
            printf("You enter room 2 and hear creepy whispers. The room is dark and you can't see anything.\n");
            printf("You need to find a way to turn on the lights.\n");
            printf("There is a drawer in the room. Do you want to check it?\n");
            printf("Yes\n");
            printf("No\n");
            
            int drawer_choice;
            scanf("%d", &drawer_choice);
            
            if(drawer_choice == 1){
                printf("You open the drawer and find a flashlight. You turn it on and the lights in the room turn on as well.\n");
            }
            else{
                printf("You didn't check the drawer and wander around in the dark until you finally find the light switch.\n");
            }
            break;
        case 3:
            printf("You enter room 3 and see a coffin in the middle of the room. It's closed. What do you do?\n");
            printf("Open the coffin\n");
            printf("Go back\n");
            
            int coffin_choice;
            scanf("%d", &coffin_choice);
            
            if(coffin_choice == 1){
                int coffin_result = rand() % 2; // generates a random number between 0 and 1
                
                if(coffin_result == 0){
                    printf("You open the coffin and nothing happens. You find a key inside and take it.\n");
                }
                else{
                    printf("You open the coffin and a zombie jumps out at you! You barely escape with your life.\n");
                }
            }
            else{
                printf("You decide not to mess with the coffin and head back to the previous room.\n");
            }
            break;
        default:
            printf("That's not a valid choice. Try again.\n");
            break;
    }
    
    printf("\nYou now have these keys: ");
    
    if(room1 < 4){
        printf("Key 1 ");
    }
    if(room2 < 4){
        printf("Key 2 ");
    }
    if(room3 < 4){
        printf("Key 3 ");
    }
    
    printf("\nWhich room do you want to enter next?\n");
    printf("Room 1\n");
    printf("Room 2\n");
    printf("Room 3\n");
    
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            if(room1 < 4){
                printf("You enter room 1 and find a locked door. You use Key 1 to unlock it.\n");
                printf("Inside the room, you find a treasure chest. You open it and find a valuable gemstone.\n");
            }
            else{
                printf("You enter room 1 but find nothing of interest.\n");
            }
            break;
        case 2:
            if(room2 < 4){
                printf("You enter room 2 and find a locked door. You use Key 2 to unlock it.\n");
                printf("Inside the room, you find a book with strange incantations. You take it with you.\n");
            }
            else{
                printf("You enter room 2 but find nothing of interest.\n");
            }
            break;
        case 3:
            if(room3 < 4){
                printf("You enter room 3 and find a locked door. You use Key 3 to unlock it.\n");
                printf("Inside the room, you find a potion that seems to heal all wounds. You take it with you.\n");
            }
            else{
                printf("You enter room 3 but find nothing of interest.\n");
            }
            break;
        default:
            printf("That's not a valid choice. Try again.\n");
            break;
    }
    
    printf("\nCongratulations! You made it out of the haunted house with valuable loot and your life intact.\n");
    
    return 0;
}