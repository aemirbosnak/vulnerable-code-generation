//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* This program simulates a Smart Home Automation system where the user can control devices such as lights, air conditioner, and door locks using their computer or phone. */

// Struct to represent a device
struct Device 
{
    bool on;
    int brightness;
};

// Function to turn on/off the device
void switchDevice(struct Device *d) 
{
    d->on = !d->on;
}

// Function to set the brightness of the device
void setBrightness(struct Device *d, int b) 
{
    if (d->on) 
    {
        d->brightness = b;
    } 
    else 
    {
        printf("Device is off, turn it on to adjust brightness.\n");
    }
}

int main() 
{
    // Initialize devices
    struct Device light = {false, 0};
    struct Device ac = {false, 0};
    struct Device door = {false, 0};

    // User menu to control devices
    char option;
    do 
    {
        printf("\n");
        printf("Select an option:\n\n");
        printf("1. Turn on/off Light\n");
        printf("2. Adjust Light brightness\n");
        printf("3. Turn on/off Air Conditioner\n");
        printf("4. Adjust Air Conditioner temperature\n");
        printf("5. Lock/unlock Door\n");
        printf("6. Exit\n");
        printf("\n");

        scanf(" %c", &option);

        switch (option) 
        {
            case '1':
                printf("Turning Light ");
                switchDevice(&light);
                printf("%s\n", light.on ? "on" : "off");
                break;

            case '2':
                printf("Adjust Light brightness (0-100): ");
                int lb;
                scanf("%d", &lb);
                setBrightness(&light, lb);
                printf("Light brightness set to %d\n", light.brightness);
                break;

            case '3':
                printf("Turning Air Conditioner ");
                switchDevice(&ac);
                printf("%s\n", ac.on ? "on" : "off");
                break;

            case '4':
                if (ac.on) 
                {
                    printf("Adjust Air Conditioner temperature (16-30): ");
                    int at;
                    scanf("%d", &at);
                    if (at < 16 || at > 30) 
                    {
                        printf("Invalid temperature.\n");
                    } 
                    else 
                    {
                        printf("Air Conditioner temperature set to %d\n", at);
                    }
                } 
                else 
                {
                    printf("Air Conditioner is off, turn it on to adjust temperature.\n");
                }
                break;

            case '5':
                printf("Locking Door ");
                switchDevice(&door);
                printf("%s\n", door.on ? "on" : "off");
                break;

            case '6':
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option, please select again.\n");
        }

    } while (option != '6');

    return 0;
}