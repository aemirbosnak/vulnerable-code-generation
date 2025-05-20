//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[32];
    int brightness;
    int duration;
} light_t;

light_t lights[MAX_LIGHTS];

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].brightness = 0;
        lights[i].duration = 0;
    }
}

void print_lights() {
    printf("Light Name\tBrightness\tDuration\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s\t\t%d\t\t%d\n", lights[i].name, lights[i].brightness, lights[i].duration);
    }
}

int main() {
    init_lights();
    int choice;
    while (1) {
        printf("1. Add Light\n2. Remove Light\n3. Turn On\n4. Turn Off\n5. Print Lights\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Light Name: ");
                scanf(" %[^\n]", lights[0].name);
                break;
            case 2:
                printf("Enter Light Name to Remove: ");
                scanf(" %[^\n]", lights[0].name);
                break;
            case 3:
                printf("Enter Light Name: ");
                scanf(" %[^\n]", lights[0].name);
                printf("Enter Brightness (0-100): ");
                scanf("%d", &lights[0].brightness);
                printf("Enter Duration (seconds): ");
                scanf("%d", &lights[0].duration);
                break;
            case 4:
                printf("Enter Light Name: ");
                scanf(" %[^\n]", lights[0].name);
                lights[0].brightness = 0;
                lights[0].duration = 0;
                break;
            case 5:
                print_lights();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}