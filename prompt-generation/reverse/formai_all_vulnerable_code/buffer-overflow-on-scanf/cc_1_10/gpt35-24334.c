//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char player_name[20];
    char response[20];
    int health = 100;
    int damage = 0;

    printf("Welcome to the Visionary Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);

    printf("Hello %s, your adventure begins in a dark forest.\n", player_name);
    printf("Your objective is to find a magical amulet that has been lost in the forest for centuries.\n");
    printf("Explore the forest and beware of the dangers that lurk.\n");

    printf("\nYou come across a fork in the road. Do you go left or right? (Enter 'left' or 'right'): ");
    scanf("%s", response);

    if(strcmp(response, "left") == 0) {
        printf("You chose to go left.\n");
        printf("As you're walking, you hear a rustling in the bushes. Do you investigate? (Enter 'yes' or 'no'): ");
        scanf("%s", response);

        if(strcmp(response, "yes") == 0) {
            printf("You investigate the rustling and encounter a giant spider!\n");
            printf("Get ready to fight!\n");

            // Battle sequence
            do {
                damage = rand() % 20;
                health -= damage;
                printf("You take %d damage from the spider. Your health is now at %d.\n", damage, health);

                damage = rand() % 20;
                printf("You deal %d damage to the spider.\n", damage);
            } while(health > 0);

            printf("\nCongratulations, you defeated the spider and earned 50 experience points!\n");
        } else {
            printf("You continue down the path and come across a clearing with a waterfall.\n");
            printf("You relax by the waterfall and regain 20 health points.\n");
            
            health += 20;
            printf("Your health is now at %d.\n", health);
        }
    } else {
        printf("You chose to go right.\n");
        printf("You come across a group of goblins! They see you and start attacking!\n");
        printf("Get ready to fight!\n");

        // Battle sequence
        do {
            damage = rand() % 20;
            health -= damage;
            printf("You take %d damage from the goblins. Your health is now at %d.\n", damage, health);

            damage = rand() % 20;
            printf("You deal %d damage to the goblins.\n", damage);
        } while(health > 0);

        printf("\nYou were defeated by the goblins. Game over!\n");
        return 0;
    }

    printf("\nAs you continue through the forest, you come across a magical tree.\n");
    printf("The tree speaks to you and tells you that the amulet is located in a nearby cave.\n");
    printf("You thank the tree for its help and make your way to the cave.\n");

    printf("\nAt the entrance of the cave, you see a sign that reads 'Beware of the dragon!'\n");
    printf("Do you enter the cave or turn back? (Enter 'enter' or 'turn back'): ");
    scanf("%s", response);

    if(strcmp(response, "enter") == 0) {
        printf("You enter the cave and come face-to-face with the dragon!\n");
        printf("Get ready to fight!\n");

        // Battle sequence
        do {
            damage = rand() % 20;
            health -= damage;
            printf("You take %d damage from the dragon. Your health is now at %d.\n", damage, health);

            damage = rand() % 20;
            printf("You deal %d damage to the dragon.\n", damage);
        } while(health > 0);

        if(health <= 0) {
            printf("\nYou were defeated by the dragon. Game over!\n");
            return 0;
        } else {
            printf("\nCongratulations, you defeated the dragon and found the magical amulet!\n");
            printf("You put on the amulet and feel its magical power surging through you.\n");
            printf("You have completed your quest. Congratulations %s!\n", player_name);
        }

    } else {
        printf("You turn back and decide not to face the dragon.\n");
        printf("You live the rest of your life wondering what could have been...\n");
        printf("Game over!\n");
    }

    return 0;
}