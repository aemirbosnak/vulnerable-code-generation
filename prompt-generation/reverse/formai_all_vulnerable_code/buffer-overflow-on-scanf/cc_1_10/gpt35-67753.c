//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void intro();
void kingroom();
void dragonroom();

int main(){
    intro();
    return 0;
}

void intro(){
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome to the kingdom, %s!\n", name);
    printf("You are here to defeat the fire dragon and restore peace to the land.\n");
    printf("You enter the kingdom and find two paths- one leading to the king's room and the other to the dragon's lair.\n");
    printf("Which path would you like to choose? (k/d): ");
    char choice;
    scanf(" %c", &choice);
    if(choice=='k'){
        kingroom();
    }
    else if(choice=='d'){
        dragonroom();
    }
    else{
        printf("Invalid input!");
        intro();
    }
}

void kingroom(){
    printf("You enter the king's room and bow before him.\n");
    printf("King: Welcome, young traveler. I am in need of a hero to defeat the fire dragon and restore peace to our land.\n");
    printf("King: Are you the one I have been seeking? (y/n): ");
    char choice2;
    scanf(" %c", &choice2);
    if(choice2=='y'){
        printf("King: Excellent! I will give you my strongest horse to aid you.\n");
        printf("You ride the horse and head towards the dragon's lair.\n");
        dragonroom();
    }
    else if(choice2=='n'){
        printf("King: Very well. Leave my presence at once!\n");
        exit(0);
    }
    else{
        printf("Invalid input!");
        kingroom();
    }
}

void dragonroom(){
    printf("You enter the dragon's lair and find yourself face to face with the fire-breathing beast.\n");
    printf("Dragon: Who dares to enter my domain? Prepare to meet your doom!\n");
    printf("What do you do? (attack/hide): ");
    char choice3[10];
    scanf(" %s", choice3);
    if(strcmp(choice3, "attack")==0){
        printf("You draw your sword and charge towards the dragon.\n");
        printf("Dragon: Ha! You think a mere mortal can defeat me?\n");
        printf("The dragon unleashes a blast of fire, killing you instantly.\n");
        printf("GAME OVER!");
        exit(0);
    }
    else if(strcmp(choice3, "hide")==0){
        printf("You hide behind a large boulder and wait for the dragon to turn its back.\n");
        printf("As the dragon passes by, you strike its exposed neck with your sword.\n");
        printf("The dragon roars in pain and falls to the ground.\n");
        printf("You have defeated the fire dragon and restored peace to the land!\n");
        printf("CONGRATULATIONS!");
        exit(0);
    }
    else{
        printf("Invalid input!");
        dragonroom();
    }
}