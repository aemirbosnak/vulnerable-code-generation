//Falcon-180B DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to print the medieval style menu
void medievalMenu() {
    printf("Ye Olde Menu:\n");
    printf("1. Dine with the King\n");
    printf("2. Joust for Honor\n");
    printf("3. Visit the Castle\n");
    printf("4. Quit\n");
}

// Function to simulate dining with the king
void dineWithKing() {
    printf("You are seated at the king's table, feasting on roasted boar and mead.\n");
    printf("The king regales you with tales of his latest conquests.\n");
    printf("You feel honored to be in his presence.\n");
}

// Function to simulate jousting for honor
void joustForHonor() {
    printf("You mount your trusty steed and charge towards your opponent.\n");
    printf("Your lances clash, sending sparks flying.\n");
    printf("You manage to unseat your opponent and claim victory.\n");
    printf("The crowd cheers as you are crowned the champion.\n");
}

// Function to simulate visiting the castle
void visitCastle() {
    printf("You enter the castle gates and are greeted by the guards.\n");
    printf("You explore the castle's many rooms and halls, marveling at its grandeur.\n");
    printf("From the top of the castle tower, you can see the entire kingdom spread out before you.\n");
}

// Recursive function to handle user input and call appropriate functions
void handleInput(int choice) {
    switch(choice) {
        case 1:
            dineWithKing();
            break;
        case 2:
            joustForHonor();
            break;
        case 3:
            visitCastle();
            break;
        case 4:
            printf("You bid farewell to the medieval world and return to reality.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice;

    // Print the medieval style menu
    medievalMenu();

    // Recursive loop to handle user input
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleInput(choice);
        printf("\n");
    }

    return 0;
}