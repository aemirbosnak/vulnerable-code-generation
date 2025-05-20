//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int level;
} Light;

Light lights[MAX_LIGHTS];
int num_lights;

void print_lights() {
    printf("Name | Level\n");
    printf("---------------------\n");
    for (int i = 0; i < num_lights; i++) {
        printf("%s | %d\n", lights[i].name, lights[i].level);
    }
}

int main() {
    int choice = 0;
    while (choice!= 4) {
        printf("1. Add light\n2. Remove light\n3. Set light level\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                if (num_lights >= MAX_LIGHTS) {
                    printf("Maximum lights reached. ");
                } else {
                    printf("Enter light name: ");
                    scanf("%s", lights[num_lights].name);
                    printf("Enter light level (0-100): ");
                    scanf("%d", &lights[num_lights].level);
                    num_lights++;
                }
                break;
            }
            case 2: {
                printf("Enter light name to remove: ");
                char remove_name[20];
                scanf("%s", remove_name);
                for (int i = 0; i < num_lights; i++) {
                    if (strcmp(remove_name, lights[i].name) == 0) {
                        for (int j = i; j < num_lights - 1; j++) {
                            strcpy(lights[j].name, lights[j + 1].name);
                            lights[j].level = lights[j + 1].level;
                        }
                        num_lights--;
                        break;
                    }
                }
                break;
            }
            case 3: {
                printf("Enter light name: ");
                char set_name[20];
                scanf("%s", set_name);
                for (int i = 0; i < num_lights; i++) {
                    if (strcmp(set_name, lights[i].name) == 0) {
                        printf("Enter new light level (0-100): ");
                        scanf("%d", &lights[i].level);
                        break;
                    }
                }
                break;
            }
            case 4: {
                printf("Exiting... ");
                break;
            }
            default: {
                printf("Invalid choice. ");
            }
        }
    }
    return 0;
}