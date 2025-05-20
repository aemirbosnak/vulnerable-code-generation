//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define SIZE 10

typedef struct {
    char name[20];
    int health;
    int xp;
} Survivor;

void print_survivor(Survivor survivor) {
    printf(GREEN);
    printf("%s (%d HP, %d XP)\n", survivor.name, survivor.health, survivor.xp);
    printf(RESET);
}

void init_survivors(Survivor survivors[]) {
    for (int i = 0; i < SIZE; i++) {
        strcpy(survivors[i].name, "Survivor");
        survivors[i].health = 100;
        survivors[i].xp = 0;
    }
}

int main() {
    Survivor survivors[SIZE];
    int choice;

    init_survivors(survivors);

    printf(RED);
    printf("-----------------------------------------------------------------------\n");
    printf("|                                                                       |\n");
    printf("|                        WELCOME TO THE WASTELAND!                        |\n");
    printf("|                                                                       |\n");
    printf("-----------------------------------------------------------------------|\n");
    printf(RESET);

    while (1) {
        printf(YELLOW);
        printf("\nWhat would you like to do?\n");
        printf("1. Scavenge\n");
        printf("2. Heal\n");
        printf("3. Rest\n");
        printf("4. View Survivors\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Scavenge code here
                break;
            case 2:
                // Heal code here
                break;
            case 3:
                // Rest code here
                break;
            case 4:
                for (int i = 0; i < SIZE; i++) {
                    print_survivor(survivors[i]);
                }
                break;
            case 5:
                printf(RED);
                printf("Are you sure you want to quit? (y/n): ");
                char quit;
                scanf("%c", &quit);
                if (quit == 'y') {
                    exit(0);
                }
                break;
            default:
                printf(MAGENTA);
                printf("Invalid choice. Please try again.\n");
                printf(RESET);
                break;
        }
    }

    return 0;
}