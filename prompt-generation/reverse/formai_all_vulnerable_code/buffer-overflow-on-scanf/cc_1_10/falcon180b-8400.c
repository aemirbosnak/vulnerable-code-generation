//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    char name[20];

    printf("Welcome to the Happy Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n");
    printf("Hello, %s! You are standing in a beautiful meadow filled with colorful flowers.\n", name);
    printf("The sun is shining brightly and the birds are singing.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the meadow\n");
    printf("2. Listen to the birds\n");
    printf("3. Pick some flowers\n");
    printf("4. Dance in the sunshine\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n");
            printf("You decide to explore the meadow.\n");
            printf("As you walk through the tall grass, you discover a hidden path leading to a magical forest.\n");
            printf("Do you want to follow the path? (y/n)\n");
            char follow;
            scanf(" %c", &follow);

            if(follow == 'y' || follow == 'Y') {
                printf("\n");
                printf("You follow the path and enter the magical forest.\n");
                printf("The trees are covered in sparkling fairy lights and there's a gentle breeze blowing.\n");
                printf("You feel so happy and at peace here.\n");
            } else {
                printf("\n");
                printf("You decide to stay in the meadow and enjoy the beautiful scenery.\n");
            }
            break;

        case 2:
            printf("\n");
            printf("You close your eyes and listen to the birds singing their sweet melodies.\n");
            printf("It's such a peaceful and calming experience.\n");
            break;

        case 3:
            printf("\n");
            printf("You carefully pick some of the most beautiful flowers in the meadow.\n");
            printf("They smell so lovely and make you feel even happier.\n");
            break;

        case 4:
            printf("\n");
            printf("You start dancing in the sunshine, twirling around and laughing.\n");
            printf("It feels so freeing and joyful!\n");
            break;

        default:
            printf("\n");
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}