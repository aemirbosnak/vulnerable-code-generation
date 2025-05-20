//FormAI DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[20];
    int brightness;
    int color_temp;
    int is_on;
} Light;

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;

    printf("Welcome to your smart home light control system!\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a light\n");
        printf("2. Remove a light\n");
        printf("3. View all lights\n");
        printf("4. Edit a light\n");
        printf("5. Turn on/off a light\n");
        printf("6. Set brightness for a light\n");
        printf("7. Set color temperature for a light\n");
        printf("8. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {   // add a light
                if (num_lights == MAX_LIGHTS) {
                    printf("Error: maximum number of lights reached.\n");
                    break;
                }

                Light new_light;
                new_light.id = num_lights + 1;

                printf("Enter the name of the light (20 characters or less):\n");
                scanf("%s", new_light.name);

                printf("Enter the brightness of the light (0-100):\n");
                scanf("%d", &new_light.brightness);

                printf("Enter the color temperature of the light (0-100):\n");
                scanf("%d", &new_light.color_temp);

                new_light.is_on = 0;

                lights[num_lights] = new_light;
                num_lights++;

                printf("Light added successfully!\n\n");
                break;
            }

            case 2: {   // remove a light
                if (num_lights == 0) {
                    printf("Error: no lights to remove.\n");
                    break;
                }

                printf("Which light would you like to remove (enter the ID number)?\n");

                int remove_id;
                scanf("%d", &remove_id);

                int index_to_remove = -1;
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == remove_id) {
                        index_to_remove = i;
                        break;
                    }
                }

                if (index_to_remove == -1) {
                    printf("Error: no light with that ID found.\n");
                } else {
                    for (int i = index_to_remove + 1; i < num_lights; i++) {
                        lights[i-1] = lights[i];
                        lights[i-1].id--;
                    }
                    num_lights--;
                    printf("Light removed successfully!\n\n");
                }

                break;
            }

            case 3: {   // view all lights
                if (num_lights == 0) {
                    printf("No lights found.\n");
                } else {
                    printf("ID | Name                 | Brightness | Color Temp | On/\n");
                    printf("   |                      |           |            | Off\n");
                    for (int i = 0; i < num_lights; i++) {
                        Light curr = lights[i];
                        printf("%2d | ", curr.id);
                        printf("%-20s | ", curr.name);
                        printf("%-10d | ", curr.brightness);
                        printf("%-10d | ", curr.color_temp);
                        if (curr.is_on) {
                            printf("On\n");
                        } else {
                            printf("Off\n");
                        }
                    }
                }
                printf("\n");
                break;
            }

            case 4: {   // edit a light
                if (num_lights == 0) {
                    printf("Error: no lights to edit.\n");
                    break;
                }

                printf("Which light would you like to edit (enter the ID number)?\n");

                int edit_id;
                scanf("%d", &edit_id);

                Light *edit_light = NULL;
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == edit_id) {
                        edit_light = &lights[i];
                        break;
                    }
                }

                if (edit_light == NULL) {
                    printf("Error: no light with that ID found.\n");
                } else {
                    printf("What would you like to edit?\n");
                    printf("1. Name\n");
                    printf("2. Brightness\n");
                    printf("3. Color temperature\n");

                    int edit_choice;
                    scanf("%d", &edit_choice);

                    switch (edit_choice) {
                        case 1: {
                            printf("Enter the new name of the light:\n");
                            scanf("%s", edit_light->name);
                            printf("Name updated successfully!\n\n");
                            break;
                        }
                        case 2: {
                            printf("Enter the new brightness level (0-100):\n");
                            scanf("%d", &edit_light->brightness);
                            printf("Brightness updated successfully!\n\n");
                            break;
                        }
                        case 3: {
                            printf("Enter the new color temperature (0-100):\n");
                            scanf("%d", &edit_light->color_temp);
                            printf("Color temperature updated successfully!\n\n");
                            break;
                        }
                        default: {
                            printf("Error: invalid option selected.\n\n");
                            break;
                        }
                    }
                }

                break;
            }

            case 5: {   // turn on/off a light
                if (num_lights == 0) {
                    printf("Error: no lights to turn on/off.\n");
                    break;
                }

                printf("Which light would you like to turn on/off (enter the ID number)?\n");

                int onoff_id;
                scanf("%d", &onoff_id);

                Light *onoff_light = NULL;
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == onoff_id) {
                        onoff_light = &lights[i];
                        break;
                    }
                }

                if (onoff_light == NULL) {
                    printf("Error: no light with that ID found.\n");
                } else {
                    if (onoff_light->is_on) {
                        onoff_light->is_on = 0;
                        printf("Light turned off successfully!\n\n");
                    } else {
                        onoff_light->is_on = 1;
                        printf("Light turned on successfully!\n\n");
                    }
                }

                break;
            }

            case 6: {   // set brightness for a light
                if (num_lights == 0) {
                    printf("Error: no lights to set brightness for.\n");
                    break;
                }

                printf("Which light would you like to set the brightness for (enter the ID number)?\n");

                int brightness_id;
                scanf("%d", &brightness_id);

                Light *brightness_light = NULL;
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == brightness_id) {
                        brightness_light = &lights[i];
                        break;
                    }
                }

                if (brightness_light == NULL) {
                    printf("Error: no light with that ID found.\n");
                } else {
                    printf("Enter the new brightness level (0-100):\n");
                    scanf("%d", &brightness_light->brightness);
                    printf("Brightness set successfully!\n\n");
                }

                break;
            }

            case 7: {   // set color temperature for a light
                if (num_lights == 0) {
                    printf("Error: no lights to set color temperature for.\n");
                    break;
                }

                printf("Which light would you like to set the color temperature for (enter the ID number)?\n");

                int color_id;
                scanf("%d", &color_id);

                Light *color_light = NULL;
                for (int i = 0; i < num_lights; i++) {
                    if (lights[i].id == color_id) {
                        color_light = &lights[i];
                        break;
                    }
                }

                if (color_light == NULL) {
                    printf("Error: no light with that ID found.\n");
                } else {
                    printf("Enter the new color temperature (0-100):\n");
                    scanf("%d", &color_light->color_temp);
                    printf("Color temperature set successfully!\n\n");
                }

                break;
            }

            case 8:     // exit
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Error: invalid option selected.\n\n");
                break;
        }
    }

    return 0;
}