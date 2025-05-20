#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char type[10];
    float value;
} Component;

void add_component(Component* components, int* num_components) {
    printf("Enter component type (Resistor, Capacitor, Voltage Source): ");
    scanf("%s", components[*num_components].type);
    printf("Enter component value: ");
    scanf("%f", &components[*num_components].value);
    printf("Enter component name: ");
    scanf("%s", components[*num_components].name);
    (*num_components)++;
}

void simulate(Component* components, int num_components) {
    // Simulation logic goes here
}

int main() {
    Component components[100];
    int num_components = 0;
    int choice;

    while (1) {
        printf("\n1. Add Component\n2. Simulate\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_component(components, &num_components);
                break;
            case 2:
                simulate(components, num_components);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
