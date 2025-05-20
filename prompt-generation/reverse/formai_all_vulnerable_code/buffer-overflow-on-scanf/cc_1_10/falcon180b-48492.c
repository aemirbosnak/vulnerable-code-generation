//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the Introspective Space Adventure!\n\n");
    printf("You are a seasoned space explorer, traveling through the vastness of the universe.\n");
    printf("Your mission is to navigate through various challenges and discover new worlds.\n\n");

    while (1) {
        system("clear");
        printf("What would you like to do?\n");
        printf("1. Explore a new planet\n");
        printf("2. Repair your spaceship\n");
        printf("3. Encounter an alien species\n");
        printf("4. Reflect on your journey so far\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou land on a new planet, eager to explore its unknown terrain.\n");
                printf("As you step out of your spaceship, you notice the air is thick with a strange mist.\n");
                printf("You take a deep breath and begin your journey, unsure of what lies ahead.\n");
                break;

            case 2:
                printf("\nYour spaceship has been damaged during your latest adventure.\n");
                printf("You must repair it before continuing your journey through the cosmos.\n");
                break;

            case 3:
                printf("\nWhile exploring a distant planet, you encounter an alien species unlike any you've seen before.\n");
                printf("They communicate with you telepathically, sharing their knowledge of the universe and its secrets.\n");
                break;

            case 4:
                printf("\nYou take a moment to reflect on your journey so far, remembering the challenges you've faced and overcome.\n");
                printf("As you think back on your experiences, you realize how much you've grown as a space explorer.\n");
                break;

            case 5:
                printf("\nThank you for joining us on this Introspective Space Adventure!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}