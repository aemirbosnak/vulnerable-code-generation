//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player_health = 100;
    int ghost_health = 75;
    int player_damage = 20;
    int ghost_damage = 15;
    int potion_values[3] = {20,30,40};
    char player_choice;
    srand(time(0));

    printf("Welcome to the Haunted House Simulator! You are a brave adventurer who seeks thrills and treasure. However, this house is said to be cursed. Are you sure you want to continue? [Y/N] ");
    scanf("%c",&player_choice);

    if(player_choice == 'Y' || player_choice == 'y'){
        printf("You enter the dark and gloomy entrance of the haunted house. As you walk through the hallway, you hear strange noises and feel a chill running down your spine.\n");
        while(player_health > 0 && ghost_health > 0){
            int random_choice = rand()%3;
            printf("\nYour current health: %d\n",player_health);
            printf("You have encountered a ghost! Its health is %d\n",ghost_health);
            printf("What do you want to do? \n");
            printf("[A] Attack the ghost \n");
            printf("[H] Use a health potion \n");
            printf("[R] Run away \n");
            scanf("%c",&player_choice);
            if(player_choice == 'A' || player_choice == 'a'){
                int player_roll = rand()%16;
                int ghost_roll = rand()%16;
                printf("\nYou attack the ghost and deal %d damage! \n",player_damage+player_roll);
                printf("The ghost retaliates and deals %d damage. \n",ghost_damage+ghost_roll);
                player_health -= ghost_damage+ghost_roll;
                ghost_health -= player_damage+player_roll;
            }
            else if(player_choice == 'H' || player_choice == 'h'){
                printf("Which potion do you want to use? \n");
                printf("[1] %d health points\n",potion_values[0]);
                printf("[2] %d health points\n",potion_values[1]);
                printf("[3] %d health points\n",potion_values[2]);
                scanf("%c",&player_choice);
                if(player_choice == '1'){
                    player_health += potion_values[0];
                }
                else if(player_choice == '2'){
                    player_health += potion_values[1];
                }
                else if(player_choice == '3'){
                    player_health += potion_values[2];
                }
                printf("\nYou feel reinvigorated! Your health is now %d\n",player_health);
            }
            else if(player_choice == 'R' || player_choice == 'r'){
                printf("You run as fast as you can and leave the haunted house behind...\n");
                break;
            }
            else{
                printf("Invalid input. Please try again.\n");
            }
        }
        if(player_health <= 0){
            printf("You have been defeated by the ghost. Your adventure ends here.\n");
        }
        else{
            printf("You have defeated the ghost and emerge victorious! As you loot its corpse, you find a valuable treasure. Congratulations, brave adventurer!\n");
        }

    }
    else{
        printf("You decide to turn back and leave the haunted house untouched.\n");
    }
    return 0;
}