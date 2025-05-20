//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to the Land of Adventure!\n\n");
    printf("You find yourself in a beautiful forest filled with tall trees and colorful flowers.\n");
    printf("The sun is shining brightly through the leaves, casting dappled shadows on the ground.\n");
    printf("A gentle breeze rustles the leaves and carries the sweet scent of blooming flowers.\n\n");
    printf("What would you like to do?\n");
}

void forest() {
    printf("You decide to explore the forest further.\n\n");
    printf("As you walk along the winding path, you come across a small stream.\n");
    printf("The water is crystal clear and sparkles in the sunlight.\n");
    printf("You can hear the soothing sound of the water flowing over smooth stones.\n\n");
    printf("What would you like to do?\n");
}

void stream() {
    printf("You decide to follow the stream.\n\n");
    printf("As you walk along the bank, you notice a group of butterflies fluttering around a patch of wildflowers.\n");
    printf("Their wings are brightly colored and seem to shimmer in the sunlight.\n");
    printf("You can hear the soft fluttering of their wings as they dance from flower to flower.\n\n");
    printf("What would you like to do?\n");
}

void butterflies() {
    printf("You decide to watch the butterflies for a while.\n\n");
    printf("As you sit down on the soft grass, you feel a sense of peace and tranquility wash over you.\n");
    printf("The gentle breeze carries the sweet scent of the flowers, and you can hear the distant sound of birdsong.\n");
    printf("You watch as the butterflies continue their graceful dance, and you feel a sense of wonder at the beauty of nature.\n\n");
    printf("What would you like to do?\n");
}

void main() {
    srand(time(NULL));
    int choice;

    intro();

    while(1) {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                forest();
                break;
            case 2:
                stream();
                break;
            case 3:
                butterflies();
                break;
            case 4:
                printf("Thank you for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}