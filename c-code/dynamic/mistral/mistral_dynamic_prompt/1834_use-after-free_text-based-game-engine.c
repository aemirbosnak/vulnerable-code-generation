#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game {
    char* name;
    char* description;
    char* creator;
    struct Game* next;
} Game;

Game* head = NULL;

void addGame(char* name, char* description, char* creator) {
    Game* newGame = (Game*) malloc(sizeof(Game));
    newGame->name = name;
    newGame->description = description;
    newGame->creator = creator;
    newGame->next = head;
    head = newGame;
}

void displayGames() {
    Game* current = head;
    printf("Game List:\n");
    while (current != NULL) {
        printf("%s - %s\nCreated by: %s\n", current->name, current->description, current->creator);
        current = current->next;
    }
}

void freeMemory() {
    Game* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    addGame("Game A", "A classic adventure", "John Doe");
    addGame("Game B", "A mysterious journey", "Jane Doe");

    displayGames();

    free(head->name);
    head->name = NULL;

    displayGames();

    freeMemory();

    return 0;
}
