//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIGHTS 10
#define STR_LEN 50

typedef enum { OFF, ON } State;
typedef struct {
    char name[STR_LEN];
    State state;
    int dim_level; // 0 to 100
} Light;

void initialize_lights(Light* lights, int num);
void toggle_light(Light* light);
void set_light_state(Light* light, State state);
void dim_light(Light* light, int level);
void print_light_status(Light* light);
void display_menu();
int get_choice();

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;
    int choice, light_index;

    printf("Welcome to Cryptic Smart Home Light Control.\n");
    printf("How many lights do you want to control? (Max %d): ", MAX_LIGHTS);
    scanf("%d", &num_lights);
    if (num_lights > MAX_LIGHTS) {
        num_lights = MAX_LIGHTS;
    }
    
    initialize_lights(lights, num_lights);
    
    do {
        display_menu();
        choice = get_choice();
        
        switch (choice) {
            case 1:
                printf("Enter light index (0 to %d): ", num_lights - 1);
                scanf("%d", &light_index);
                if (light_index >= 0 && light_index < num_lights) {
                    toggle_light(&lights[light_index]);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            
            case 2:
                printf("Enter light index (0 to %d): ", num_lights - 1);
                scanf("%d", &light_index);
                if (light_index >= 0 && light_index < num_lights) {
                    State new_state;
                    printf("Enter new state (0 for OFF, 1 for ON): ");
                    scanf("%d", &new_state);
                    set_light_state(&lights[light_index], new_state);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            
            case 3:
                printf("Enter light index (0 to %d): ", num_lights - 1);
                scanf("%d", &light_index);
                if (light_index >= 0 && light_index < num_lights) {
                    int level;
                    printf("Enter dim level (0-100): ");
                    scanf("%d", &level);
                    if (level >= 0 && level <= 100) {
                        dim_light(&lights[light_index], level);
                    } else {
                        printf("Invalid dim level.\n");
                    }
                } else {
                    printf("Invalid index.\n");
                }
                break;
            
            case 4:
                for (int i = 0; i < num_lights; i++) {
                    print_light_status(&lights[i]);
                }
                break;
            
            case 0:
                printf("Exiting the light control... Till next time!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}

void initialize_lights(Light* lights, int num) {
    for (int i = 0; i < num; i++) {
        snprintf(lights[i].name, STR_LEN, "Light %d", i);
        lights[i].state = OFF;
        lights[i].dim_level = 0;
    }
}

void toggle_light(Light* light) {
    if (light->state == ON) {
        light->state = OFF;
        light->dim_level = 0;
        printf("%s is now OFF.\n", light->name);
    } else {
        light->state = ON;
        printf("%s is now ON. Setting dim level to 100.\n", light->name);
        light->dim_level = 100;
    }
}

void set_light_state(Light* light, State state) {
    light->state = state;
    if (state == ON) {
        printf("%s is ON.\n", light->name);
    } else {
        printf("%s is OFF.\n", light->name);
    }
}

void dim_light(Light* light, int level) {
    if (light->state == ON) {
        light->dim_level = level;
        printf("%s dimmed to %d%%.\n", light->name, level);
    } else {
        printf("%s is OFF. Cannot dim.\n", light->name);
    }
}

void print_light_status(Light* light) {
    printf("%s - State: %s, Dim level: %d%%\n", light->name, 
           light->state == ON ? "ON" : "OFF", light->dim_level);
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Toggle Light\n");
    printf("2. Set Light State\n");
    printf("3. Dim Light\n");
    printf("4. Show Light Status\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}