//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 5
#define BUFFER_SIZE 100

typedef struct {
    char name[BUFFER_SIZE];
    int brightness;
    int is_on;
} Light;

void illuminate(Light *light) {
    if (light->is_on) {
        printf("The %s glows softly at brightness level %d.\n", light->name, light->brightness);
    } else {
        printf("The %s awaits your gentle touch to awaken its beauty.\n", light->name);
    }
}

void romantically_set_brightness(Light *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Oh dear! That brightness level is sadly out of reach. Choose a value between 0 and 100.\n");
        return;
    }

    light->brightness = brightness;
    if (brightness > 0) {
        light->is_on = 1;
        printf("With a tender hand, you've set %s's brightness to %d. The room is now bathed in a warm embrace.\n",
               light->name, light->brightness);
    } else {
        light->is_on = 0;
        printf("You’ve dimmed the lights of %s. The world outside fades, steeped in mystery.\n", light->name);
    }
}

void romantic_dinner(Light *lights, int total_lights) {
    printf("Ah, the ambiance of a romantic dinner! Let us set the mood...\n");
    for (int i = 0; i < total_lights; i++) {
        romantically_set_brightness(&lights[i], (i % 2 == 0) ? 70 : 30);
    }

    printf("\nThe lights softly flicker as love whispers between you and your beloved.\n");
}

void reveal_lights(Light *lights, int total_lights) {
    printf("\nIn this sanctuary, we have:\n");
    for (int i = 0; i < total_lights; i++) {
        printf("- %s: Brightness %d, Status: %s\n", lights[i].name, lights[i].brightness,
               lights[i].is_on ? "On" : "Off");
    }
    printf("\nLet your heart decide which light to caress.\n");
}

int main() {
    Light lights[MAX_LIGHTS] = {
        {"Candlelight", 0, 0},
        {"Moonlight", 0, 0},
        {"Sunset Glow", 0, 0},
        {"Twilight", 0, 0},
        {"Starry Night", 0, 0}
    };

    char command[BUFFER_SIZE];
    printf("Welcome, sweet soul, to your romantic light control.\n");

    while (1) {
        printf("\nType a command (set, dinner, reveal, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove newline character

        if (strcmp(command, "set") == 0) {
            int index, brightness;
            printf("Which light would you like to set (0 - %d)? ", MAX_LIGHTS-1);
            scanf("%d", &index);
            printf("And what brightness level, dear heart (0-100)? ");
            scanf("%d", &brightness);
            getchar(); // Clear the newline character from input buffer
            
            if (index >= 0 && index < MAX_LIGHTS) {
                romantically_set_brightness(&lights[index], brightness);
            } else {
                printf("Alas! There is no light corresponding to that number.\n");
            }
        } else if (strcmp(command, "dinner") == 0) {
            romantic_dinner(lights, MAX_LIGHTS);
        } else if (strcmp(command, "reveal") == 0) {
            reveal_lights(lights, MAX_LIGHTS);
        } else if (strcmp(command, "exit") == 0) {
            printf("Parting is such sweet sorrow! Farewell, until we meet again...\n");
            break;
        } else {
            printf("Your words confound me, sweet one. Please, say it again.\n");
        }
    }

    return 0;
}