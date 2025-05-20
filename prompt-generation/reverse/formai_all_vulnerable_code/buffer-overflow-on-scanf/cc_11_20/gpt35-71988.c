//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define GHOST 1
#define GOBLIN 2
#define VAMPIRE 3
#define POLTERGEIST 4

int main() {
    srand(time(NULL));
    int room, enemy, choice, steps = 0;
    int is_dead = 0;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a dark room. The door behind you slams shut!\n");
    printf("You need to find your way out. Each room may contain an enemy.\n");
    while (1) {
        printf("You are in Room %d\n", steps+1);
        printf("There are four doors. Choose one (1,2,3,4): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice!\n");
            continue;
        }
        room = rand() % 4 + 1;
        if (room == choice) {
            printf("You move to the next room.\n");
            printf("\n");
            steps++;
            if (steps >= 10) {
                printf("You see a door at the end of the hallway!\n");
                printf("You open it and escape the haunted house. Congratulations!\n");
                break;
            }
            continue;
        }
        printf("You open the door and see...\n");
        enemy = rand() % 4 + 1;
        if (enemy == GHOST) {
            printf("A ghost!\n");
        } else if (enemy == GOBLIN) {
            printf("A goblin!\n");
        } else if (enemy == VAMPIRE) {
            printf("A vampire!\n");
        } else if (enemy == POLTERGEIST) {
            printf("A poltergeist!\n");
        }
        printf("[0] Fight \n");
        printf("[1] Runaway\n");
        printf("Choose an option: ");

        scanf("%d", &choice);
        if (choice != 0 && choice != 1) {
            printf("Invalid choice!\n");
            continue;
        }

        if (choice == 1) {
            printf("You try to run away...\n");
            if (rand() % 2 == 0) {
                printf("You make it to the next room!\n");
                printf("\n");
                steps++;
                if (steps >= 10) {
                    printf("You see a door at the end of the hallway!\n");
                    printf("You open it and escape the haunted house. Congratulations!\n");
                    break;
                }
                continue;
            } else {
                printf("The enemy blocks your path. You must fight!\n");
            }
        }
        printf("You enter into a fight!\n");
        int your_strength = rand() % 10 + 1;
        int enemy_strength = rand() % 10 + 1;
        if (your_strength > enemy_strength) {
            printf("You defeated the enemy!\n");
            printf("You move to the next room.\n");
            printf("\n");
            steps++;
            if (steps >= 10) {
                printf("You see a door at the end of the hallway!\n");
                printf("You open it and escape the haunted house. Congratulations!\n");
                break;
            }
        } else {
            printf("You were defeated by the enemy and died!\n");
            is_dead = 1;
            break;
        }
    }
    if (is_dead) {
        printf("Game over!\n");
    }
    return 0;
}