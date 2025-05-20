//Gemma-7B DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DRONE_PIN 3

int main()
{
    system("/bin/clear");
    char cmd[20];
    printf("Welcome to the Drone Commander!\n");
    printf("Enter 'help' for instructions.\n");

    while (1)
    {
        printf("Enter your command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "help") == 0)
        {
            printf("Available commands:\n");
            printf("  move forward\n");
            printf("  move back\n");
            printf("  turn right\n");
            printf("  turn left\n");
            printf("  land\n");
            printf("  status\n");
        }
        else if (strcmp(cmd, "move forward") == 0)
        {
            system("gpio -o pinset 1 5");
            sleep(1);
            system("gpio -o pinclear 1 5");
        }
        else if (strcmp(cmd, "move back") == 0)
        {
            system("gpio -o pinset 1 6");
            sleep(1);
            system("gpio -o pinclear 1 6");
        }
        else if (strcmp(cmd, "turn right") == 0)
        {
            system("gpio -o pinset 1 7");
            sleep(1);
            system("gpio -o pinclear 1 7");
        }
        else if (strcmp(cmd, "turn left") == 0)
        {
            system("gpio -o pinset 1 8");
            sleep(1);
            system("gpio -o pinclear 1 8");
        }
        else if (strcmp(cmd, "land") == 0)
        {
            system("gpio -o pinset 1 2");
            sleep(1);
            system("gpio -o pinclear 1 2");
        }
        else if (strcmp(cmd, "status") == 0)
        {
            system("gpio read");
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}