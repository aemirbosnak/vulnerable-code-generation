//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool player_has_key = false;
    bool ghost_appeared = false;
    bool door_locked = true;
    int player_choice = 0;
    int room_number = 1;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are in room %d.\n", room_number);
    
    do {
        switch(room_number) {
            case 1:
                printf("You are in the living room.\n");
                printf("You see a key on the table.\n");
                printf("What do you want to do? Press 1 to take the key, 2 to move to the next room: ");
                scanf("%d", &player_choice);
                if(player_choice == 1) {
                    player_has_key = true;
                    printf("You picked up the key.\n");
                } else {
                    printf("You move to the next room.\n");
                    room_number++;
                }
                break;
            
            case 2:
                printf("You are in the hallway.\n");
                printf("You hear a faint whispering sound.\n");
                printf("What do you want to do? Press 1 to investigate the sound, 2 to move to the next room: ");
                scanf("%d", &player_choice);
                if(player_choice == 1) {
                    if(player_has_key) {
                        printf("You use the key to open the door and find a safe room.\n");
                        printf("Congratulations, you survived!\n");
                        door_locked = false;
                        break;
                    } else {
                        printf("You approach the sound but suddenly a ghost appears!\n");
                        printf("What do you want to do? Press 1 to run back to the living room: ");
                        scanf("%d", &player_choice);
                        if(player_choice == 1) {
                            printf("You run back to the living room.\n");
                            room_number--;
                            ghost_appeared = true;
                        }
                    }
                } else {
                    printf("You move to the next room.\n");
                    room_number++;
                }
                break;
            
            case 3:
                printf("You are in the basement.\n");
                printf("You hear a loud banging noise.\n");
                printf("What do you want to do? Press 1 to investigate the noise, 2 to move to the next room: ");
                scanf("%d", &player_choice);
                if(player_choice == 1) {
                    if(ghost_appeared) {
                        printf("You investigate the noise and find nothing.\n");
                        printf("You move to the next room.\n");
                        room_number++;
                    } else {
                        printf("You investigate the noise and suddenly a ghost appears!\n");
                        printf("What do you want to do? Press 1 to run back to the living room: ");
                        scanf("%d", &player_choice);
                        if(player_choice == 1) {
                            printf("You run back to the living room.\n");
                            room_number = 1;
                            ghost_appeared = false;
                        }
                    }
                } else {
                    printf("You move to the next room.\n");
                    room_number++;
                }
                break;
            
            default:
                printf("You are lost in the haunted house. Game over.\n");
                break;
        }
    } while(door_locked);
    
    return 0;
}