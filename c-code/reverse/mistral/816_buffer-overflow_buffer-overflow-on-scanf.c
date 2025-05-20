#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void controlDevice(char *command) {
    int i;
    for(i = 0; i < strlen(command); i++) {
        if(command[i] == 'o' && command[i+1] == 'v' && command[i+2] == 'e' && command[i+3] == 'r') {
            printf("Turning on the TV.\n");
        } else if(command[i] == 'o' && command[i+1] == 'f' && command[i+2] == 'f' && command[i+3] == ' ') {
            printf("Turning off the fan.\n");
        } else if(command[i] == 's' && command[i+1] == 'e' && command[i+2] == 't' && command[i+3] == ' ') {
            printf("Setting the temperature.\n");
        } else {
            printf("Invalid command.\n");
        }
    }
}

int main() {
    char command[100];
    printf("Enter command: ");
    scanf("%s", command);
    controlDevice(command);
    return 0;
}
