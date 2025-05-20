//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    int choice1, choice2, choice3, weapon;
    int health = 100, ammo = 20, credits = 0;
    
    printf("Welcome to the Cyberpunk City. What's your name?\n");
    scanf("%s", name);
    printf("\n");
    
    printf("Greetings %s, you are a mercenary hired for a mission.\n", name);
    printf("Your objective is to infiltrate the Tower of Megacorp and steal the data\n");
    printf("of their latest project. However, the Tower is heavily guarded, so you will\n");
    printf("need to make choices wisely, choose your weapons and inventory carefully.\n");
    printf("\n");
    printf("Press any key to continue.\n");
    getchar();
    
    printf("You approach the Tower, there are several ways to get inside.\n");
    printf("1) Sneak in through the ventilation system.\n");
    printf("2) Bribe the guard with credits.\n");
    printf("3) Guns blazing through the front entrance.\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);
    printf("\n");
    
    if(choice1 == 1) {
        printf("You successfully manage to sneak through the ventilation system\n");
        printf("and enter the Tower undetected. However, you are unarmed.\n");
        printf("You see a pistol and a knife lying on the table.\n");
        printf("1) Take the pistol.\n");
        printf("2) Take the knife.\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &weapon);
        printf("\n");
        
        if(weapon == 1) {
            printf("You take the pistol, it has %d ammo.\n", ammo);
        }
        else {
            printf("You take the knife.\n");
        }
    }
    else if(choice1 == 2) {
        printf("You approach the guard and offer him %d credits.\n", credits);
        printf("He takes the credits and lets you pass. You enter the Tower.\n");
        printf("You see a pistol and a knife lying on the table.\n");
        printf("1) Take the pistol.\n");
        printf("2) Take the knife.\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &weapon);
        printf("\n");

        if(weapon == 1) {
            printf("You take the pistol, it has %d ammo.\n", ammo);
        }
        else {
            printf("You take the knife.\n");
        }
    }
    else {
        printf("You run towards the front entrance, guns blazing.\n");
        printf("There are several guards in front of you, you need to eliminate them.\n");
        printf("1) Use the pistol.\n");
        printf("2) Use the knife.\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &weapon);
        printf("\n");

        if(weapon == 1) {
            ammo -= 5;
            printf("You fire the pistol, taking down %d guards. You have %d ammo left.\n", 5, ammo);
        }
        else {
            printf("You charge towards the guards with the knife, taking down %d guards.\n", 3);
        }
    }
    
    printf("You make your way up to the objective, however it's guarded by a boss.\n");
    printf("The boss has %d health, you need to defeat him to get the data.\n", 150);
    printf("\n");
    printf("1) Use the pistol.\n");
    printf("2) Use the knife.\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);
    printf("\n");
    
    if(choice2 == 1) {
        while(health > 0 && ammo > 0) {
            health -= 25;
            ammo -= 5;
            printf("You shoot the boss with your pistol, dealing 25 damage. ");
            printf("The boss has %d health left. You have %d ammo left.\n", health, ammo);
            printf("\n");
        }
    }
    else {
        while(health > 0) {
            health -= 20;
            printf("You attack the boss with your knife, dealing 20 damage. ");
            printf("The boss has %d health left.\n", health);
            printf("\n");
        }
    }
    
    if(health <= 0) {
        printf("You defeat the boss and obtain the data. ");
        printf("Congratulations %s, you have completed the mission.\n", name);
    }
    else {
        printf("You ran out of ammo and the boss defeats you. ");
        printf("Better luck next time.\n");
    }
    
    return 0;
}