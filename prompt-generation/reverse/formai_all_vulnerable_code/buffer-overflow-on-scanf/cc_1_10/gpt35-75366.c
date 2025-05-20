//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_OF_LIGHTS 5

struct Light
{
    char name[20];
    bool isOn;
};

void switchOnLight(struct Light *light)
{
    light->isOn = true;
    printf("%s is switched on.\n", light->name);
}

void switchOffLight(struct Light *light)
{
    light->isOn = false;
    printf("%s is switched off.\n", light->name);
}

int main()
{
    struct Light lights[NUM_OF_LIGHTS] = {
        {"Living Room Light", true},
        {"Kitchen Light", false},
        {"Bedroom Light 1", true},
        {"Bedroom Light 2", false},
        {"Bathroom Light", true},
    };

    printf("Welcome to Smart Home Light Control Program!\n");

    int choice = 1;

    while (choice != 0)
    {
        printf("\nCurrent status of lights\n");

        for (int i = 0; i < NUM_OF_LIGHTS; i++)
        {
            if (lights[i].isOn)
            {
                printf("%s - ON\n", lights[i].name);
            }
            else
            {
                printf("%s - OFF\n", lights[i].name);
            }
        }

        printf("\nEnter your choice:\n");
        printf("1. Switch on a light\n");
        printf("2. Switch off a light\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int lightChoice;
            printf("Enter light number (1-5): ");
            scanf("%d", &lightChoice);

            if (lightChoice < 1 || lightChoice > 5)
            {
                printf("Invalid choice. Try again.\n");
                continue;
            }

            switchOnLight(&lights[lightChoice - 1]);
        }
        else if (choice == 2)
        {
            int lightChoice;
            printf("Enter light number (1-5): ");
            scanf("%d", &lightChoice);

            if (lightChoice < 1 || lightChoice > 5)
            {
                printf("Invalid choice. Try again.\n");
                continue;
            }

            switchOffLight(&lights[lightChoice - 1]);
        }
        else if (choice != 0)
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Thank you for using Smart Home Light Control Program!\n");

    return 0;
}