#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_COMMAND_LENGTH 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Enter drone command: ");
    scanf("%s", command);

    if (command[0] == 't') {
        if (command[1] == 'a' && command[2] == 'k' && command[3] == 'e' && command[4] == 'o' && command[5] == 'f') {
            printf("Drone taking off.\n");
        } else if (command[1] == 'l' && command[2] == 'a' && command[3] == 'v' && command[4] == 'e' && command[5] == 'r' && command[6] == 't' && command[7] == 'o' && command[8] == 'w') {
            printf("Drone landing.\n");
        }
    } else if (command[0] == 'p') {
        if (command[1] == 'i' && command[2] == 'd' && command[3] == 'g' && command[4] == 'e' && command[5] == 'n' && command[6] == 'g') {
            printf("Drone hovering.\n");
        } else if (command[1] == 'o' && command[2] == 'v' && command[3] == 'e' && command[4] == 'r' && command[5] == ' ' && command[6] == '+' && command[7] == 'x' && command[8] == 'y' && command[9] == 'z') {
            printf("Drone moving over x, y, z coordinates.\n");
        }
    }

    return 0;
}
