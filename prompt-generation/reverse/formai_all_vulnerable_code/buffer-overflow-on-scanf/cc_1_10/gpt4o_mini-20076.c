//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void introduction();
void choice1();
void choice2();
void choice3();
void happyEnding();
void tragicEnding();

int main() {
    introduction();

    return 0;
}

void introduction() {
    printf("Romeo and Juliet: A Tragic Love Story\n");
    printf("In fair Verona, where we lay our scene...\n\n");
    printf("You are Romeo. You have fallen in love with Juliet.\n");
    printf("Choose wisely, for your love story awaits!\n");
    choice1();
}

void choice1() {
    int choice;

    printf("Do you want to:\n");
    printf("1. Sneak into the Capulet's party\n");
    printf("2. Go home and forget about Juliet\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            choice2();
            break;
        case 2:
            printf("With a heavy heart, you return home and forget your love.\n");
            break;
        default:
            printf("Invalid choice. You simply stand in confusion...\n");
            choice1();
            break;
    }
}

void choice2() {
    int choice;

    printf("\nYou've made it to the Capulet's party!\n");
    printf("Do you want to:\n");
    printf("1. Dance with Juliet\n");
    printf("2. Leave the party quickly\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            choice3();
            break;
        case 2:
            printf("You leave the party and miss your chance at love. What a regret...\n");
            break;
        default:
            printf("Invalid choice. You hesitate, lost in thought...\n");
            choice2();
            break;
    }
}

void choice3() {
    int choice;

    printf("\nYou dance with Juliet and your hearts intertwine!\n");
    printf("Do you want to:\n");
    printf("1. Confess your love for Juliet\n");
    printf("2. Keep it a secret for now\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            happyEnding();
            break;
        case 2:
            tragicEnding();
            break;
        default:
            printf("Invalid choice. You get lost in the moment...\n");
            choice3();
            break;
    }
}

void happyEnding() {
    printf("\nYou confess your love for Juliet!\n");
    printf("Together, you defy the feud between the Montagues and Capulets.\n");
    printf("Against all odds, your love prevails. A happy ending!\n");
}

void tragicEnding() {
    printf("\nYou keep your love a secret, but fate has other plans...\n");
    printf("Miscommunication leads to a tragic chain of events.\n");
    printf("In the end, both you and Juliet meet a tragic fate.\n");
    printf("What could have been is lost forever...\n");
}