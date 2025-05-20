//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ammo, medkit, health, enemiesKilled;
    srand(time(0));

    printf("Welcome to the post-apocalyptic world!\n");
    printf("You are a survivor trying to make it through the wasteland.\n");
    printf("You start with 5 ammo and 1 medkit.\n");
    printf("Stay healthy and kill as many enemies as you can.\n\n");

    ammo = 5;
    medkit = 1;
    health = 100;
    enemiesKilled = 0;

    while (health > 0) {
        int randNum = rand() % 10 + 1;
        printf("You encounter %d enemies!\n", randNum);

        for (int i = 0; i < randNum; i++) {
            ammo--;
            if (ammo < 0) {
                printf("You have run out of ammo!\n");
                break;
            }

            int enemyHealth = rand() % 100 + 1;
            printf("You shoot the enemy for %d damage!\n", rand() % 20 + 1);
            enemyHealth -= rand() % 20 + 1;

            if (enemyHealth <= 0) {
                printf("You have killed the enemy!\n");
                enemiesKilled++;
            } else {
                printf("The enemy attacks you for %d damage!\n", rand() % 20 + 1);
                health -= rand() % 20 + 1;
                if (health <= 0) {
                    printf("You have died in battle.\n");
                    break;
                }
            }
        }

        if (health <= 0) {
            break;
        }

        printf("You have %d ammo left.\n", ammo);
        printf("You have %d medkit(s) left.\n", medkit);

        printf("Would you like to use a medkit? (y/n)\n");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            medkit--;
            health += rand() % 20 + 1;
            printf("You use a medkit and restore %d health.\n", rand() % 20 + 1);
        }

        if (enemiesKilled % 5 == 0) {
            printf("You have found a stash of ammo!\n");
            ammo += rand() % 10 + 1;
        }

        printf("\n");
    }

    printf("Game over!\n");
    printf("You killed %d enemies.\n", enemiesKilled);

    return 0;
}