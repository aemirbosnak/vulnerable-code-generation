#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Define a simple structure for a game entity
typedef struct {
    int health;
    char name[20];
} Entity;

// Function to create an entity
Entity* create_entity(const char* name, int health) {
    Entity* new_entity = (Entity*)malloc(sizeof(Entity));
    if (new_entity == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(new_entity->name, name);
    new_entity->health = health;
    return new_entity;
}

// Function to display entity information
void display_entity(Entity* entity) {
    if (entity != NULL) {
        printf("Name: %s\n", entity->name);
        printf("Health: %d\n", entity->health);
    } else {
        printf("Invalid entity pointer!\n");
    }
}

int main() {
    // Create an entity
    Entity* player = create_entity("Hero", 100);

    // Display entity information
    display_entity(player);

    // Intentionally set a null pointer to demonstrate dereference failure
    Entity* invalid_entity = NULL;
    display_entity(invalid_entity); // This will cause a dereference failure

    // Free allocated memory
    free(player);

    return 0;
}
