//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    char choice1[20];
    char choice2[20];
    
    printf("Welcome to the Quest for the Golden Chalice!\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    printf("Greetings, %s! And how old are you?\n", name);
    scanf("%d", &age);
    printf("Ah, a brave young soul indeed with the courage of %d years!\n", age);
    printf("You find yourself at the entrance to a dark cave. Do you enter?\n");
    printf("Yes or No?\n");
    scanf("%s", choice1);
    
    if (strcmp(choice1, "Yes") == 0) {
        printf("As you enter the cave, you hear a loud rumbling sound.\n");
        printf("Do you investigate or run away?\n");
        scanf("%s", choice2);
        
        if (strcmp(choice2, "Investigate") == 0) {
            printf("You follow the sound and discover an underground river.\n");
            printf("Do you follow the river or continue deeper into the cave?\n");
            scanf("%s", choice1);
            
            if (strcmp(choice1, "Follow") == 0) {
                printf("The river takes you to an underground lake.\n");
                printf("You see a glimmering object in the distance.\n");
                printf("Do you swim to the object or turn back?\n");
                scanf("%s", choice2);
                
                if (strcmp(choice2, "Swim") == 0) {
                    printf("As you get closer, you realize it is the Golden Chalice!\n");
                    printf("Congratulations, %s! You have completed the Quest for the Golden Chalice!\n", name);
                }
                else {
                    printf("You turn back and continue deeper into the cave.\n");
                    printf("You come across a room filled with treasures, but also guarded by a fierce dragon.\n");
                    printf("Do you fight the dragon or try to sneak past it?\n");
                    scanf("%s", choice1);
                    
                    if (strcmp(choice1, "Fight") == 0) {
                        printf("You bravely charge the dragon and slay it with your sword!\n");
                        printf("You collect the treasures and find the Golden Chalice among them.\n");
                        printf("Congratulations, %s! You have completed the Quest for the Golden Chalice!\n", name);
                    }
                    else {
                        printf("You attempt to sneak past the dragon, but it catches your scent.\n");
                        printf("You quickly run back to the entrance of the cave.\n");
                        printf("The Quest for the Golden Chalice remains uncompleted...\n");
                    }
                }
            }
            else {
                printf("You continue deeper into the cave and come across a chamber filled with lava.\n");
                printf("Do you attempt to navigate around the lava or turn back?\n");
                scanf("%s", choice2);
                
                if (strcmp(choice2, "Navigate") == 0) {
                    printf("You carefully navigate around the lava and come across a room filled with treasures.\n");
                    printf("You find the Golden Chalice among them.\n");
                    printf("Congratulations, %s! You have completed the Quest for the Golden Chalice!\n", name);
                }
                else {
                    printf("You turn back and head to the entrance of the cave.\n");
                    printf("The Quest for the Golden Chalice remains uncompleted...\n");
                }
            }
        }
        else {
            printf("You run away from the sound and find yourself outside of the cave.\n");
            printf("The Quest for the Golden Chalice remains uncompleted...\n");
        }
    }
    else {
        printf("You decide not to enter the cave.\n");
        printf("The Quest for the Golden Chalice remains uncompleted...\n");
    }
    
    return 0;
}