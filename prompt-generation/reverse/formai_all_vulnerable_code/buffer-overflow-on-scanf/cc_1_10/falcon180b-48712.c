//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;

    printf("Welcome to the year 3019, where humanity has finally achieved intergalactic travel.\n");
    printf("You are a space adventurer on a mission to explore the universe.\n");
    printf("What would you like to do?\n");
    printf("1. Explore a new planet\n");
    printf("2. Engage in a space battle\n");
    printf("3. Repair your spaceship\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have landed on a new planet.\n");
            printf("The atmosphere is breathable and the temperature is moderate.\n");
            printf("As you explore, you discover a new species of alien.\n");
            printf("Do you want to make contact with them?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You make contact with the aliens and they are friendly.\n");
                printf("They show you around their planet and teach you about their culture.\n");
            } else {
                printf("You decide not to make contact and continue exploring.\n");
            }
            break;

        case 2:
            printf("You engage in a space battle with an enemy ship.\n");
            printf("Your ship is armed with lasers and missiles.\n");
            printf("Do you want to use lasers or missiles?\n");
            printf("1. Lasers\n");
            printf("2. Missiles\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You fire your lasers and hit the enemy ship.\n");
                printf("The enemy ship is damaged but they fire back.\n");
                printf("You dodge their attack and fire another laser.\n");
                printf("The enemy ship is destroyed.\n");
            } else {
                printf("You launch a missile and hit the enemy ship.\n");
                printf("The enemy ship explodes into pieces.\n");
            }
            break;

        case 3:
            printf("Your spaceship has been damaged and needs repairs.\n");
            printf("Do you have the necessary tools to repair it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You use your tools to repair the spaceship.\n");
                printf("The repairs are successful and the spaceship is ready to fly again.\n");
            } else {
                printf("You do not have the necessary tools and must find a space station to repair the ship.\n");
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}