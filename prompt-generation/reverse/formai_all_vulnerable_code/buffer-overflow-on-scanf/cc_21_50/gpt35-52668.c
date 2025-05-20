//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    // Welcome message
    printf("Welcome to the Surrealist Adventure Game!\n");
    printf("You wake up in a room that is completely dark. What do you do?\n");
    
    // Variables for player input and game state
    char input[100];
    bool hasKey = false;
    bool hasMatches = false;
    bool hasFlashlight = false;
    bool isDoorLocked = true;
    bool isRoomOnFire = false;
    
    // Game loop
    while (true) {
        printf("> ");
        scanf("%s", input);
        
        // Check player input and update game state accordingly
        if (strcmp(input, "look") == 0) {
            printf("You are in a dark room with no visible exits. You see a faint light coming from under the door.\n");
        } else if ((strcmp(input, "open") == 0) && (isDoorLocked == true) && (hasKey == true)) {
            printf("You use the key to unlock the door and it creaks open. You can now see outside the room.\n");
            isDoorLocked = false;
        } else if ((strcmp(input, "open") == 0) && (isDoorLocked == true)) {
            printf("The door is locked.\n");
        } else if ((strcmp(input, "take") == 0) && (isRoomOnFire == false)) {
            printf("Take what?\n");
        } else if ((strcmp(input, "take") == 0) && (isRoomOnFire == true)) {
            printf("The room is on fire! You can't take anything.\n");
        } else if ((strcmp(input, "take") == 0) && (strcmp("matches", input) == 0)) {
            printf("You take the matches.\n");
            hasMatches = true;
        } else if ((strcmp(input, "take") == 0) && (strcmp("key", input) == 0)) {
            printf("You take the key.\n");
            hasKey = true;
        } else if ((strcmp(input, "take") == 0) && (strcmp("flashlight", input) == 0) && (hasMatches == true)) {
            printf("You take the flashlight.\n");
            hasFlashlight = true;
        } else if ((strcmp(input, "use") == 0) && (strcmp("matches", input) == 0)) {
            printf("You light a match and suddenly the whole room is on fire! You need to get out of here!\n");
            isRoomOnFire = true;
        } else if ((strcmp(input, "use") == 0) && (strcmp("flashlight", input) == 0) && (isRoomOnFire == false)) {
            printf("The flashlight doesn't work without batteries.\n");
        } else if ((strcmp(input, "use") == 0) && (strcmp("flashlight", input) == 0) && (isRoomOnFire == true)) {
            printf("You turn on the flashlight and see the way out. You escape the burning room and the game is over. Congratulations!\n");
            return 0;
        } else {
            printf("I don't understand that command.\n");
        }
    }
}