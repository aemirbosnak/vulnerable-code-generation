//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10

int lights[MAX_LIGHTS];

void print_lights(int num_lights)
{
    printf("Lights: ");
    for(int i=0; i<num_lights; i++)
    {
        printf("%d ", lights[i]);
    }
    printf("\n");
}

// Recursive function to turn on a light
void turn_on_light(int num_lights, int light_num)
{
    // Base case
    if(light_num == num_lights)
    {
        printf("Light %d is already on.\n", light_num);
        print_lights(num_lights);
        return;
    }
    
    // Recursive case
    if(!lights[light_num])
    {
        printf("Turning on light %d.\n", light_num);
        lights[light_num] = 1;
    }
    else
    {
        printf("Light %d is already on.\n", light_num);
    }
    print_lights(num_lights);
    turn_on_light(num_lights, light_num+1);
}

// Recursive function to turn off a light
void turn_off_light(int num_lights, int light_num)
{
    // Base case
    if(light_num == num_lights)
    {
        printf("Light %d is already off.\n", light_num);
        print_lights(num_lights);
        return;
    }
    
    // Recursive case
    if(lights[light_num])
    {
        printf("Turning off light %d.\n", light_num);
        lights[light_num] = 0;
    }
    else
    {
        printf("Light %d is already off.\n", light_num);
    }
    print_lights(num_lights);
    turn_off_light(num_lights, light_num+1);
}

int main()
{
    int choice, num_lights, light_num;
    
    printf("Enter the number of lights: ");
    scanf("%d", &num_lights);
    
    // Initialize all lights to off
    for(int i=0; i<num_lights; i++)
    {
        lights[i] = 0;
    }
    
    do
    {
        printf("\n1. Turn on light\n2. Turn off light\n0. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter the light number to turn on: ");
                scanf("%d", &light_num);
                turn_on_light(num_lights, light_num);
                break;
            case 2:
                printf("Enter the light number to turn off: ");
                scanf("%d", &light_num);
                turn_off_light(num_lights, light_num);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);
    
    return 0;
}