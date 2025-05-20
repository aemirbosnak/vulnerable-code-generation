//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void print_instructions() {
    printf("Welcome to the Terminal Game!\n");
    printf("You are in a forest.\n");
    printf("You can go north, south, east, or west.\n");
    printf("You are surrounded by trees and bushes.\n");
}

void print_tree() {
    printf("-------------------------\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("|         |         |\n");
    printf("-------------------------\n");
}

void print_bush() {
    printf("-------------------------\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("|          |          |\n");
    printf("-------------------------\n");
}

void print_player() {
    printf("-------------------------\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("|                         |\n");
    printf("-------------------------\n");
}

void print_forest() {
    print_tree();
    print_bush();
    print_player();
    print_bush();
    print_tree();
}

int main() {
    print_instructions();
    print_forest();
    char c;
    while (1) {
        printf("Enter your direction: ");
        scanf(" %c", &c);
        switch (c) {
            case 'n':
                print_forest();
                break;
            case's':
                print_forest();
                break;
            case 'e':
                print_forest();
                break;
            case 'w':
                print_forest();
                break;
            default:
                printf("Invalid direction!\n");
        }
    }
    return 0;
}