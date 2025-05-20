//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to turn on light
void turn_on_light()
{
    printf("The light is on.\n");
}

// function to turn off light
void turn_off_light()
{
    printf("The light is off.\n");
}

// function to dim light
void dim_light(int level)
{
    printf("The light is dimmed to level %d.\n", level);
}

// function to brighten light
void brighten_light(int level)
{
    printf("The light is brightened to level %d.\n", level);
}

int main()
{
    bool is_light_on = false;
    int light_level = 0;

    // loop to control smart home light
    while (true)
    {
        char input[10];

        // prompt user to input command
        printf("Enter command (on, off, dim, brighten): ");
        scanf("%s", input);

        // check input command and perform action accordingly
        if (strcmp(input, "on") == 0)
        {
            turn_on_light();
            is_light_on = true;
        }
        else if (strcmp(input, "off") == 0)
        {
            turn_off_light();
            is_light_on = false;
            light_level = 0;
        }
        else if (strcmp(input, "dim") == 0)
        {
            if (!is_light_on)
            {
                printf("Cannot dim light when it is off.\n");
            }
            else
            {
                int level;
                printf("Enter level (1-5): ");
                scanf("%d", &level);
                dim_light(level);
                light_level = level;
            }
        }
        else if (strcmp(input, "brighten") == 0)
        {
            if (!is_light_on)
            {
                printf("Cannot brighten light when it is off.\n");
            }
            else
            {
                int level;
                printf("Enter level (1-5): ");
                scanf("%d", &level);
                brighten_light(level);
                light_level = level;
            }
        }
        else
        {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}