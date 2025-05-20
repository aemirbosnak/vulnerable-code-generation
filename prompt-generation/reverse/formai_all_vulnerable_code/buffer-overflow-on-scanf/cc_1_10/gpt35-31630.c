//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ITEM_LENGTH 20

char items[MAX_ITEMS][MAX_ITEM_LENGTH];
int num_items = 0;
int location = 0;

void look_around();
void take(char* item);
void use(char* item);
void invalid_command();
int check_if_item_exists(char* item);
void display_items();

int main() {
    strcpy(items[0], "key");
    num_items++;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself standing outside a large, old house.\n");
    printf("There is a sign on the door that reads 'Abandoned for 50 years'.\n");

    while (1) {
        char command[10];
        char parameter[MAX_ITEM_LENGTH];
        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "look") == 0) {
            look_around();
        } else if (strcmp(command, "take") == 0) {
            scanf("%s", parameter);
            take(parameter);
        } else if (strcmp(command, "use") == 0) {
            scanf("%s", parameter);
            use(parameter);
        } else if (strcmp(command, "items") == 0) {
            display_items();
        } else {
            invalid_command();
        }
    }

    return 0;
}

void look_around() {
    if (location == 0) {
        printf("You are standing outside the house.\n");
        printf("There is a key on the ground.\n");
    } else if (location == 1) {
        printf("You are in the living room.\n");
        printf("There is a table with a vase on it.\n");
        printf("There is a door to the east.\n");
    } else if (location == 2) {
        printf("You are in the kitchen.\n");
        printf("There is a stove and a sink.\n");
        printf("There is a door to the west.\n");
    }
}

void take(char* item) {
    if (strcmp(item, "key") == 0) {
        if (location == 0) {
            strcpy(items[num_items], "key");
            num_items++;
            printf("You have picked up the key.\n");
        } else {
            printf("There is no key here.\n");
        }
    } else {
        printf("You cannot take that.\n");
    }
}

void use(char* item) {
    if (strcmp(item, "key") == 0) {
        if (location == 1) {
            printf("You have unlocked the door to the east.\n");
            location = 2;
        } else if (location == 2) {
            printf("You have unlocked the door to the west.\n");
            location = 1;
        } else {
            printf("There is no door to unlock.\n");
        }
    } else {
        printf("You cannot use that.\n");
    }
}

void invalid_command() {
    printf("Invalid command. Type 'help' for a list of commands.\n");
}

int check_if_item_exists(char* item) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}

void display_items() {
    int i;
    printf("You are carrying:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\n", items[i]);
    }
}