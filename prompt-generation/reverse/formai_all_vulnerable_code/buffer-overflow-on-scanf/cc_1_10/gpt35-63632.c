//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_HEALTH 100
#define MAX_SHIELD 50
#define MAX_WEAPONS 3

struct enemy {
    char name[30];
    int health;
};

struct player {
    char name[30];
    int health;
    int shield;
    int weapon;
    int credits;
    int score;
};

typedef struct enemy Enemy;
typedef struct player Player;

void printIntro();
void initializePlayer(Player *p);
void initializeEnemies(Enemy *e);
void fight(Player *p, Enemy *e);
void printGameOver(Player *p);

int main() {
    srand(time(NULL));

    printIntro();

    Player player;
    initializePlayer(&player);

    Enemy enemies[MAX_ENEMIES];
    initializeEnemies(enemies);

    for(int i=0; i<MAX_ENEMIES; i++) {
        fight(&player, &enemies[i]);
        if(player.health <= 0) {
            printGameOver(&player);
            return 0;
        }
        player.score += 10;
    }

    printf("\nCongratulations! You have completed the adventure with a score of %d.\n", player.score);

    return 0;
}

void printIntro() {
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("Your mission is to defeat all the enemies and earn as much credits as possible.\n\n");
}

void initializePlayer(Player *p) {
    printf("Enter your name: ");
    scanf("%s", p->name);
    p->health = MAX_HEALTH;
    p->shield = MAX_SHIELD;
    p->weapon = 0;
    p->credits = 0;
    p->score = 0;
}

void initializeEnemies(Enemy *e) {
    for(int i=0; i<MAX_ENEMIES; i++) {
        sprintf(e[i].name, "Enemy %d", i+1);
        e[i].health = rand() % MAX_HEALTH + 1;
    }
}

void fight(Player *p, Enemy *e) {
    printf("\n%s has appeared with %d health.\n", e->name, e->health);

    while(e->health > 0) {
        printf("\n%s's health: %d\n", e->name, e->health);
        printf("%s's health: %d\n", p->name, p->health);
        printf("%s's shield: %d\n", p->name, p->shield);
        printf("%s's credits: %d\n", p->name, p->credits);
        printf("%s's score: %d\n", p->name, p->score);

        int choice;
        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Change weapon\n");
        printf("4. Run\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n%s attacks with their weapon.\n", p->name);
                int damage = rand() % (p->weapon+1) + 1;
                e->health -= damage;
                printf("You dealt %d damage to %s.\n", damage, e->name);
                break;
            case 2:
                printf("\n%s defends with their shield.\n", p->name);
                int deflect = rand() % (p->shield+1) + 1;
                int enemyDamage = rand() % 11 + 1;
                if(deflect >= enemyDamage) {
                    printf("You successfully defended the attack.\n");
                } else {
                    p->health -= enemyDamage - deflect;
                    printf("You took %d damage.\n", enemyDamage - deflect);
                }
                break;
            case 3:
                printf("\n%s changes to a new weapon.\n", p->name);
                if(p->weapon < MAX_WEAPONS) {
                    p->weapon++;
                    printf("You now have a level %d weapon.\n", p->weapon);
                } else {
                    printf("You already have the highest level weapon.\n");
                }
                break;
            case 4:
                printf("\n%s tries to run away.\n", p->name);
                int success = rand() % 2;
                if(success) {
                    printf("You managed to escape.\n");
                    return;
                } else {
                    printf("You failed to escape.\n");
                    break;
                }
            default:
                printf("\nInvalid choice. Try again.\n");
        }

        if(e->health <= 0) {
            printf("\nYou defeated %s.\n", e->name);
            int creditsEarned = rand() % 21 + 10;
            p->credits += creditsEarned;
            printf("You earned %d credits.\n", creditsEarned);
        }

        if(p->health <= 0) {
            printf("\n%s has been defeated.\n", p->name);
            return;
        }
    }
}

void printGameOver(Player *p) {
    printf("\n*********** GAME OVER ***********\n");
    printf("You have been defeated.\n");
    printf("Final score: %d\n", p->score);
    printf("Final credits: %d\n", p->credits);
}