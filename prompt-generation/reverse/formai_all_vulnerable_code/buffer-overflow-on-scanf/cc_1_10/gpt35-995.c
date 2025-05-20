//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define room constants
#define ROOM_KITCHEN 1
#define ROOM_LIVING 2
#define ROOM_BEDROOM 3

// Define function prototypes
void show_menu();
int get_room_selection();
int get_light_selection();
void control_light(int room, int light, bool state);
void print_state(int state);

int main()
{
    // Initialize light states for each room
    int kitchen_lights = LIGHT_OFF;
    int living_lights = LIGHT_OFF;
    int bedroom_lights = LIGHT_OFF;

    bool running = true;

    while (running)
    {
        // Display menu
        show_menu();

        // Get user's selection
        int room = get_room_selection();
        int light = get_light_selection();

        // Control selected light
        switch (room)
        {
            case ROOM_KITCHEN:
                control_light(kitchen_lights, light, !kitchen_lights);
                kitchen_lights = !kitchen_lights;
                break;
            case ROOM_LIVING:
                control_light(living_lights, light, !living_lights);
                living_lights = !living_lights;
                break;
            case ROOM_BEDROOM:
                control_light(bedroom_lights, light, !bedroom_lights);
                bedroom_lights = !bedroom_lights;
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }

        // Ask if user wants to control another light
        char response[10];
        printf("Do you want to control another light? (y/n)\n");
        scanf("%s", response);

        // Check response
        if (strcmp(response, "n") == 0)
        {
            running = false;
        }
    }

    return 0;
}

void show_menu()
{
    printf("Select a room:\n");
    printf("%d. Kitchen\n", ROOM_KITCHEN);
    printf("%d. Living Room\n", ROOM_LIVING);
    printf("%d. Bedroom\n", ROOM_BEDROOM);
}

int get_room_selection()
{
    int selection;
    printf("Enter a room number: ");
    scanf("%d", &selection);
    return selection;
}

int get_light_selection()
{
    int selection;
    printf("Enter a light number (1 or 2): ");
    scanf("%d", &selection);
    return selection;
}

void control_light(int room, int light, bool state)
{
    printf("Turning ");

    if (state == LIGHT_ON)
    {
        printf("on ");
    }
    else
    {
        printf("off ");
    }

    printf("light %d in room %d.\n", light, room);
}

void print_state(int state)
{
    if (state == LIGHT_ON)
    {
        printf("ON");
    }
    else
    {
        printf("OFF");
    }
}