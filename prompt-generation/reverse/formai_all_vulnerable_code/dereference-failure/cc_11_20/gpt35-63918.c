//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main()
{
    int light1_service = 0;
    int light2_service = 0;
    int light3_service = 0;

    while (1)
    {
        char operation[50];
        printf("Enter Operation (ex. turn on light1): ");
        fgets(operation, 50, stdin);

        // Convert the operation to lowercase
        int i = 0;
        while (operation[i] != '\0')
        {
            operation[i] = tolower(operation[i]);
            i++;
        }

        // Parse the operation
        char *token = strtok(operation, " ");
        char *action = token;
        token = strtok(NULL, " ");
        char *light = token;

        // Turn on / off lights based on the operation
        if (strcmp(action, "turn") == 0)
        {
            token = strtok(NULL, " ");
            char *status = token;
            if (strcmp(status, "on\n") == 0)
            {
                if (strcmp(light, "light1\n") == 0)
                {
                    light1_service = 1;
                    printf("Light1 is turned on.\n");
                }
                else if (strcmp(light, "light2\n") == 0)
                {
                    light2_service = 1;
                    printf("Light2 is turned on.\n");
                }
                else if (strcmp(light, "light3\n") == 0)
                {
                    light3_service = 1;
                    printf("Light3 is turned on.\n");
                }
                else
                {
                    printf("Invalid light input.\n");
                }
            }
            else if (strcmp(status, "off\n") == 0)
            {
                if (strcmp(light, "light1\n") == 0)
                {
                    light1_service = 0;
                    printf("Light1 is turned off.\n");
                }
                else if (strcmp(light, "light2\n") == 0)
                {
                    light2_service = 0;
                    printf("Light2 is turned off.\n");
                }
                else if (strcmp(light, "light3\n") == 0)
                {
                    light3_service = 0;
                    printf("Light3 is turned off.\n");
                }
                else
                {
                    printf("Invalid light input.\n");
                }
            }
        }

        // Check the status of lights based on the operation
        else if (strcmp(action, "check") == 0 && strcmp(light, "status\n") == 0)
        {
            printf("Light1 is %s\n", light1_service ? "on" : "off");
            printf("Light2 is %s\n", light2_service ? "on" : "off");
            printf("Light3 is %s\n", light3_service ? "on" : "off");
        }

        // Invalid input
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}