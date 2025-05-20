//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 100

struct knight{
    char name[MAX_STRING_LENGTH];
    int health;
    int attack;
    int defense;
};

struct castle{
    char name[MAX_STRING_LENGTH];
    int health;
    int defense;
};

void createKnight(struct knight* knight, char* name, int health, int attack, int defense){
    strcpy(knight->name, name);
    knight->health = health;
    knight->attack = attack;
    knight->defense = defense;
}

void createCastle(struct castle* castle, char* name, int health, int defense){
    strcpy(castle->name, name);
    castle->health = health;
    castle->defense = defense;
}

void attackCastle(struct knight* knight, struct castle* castle){
    int damage = knight->attack - castle->defense;
    if(damage > 0){
        castle->health -= damage;
        printf("%s has dealt %d damage to %s.\n", knight->name, damage, castle->name);
    }
    else{
        printf("%s's attack was blocked by %s.\n", knight->name, castle->name);
    }
}

void defendCastle(struct castle* castle){
    printf("%s is defending itself.\n", castle->name);
}

int main(){
    struct knight sirLancelot;
    createKnight(&sirLancelot, "Sir Lancelot", 100, 20, 10);

    struct castle camelot;
    createCastle(&camelot, "Camelot", 200, 30);

    int choice;
    do{
        printf("Enter your choice:\n");
        printf("1. Attack Camelot\n");
        printf("2. Defend Camelot\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                attackCastle(&sirLancelot, &camelot);
                break;
            case 2:
                defendCastle(&camelot);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!= 3);

    return 0;
}