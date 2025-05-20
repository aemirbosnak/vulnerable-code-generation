//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int room = 1;
    int health = 100;
    int ammo = 0;
    int monster_health = 50;
    
    printf("Welcome to the adventure game!\n");
    printf("You are in a haunted house and your goal is to find\nthe treasure and escape!\n");

    while (room != 5) {
        printf("\n\nYou are in room %d\n", room);
        printf("Health: %d\n", health);
        printf("Ammo: %d\n", ammo);
        printf("Monster Health: %d\n", monster_health);

        int choice;
        printf("Enter 1 to move to the next room\n");
        printf("Enter 2 to search the room\n");
        printf("Enter 3 to attack the monster\n");
        printf("Enter 4 to quit the game\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                room++;
                break;
            case 2:
                if (rand() % 2 == 0) {
                    printf("You found a bullet!\n");
                    ammo++;
                } else {
                    printf("You found nothing.\n");
                }
                break;
            case 3:
                if (ammo > 0) {
                    int damage = rand() % 30 + 1;
                    monster_health -= damage;
                    printf("You did %d damage!\n", damage);
                    if (monster_health <= 0) {
                        printf("You killed the monster!\n");
                        monster_health = 50;
                        ammo--;
                    } else {
                        int monster_damage = rand() % 20 + 1;
                        health -= monster_damage;
                        printf("The monster did %d damage!\n", monster_damage);
                        if (health <= 0) {
                            printf("You are dead. GAME OVER.\n");
                            return 0;
                        }
                    }
                } else {
                    printf("You don't have any bullets!\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Congratulations! You found the treasure and escaped the haunted house!\n");
    return 0;
}