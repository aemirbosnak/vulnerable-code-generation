//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 1000
#define MAX_COMMAND_LENGTH 100

struct command {
    char *name;
    char *parameters;
};

int num_commands = 0;
struct command commands[MAX_COMMANDS];

void add_command(char *name, char *parameters) {
    if (num_commands >= MAX_COMMANDS) {
        printf("Error: Too many commands\n");
        exit(1);
    }

    commands[num_commands].name = strdup(name);
    commands[num_commands].parameters = strdup(parameters);

    num_commands++;
}

int main() {
    // Act I, Scene I
    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");

    // Act I, Scene II
    add_command("Capulet", "Montague");
    add_command("Montague", "Capulet");

    // Act II, Scene II
    printf("But soft! What light through yonder window breaks?\n");
    printf("It is the east, and Juliet is the sun.\n");

    // Act II, Scene VI
    add_command("Friar Laurence", "Romeo and Juliet");

    // Act III, Scene I
    printf("For never was a story of more woe\n");
    printf("Than this of Juliet and her Romeo.\n");

    // Act III, Scene V
    add_command("Romeo", "Juliet");

    // Act V, Scene III
    printf("For this alliance may so happy prove,\n");
    printf("To turn your households' rancor to pure love.\n");

    for (int i = 0; i < num_commands; i++) {
        printf("%s\n", commands[i].name);
    }

    return 0;
}