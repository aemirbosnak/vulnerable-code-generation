//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You are an adventurer seeking the legendary treasure hidden deep in the forest.\n");
    printf("Be careful, as the forest is home to magical creatures and dangerous traps.\n\n");
    printf("Press Enter to start your journey...\n");
    getchar();
}

void first_choice() {
    int choice;
    printf("You find yourself at the entrance of the forest.\n");
    printf("In front of you, two paths diverge:\n");
    printf("1. Take the left path (you hear a river).\n");
    printf("2. Take the right path (you see a faint light).\n");
    printf("Make your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume leftover newline

    if (choice == 1) {
        printf("\nYou chose the left path...\n");
        printf("You arrive at a river with a mysterious bridge.\n");
        printf("What will you do?\n");
        printf("1. Cross the bridge.\n");
        printf("2. Follow the river upstream.\n");
    } else {
        printf("\nYou chose the right path...\n");
        printf("You find yourself facing a small clearing with a glowing mushroom.\n");
        printf("What will you do?\n");
        printf("1. Inspect the mushroom.\n");
        printf("2. Continue deeper into the forest.\n");
    }
}

void left_path_choice() {
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou bravely cross the bridge...\n");
        printf("Halfway across, the bridge starts to tremble!\n");
        printf("You can either:\n");
        printf("1. Run back to safety.\n");
        printf("2. Keep going bravely.\n");
        
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou run back just in time, narrowly escaping the collapsing bridge!\n");
            printf("You have to find another way.\n");
            first_choice();
        } else {
            printf("\nYou bravely continue and reach the other side.\n");
            printf("There, you find the treasure chest!\n");
            printf("Congratulations! You have found the legendary treasure!\n");
        }
    } else {
        printf("\nYou follow the river upstream...\n");
        printf("You find a hidden cave, but inside lurks a fearsome guardian!\n");
        printf("You have two choices:\n");
        printf("1. Fight the guardian.\n");
        printf("2. Sneak away quietly.\n");
        
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou valiantly fight the guardian!\n");
            printf("After a fierce battle, you defeat it and find a hidden gem in the cave.\n");
            printf("Congratulations! You are a true hero of the forest.\n");
        } else {
            printf("\nYou sneak away quietly, avoiding the conflict.\n");
            printf("However, you miss the opportunity for treasure...\n");
            printf("But you still live to see another day.\n");
        }
    }
}

void right_path_choice() {
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nYou curiously inspect the glowing mushroom...\n");
        printf("As you touch it, you are engulfed in a cloud of sparkling dust!\n");
        printf("You are now under a magical spell...\n");
        printf("You can either:\n");
        printf("1. Try to resist the spell.\n");
        printf("2. Embrace the magic.\n");
        
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou resist the spell with all your might!\n");
            printf("You break free and escape the clearing safely!\n");
            first_choice();
        } else {
            printf("\nYou embrace the magic and gain the ability to communicate with the creatures of the forest!\n");
            printf("They guide you to the treasure!\n");
            printf("Congratulations! You are now the protector of the Enchanted Forest.\n");
        }
    } else {
        printf("\nYou continue deeper into the forest...\n");
        printf("You encounter a wise old tree that offers you advice:\n");
        printf("1. Accept the advice and follow it.\n");
        printf("2. Ignore the tree and pursue your own path.\n");
        
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou follow the tree's advice...\n");
            printf("It leads you directly to the treasure!\n");
            printf("Congratulations! You have become the wealthiest adventurer!\n");
        } else {
            printf("\nYou ignore the tree and continue wandering.\n");
            printf("Unfortunately, you become lost in the forest...\n");
            printf("But you vow to find your way back another day.\n");
        }
    }
}

int main() {
    introduction();
    first_choice();
    return 0;
}