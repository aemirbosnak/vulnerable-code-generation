//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int light_status = 0;
    int light_change = 0;
    int light_request = 0;

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Please enter your command:\n");
    scanf("%s", input);

    while (strcmp(input, "quit")!= 0) {
        if (strcmp(input, "on") == 0) {
            if (light_status == 0) {
                printf("Lights turned on.\n");
                light_status = 1;
            } else {
                printf("Lights are already on.\n");
            }
        } else if (strcmp(input, "off") == 0) {
            if (light_status == 1) {
                printf("Lights turned off.\n");
                light_status = 0;
            } else {
                printf("Lights are already off.\n");
            }
        } else if (strcmp(input, "toggle") == 0) {
            if (light_status == 0) {
                printf("Lights turned on.\n");
                light_status = 1;
            } else {
                printf("Lights turned off.\n");
                light_status = 0;
            }
        } else if (strcmp(input, "schedule") == 0) {
            printf("Please enter the schedule (24-hour format):\n");
            scanf("%s", input);
            if (light_status == 0) {
                printf("Lights scheduled to turn on at %s.\n", input);
                light_change = 1;
            } else {
                printf("Lights scheduled to turn off at %s.\n", input);
                light_change = 2;
            }
        } else if (strcmp(input, "cancel") == 0) {
            if (light_change == 1) {
                printf("Lights turn on schedule canceled.\n");
                light_change = 0;
            } else if (light_change == 2) {
                printf("Lights turn off schedule canceled.\n");
                light_change = 0;
            } else {
                printf("No schedule to cancel.\n");
            }
        } else if (strcmp(input, "request") == 0) {
            printf("Please enter your request:\n");
            scanf("%s", input);
            if (strcmp(input, "status") == 0) {
                if (light_status == 0) {
                    printf("Lights are off.\n");
                } else {
                    printf("Lights are on.\n");
                }
            } else if (strcmp(input, "schedule") == 0) {
                if (light_change == 0) {
                    printf("No schedule set.\n");
                } else {
                    printf("Lights scheduled to %s at %s.\n",
                           (light_change == 1)? "turn on" : "turn off",
                           input);
                }
            } else {
                printf("Invalid request.\n");
            }
        } else {
            printf("Invalid command.\n");
        }

        printf("Enter your next command:\n");
        scanf("%s", input);
    }

    return 0;
}