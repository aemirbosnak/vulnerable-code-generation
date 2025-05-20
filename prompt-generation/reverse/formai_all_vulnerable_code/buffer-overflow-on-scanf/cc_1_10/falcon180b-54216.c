//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <stdbool.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20
#define MAX_LIGHTS 10
#define MAX_LIGHT_NAME_LENGTH 20
#define MAX_LIGHT_VALUE 100

typedef struct {
    char name[MAX_LIGHT_NAME_LENGTH];
    int value;
} Light;

Light lights[MAX_LIGHTS];
int num_lights = 0;

int main() {
    int choice, result;
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Enter 'create' to create a new light or 'list' to list all lights:\n");
    scanf("%s", input);

    if (strcmp(input, "create") == 0) {
        printf("Enter the name of the new light:\n");
        scanf("%s", input);

        for (int i = 0; i < num_lights; i++) {
            if (strcmp(lights[i].name, input) == 0) {
                printf("This light already exists!\n");
                return 1;
            }
        }

        strcpy(lights[num_lights].name, input);
        lights[num_lights].value = 0;
        num_lights++;

        printf("Light created successfully!\n");
    } else if (strcmp(input, "list") == 0) {
        for (int i = 0; i < num_lights; i++) {
            printf("%s: %d\n", lights[i].name, lights[i].value);
        }
    } else {
        printf("Invalid command!\n");
    }

    return 0;
}