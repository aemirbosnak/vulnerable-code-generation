//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIGHTS 10

struct Light {
    int id;
    int brightness;
    int color;
    char state[10];
};

int main() {
    struct Light lights[MAX_LIGHTS];
    int num_lights = 0;

    srand(time(NULL));

    printf("Welcome to the Surrealist Smart Home Light Control System!\n\n");

    while (1) {
        printf("What would you like to do? (add, remove, toggle, randomize, quit): ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            if (num_lights < MAX_LIGHTS) {
                lights[num_lights].id = num_lights + 1;
                lights[num_lights].brightness = 100;
                lights[num_lights].color = rand() % 256;
                strcpy(lights[num_lights].state, "on");
                printf("Light %d added!\n\n", lights[num_lights].id);
                num_lights++;
            } else {
                printf("Sorry, you have reached the maximum number of lights allowed.\n\n");
            }
        }
        else if (strcmp(input, "remove") == 0) {
            if (num_lights > 0) {
                int id;
                printf("Please enter the id of the light you would like to remove: ");
                scanf("%d", &id);
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == id) {
                        for (int j = i; j < num_lights - 1; j++) {
                            lights[j] = lights[j+1];
                            lights[j].id--;
                        }
                        num_lights--;
                        printf("Light %d removed!\n\n", id);
                        break;
                    }
                }
            } else {
                printf("Sorry, there are no lights to remove.\n\n");
            }
        }
        else if (strcmp(input, "toggle") == 0) {
            if (num_lights > 0) {
                int id;
                printf("Please enter the id of the light you would like to toggle: ");
                scanf("%d", &id);
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == id) {
                        if (strcmp(lights[i].state, "on") == 0) {
                            strcpy(lights[i].state, "off");
                        } else {
                            strcpy(lights[i].state, "on");
                        }
                        printf("Light %d toggled!\n\n", id);
                        break;
                    }
                }
            } else {
                printf("Sorry, there are no lights to toggle.\n\n");
            }
        }
        else if (strcmp(input, "randomize") == 0) {
            if (num_lights > 0) {
                printf("Randomizing all lights...\n\n");
                for (int i = 0; i < num_lights; i++) {
                    int random_brightness = rand() % 101;
                    int random_color = rand() % 256;
                    lights[i].brightness = random_brightness;
                    lights[i].color = random_color;
                }
            } else {
                printf("Sorry, there are no lights to randomize.\n\n");
            }
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Thank you for using the Surrealist Smart Home Light Control System!\n");
            break;
        }
        else {
            printf("Sorry, that is not a valid command.\n\n");
        }
    }

    return 0;
}