//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_METHODS 3
#define TAROT_CARDS 1
#define CRYSTAL_BALL 2
#define PALM_READING 3

const char *fortunes[] = {
    [TAROT_CARDS] = "You will find happiness and prosperity soon.",
    [CRYSTAL_BALL] = "The future holds great opportunities for you.",
    [PALM_READING] = "Your past actions will influence your future."
};

void print_menu() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please select a method for your fortune telling:\n");
    printf("1. Tarot Cards\n");
    printf("2. Crystal Ball\n");
    printf("3. Palm Reading\n");
    printf("Enter your choice (1-3): ");
}

int get_user_input() {
    int choice;
    scanf("%d", &choice);

    while (choice < 1 || choice > NUM_METHODS) {
        printf("Invalid input! Please enter a valid choice (1-3): ");
        scanf("%d", &choice);
    }

    return choice;
}

int main() {
    int user_choice;
    int random_number;

    srand(time(NULL));

    print_menu();
    user_choice = get_user_input();

    random_number = rand() % NUM_METHODS + 1;

    if (user_choice == random_number) {
        printf("Your fortune is: %s\n", fortunes[user_choice - 1]);
    } else {
        printf("Try again next time!\n");
    }

    return 0;
}