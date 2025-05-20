//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Are you ready to explore the haunted house?\n", name);
    printf("1. Yes\n2. No\n");
    scanf("%d", &choice);
    if(choice == 1) {
        int room = rand() % 4;
        switch(room) {
            case 0:
                printf("You enter the first room. It's dark and spooky. You hear strange noises.\n");
                printf("1. Investigate\n2. Leave\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("You find a ghost! It scares you and you run away.\n");
                } else {
                    printf("You leave the room.\n");
                }
                break;
            case 1:
                printf("You enter the second room. It's filled with cobwebs and dust.\n");
                printf("1. Explore\n2. Leave\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("You find a hidden passage! It leads you to a secret room.\n");
                } else {
                    printf("You leave the room.\n");
                }
                break;
            case 2:
                printf("You enter the third room. It's a library with old books.\n");
                printf("1. Read a book\n2. Leave\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("You start reading a book about ghosts. Suddenly, the pages start turning by themselves!\n");
                } else {
                    printf("You leave the room.\n");
                }
                break;
            case 3:
                printf("You enter the fourth room. It's a kitchen with a table and chairs.\n");
                printf("1. Sit at the table\n2. Leave\n");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("You sit at the table and suddenly feel a cold breeze. You turn around and see a ghostly figure!\n");
                } else {
                    printf("You leave the room.\n");
                }
                break;
            default:
                printf("Invalid room number.\n");
        }
    } else {
        printf("You decide not to explore the haunted house.\n");
    }
    return 0;
}