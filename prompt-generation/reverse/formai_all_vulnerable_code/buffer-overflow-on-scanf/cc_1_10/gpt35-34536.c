//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

int main(){
    printf("Welcome to the Surrealist Traffic Light Controller Program!\n");
    printf("You are about to embark on a journey that will transport you to a world where traffic lights are not just mere signals, but magical entities that possess a power beyond human comprehension.\n");
    printf("Buckle up and hold on tight, for this ride will be unlike any other.\n");

    int choice, current_light;

    printf("\nYou find yourself standing in front of a strange device. It looks like a traffic light controller, but something about it seems off.\n");
    printf("You notice that there are no buttons or switches on the device. Instead, there is a small screen that displays a message:\n");

    printf("\"To activate the traffic lights, you must speak the magic words.\"\n");

    printf("You scratch your head, wondering what the magic words could be. Suddenly, a voice booms from the device:\n");

    printf("\"Say the colors of the lights in alphabetical order.\"\n");

    printf("You take a deep breath and begin:\n");

    printf("Red.\n");
    printf("Yellow.\n");
    printf("Green.\n");

    printf("Suddenly, the device springs to life. The screen lights up and displays a message:\n");

    printf("\"Congratulations, you have unlocked the power of the surreal traffic light controller. What would you like to do?\"\n");

    while(1){
        printf("\n1. Change traffic light color.\n");
        printf("2. Exit program.\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nWhich traffic light color would you like to change?\n");
                printf("1. Red\n");
                printf("2. Yellow\n");
                printf("3. Green\n");

                printf("Your choice: ");
                scanf("%d", &current_light);

                switch(current_light){
                    case RED_LIGHT:
                        printf("\nThe red light begins to pulse and glow.\n");
                        printf("Suddenly, a portal opens up in front of you.\n");
                        printf("You step through the portal and find yourself in a strange and wondrous world.\n");
                        break;

                    case YELLOW_LIGHT:
                        printf("\nThe yellow light begins to flicker and shimmer.\n");
                        printf("Suddenly, you feel as though you are floating in mid-air.\n");
                        printf("A strange force surrounds you, lifting you up and carrying you to places unknown.\n");
                        break;

                    case GREEN_LIGHT:
                        printf("\nThe green light begins to whirl and spin.\n");
                        printf("Suddenly, you find yourself hurtling through space and time.\n");
                        printf("You travel to distant planets and explore the wonders of the universe.\n");
                        break;

                    default:
                        printf("\nInvalid choice. Please try again.\n");
                        break;
                }

                break;

            case 2:
                printf("\nThank you for exploring the surreal traffic light controller program.\n");
                printf("We hope you enjoyed your journey into the unknown.\n");
                printf("Goodbye!\n");

                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}