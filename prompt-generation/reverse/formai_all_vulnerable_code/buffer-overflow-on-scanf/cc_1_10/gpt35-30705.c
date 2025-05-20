//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

#define LIVING_ROOM 1
#define KITCHEN 2
#define BEDROOM 3
#define STUDY_ROOM 4

void living_room_lights(int);
void kitchen_lights(int);
void bedroom_lights(int);
void study_room_lights(int);

int main()
{
    int room_num, action_num;
    char action[10];
    printf("Welcome to Sherlock's Smart Home Automation System!\n");

    while(1)
    {
        printf("\nEnter the room number (1 - Living Room, 2 - Kitchen, 3 - Bedroom, 4 - Study Room): ");
        scanf("%d", &room_num);

        printf("\nEnter the action (ON/OFF): ");
        scanf("%s", action);

        if(strcmp(action, "ON") == 0)
        {
            action_num = 1;
        }
        else if(strcmp(action, "OFF") == 0)
        {
            action_num = 0;
        }
        else
        {
            printf("\nInvalid action. Try again.\n");
            continue;
        }

        switch(room_num)
        {
            case LIVING_ROOM:
                living_room_lights(action_num);
                break;

            case KITCHEN:
                kitchen_lights(action_num);
                break;

            case BEDROOM:
                bedroom_lights(action_num);
                break;

            case STUDY_ROOM:
                study_room_lights(action_num);
                break;

            default:
                printf("\nInvalid room number. Try again.");
                break;
        }
    }

    return 0;
}

void living_room_lights(int action)
{
    if(action == 1)
    {
        printf("\nSherlock has turned on the lights in the Living Room.\n");
    }
    else
    {
        printf("\nSherlock has turned off the lights in the Living Room.\n");
    }
}

void kitchen_lights(int action)
{
    if(action == 1)
    {
        printf("\nSherlock has turned on the lights in the Kitchen.\n");
    }
    else
    {
        printf("\nSherlock has turned off the lights in the Kitchen.\n");
    }
}

void bedroom_lights(int action)
{
    if(action == 1)
    {
        printf("\nSherlock has turned on the lights in the Bedroom.\n");
    }
    else
    {
        printf("\nSherlock has turned off the lights in the Bedroom.\n");
    }
}

void study_room_lights(int action)
{
    if(action == 1)
    {
        printf("\nSherlock has turned on the lights in the Study Room.\n");
    }
    else
    {
        printf("\nSherlock has turned off the lights in the Study Room.\n");
    }
}