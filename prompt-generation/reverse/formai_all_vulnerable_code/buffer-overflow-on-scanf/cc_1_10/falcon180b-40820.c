//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n%s, you find yourself in a dark and mysterious forest.\n", name);
    printf("There are three paths ahead of you:\n");
    printf("1. The path to the left leads to a river.\n");
    printf("2. The path in the middle leads to a mountain.\n");
    printf("3. The path to the right leads to a castle.\n");
    printf("\nWhich path do you choose? ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou have chosen the path to the left.\n");
            printf("%s, you walk along the path and soon hear the sound of rushing water.\n", name);
            printf("As you approach the river, you see a small boat tied to a tree.\n");
            printf("Do you want to take the boat across the river? (y/n) ");
            char boat;
            scanf("%c", &boat);
            if(boat == 'y' || boat == 'Y') {
                printf("\nYou get into the boat and start rowing across the river.\n");
                printf("%s, you successfully make it to the other side.\n", name);
            } else {
                printf("\nYou decide not to take the boat and turn back.\n");
            }
            break;
        case 2:
            printf("\nYou have chosen the path in the middle.\n");
            printf("%s, you walk along the path and soon see a towering mountain in front of you.\n", name);
            printf("Do you want to climb the mountain? (y/n) ");
            char climb;
            scanf("%c", &climb);
            if(climb == 'y' || climb == 'Y') {
                printf("\nYou start climbing the mountain.\n");
                printf("%s, after a strenuous climb, you finally reach the top.\n", name);
            } else {
                printf("\nYou decide not to climb the mountain and turn back.\n");
            }
            break;
        case 3:
            printf("\nYou have chosen the path to the right.\n");
            printf("%s, you walk along the path and soon see a magnificent castle in front of you.\n", name);
            printf("Do you want to enter the castle? (y/n) ");
            char castle;
            scanf("%c", &castle);
            if(castle == 'y' || castle == 'Y') {
                printf("\nYou enter the castle and explore its many rooms.\n");
                printf("%s, you find a treasure hidden in one of the rooms.\n", name);
            } else {
                printf("\nYou decide not to enter the castle and turn back.\n");
            }
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}