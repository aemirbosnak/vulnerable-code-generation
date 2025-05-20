//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[20];
    char answer[10];
    int choice, sword = 0, treasure = 0; 
    
    printf("Welcome to Medieval Adventure Game!\n");
    printf("What is your name, adventurer?\n");
    scanf("%s", name);
    
    printf("\nGreetings, %s! You find yourself in a forest clearing.\n", name);
    printf("There are two paths in front of you. Which one do you take?\n");
    printf("1. The path to the left.\n2. The path to the right.\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou come across a band of goblins!\n");
        printf("Do you:\n1. Fight the goblins.\n2. Run away.\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nYou fight the goblins and emerge victorious!\n");
            printf("You find a sword lying among the goblin's possessions.\n");
            printf("Do you take the sword?\n1. Yes.\n2. No.\n");
            scanf("%d", &choice);
            
            if (choice == 1) {
                sword = 1;
                printf("\nYou take the sword and continue on your way.\n");
            } else {
                printf("\nYou leave the sword and continue on your way.\n");
            }
        } else {
            printf("\nYou run away and continue on your way.\n");
        }
        
        printf("\nYou come across a dragon!\n");
        printf("Do you:\n1. Fight the dragon.\n2. Offer it the goblin's treasure.\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (sword == 1) {
                printf("\nYou use the sword to slay the dragon and claim its treasure!\n");
                treasure = 1;
            } else {
                printf("\nYou do not have a sword and are unable to fight the dragon. You continue on your way.\n");
            }
        } else {
            if (treasure == 1) {
                printf("\nYou offer the dragon the treasure and it lets you pass unharmed.\n");
            } else {
                printf("\nYou do not have the treasure and the dragon attacks you. You are unable to continue.\n");
                return 0;
            }
        }
        
        printf("\nCongratulations, %s! You have completed the game!\n", name);
    } else {
        printf("\nYou come across a wizard!\n");
        printf("Do you:\n1. Talk to the wizard.\n2. Ignore the wizard and continue on your way.\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nThe wizard tells you that a curse has been placed on a nearby village.\n");
            printf("He says that if you help break the curse, he will reward you with treasure.\n");
            printf("Do you:\n1. Accept the wizard's offer.\n2. Reject the wizard's offer.\n");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou agree to break the curse and the wizard teleports you to the village.\n");
                printf("You find that the curse has caused all of the crops to wither and die.\n");
                printf("You must find a way to restore the crops.\n");
                printf("Do you:\n1. Use your own magic to restore the crops.\n2. Find a magical plant to restore the crops.\n");
                scanf("%d",&choice);
                
                if (choice == 1) {
                    printf("\nYou use your own magic to restore the crops and break the curse!\n");
                    treasure = 1;
                } else {
                    printf("\nYou venture out into the forest to find a magical plant.\n");
                    printf("You come across a hidden garden where the plant grows.\n");
                    printf("As you pick the plant, you are confronted by a group of bandits!\n");
                    printf("Do you:\n1. Fight the bandits.\n2. Offer them the plant.\n");
                    scanf("%d", &choice);
                    
                    if (choice == 1) {
                        printf("\nYou fight the bandits and retrieve the treasure they had stolen!\n");
                        treasure = 1;
                    } else {
                        printf("\nYou offer the plant to the bandits and they let you pass unharmed.\n");
                        treasure = 1;
                    }
                }
                
                printf("\nYou return to the wizard and break the curse!\n");
                
                if (treasure == 1) {
                    printf("The wizard rewards you with treasure for your efforts!\n");
                }
                
                printf("\nCongratulations, %s! You have completed the game!\n", name);
            } else {
                printf("\nYou reject the wizard's offer and continue on your way.\n");
                printf("You come across a troll under a bridge!\n");
                printf("Do you:\n1. Pay the toll.\n2. Refuse to pay the toll and try to fight the troll.\n");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    printf("\nYou pay the toll and continue on your way. You have failed the game.\n");
                    return 0;
                } else {
                    printf("\nYou try to fight the troll but it is too strong!\n");
                    printf("You have failed the game.\n");
                    return 0;
                }
            }
        } else {
            printf("\nYou ignore the wizard and continue on your way.\n");
            printf("You come across a group of villagers who need your help!\n");
            printf("Do you:\n1. Help the villagers.\n2. Ignore the villagers and continue on your way.\n");
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("\nYou help the villagers and they reward you with treasure!\n");
                printf("\nCongratulations, %s! You have completed the game!\n", name);
            } else {
                printf("\nYou ignore the villagers and continue on your way.\n");
                printf("You come across a pack of wolves!\n");
                printf("Do you:\n1. Fight the wolves.\n2. Run away from the wolves.\n");
                scanf("%d", &choice);
                
                if (choice == 1) {
                    printf("\nYou fight the wolves but are badly injured!\n");
                    printf("You are unable to continue and have failed the game.\n");
                    return 0;
                } else {
                    printf("\nYou run away from the wolves and continue on your way.\n");
                    printf("\nCongratulations, %s! You have completed the game!\n", name);
                }
            }
        }
    }
    
    return 0;
}