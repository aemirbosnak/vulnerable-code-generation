//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;

    printf("Welcome to the Happy Adventure Game!\n\n");
    printf("You wake up in a beautiful meadow filled with flowers and sunshine.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the meadow\n");
    printf("2. Take a nap in the sun\n");
    printf("3. Dance among the flowers\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("As you explore the meadow, you come across a group of friendly butterflies.\n");
            printf("They invite you to join them on their journey through the meadow.\n");
            printf("Do you accept their invitation? (y/n)\n");
            char response;
            scanf(" %c", &response);

            if(response == 'y' || response == 'Y') {
                printf("You follow the butterflies through the meadow, enjoying the beautiful scenery.\n");
                printf("Eventually, you come across a magical tree with delicious fruit.\n");
                printf("The butterflies share some of the fruit with you and it's the best thing you've ever tasted!\n");
            } else {
                printf("You decide not to join the butterflies and continue exploring on your own.\n");
            }
            break;

        case 2:
            printf("You find a cozy spot in the sun and take a nap.\n");
            printf("When you wake up, you feel refreshed and happy.\n");
            break;

        case 3:
            printf("As you dance among the flowers, you hear beautiful music.\n");
            printf("You follow the sound and discover a group of fairies playing instruments.\n");
            printf("They invite you to join them and you have a wonderful time dancing and singing together.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}