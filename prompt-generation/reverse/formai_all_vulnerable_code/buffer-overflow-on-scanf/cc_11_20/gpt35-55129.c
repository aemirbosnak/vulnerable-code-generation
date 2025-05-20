//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

int main() {
    char inventory[20][50] = {"knife", "water bottle", "matches", "map", "flashlight", "rope", "first aid kit", "compass", "canned food", "gun"};
    int num_items = 10;

    printf("Welcome to the post-apocalyptic world! Your task is to survive and make it to the next safe zone. Here's your inventory:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s\n", i+1, inventory[i]);
    }

    char action[20];
    int choice;
    printf("What will you do now, survivor? (type 'help' for instructions)\n");
    scanf("%s", action);

    while(1) {
        if(strcmp(action, "help") == 0) {
            printf("Type 'explore' to search for more supplies.\nType 'use' to use an item.\nType 'exit' to quit the program.\n");
        }
        else if(strcmp(action, "explore") == 0) {
            printf("You venture into the unknown, searching for supplies...\n");
            // some code to generate random supply
            // assume we found a new supply "gasoline"
            strcpy(inventory[num_items], "gasoline");
            num_items++;
            printf("You have found a new item - gasoline! Your inventory now consists of:\n");
            for(int i=0; i<num_items; i++) {
                printf("%d. %s\n", i+1, inventory[i]);
            }
        }
        else if(strcmp(action, "use") == 0) {
            printf("Which item would you like to use? (type the number of the item)\n");
            scanf("%d", &choice);
            if(choice>num_items || choice<=0) {
                printf("Invalid choice, please choose a valid item.\n");
                continue;
            }
            printf("You used the %s.\n", inventory[choice-1]);
            // some code to handle item usage (like decreasing health)
            // assume using gasoline increases speed
            if(strcmp(inventory[choice-1], "gasoline") == 0) {
                printf("Using gasoline, you are now able to travel faster!\n");
            }
        }
        else if(strcmp(action, "exit") == 0) {
            printf("Goodbye survivor, stay safe out there!\n");
            break;
        }
        else {
            printf("Invalid input, please type 'help' for instructions.\n");
        }
        printf("What will you do next, survivor?\n");
        scanf("%s", action);
    }

    return 0;
}