//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    char name[20];
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s! You are in a magical forest.\n", name);
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Talk to the animals\n");
    printf("3. Find a treasure\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You decide to explore the forest.\n");
            printf("As you walk through the forest, you come across a river.\n");
            printf("Do you want to cross the river? (y/n) ");
            char river;
            scanf("%c", &river);
            if(river == 'y') {
                printf("You successfully crossed the river.\n");
            } else {
                printf("You decide not to cross the river.\n");
            }
            break;
        case 2:
            printf("You decide to talk to the animals.\n");
            printf("You see a rabbit. Do you want to talk to it? (y/n) ");
            char rabbit;
            scanf("%c", &rabbit);
            if(rabbit == 'y') {
                printf("The rabbit tells you about a secret path in the forest.\n");
            } else {
                printf("You decide not to talk to the rabbit.\n");
            }
            break;
        case 3:
            printf("You decide to find a treasure.\n");
            printf("You follow the secret path and find a treasure chest!\n");
            printf("What is the combination to open the chest? ");
            int combination;
            scanf("%d", &combination);
            if(combination == 123) {
                printf("You successfully opened the chest and found a gold coin!\n");
            } else {
                printf("The chest is locked. You need to find the right combination.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}