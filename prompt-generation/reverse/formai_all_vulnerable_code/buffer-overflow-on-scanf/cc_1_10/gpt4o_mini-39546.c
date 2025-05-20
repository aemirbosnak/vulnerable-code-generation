//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define STATUS_ON "ON"
#define STATUS_OFF "OFF"

typedef struct {
    int id;
    char name[30];
    char status[4];
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        lights[light_count].id = light_count + 1;
        strncpy(lights[light_count].name, name, sizeof(lights[light_count].name));
        strncpy(lights[light_count].status, STATUS_OFF, sizeof(lights[light_count].status));
        light_count++;
        printf("Added light %s with ID %d\n", name, light_count);
    } else {
        printf("Maximum number of lights reached.\n");
    }
}

void list_lights() {
    printf("Available Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d | Name: %s | Status: %s\n", lights[i].id, lights[i].name, lights[i].status);
    }
}

void toggle_light(int id) {
    if (id > 0 && id <= light_count) {
        if (strcmp(lights[id - 1].status, STATUS_ON) == 0) {
            strncpy(lights[id - 1].status, STATUS_OFF, sizeof(lights[id - 1].status));
            printf("Turned OFF light %s\n", lights[id - 1].name);
        } else {
            strncpy(lights[id - 1].status, STATUS_ON, sizeof(lights[id - 1].status));
            printf("Turned ON light %s\n", lights[id - 1].name);
        }
    } else {
        printf("Invalid light ID.\n");
    }
}

void delete_light(int id) {
    if (id > 0 && id <= light_count) {
        printf("Deleting light %s\n", lights[id - 1].name);
        for (int i = id - 1; i < light_count - 1; i++) {
            lights[i] = lights[i + 1];
        }
        light_count--;
    } else {
        printf("Invalid light ID.\n");
    }
}

void show_menu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("1. Add Light\n");
    printf("2. List Lights\n");
    printf("3. Toggle Light\n");
    printf("4. Delete Light\n");
    printf("5. Exit\n");
}

int main() {
    int choice, id;
    char name[30];

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                list_lights();
                break;
            case 3:
                printf("Enter light ID to toggle: ");
                scanf("%d", &id);
                toggle_light(id);
                break;
            case 4:
                printf("Enter light ID to delete: ");
                scanf("%d", &id);
                delete_light(id);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        sleep(1); // Sleep for a brief moment for better user experience
    }

    return 0;
}