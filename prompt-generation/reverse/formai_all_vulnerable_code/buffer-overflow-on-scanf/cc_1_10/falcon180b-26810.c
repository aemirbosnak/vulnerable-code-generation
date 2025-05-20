//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure of the lost city.\n");
    printf("To begin your journey, choose a path:\n");
    printf("1. Go north\n2. Go east\n3. Go west\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You walk north and come across a river. Do you:\n");
            printf("1. Swim across\n2. Build a raft\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You successfully swim across the river and continue your journey.\n");
            } else if(choice == 2) {
                printf("You build a sturdy raft and sail across the river. Your journey continues.\n");
            } else {
                printf("Invalid choice. Game over.\n");
                return 0;
            }
            break;
        case 2:
            printf("You walk east and find yourself in a dense forest. Do you:\n");
            printf("1. Try to find a way through\n2. Turn back\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You bravely navigate through the forest and find a hidden path. Your journey continues.\n");
            } else if(choice == 2) {
                printf("You decide to turn back and try a different path. Your journey continues.\n");
            } else {
                printf("Invalid choice. Game over.\n");
                return 0;
            }
            break;
        case 3:
            printf("You walk west and come across a mountain range. Do you:\n");
            printf("1. Climb the mountains\n2. Look for a pass\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You successfully climb the mountains and reach the other side. Your journey continues.\n");
            } else if(choice == 2) {
                printf("You find a narrow pass through the mountains and continue your journey.\n");
            } else {
                printf("Invalid choice. Game over.\n");
                return 0;
            }
            break;
        default:
            printf("Invalid choice. Game over.\n");
            return 0;
    }
    printf("Congratulations! You have reached the lost city and found the legendary treasure.\n");
    return 0;
}