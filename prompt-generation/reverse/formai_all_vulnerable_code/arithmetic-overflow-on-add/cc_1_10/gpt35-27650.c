//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int seconds) {
    clock_t start_time = clock();
    while(clock() < start_time + seconds * CLOCKS_PER_SEC);
}

struct Knight {
    char name[20];
    int health;
    int attack;
};

struct Treasure {
    char name[20];
    int value;
};

void travel_to_past() {
    int age;
    printf("Enter the age you want to travel to: ");
    scanf("%d", &age);

    if(age < 500) {
        printf("This is pre-medieval era, time travel is not possible!\n");
        exit(0);
    }
    else if(age >= 500 && age < 1000) {
        printf("Welcome to the Dark Ages!\n");
    }
    else if(age >= 1000 && age < 1500) {
        printf("Welcome to the Middle Ages!\n");
    }
    else {
        printf("Whoa! This is ancient!\n");
    }

    struct Knight player = {"Player", 100, 20};

    printf("What is your name, knight?\n");
    scanf("%s", player.name);

    printf("Welcome, %s. Your health is %d, and your attack power is %d\n", player.name, player.health, player.attack);
    delay(2);

    printf("You walk into a village and see a group of people gathered around a man in rags.\n");
    printf("Walking up to the group you realize the man is a wizard, offering treasure for anyone who will aid him on his quest.\n");
    delay(2);

    struct Treasure wand = {"Wand of Power", 500};
    printf("The wizard tells you of the powerful wand he seeks. If you find it for him, he will reward you with %d gold.\n", wand.value);
    delay(2);

    printf("Will you accept his quest? (Yes/No)\n");
    char response[5];
    scanf("%s", response);

    if(strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
        printf("The wizard thanks you and provides you with a map to the location of the wand.\n");
        delay(2);
        printf("You follow the map and come to a castle, guarded by a fierce dragon.\n");
        delay(2);
        printf("What do you do? (Fight/Sneak)\n");
        char action[10];
        scanf("%s", action);

        if(strcmp(action, "Fight") == 0 || strcmp(action, "fight") == 0) {
            printf("You approach the dragon, sword drawn, ready for battle.\n");
            delay(2);

            struct Knight dragon = {"Dragon", 200, 30};
            printf("The dragon towers over you, breathing fire and smoke. He has %d health, but deals %d damage per attack!\n", dragon.health, dragon.attack);
            delay(2);

            while(player.health > 0 && dragon.health > 0) {
                player.health -= dragon.attack;
                dragon.health -= player.attack;

                printf("You attack the dragon! ");
                printf("Dragon Health: %d, Player Health: %d\n", dragon.health, player.health);
                delay(1);

                printf("The dragon breathes fire at you! ");
                printf("Dragon Health: %d, Player Health: %d\n", dragon.health, player.health);
                delay(1);
            }

            if(player.health <= 0) {
                printf("You have been defeated by the dragon. GAME OVER.\n");
                exit(0);
            }
            else {
                printf("You have defeated the dragon and claimed the wand of power!\n");
                player.health = 100;
                player.attack += 10;
                printf("Your health has been fully restored, and your attack power has increased to %d.\n", player.attack);
                delay(2);
            }
        }
        else {
            printf("You sneak past the dragon and find the wand in the castle's treasure room.\n");
            printf("As you exit the castle, the wizard approaches you and gives you %d gold pieces as a reward.\n", wand.value);
            player.attack += 10;
            printf("Your attack power has increased to %d.\n", player.attack);
            delay(2);
        }
    }
    else {
        printf("The wizard looks disappointed, but wishes you well in your travels.\n");
        delay(2);
    }

    printf("You continue through the village until you come to a bridge over a deep canyon.\n");
    printf("As you begin to cross, an army of knights appear, led by the evil sorcerer who once terrorized these lands.\n");
    delay(2);

    struct Knight sorcerer = {"Sorcerer", 150, 25};
    printf("The sorcerer rides towards you, his army behind him. He has %d health and can deal %d damage per attack.\n", sorcerer.health, sorcerer.attack);
    delay(2);

    while(player.health > 0 && sorcerer.health > 0) {
        player.health -= sorcerer.attack;
        sorcerer.health -= player.attack;

        printf("You attack the sorcerer! ");
        printf("Sorcerer Health: %d, Player Health: %d\n", sorcerer.health, player.health);
        delay(1);

        printf("The sorcerer casts a spell at you! ");
        printf("Sorcerer Health: %d, Player Health: %d\n", sorcerer.health, player.health);
        delay(1);
    }

    if(player.health <= 0) {
        printf("You have been defeated by the sorcerer's army. GAME OVER.\n");
    }
    else {
        printf("You have defeated the sorcerer and his army!\n");
        printf("Congratulations, %s! You have completed your quest and saved the village.\n", player.name);
    }
}

int main() {
    printf("Welcome to the time travel simulator!\n");
    delay(2);

    printf("Would you like to travel through time? (Yes/No)\n");
    char response[5];
    scanf("%s", response);

    if(strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
        travel_to_past();
    }
    else {
        printf("Thank you for playing the time travel simulator!\n");
    }

    return 0;
}