//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int living_room_light = 0; // lights off
    int living_room_temp = 74; // initial temperature
    int bedroom_light = 0; // lights off
    int bedroom_temp = 70; // initial temperature

    while(1) {
        printf("Enter a command (living room|bedroom|exit): ");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "living room") == 0) {
            printf("Enter a subcommand (light|temp): ");
            char subcommand[10];
            scanf("%s", subcommand);

            if(strcmp(subcommand, "light") == 0) {
                printf("Enter a value (0|1): ");
                int value;
                scanf("%d", &value);

                if(value == 0 || value == 1) {
                    living_room_light = value;
                    printf("Living room lights turned %s\n", value ? "on" : "off");
                } else {
                    printf("Invalid value\n");
                }
            } else if(strcmp(subcommand, "temp") == 0) {
                printf("Enter a value (-10 to 100): ");
                int value;
                scanf("%d", &value);

                if(value >= -10 && value <= 100) {
                    living_room_temp = value;
                    printf("Living room temperature set to %d\n", value);
                } else {
                    printf("Invalid value\n");
                }
            } else {
                printf("Invalid subcommand\n");
            }
        } else if(strcmp(command, "bedroom") == 0) {
            printf("Enter a subcommand (light|temp): ");
            char subcommand[10];
            scanf("%s", subcommand);

            if(strcmp(subcommand, "light") == 0) {
                printf("Enter a value (0|1): ");
                int value;
                scanf("%d", &value);

                if(value == 0 || value == 1) {
                    bedroom_light = value;
                    printf("Bedroom lights turned %s\n", value ? "on" : "off");
                } else {
                    printf("Invalid value\n");
                }
            } else if(strcmp(subcommand, "temp") == 0) {
                printf("Enter a value (-10 to 100): ");
                int value;
                scanf("%d", &value);

                if(value >= -10 && value <= 100) {
                    bedroom_temp = value;
                    printf("Bedroom temperature set to %d\n", value);
                } else {
                    printf("Invalid value\n");
                }
            } else {
                printf("Invalid subcommand\n");
            }
        } else if(strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}