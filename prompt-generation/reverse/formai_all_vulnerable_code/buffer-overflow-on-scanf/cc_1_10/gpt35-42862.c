//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void wait(int seconds){
    clock_t end_wait;
    end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait) {}
}

struct Spaceship{
    char *name;
    int fuel;
    int health;
};

struct Enemy{
    char *name;
    int damage;
    int health;
};

void attack(struct Spaceship *player, struct Enemy *enemy){
    printf("%s attacks %s\n", player->name, enemy->name);
    enemy->health -= rand() % 30;
    if(enemy->health <= 0){
        printf("Congratulations, you defeated the enemy %s!", enemy->name);
        return;
    }
    printf("%s attacks %s\n", enemy->name, player->name);
    player->health -= rand() % 20;
    if(player->health <= 0){
        printf("Game over! Your spaceship was destroyed by the enemy %s.\n", enemy->name);
        exit(0);
    }
}

int main(){
    srand(time(0));

    struct Spaceship player;
    player.name = "USS Enterprise";
    player.fuel = 100;
    player.health = 100;

    printf("Welcome to the space adventure game! You are the commander of the spaceship %s.\n", player.name);

    wait(2); //wait for 2 seconds

    printf("Your mission is to explore the galaxy and defeat all the enemies you encounter.\n");

    wait(2); //wait for 2 seconds

    printf("You are currently in the Milky Way galaxy, please select your destination.\n");

    wait(2); //wait for 2 seconds

    printf("1. Andromeda galaxy\n");
    printf("2. Triangulum galaxy\n");
    printf("3. Sombrero galaxy\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("You have selected the Andromeda galaxy.\n");
        player.fuel -= 25;

        wait(2); //wait for 2 seconds

        struct Enemy andromeda = {"Alien", 10, 50};

        printf("You have encountered an enemy %s with %d health and %d damage.\n", andromeda.name, andromeda.health, andromeda.damage);

        while(andromeda.health > 0 && player.health > 0){
            attack(&player, &andromeda);

            wait(2); //wait for 2 seconds
        }

        printf("You have defeated the enemy %s!\n", andromeda.name);

        wait(2); //wait for 2 seconds

        printf("You have successfully completed your mission in the Andromeda galaxy.\n");
    }else if(choice == 2){
        printf("You have selected the Triangulum galaxy.\n");
        player.fuel -= 30;

        wait(2); //wait for 2 seconds

        struct Enemy triangulum = {"Ghidorah", 20, 80};

        printf("You have encountered an enemy %s with %d health and %d damage.\n", triangulum.name, triangulum.health, triangulum.damage);

        while(triangulum.health > 0 && player.health > 0){
            attack(&player, &triangulum);

            wait(2); //wait for 2 seconds
        }

        printf("You have defeated the enemy %s!\n", triangulum.name);

        wait(2); //wait for 2 seconds

        printf("You have successfully completed your mission in the Triangulum galaxy.\n");
    }else if(choice == 3){
        printf("You have selected the Sombrero galaxy.\n");
        player.fuel -= 40;

        wait(2); //wait for 2 seconds

        struct Enemy sombrero = {"Mothra", 30, 100};

        printf("You have encountered an enemy %s with %d health and %d damage.\n", sombrero.name, sombrero.health, sombrero.damage);

        while(sombrero.health > 0 && player.health > 0){
            attack(&player, &sombrero);

            wait(2); //wait for 2 seconds
        }

        printf("You have defeated the enemy %s!\n", sombrero.name);

        wait(2); //wait for 2 seconds

        printf("You have successfully completed your mission in the Sombrero galaxy.\n");
    }else{
        printf("Invalid choice! Please try again.\n");
        exit(0);
    }

    printf("You now have %d fuel and %d health remaining.\n", player.fuel, player.health);

    wait(2); //wait for 2 seconds

    printf("Congratulations, you have completed all the missions and explored the entire galaxy!\n");
    
    return 0;
}