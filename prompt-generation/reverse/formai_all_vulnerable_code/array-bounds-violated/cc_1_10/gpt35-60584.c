//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int brightness = 100;
    char command[50];
    char input[20];

    printf("Welcome to Smart Light Control!\n");
    while(1) {
        printf("Current brightness: %d%\nEnter a command: ", brightness);
        fgets(input, 20, stdin);
        input[strlen(input) - 1] = '\0';

        if(strcmp(input, "on") == 0) {
            brightness = 100;
            printf("Light turned on!\n");
        }
        else if(strcmp(input, "off") == 0) {
            brightness = 0;
            printf("Light turned off!\n");
        }
        else if(strcmp(input, "dim") == 0) {
            brightness -= 10;
            if(brightness < 0) {
                brightness = 0;
            }
            printf("Light dimmed!\n");
        }
        else if(strcmp(input, "brighten") == 0) {
            brightness += 10;
            if(brightness > 100) {
                brightness = 100;
            }
            printf("Light brightened!\n");
        }
        else if(strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command\n");
        }

        sprintf(command, "sudo light -S %d", brightness);
        system(command);
        sleep(1);
        system("clear");
    }

    return 0;
}