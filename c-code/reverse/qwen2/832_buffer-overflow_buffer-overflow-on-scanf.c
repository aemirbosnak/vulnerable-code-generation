#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMPONENTS 10
#define NAME_LENGTH 20

typedef struct {
    char type[NAME_LENGTH];
    double value;
} Component;

Component components[MAX_COMPONENTS];
int component_count = 0;

void add_component() {
    if (component_count >= MAX_COMPONENTS) {
        printf("Cannot add more components.\n");
        return;
    }
    Component new_component;
    printf("Enter component type: ");
    scanf("%s", new_component.type);
    printf("Enter component value: ");
    scanf("%lf", &new_component.value);
    components[component_count++] = new_component;
}

void display_components() {
    for (int i = 0; i < component_count; i++) {
        printf("%s: %.2f\n", components[i].type, components[i].value);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Component\n");
        printf("2. Display Components\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_component();
                break;
            case 2:
                display_components();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
