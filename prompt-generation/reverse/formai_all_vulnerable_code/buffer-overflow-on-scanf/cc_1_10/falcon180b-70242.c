//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil alien.\n");
    printf("You have %d health points.\n", player_health);
    printf("The alien has %d health points.\n", enemy_health);
    printf("Your attack power is %d.\n", player_attack);
    printf("The alien's attack power is %d.\n", enemy_attack);

    int choice;
    while(1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Attack\n2. Defend\n3. Check health\n4. Check enemy health\n5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You attacked the alien with %d damage!\n", player_attack);
                enemy_health -= player_attack;
                if(enemy_health <= 0) {
                    printf("You defeated the alien! Congratulations!\n");
                    break;
                }
                printf("The alien has %d health points left.\n", enemy_health);
                break;
            case 2:
                printf("You defended yourself with %d defense!\n", player_attack);
                player_health += player_attack;
                printf("You have %d health points.\n", player_health);
                break;
            case 3:
                printf("You have %d health points.\n", player_health);
                break;
            case 4:
                printf("The alien has %d health points.\n", enemy_health);
                break;
            case 5:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}