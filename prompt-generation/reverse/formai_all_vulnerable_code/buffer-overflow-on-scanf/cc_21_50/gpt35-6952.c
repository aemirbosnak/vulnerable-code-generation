//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); // seetting random seed

    char choice;
    int count=0, flashlight=0, key=0;
    int ghost_pos, player_pos = 0, steps = 0, doors[3];
    int door1 = 0, door2 = 0, door3 = 0;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tWelcome to the Haunted House Simulator!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("In this game, you will be taking a tour of a haunted house, walking down creepy hallways, opening locked doors, all the while trying not to wake up the ghosts.\n\n");
    printf("Are you ready? (y/n): ");
    scanf("%c", &choice);

    if(choice == 'n' || choice == 'N'){
        printf("\n\n\t\t\t!!!! Thanks for visiting the Haunted House !!!!");
        return 0;
    }

    printf("\n\nGreat! Let's begin..\n You are at door 1 now\n");
    doors[0] = 1;           // setting the door array
    doors[1] = 2;
    doors[2] = 3;

    ghost_pos = doors[rand() % 3];  // Choosing random ghost position

    while(1){
        printf("\nYou are now at door %d, You have been in this haunted house for %d steps.\n", player_pos+1, steps);

        if(player_pos + 1 == ghost_pos){
            printf("\n!!!! You woke up a ghost !!!!\n\n");
            printf("\n\n\t\t\t\t **** Game Over **** \n\n\n");
            break;
        }

        printf("\nDo you want to (O) Open the door or (M) Move to the next door or (Q) Quit the game? ");
        scanf(" %c", &choice);

        if(choice == 'q' || choice == 'Q'){
            printf("\n\n\t\t\t!!!! Thanks for visiting the Haunted House !!!!");
            break;
        }
        else if(choice == 'm' || choice == 'M'){
            player_pos++;
            steps++;
        }
        else if(choice == 'o' || choice == 'O'){

            if(player_pos+1 == 1 && door1 != 1){
                printf("\n\nDoor 1 is Locked, Do you want to use the key? (y/n): ");
                scanf(" %c",&choice);
                if(choice == 'y' || choice == 'Y'){
                    if(key == 0){
                        printf("\nYou do not have the key.\n");
                    }
                    else{
                        door1 = 1;
                        printf("\nYou have unlocked the door.\n");
                    }
                }
            }
            else if(player_pos+1 == 2 && door2 != 1){
                printf("\n\nDoor 2 is Locked, Do you want to use the key? (y/n): ");
                scanf(" %c",&choice);
                if(choice == 'y' || choice == 'Y'){
                    if(key == 0){
                        printf("\nYou do not have the key.\n");
                    }
                    else{
                        door2 = 1;
                        printf("\nYou have unlocked the door.\n");
                    }
                }
            }
            else if(player_pos+1 == 3 && door3 != 1){
                printf("\n\nDoor 3 is Locked, Do you want to use the key? (y/n): ");
                scanf(" %c",&choice);
                if(choice == 'y' || choice == 'Y'){
                    if(key == 0){
                        printf("\nYou do not have the key.\n");
                    }
                    else{
                        door3 = 1;
                        printf("\nYou have unlocked the door.\n");
                    }
                }
            }
            else{
                printf("\n\nThis door is already open\n");
            }

            if(door1 == 1 && door2 == 1 && door3 == 1){
                printf("\n\n\t\tCongratulations! You have successfully completed the Haunted House Simulator without waking any ghosts!\n\n");
                break;
            }
        }

        if(flashlight == 0 && player_pos == 1){
            printf("\n\nYou found a flashlight, use it for better visibility (y/n)? ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y'){
                flashlight = 1;
            }
        }

        if(key == 0 && player_pos == 2){
            printf("\n\nYou found a key, it might be useful (y/n)? ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y'){
                key = 1;
            }
        }
    }
    return 0;
}