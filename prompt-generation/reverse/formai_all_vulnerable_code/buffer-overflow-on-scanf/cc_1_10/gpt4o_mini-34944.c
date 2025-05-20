//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_intro() {
    printf("Welcome to the Serene Forest Adventure!\n");
    printf("You find yourself in a tranquil forest, surrounded by towering trees and chirping birds.\n");
    printf("Your goal is to explore the forest, meet its friendly inhabitants, and discover the hidden treasures.\n\n");
}

void forest_path();
void meet_squirrel();
void follow_stream();
void find_grove();
void listen_to_birdsong();

int main() {
    show_intro();
    forest_path();
    return 0;
}

void forest_path() {
    char choice[10];
    printf("You stand at a fork in the path. Do you want to go 'left' or 'right'? ");
    scanf("%s", choice);

    if (strcmp(choice, "left") == 0) {
        meet_squirrel();
    } else if (strcmp(choice, "right") == 0) {
        follow_stream();
    } else {
        printf("That's not a valid option! Please choose 'left' or 'right'.\n");
        forest_path();
    }
}

void meet_squirrel() {
    printf("\nYou chose to go left and found a cheerful squirrel!\n");
    char choice[10];
    printf("The squirrel offers you a nut. Do you want to 'accept' or 'decline'? ");
    scanf("%s", choice);

    if (strcmp(choice, "accept") == 0) {
        printf("You accept the nut and the squirrel dances happily!\n");
        printf("With a full heart, you continue your adventure.\n\n");
        find_grove();
    } else if (strcmp(choice, "decline") == 0) {
        printf("The squirrel looks a bit sad but wishes you well.\n");
        listen_to_birdsong();
    } else {
        printf("That's not a valid option! Please choose 'accept' or 'decline'.\n");
        meet_squirrel();
    }
}

void follow_stream() {
    printf("\nYou chose to go right and walk along a gentle stream.\n");
    char choice[10];
    printf("As you stroll, you notice a family of ducks swimming. Do you want to 'watch' them or 'continue' walking? ");
    scanf("%s", choice);

    if (strcmp(choice, "watch") == 0) {
        printf("You sit by the stream and watch the ducks play. It’s a peaceful moment.\n");
        printf("After a while, you feel refreshed and decide to continue your adventure.\n\n");
        find_grove();
    } else if (strcmp(choice, "continue") == 0) {
        printf("You continue walking along the stream until you find a beautiful clearing.\n");
        listen_to_birdsong();
    } else {
        printf("That's not a valid option! Please choose 'watch' or 'continue'.\n");
        follow_stream();
    }
}

void find_grove() {
    printf("\nYou arrive at a beautiful grove filled with vibrant flowers and singing birds.\n");
    printf("It's a perfect place to relax and reflect. Do you want to 'rest' or 'explore' further? ");
    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "rest") == 0) {
        printf("You sit down on the soft grass and take in the beauty around you, feeling peaceful.\n");
        printf("The sun sets, and you feel a sense of fulfillment.\n");
        printf("Thank you for playing the Serene Forest Adventure!\n");
    } else if (strcmp(choice, "explore") == 0) {
        printf("You wander deeper into the grove and discover a hidden treasure: a sparkling gem!\n");
        printf("You take it as a keepsake of this beautiful journey.\n");
        printf("Thank you for playing the Serene Forest Adventure!\n");
    } else {
        printf("That's not a valid option! Please choose 'rest' or 'explore'.\n");
        find_grove();
    }
}

void listen_to_birdsong() {
    printf("\nYou sit quietly and close your eyes, letting the melodies of the birds wash over you.\n");
    printf("It's a calming experience, and you feel a deep connection to nature.\n");
    printf("After a while, you decide to continue your exploration of the forest.\n");
    find_grove();
}