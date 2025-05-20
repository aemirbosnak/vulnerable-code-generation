//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shape shifting
// An enigmatic C testament to the marvel of smart home automation

#include <stdio.h>
#include <stdlib.h>

// Encapsulation of a household appliance with its current state
typedef struct {
    char name[32];
    int state; // 0 for off, 1 for on
} Appliance;

// Our humble abode, where appliances reside
Appliance house[5] = {
    {"Lights", 0},
    {"Fan", 0},
    {"Heater", 0},
    {"AC", 0},
    {"TV", 0}
};

// Command processor, interpreting user's desires
void processCommand(char *cmd) {
    char appliance[32], action[16];
    sscanf(cmd, "%s %s", appliance, action);
    
    // Traverse the household, seeking the appliance in question
    for (int i = 0; i < 5; i++) {
        if (strcmp(house[i].name, appliance) == 0) {
            if (strcmp(action, "on") == 0) {
                house[i].state = 1;
                printf("%s turned on.\n", appliance);
            } else if (strcmp(action, "off") == 0) {
                house[i].state = 0;
                printf("%s turned off.\n", appliance);
            } else {
                printf("Invalid action: %s\n", action);
            }
            return;
        }
    }
    
    // Appliance not found, report the unfortunate news
    printf("Appliance '%s' not found.\n", appliance);
}

// Main orchestration, where user commands take flight
int main() {
    char cmd[64];
    
    // An eternal loop, ready to serve until the end of time
    while (1) {
        printf("> ");
        fgets(cmd, 64, stdin);
        
        // Exit gracefully when the user so desires
        if (strcmp(cmd, "exit\n") == 0) {
            break;
        }
        
        // Unleash the command processor upon the user's request
        processCommand(cmd);
        
        // A pause for dramatic effect, or simply a brief respite
        sleep(1);
    }
    
    return 0;
}