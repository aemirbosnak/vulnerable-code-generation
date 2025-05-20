#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_COMPONENTS 100

typedef struct Component {
    char type[MAX_NAME_LENGTH];
    int id;
} Component;

Component components[MAX_COMPONENTS];
int numComponents = 0;

void addComponent(char *componentType, int id) {
    strcpy(components[numComponents].type, componentType);
    components[numComponents].id = id;
    numComponents++;
}

void printMenu() {
    printf("Multiplayer Circuit Simulator\n");
    printf("1. Add Component\n");
    printf("2. Simulate Circuit\n");
    printf("3. Exit\n");
}

int main() {
    char input[MAX_NAME_LENGTH];
    int id;

    while (1) {
        printMenu();
        scanf("%s %d", input, &id);

        if (strcmp(input, "1") == 0) {
            printf("Enter component type: ");
            scanf("%s", input); // Vulnerable to buffer overflow
            addComponent(input, id);
        } else if (strcmp(input, "2") == 0) {
            // Simulate circuit logic
        } else if (strcmp(input, "3") == 0) {
            break;
        }
    }

    return 0;
}
