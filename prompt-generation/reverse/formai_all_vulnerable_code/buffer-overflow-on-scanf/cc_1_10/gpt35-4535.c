//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int random_generator(int min_number, int max_number){
    /* This function generates a random number between min and max numbers */
    int random_number;
    srand(time(NULL)); //This function initializes the random seed with time
    random_number = min_number + (rand() % (max_number - min_number + 1));
    return random_number;
}

int main(){
    /*Initialization of variables*/
    int fuel = 100; 
    int distance = 0;  
    int damage = 0; 
    int max_distance = 1000;
    int enemy_attack = 0;
    int enemy_damage = 0;
    int enemy_health = 0;
    int escape_chance = 0;
    int encounter = 0;
    int choice = 0;
    int game_over = 0;

    printf("Welcome to the Procedural Space Adventure!\n\n");

    while(game_over!=1){
        /*Travel phase*/
        printf("\n\nFuel level: %d\nDistance covered: %d\nDamage taken: %d\n", fuel, distance, damage);
        printf("You are currently travelling through space...\n");
        fuel = fuel - 10;
        distance = distance + random_generator(50, 100);
        
        /*Encounter phase*/
        encounter = random_generator(1, 3);
        if(encounter == 1){
            printf("\n\nYou have encountered an enemy spaceship!\n");
            enemy_health = random_generator(50, 100);
            printf("Enemy spaceship health: %d\n", enemy_health);
            while(enemy_health > 0 && fuel > 0 && damage < 100){
                printf("\n\nYour spacecraft's health: %d\nEnemy spacecraft's health: %d\n", 100-damage, enemy_health);
                printf("1. Attack\n2. Escape\nEnter your choice: ");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou attack the enemy!\n");
                    enemy_attack = random_generator(10, 20);
                    enemy_health = enemy_health - enemy_attack;
                    printf("Enemy took %d damage!\n", enemy_attack);
                    if(enemy_health > 0){
                        enemy_damage = random_generator(10, 20);
                        damage = damage + enemy_damage;
                        printf("Enemy counter-attacks and you take %d damage!\n", enemy_damage);
                    }
                }else if(choice == 2){
                    printf("\nYou try to flee!\n");
                    escape_chance = random_generator(1, 2);
                    if(escape_chance == 1){
                        printf("You manage to escape successfully!\n");
                        break;
                    }else{
                        printf("Enemy prevents you from escaping!\n");
                        enemy_damage = random_generator(10, 20);
                        damage = damage + enemy_damage;
                        printf("Enemy attacks and you take %d damage!\n", enemy_damage);
                    }
                }else{
                    printf("\nInvalid choice. Please try again.\n");
                }
            }
            
            if(enemy_health <= 0){
                printf("\n\nCongratulations! You have defeated the enemy spaceship!\n");
                printf("You get extra fuel and continue your journey...\n");
                fuel = fuel + 50;
            }else if(fuel<=0){
                printf("\n\nOh no! You are out of fuel...\nGAME OVER!\n");
                game_over = 1;
            }else if(damage>=100){
                printf("\n\nYour spacecraft has taken too much damage...\nGAME OVER!\n");
                game_over = 1;
            }else{
                printf("\n\nYou have escaped from the enemy and continue your journey...\n");
            }
        }
        
        /*Check if mission complete*/
        if(distance >= max_distance){
            printf("\n\nCongratulations! You have completed your mission!\nYou land your spacecraft successfully...\n");
            game_over = 1;
        }else if(game_over != 1){
            printf("\n\nPress any key to continue your journey...\n");
            getchar();
            getchar();
        }
    }
    return 0;
}