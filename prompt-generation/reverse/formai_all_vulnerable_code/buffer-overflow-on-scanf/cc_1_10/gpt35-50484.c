//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Space Adventure game!\n");
    printf("In this game, you are a brave astronaut on a mission to explore different planets and galaxies. \n");

    int fuel = 100;
    int credits = 0;

    while(fuel > 0) {
        printf("You currently have %d units of fuel and %d credits.\n", fuel, credits);
        printf("Which planet do you want to explore next? (1 for Mars, 2 for Jupiter, 3 for Saturn): ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You are now approaching Mars...\n");
                printf("You have landed safely on Mars and are greeted by little green Martians!\n");
                printf("They offer to sell you some fuel for 10 credits. Do you want to buy it? (y/n) ");

                char buy_fuel;
                scanf(" %c", &buy_fuel);

                if(buy_fuel == 'y') {
                    fuel += 50;
                    credits -= 10;
                    printf("You now have %d units of fuel and %d credits left.\n", fuel, credits);
                } else {
                    printf("You decide not to buy fuel and continue exploring Mars...\n");
                }
                break;

            case 2:
                printf("You are now approaching Jupiter...\n");
                printf("As you start to enter Jupiter's atmosphere, your spacecraft starts to shake violently!\n");
                printf("You realize you need to buy some upgrades for your spacecraft in order to survive on Jupiter.\n");
                printf("You find a space shop nearby and ask the shopkeeper if he has any upgrades for sale.\n");
                printf("He offers you a high-tech space shield for 20 credits. Do you want to buy it? (y/n) ");

                char buy_upgrade;
                scanf(" %c", &buy_upgrade);

                if(buy_upgrade == 'y') {
                    credits -= 20;
                    printf("You now have %d credits left.\n", credits);
                } else {
                    printf("You decide not to buy the upgrade and take your chances on Jupiter...\n");
                }

                printf("You manage to survive on Jupiter thanks to your daring skills and make it back to your spacecraft!\n");
                break;

            case 3:
                printf("You are now approaching Saturn...\n");
                printf("As you land on Saturn's moon Titan, you are greeted by a group of friendly alien astronauts!\n");
                printf("They invite you to join them for a space party and offer you some delicious Saturnian food.\n");
                printf("You accept their invitation and party all night long!\n");
                printf("In the morning, you realize you've lost all your credits and need to find a way to make some more...\n");
                printf("One of the alien astronauts tells you they have a secret stash of precious minerals on a nearby asteroid.\n");
                printf("They offer to let you mine the minerals and sell them for a profit. Do you accept? (y/n) ");

                char mine_minerals;
                scanf(" %c", &mine_minerals);

                if(mine_minerals == 'y') {
                    credits += 50;
                    printf("You successfully mine the precious minerals and sell them for a profit!\n");
                    printf("You now have %d credits.\n", credits);
                } else {
                    printf("You decide not to mine the minerals and explore more of Saturn instead...\n");
                }
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        fuel--;
    }

    printf("Oh no, you've run out of fuel! Your space adventure has come to an end...\n");
    return 0;
}