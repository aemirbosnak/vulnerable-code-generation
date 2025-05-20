//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void){
    bool left = false;
    bool right = false;
    bool forward = false;
    bool backward = false;
    char input[256];
    
    printf("Enter a command: ");
    scanf("%s", input);
    
    while (true) {
        if (strcmp(input, "left") == 0) {
            left = true;
        } else if (strcmp(input, "right") == 0) {
            right = true;
        } else if (strcmp(input, "forward") == 0) {
            forward = true;
        } else if (strcmp(input, "backward") == 0) {
            backward = true;
        } else if (strcmp(input, "stop") == 0) {
            left = false;
            right = false;
            forward = false;
            backward = false;
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", input);
        }
        if (left) {
            printf("The robot turns left.\n");
        }
        if (right) {
            printf("The robot turns right.\n");
        }
        if (forward) {
            printf("The robot moves forward.\n");
        }
        if (backward) {
            printf("The robot moves backward.\n");
        }
        printf("Enter a command: ");
        scanf("%s", input);
    }
    printf("Exiting program.\n");
    return 0;
}