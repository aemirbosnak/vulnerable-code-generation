//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 10
#define MAX_MESSAGE_LEN 100

typedef struct {
    char username[20];
    int x_pos;
    int y_pos;
} user_t;

void broadcast_message(user_t users[], int num_users, char message[MAX_MESSAGE_LEN]) {
    int i;
    for(i = 0; i < num_users; i++) {
        printf("[%s]: %s\n", users[i].username, message);
    }
}

int main() {
    user_t users[MAX_USERS];
    char message[MAX_MESSAGE_LEN];
    bool end_program = false;
    int num_users = 0;
    int i;
    
    // get username and initial position for each user
    for(i = 0; i < MAX_USERS && !end_program; i++) {
        user_t new_user;
        printf("Enter username (or 'quit' to exit): ");
        scanf("%s", new_user.username);
        if(strcmp(new_user.username, "quit") == 0) {
            end_program = true;
        } else {
            new_user.x_pos = 0;
            new_user.y_pos = 0;
            users[num_users] = new_user;
            num_users++;
        }
    }
    
    // allow users to move around and chat
    while(!end_program) {
        printf("[COMMANDS]\n");
        printf("type 'move <direction>' to move (e.g. 'move left', 'move up')\n");
        printf("type 'chat <message>' to send a chat message\n");
        printf("type 'quit' to exit\n\n");
        
        char input[100];
        scanf("%s", input);
        if(strcmp(input, "quit") == 0) {
            end_program = true;
        } else if(strncmp(input, "move", 4) == 0) {
            // get direction to move from input
            char direction[10];
            sscanf(input, "move %s", direction);
            
            // move user in that direction
            int dx = 0, dy = 0;
            if(strcmp(direction, "left") == 0) {
                dx = -1;
            } else if(strcmp(direction, "right") == 0) {
                dx = 1;
            } else if(strcmp(direction, "up") == 0) {
                dy = -1;
            } else if(strcmp(direction, "down") == 0) {
                dy = 1;
            } else {
                printf("Invalid direction: %s\n", direction);
            }
            for(i = 0; i < num_users; i++) {
                user_t *user = &users[i];
                user->x_pos += dx;
                user->y_pos += dy;
                printf("%s moved %d units in x direction and %d units in y direction\n", user->username, dx, dy);
            }
        } else if(strncmp(input, "chat", 4) == 0) {
            // get message to send from input
            char message[MAX_MESSAGE_LEN];
            sscanf(input, "chat %[^\n]", message);
            
            // broadcast message to all users
            broadcast_message(users, num_users, message);
        } else {
            printf("Invalid command: %s\n", input);
        }
    }
    
    return 0;
}