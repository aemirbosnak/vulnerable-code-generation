//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    
void clear_screen() {
    system("clear");
}

void wait_for_input() {
    printf("\nPress ENTER to continue...");
    getchar();
}

void display_introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    wait_for_input();
    clear_screen();
}

int display_options(char* options[], int num_options) {
    printf("What do you want to do next?\n");
    for (int i = 0; i < num_options; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
    printf("Enter the number of your choice: ");
    int choice;
    scanf("%d", &choice);
    while (choice < 1 || choice > num_options) {
        printf("\nInvalid choice. Please try again.\n");
        printf("Enter the number of your choice: ");
        scanf("%d", &choice);
    }
    return choice;
}

void handle_selection(int choice) {
    clear_screen();
    switch (choice) {
        case 1:
            printf("You choose to explore the forest.\n");
            wait_for_input();
            clear_screen();
            break;
        case 2:
            printf("You choose to enter the castle.\n");
            wait_for_input();
            clear_screen();
            break;
        case 3:
            printf("You choose to enter the cave.\n");
            wait_for_input();
            clear_screen();
            break;
    }
}

int main() {
    char* options[3] = {"Explore the forest", "Enter the castle", "Enter the cave"};
    display_introduction();
    int choice;
    do {
        choice = display_options(options, 3);
        handle_selection(choice);
    } while (choice != 3);
    printf("Thanks for playing!\n");
    return 0;
}