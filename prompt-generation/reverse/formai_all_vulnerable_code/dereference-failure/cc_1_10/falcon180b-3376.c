//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define MAX_ROLES 3

typedef struct {
    char *name;
    char *role[MAX_ROLES];
    int num_roles;
} Character;

void add_role(Character *c, char *role) {
    if (c->num_roles >= MAX_ROLES) {
        printf("Error: Too many roles for character %s\n", c->name);
        exit(1);
    }
    c->role[c->num_roles++] = role;
}

void print_character(Character *c) {
    printf("Name: %s\n", c->name);
    for (int i = 0; i < c->num_roles; i++) {
        printf("Role: %s\n", c->role[i]);
    }
}

int main() {
    FILE *file = fopen("romeo_and_juliet.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file romeo_and_juliet.txt\n");
        exit(1);
    }

    Character *characters = malloc(sizeof(Character));
    characters[0].name = "Romeo";
    characters[0].num_roles = 0;
    characters[0].role[0] = "Lead male";
    add_role(characters, "Lover");
    add_role(characters, "Montague");

    characters[1].name = "Juliet";
    characters[1].num_roles = 0;
    characters[1].role[0] = "Lead female";
    add_role(characters, "Lover");
    add_role(characters, "Capulet");

    int current_character = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            if (strcmp(line, "#CHARACTER: ROMEO") == 0) {
                current_character = 0;
            } else if (strcmp(line, "#CHARACTER: JULIET") == 0) {
                current_character = 1;
            } else {
                printf("Error: Invalid character name %s\n", line + 1);
                exit(1);
            }
        } else {
            int len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[--len] = '\0';
            }
            if (current_character >= 0 && current_character < 2) {
                characters[current_character].name = strdup(line);
            }
        }
    }

    fclose(file);

    print_character(characters);
    print_character(characters + 1);

    free(characters);
    return 0;
}