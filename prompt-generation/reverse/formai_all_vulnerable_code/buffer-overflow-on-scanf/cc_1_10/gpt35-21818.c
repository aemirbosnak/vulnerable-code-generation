//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// struct for player information
struct Player{
    char name[20];
    int health;
    int attack;
    int defense;
};

// function prototypes
void menu();
void create_player(struct Player*);
void print_stats(struct Player*);
void battle(struct Player*, struct Player*);

int main(){
    int choice;
    struct Player player1, player2;
    
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Adventure Game!\n");
    
    do{
        menu();
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                create_player(&player1);
                create_player(&player2);
                printf("\n%s and %s are ready to battle!\n\n", player1.name, player2.name);
                battle(&player1, &player2);
                break;
            case 2:
                printf("Exiting game...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while(choice != 2);
    
    return 0;
}

// function to display menu options
void menu(){
    printf("\nMENU\n");
    printf("1. Start game\n");
    printf("2. Exit game\n");
    printf("Enter choice: ");
}

// function to create a new player
void create_player(struct Player *p){
    printf("Enter player name: ");
    scanf("%s", p->name);
    
    p->health = rand() % 100 + 1;
    p->attack = rand() % 10 + 1;
    p->defense = rand() % 10 + 1;
    
    printf("%s has been created!\n", p->name);
    print_stats(p);
}

// function to print player stats
void print_stats(struct Player *p){
    printf("\n%s's stats:\n", p->name);
    printf("Health: %d\n", p->health);
    printf("Attack: %d\n", p->attack);
    printf("Defense: %d\n", p->defense);
}

// function for the battle sequence
void battle(struct Player *p1, struct Player *p2){
    int turn = 1;
    
    while(p1->health > 0 && p2->health > 0){
        printf("TURN %d\n", turn);
        printf("%s's turn:\n", p1->name);
        int damage = p1->attack - p2->defense;
        if(damage < 0) damage = 0;
        p2->health -= damage;
        printf("%s dealt %d damage to %s.\n", p1->name, damage, p2->name);
        if(p2->health <= 0){
            printf("%s has been defeated!\n", p2->name);
            break;
        }
        print_stats(p2);
        
        printf("%s's turn:\n", p2->name);
        damage = p2->attack - p1->defense;
        if(damage < 0) damage = 0;
        p1->health -= damage;
        printf("%s dealt %d damage to %s.\n", p2->name, damage, p1->name);
        if(p1->health <= 0){
            printf("%s has been defeated!\n", p1->name);
            break;
        }
        print_stats(p1);
        
        turn++;
    }
    
    printf("\nBattle is over!\n");
}