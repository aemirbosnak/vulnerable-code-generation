#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
} Entity;

Entity* create_entity(int id, const char *name) {
    Entity *e = (Entity *)malloc(sizeof(Entity));
    if (e == NULL) return NULL;
    e->id = id;
    e->name = strdup(name);
    return e;
}

void destroy_entity(Entity *e) {
    if (e != NULL) {
        free(e->name);
        free(e);
    }
}

int main() {
    Entity *player = create_entity(1, "Hero");
    printf("Player: %d - %s\n", player->id, player->name);

    // Simulate some game logic
    sleep(2);

    // Free the player entity
    destroy_entity(player);

    // Use-after-free vulnerability
    printf("Player ID: %d\n", player->id); // Undefined behavior

    return 0;
}
