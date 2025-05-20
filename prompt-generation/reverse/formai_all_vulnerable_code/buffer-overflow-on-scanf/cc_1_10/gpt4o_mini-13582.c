//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

// Function Declarations
void print_intro();
void print_choices();
int get_choice();
void examine_kitchen();
void examine_living_room();
void examine_garage();
void find_sandwich();
void eat_sandwich();
void display_inventory();

// Global Variables
char *inventory[MAX_ITEMS];
int inventory_count = 0;

int main() {
    print_intro();

    while (1) {
        print_choices();
        int choice = get_choice();

        switch (choice) {
            case 1:
                examine_kitchen();
                break;
            case 2:
                examine_living_room();
                break;
            case 3:
                examine_garage();
                break;
            case 4:
                eat_sandwich();
                break;
            case 5:
                display_inventory();
                break;
            case 6:
                printf("You decided to take a nap instead. Good luck finding your sandwich upon waking!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

void print_intro() {
    printf("Welcome to the Quest for the Missing Sandwich!\n");
    printf("You're on an epic journey to find your beloved sandwich.\n");
    printf("It might not be a dragon, but it's just as important!\n\n");
}

void print_choices() {
    printf("What do you want to do?\n");
    printf("1. Examine the kitchen\n");
    printf("2. Examine the living room\n");
    printf("3. Examine the garage\n");
    printf("4. Eat the sandwich (if found)\n");
    printf("5. Check your inventory\n");
    printf("6. Take a nap\n");
}

int get_choice() {
    int choice;
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    return choice;
}

void examine_kitchen() {
    printf("You stroll into the kitchen. Spaghetti is hanging from the ceiling, and a cat looks at you like you owe it money.\n");
    if (inventory_count < MAX_ITEMS) {
        printf("A delicious sandwich lies on the counter! You add it to your inventory.\n");
        inventory[inventory_count++] = "Sandwich";
    } else {
        printf("Your inventory is full! You can't carry any more sandwiches, but there’s one here!\n");
    }
}

void examine_living_room() {
    printf("You enter the living room. The couch is like a black hole, swallowing all loose change and missing socks.\n");
    printf("There’s something shiny! You find a remote control, but you can't find your sandwich.\n");
    if (inventory_count < MAX_ITEMS) {
        printf("You pick up the remote control. It's added to your inventory!\n");
        inventory[inventory_count++] = "Remote Control";
    } else {
        printf("Your inventory is full! You can't carry any more remotes.\n");
    }
}

void examine_garage() {
    printf("You walk into the garage. It smells surprisingly like old gym socks. Great.\n");
    printf("A mysterious box sits in the corner labeled 'DO NOT OPEN'. What will you do?\n");
    printf("1. Open the box\n");
    printf("2. Leave it alone\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You opened the box! A bunch of spiders pour out. Eww, gross!\n");
    } else {
        printf("You've chosen wisely! The spiders will live to terrify another day.\n");
    }
}

void eat_sandwich() {
    for (int i = 0; i < inventory_count; i++) {
        if (strcmp(inventory[i], "Sandwich") == 0) {
            printf("You munch down on the sandwich and suddenly feel like a superhero!\n");
            printf("Your quest has come to a glorious end! Sandwiches are the true source of power!\n");
            return;
        }
    }
    printf("You have no sandwich to eat! Just sad times and rumbling tummies.\n");
}

void display_inventory() {
    printf("You look into your bag and see:\n");
    if (inventory_count == 0) {
        printf("Your inventory is empty! A sad echo resonates...\n");
    } else {
        for (int i = 0; i < inventory_count; i++) {
            printf("%d. %s\n", i + 1, inventory[i]);
        }
    }
}