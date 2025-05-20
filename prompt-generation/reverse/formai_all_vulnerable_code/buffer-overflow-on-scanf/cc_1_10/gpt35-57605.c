//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function declaration
void printIntro();
void choosePath();
void fight();

int main() {

    printIntro();

    choosePath();

    return 0;
}


//function definition
void printIntro() {

    printf("\nYou find yourself in a dark forest.\n");
    printf("As you walk, you hear strange noises coming from the trees around you.\n");
    printf("You realize that you must find your way out of the forest, but you don't know where you are or which way to go.\n\n");

}

void choosePath() {

    char path;

    printf("Do you want to go left or right? (L/R): ");
    scanf("%c", &path);

    if(path == 'L' || path == 'l'){
        printf("\nYou chose to go left. You come across a river with a rocky path on one side and a muddy path on the other.\n");
        printf("Which path do you take? (R/M): ");

        scanf(" %c", &path);

        if(path == 'R' || path == 'r'){
            printf("\nYou chose the rocky path. As you make your way over the rocks, you slip and fall into the river.\n");
            printf("As you try to get out, you feel something pulling you deeper into the water.\n");
            fight();
        }
        else if(path == 'M' || path == 'm'){
            printf("\nYou chose the muddy path. As you make your way through the mud, you hear something rustling in the bushes.\n");
            printf("Suddenly, a large bear emerges and charges toward you.\n");
            fight();
        }
        else{
            printf("\nInvalid choice. Please enter 'R' or 'M'.\n");
            choosePath();
        }
    }
    else if(path == 'R' || path == 'r'){
        printf("\nYou chose to go right. You come across a small village.\n");
        printf("The villagers offer you food and shelter. Do you want to stay here or continue your journey? (S/J): ");

        scanf(" %c", &path);

        if(path == 'S' || path == 's'){
            printf("\nYou decide to stay in the village. The villagers welcome you and you spend a peaceful night.\n");
            printf("In the morning, you thank the villagers and continue your journey.\n");
            printf("Congratulations! You have successfully navigated through the forest.\n");
        }
        else if(path == 'J' || path == 'j'){
            printf("\nYou decide to continue your journey. As you leave the village, you hear footsteps behind you.\n");
            printf("You turn around and see a group of bandits approaching you.\n");
            fight();
        }
        else{
            printf("\nInvalid choice. Please enter 'S' or 'J'.\n");
            choosePath();
        }

    }
    else{
        printf("\nInvalid choice. Please enter 'L' or 'R'.\n");
        choosePath();
    }

}

void fight(){

    int playerHealth = 100;
    int banditHealth = 100;

    printf("\nA battle begins!\n");

    //randomly choose who goes first
    srand(time(NULL));
    int first = rand() % 2;

    //fight
    while(playerHealth > 0 && banditHealth > 0){

        if(first == 0){

            //player attacks
            int damage = rand() % 10;
            printf("You attack and deal %d damage.\n", damage);
            banditHealth -= damage;

            if(banditHealth <= 0){
                printf("Congratulations! You have defeated the bandits.\n");
                break;
            }

            //bandit attacks
            damage = rand() % 10;
            printf("The bandit attacks and deals %d damage.\n", damage);
            playerHealth -= damage;

            if(playerHealth <= 0){
                printf("You have been defeated by the bandits. Game Over.\n");
                exit(0);
            }

        }
        else{

            //bandit attacks
            int damage = rand() % 10;
            printf("The bandit attacks and deals %d damage.\n", damage);
            playerHealth -= damage;

            if(playerHealth <= 0){
                printf("You have been defeated by the bandits. Game Over.\n");
                exit(0);
            }

            //player attacks
            damage = rand() % 10;
            printf("You attack and deal %d damage.\n", damage);
            banditHealth -= damage;

            if(banditHealth <= 0){
                printf("Congratulations! You have defeated the bandits.\n");
                break;
            }

        }

    }

}