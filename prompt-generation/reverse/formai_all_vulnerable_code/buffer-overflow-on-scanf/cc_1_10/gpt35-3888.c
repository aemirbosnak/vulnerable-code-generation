//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

char name[20];
int health = 100;

void attack(char* enemy, int damage){
    printf("You attacked %s for %d damage!\n", enemy, damage);
}

void heal(int amount){
    health += amount;
    printf("You healed yourself for %d hit points. Your health is now %d.\n", amount, health);
}

int main(){

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Welcome, %s! Your adventure begins now...\n\n", name);

    char choice[20];
    printf("You find yourself in a dark, spooky forest. You must find your way out.\n");
    printf("As you walk along the path, you hear rustling in the bushes.\n");
    printf("Your options are to ATTACK or HEAL.\n");
    while(strcmp(choice, "attack") != 0 && strcmp(choice, "heal") != 0){
        printf("What do you want to do? ");
        scanf("%s", choice);
        if(strcmp(choice, "attack") == 0){
            attack("the monster", 20);
            break;
        }
        else if(strcmp(choice, "heal") == 0){
            heal(20);
            break;
        }
        else{
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("You continue on your journey, and you come across a river.\n");
    printf("You can either SWIM across or BUILD A RAFT.\n");
    while(strcmp(choice, "swim") != 0 && strcmp(choice, "raft") != 0){
        printf("What do you want to do? ");
        scanf("%s", choice);
        if(strcmp(choice, "swim") == 0){
            printf("You start swimming across the river. The current is strong and you struggle to stay afloat.\n");
            printf("You take some damage from hitting rocks along the way.\n");
            health -= 30;
            printf("Your health is now %d.\n", health);
            if(health <= 0){
                printf("Oh no! You died from the injuries sustained during the swim. Game over.\n");
                return 0;
            }
            break;
        }
        else if(strcmp(choice, "raft") == 0){
            printf("You build a raft out of pieces of wood and start to cross the river.\n");
            printf("You make it across safely and continue on your journey.\n");
            break;
        }
        else{
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("You come across a fork in the road. You can go left or right.\n");
    printf("LEFT takes you to a town. RIGHT takes you to a cave.\n");
    while(strcmp(choice, "left") != 0 && strcmp(choice, "right") != 0){
        printf("What do you want to do? ");
        scanf("%s", choice);
        if(strcmp(choice, "left") == 0){
            printf("You make your way to the town. You find a helpful merchant who sells you a better weapon.\n");
            printf("You now deal more damage in combat. Your attack is now 30.\n");
            break;
        }
        else if(strcmp(choice, "right") == 0){
            printf("You enter the dark cave. It's full of dangerous creatures.\n");
            printf("You come across a powerful monster. Do you want to ATTACK or RUN AWAY?\n");
            while(strcmp(choice, "attack") != 0 && strcmp(choice, "run") != 0){
                printf("What do you want to do? ");
                scanf("%s", choice);
                if(strcmp(choice, "attack") == 0){
                    attack("the powerful monster", 50);
                    printf("You defeated the powerful monster! You find a treasure chest and open it.\n");
                    printf("You find a potion that heals you completely.\n");
                    health = 100;
                    printf("Your health is now %d.\n", health);
                    break;
                }
                else if(strcmp(choice, "run") == 0){
                    printf("You try to run away, but the monster catches up to you and attacks you.\n");
                    printf("You take some damage and your health is now %d.\n", health-40);
                    if(health-40 <= 0){
                        printf("Oh no! You died from your injuries sustained during the fight. Game over.\n");
                        return 0;
                    }
                    else{
                        printf("You manage to run away and continue on your journey.\n");
                        health -= 40;
                        break;
                    }
                }
                else{
                    printf("Invalid choice. Try again.\n");
                }
            }   
            break;
        }
        else{
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("Congratulations, %s! You made it through the Text-Based Adventure Game!\n", name);
    printf("Your final health was %d.\n", health);

    return 0;
}