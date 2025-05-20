//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_rooms = 10;
    int current_room = 1;
    int has_key = 0;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in room 1.\n");
    
    while (current_room != num_rooms) {
        int direction = rand() % 2;
        int next_room;
        
        if (direction == 0) {
            next_room = current_room + 1;
        } else {
            next_room = current_room - 1;
        }
        
        printf("Do you want to go to room %d? (y/n)\n", next_room);
        char choice;
        scanf("%c", &choice);
        getchar();
        
        if (choice == 'y') {
            printf("You enter room %d...\n", next_room);
            
            if (next_room == 3 || next_room == 7) {
                printf("You found a key!\n");
                has_key = 1;
            } else if (next_room == 5) {
                if (has_key) {
                    printf("You use the key to unlock the door and enter the secret room! You win!\n");
                    return 0;
                } else {
                    printf("The door is locked and you don't have the key...\n");
                }
            }
            
            current_room = next_room;
        } else {
            printf("You stay in room %d.\n", current_room);
        }
    }
    
    printf("You've explored all the rooms but haven't found the secret room yet. Game Over.\n");
    return 0;
}