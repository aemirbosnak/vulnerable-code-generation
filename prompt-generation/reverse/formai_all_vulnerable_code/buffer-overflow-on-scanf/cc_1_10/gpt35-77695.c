//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>

int main() {
    char name[20];
    int age, score = 0;
    
    printf("Welcome to the Adventure Game!\n");
    printf("Please enter your name: \n");
    scanf("%s", name);
    printf("Please enter your age: \n");
    scanf("%d", &age);
    
    printf("\nHello %s! You find yourself standing at the entrance of a dark, eerie forest. There are two paths you can take - left or right. Which path will you choose?\n", name);
    printf("Enter 1 for left path or 2 for right path.\n");
    
    int choice1;
    scanf("%d", &choice1);
    
    if(choice1 == 1) {
        printf("\nYou chose the left path. As you walk deeper into the forest, you suddenly hear rustling and growling sounds coming from the bushes. Do you continue walking or run back?\n");
        printf("Enter 1 to continue walking or 2 to run back.\n");
        
        int choice2;
        scanf("%d", &choice2);
        
        if(choice2 == 1) {
            printf("\nAs you continue, you come across a pack of wolves! You need to defend yourself. What will you use as a weapon?\n");
            printf("Enter 1 for a sword, 2 for a bow and arrow, or 3 for a stick.\n");
            
            int choice3;
            scanf("%d", &choice3);
            
            if(choice3 == 1) {
                printf("\nThe sword was a good choice! You manage to fend off the pack and make it through the forest. You gain 10 points.\n");
                score += 10;
            } else if(choice3 == 2) {
                printf("\nThe bow and arrow wasn't effective against the pack. You barely make it out alive. You gain 5 points.\n");
                score += 5;
            } else {
                printf("\nUnfortunately, the stick was not a good choice and you were unable to fend off the pack. You lose 5 points and will have to start again.\n");
                score -= 5;
                return 0;
            }
        } else {
            printf("\nYou run back to the entrance of the forest and decide to try again another time. You lose 5 points.\n");
            score -= 5;
            return 0;
        }
    } else {
        printf("\nYou chose the right path. As you travel down this path, you come across a river. Do you choose to swim across or build a raft?\n");
        printf("Enter 1 to swim or 2 to build a raft.\n");
        
        int choice4;
        scanf("%d", &choice4);
        
        if(choice4 == 1) {
            printf("\nAs you swim across, you encounter a school of piranhas waiting for their next meal. They see you as a tasty snack and attack. You lose 10 points and will have to start again.\n");
            score -= 10;
            return 0;
        } else {
            printf("\nBuilding a raft was a wise choice. You safely make it across the river and continue on your adventure. You gain 10 points.\n");
            score += 10;
        }
        
    }
    
    printf("\nCongratulations on completing the Adventure Game, %s! Your final score is %d.\n", name, score);
    return 0;
}