//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

struct Ghost {
    char name[20];
    int room_num;
    int behavior;
    struct Ghost* next;
};

void addGhost(struct Ghost** head) {
    struct Ghost* newGhost = malloc(sizeof(struct Ghost));
    newGhost->next = NULL;

    printf("Enter the name of the ghost: ");
    scanf("%s", newGhost->name);

    printf("Enter the room number where the ghost resides: ");
    scanf("%d", &newGhost->room_num);

    printf("Enter the ghostly behavior of the ghost (1-3): ");
    scanf("%d", &newGhost->behavior);

    *head = newGhost;
}

void haunt(struct Ghost* head) {
    while (head) {
        printf("%s haunts room %d... ", head->name, head->room_num);

        switch (head->behavior) {
            case 1:
                printf("They whisper secrets.\n");
                break;
            case 2:
                printf("They move objects.\n");
                break;
            case 3:
                printf("They appear in mirrors.\n");
                break;
        }

        head = head->next;
    }
}

int main() {
    struct Ghost* head = NULL;
    int numGhosts = 0;

    printf("Welcome to the Haunted House Simulator!\n");

    while (numGhosts < MAX_GHOULS) {
        addGhost(&head);
        numGhosts++;
    }

    haunt(head);

    return 0;
}