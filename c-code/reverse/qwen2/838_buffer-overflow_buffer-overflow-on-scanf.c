#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_COMPONENT_TYPE_LENGTH 10

typedef struct {
    char type[MAX_COMPONENT_TYPE_LENGTH];
} Component;

void addComponent(Component *components[], int *count) {
    if (*count >= 10) {
        printf("Cannot add more components.\n");
        return;
    }
    Component newComponent;
    printf("Enter component type: ");
    scanf("%s", newComponent.type);
    components[*count] = &newComponent;
    (*count)++;
}

int main() {
    Component *components[10];
    int count = 0;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Component\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addComponent(components, &count);
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
