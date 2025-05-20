//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the haunted house simulator!\n\n");
    
    int choice;
    int room = 1;
    int key = 0;
    int demon_alive = 1;
    
    srand(time(NULL)); //initializes the random number generator
    
    while(room != 0){
        switch(room){
            case 1:
                printf("You are in the foyer. There are doors to your left and right. Which one do you choose? (1 for left, 2 for right)\n");
                scanf("%d", &choice);
                if(choice == 1){
                    room = 2;
                } else if (choice == 2){
                    room = 3;
                } else {
                    printf("Invalid choice! Try again.\n");
                }
                break;
            case 2:
                printf("You enter the living room. There is a piano in the corner and a fireplace on the far wall. What do you do? (1 to play piano, 2 to examine fireplace, 3 to go back to foyer)\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("As you start playing the piano, the keys begin to move on their own. Suddenly, the lid slams shut! You are trapped!\n");
                    room = 0;
                } else if (choice == 2){
                    printf("You examine the fireplace and find a key hidden inside. You take it.\n");
                    key = 1;
                } else if (choice == 3){
                    room = 1;
                } else {
                    printf("Invalid choice! Try again.\n");
                }
                break;
            case 3:
                printf("You enter the dining room. There is a table set for dinner and a door that leads to the kitchen. What do you do? (1 to examine table, 2 to go to kitchen, 3 to go back to foyer)\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("As you examine the table, you hear a growling sound coming from the kitchen. You feel a bead of sweat trickle down your forehead.\n");
                } else if (choice == 2){
                    if(key == 1){
                        printf("You unlock the kitchen door and enter. You see a demon feasting on the remains of a cat. What do you do? (1 to fight demon, 2 to run back to the dining room)\n");
                        scanf("%d", &choice);
                        if(choice == 1){
                            int demon_roll = rand() % 10 + 1; //rolls a random number between 1 and 10
                            if(demon_roll > 5){
                                printf("You defeat the demon and find a stairway leading down. You descend into the darkness...\n");
                                room = 4;
                                demon_alive = 0;
                            } else {
                                printf("The demon knocks you to the ground and devours you...\nGAME OVER\n");
                                room = 0;
                            }
                        } else if (choice == 2){
                            room = 3;
                        } else {
                            printf("Invalid choice! Try again.\n");
                        }
                    } else {
                        printf("The kitchen door is locked. You need a key to enter.\n");
                    }
                } else if (choice == 3){
                    room = 1;
                } else {
                    printf("Invalid choice! Try again.\n");
                }
                break;
            case 4:
                printf("You enter the basement. It is dark and damp. You hear strange noises coming from the shadows. Do you continue or go back upstairs? (1 to continue, 2 to go back upstairs)\n");
                scanf("%d", &choice);
                if(choice == 1){
                    if(demon_alive == 1){
                        printf("As you make your way through the darkness, the demon appears before you. What do you do? (1 to fight demon, 2 to run)\n");
                        scanf("%d", &choice);
                        if(choice == 1){
                            int demon_roll = rand() % 10 + 1;
                            if(demon_roll > 5){
                                printf("You defeat the demon and find a chest containing a treasure trove of gold and jewels. You have won the game!\n");
                                room = 0;
                            } else {
                                printf("The demon knocks you to the ground and devours you...\nGAME OVER\n");
                                room = 0;
                            }
                        } else if (choice == 2){
                            room = 3;
                        } else {
                            printf("Invalid choice! Try again.\n");
                        }
                    } else {
                        printf("You find a chest containing a treasure trove of gold and jewels. You have won the game!\n");
                        room = 0;
                    }
                } else if (choice == 2){
                    room = 3;
                } else {
                    printf("Invalid choice! Try again.\n");
                }
                break;
            default:
                break;
        }
    }
    
    return 0;
}