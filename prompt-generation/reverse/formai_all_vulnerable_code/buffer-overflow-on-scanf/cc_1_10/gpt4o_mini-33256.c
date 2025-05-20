//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_intro();
void choose_path(int *health, int *treasure);
void encounter_monster(int *health, int *treasure);
void find_treasure(int *treasure);
void display_status(int health, int treasure);
int get_random_number(int min, int max);

int main() {
    srand(time(NULL));
    int health = 100;
    int treasure = 0;
    char play_again;

    display_intro();

    do {
        choose_path(&health, &treasure);
        display_status(health, treasure);
        if (health > 0) {
            printf("You survived the forest! Do you want to play again? (y/n): ");
            while (getchar() != '\n'); // clear input buffer
            scanf("%c", &play_again);
        } else {
            printf("You have perished in the forest. Game Over! Do you want to play again? (y/n): ");
            while (getchar() != '\n'); // clear input buffer
            scanf("%c", &play_again);
            health = 100; // reset health for replay
            treasure = 0; // reset treasure for replay
        }
    } while (play_again == 'y' || play_again == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}

void display_intro() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("You begin your journey with 100 health points.\n");
    printf("Choose your path wisely to survive and find treasure!\n\n");
}

void choose_path(int *health, int *treasure) {
    int choice;

    printf("Choose a path:\n");
    printf("1. Venture deeper into the forest.\n");
    printf("2. Explore the abandoned cabin.\n");
    printf("3. Cross the river.\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encounter_monster(health, treasure);
            break;
        case 2:
            find_treasure(treasure);
            break;
        case 3:
            printf("You safely crossed the river and enjoyed the scenery.\n");
            break;
        default:
            printf("Invalid choice. Please choose again.\n");
            choose_path(health, treasure);
            break;
    }
}

void encounter_monster(int *health, int *treasure) {
    int monster_health = get_random_number(20, 50);
    int attack_power = get_random_number(5, 15);

    printf("You encountered a wild monster! It has %d health points.\n", monster_health);
    printf("Fight or flee? (1 for fight, 2 for flee): ");
    int action;
    scanf("%d", &action);

    if (action == 1) {
        printf("You decided to fight!\n");
        while (monster_health > 0 && *health > 0) {
            monster_health -= attack_power;
            *health -= get_random_number(5, 10);
            printf("You hit the monster! Monster health: %d, Your health: %d\n", monster_health, *health);
        }
        if (monster_health <= 0) {
            printf("You defeated the monster! You gain some treasure!\n");
            *treasure += get_random_number(10, 30);
        } else {
            printf("The monster has defeated you.\n");
        }
    } else {
        printf("You chose to flee safely. However, you lost 10 health points!\n");
        *health -= 10;
    }
}

void find_treasure(int *treasure) {
    int found = get_random_number(1, 100);
    if (found > 50) {
        printf("You found a hidden stash of treasure!\n");
        *treasure += get_random_number(20, 100);
        printf("You gained treasure! Total treasure: %d\n", *treasure);
    } else {
        printf("The cabin is empty. You found nothing.\n");
    }
}

void display_status(int health, int treasure) {
    printf("\n=== Player Status ===\n");
    printf("Health: %d\n", health);
    printf("Treasure: %d\n", treasure);
    printf("======================\n");
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}