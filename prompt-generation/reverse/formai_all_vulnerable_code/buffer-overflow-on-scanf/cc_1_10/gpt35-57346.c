//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice;
    char name[20], weapon[20], boss[20];

    time_t t;

    srand((unsigned) time(&t)); //using srand() function to generate random numbers

    printf("Welcome to the game of fate. What is your name?\n");
    scanf("%s", name);

    printf("Greetings, %s. You are now embarking on a journey that will test your strength and perseverance. You must choose your weapon wisely. Here are your choices:\n\n");
    printf("1. Sword\n2. Bow\n3. Magic Wand\n");

    scanf("%d", &choice);

    if(choice == 1)
        strcpy(weapon, "Sword");
    else if(choice == 2)
        strcpy(weapon, "Bow");
    else if(choice == 3)
        strcpy(weapon, "Magic Wand");

    printf("You have chosen %s as your weapon. Good choice!\n\n", weapon);

    printf("You are now faced with your first challenge. A giant %s blocks your path. What do you do?\n", boss);

    int damage = rand()%50 + 1; //using rand() function to generate a random number between 1 and 50

    printf("You attack the %s with your %s and do %d damage!\n", boss, weapon, damage);

    printf("The %s retaliates and does %d damage to you!\n", boss, rand()%50 + 1);

    printf("You must now decide whether to attack again or use a potion to heal yourself. What do you do?\n");

    printf("1. Attack again\n2. Use potion\n");

    scanf("%d", &choice);

    if(choice == 1){
        damage = rand()%50 + 1;
        printf("You attack again with your %s and do %d damage!\n", weapon, damage);
        printf("The %s retaliates and does %d damage to you!\n", boss, rand()%50 + 1);

        if(damage > 40)
            printf("You have slain the %s and gained 100 gold!\n", boss);
        else
            printf("You have been defeated. Game over.\n");
    }
    else if(choice == 2){
        printf("You use a potion and are healed!\n");
        printf("The %s attacks again and does %d damage to you!\n", boss, rand()%50 + 1);
        printf("You must now attack again to defeat the %s!\n", boss);

        damage = rand()%50 + 1;
        printf("You attack with your %s and do %d damage!\n", weapon, damage);

        if(damage > 40)
            printf("You have slain the %s and gained 100 gold!\n", boss);
        else
            printf("You have been defeated. Game over.\n");
    }

    return 0;
}