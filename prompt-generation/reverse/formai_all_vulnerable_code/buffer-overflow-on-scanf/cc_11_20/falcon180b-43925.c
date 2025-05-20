//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int choice;
    char name[10];
    int age;
    int gender;
    int health = 100;
    int money = 100;
    int score = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! You are a %d year old %s.\n", name, age, gender == 0? "man" : "woman");
    printf("You have %d health points and %d dollars.\n", health, money);

    while(1) {
        system("clear");
        printf("Score: %d\n", score);
        printf("Health: %d\n", health);
        printf("Money: $%d\n", money);
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Attack an enemy\n");
        printf("2. Defend against an attack\n");
        printf("3. Rest and regain health\n");
        printf("4. Buy items from the store\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You attack an enemy and deal 10 damage.\n");
                health -= 5;
                score += 5;
                break;
            case 2:
                printf("You defend against an attack and take 5 damage.\n");
                health -= 5;
                score += 2;
                break;
            case 3:
                printf("You rest and regain 10 health points.\n");
                health += 10;
                score += 3;
                break;
            case 4:
                printf("Welcome to the store!\n");
                printf("1. Health potion: restores 20 health points - $10\n");
                printf("2. Weapon: deals 15 damage - $50\n");
                printf("3. Armor: reduces damage by 5 - $30\n");
                printf("4. Back\n");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        if(money >= 10) {
                            printf("You buy a health potion and restore 20 health points.\n");
                            health += 20;
                            money -= 10;
                            score += 5;
                        } else {
                            printf("You don't have enough money.\n");
                        }
                        break;
                    case 2:
                        if(money >= 50) {
                            printf("You buy a weapon and can now deal 15 damage.\n");
                            money -= 50;
                            score += 10;
                        } else {
                            printf("You don't have enough money.\n");
                        }
                        break;
                    case 3:
                        if(money >= 30) {
                            printf("You buy armor and reduce damage by 5.\n");
                            money -= 30;
                            score += 7;
                        } else {
                            printf("You don't have enough money.\n");
                        }
                        break;
                    case 4:
                        printf("Back to main menu\n");
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 5:
                printf("Thanks for playing! Your final score is %d.\n", score);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}