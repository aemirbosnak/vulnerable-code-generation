//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_intro() {
    printf("Welcome to the Mysterious Castle Adventure!\n");
    printf("You are standing at the entrance of a dark, ancient castle.\n");
    printf("Your goal is to navigate through its eerie halls and find the hidden treasure.\n\n");
}

void print_options() {
    printf("You can: \n");
    printf("1. Enter the castle\n");
    printf("2. Run away\n");
}

void enter_castle() {
    printf("\nYou cautiously step into the castle. Shadows dance on the walls as your heart races.\n");
    printf("You can explore: \n");
    printf("1. The Grand Hall\n");
    printf("2. The Dark Dungeon\n");
    printf("3. The Enchanted Library\n");
}

void grand_hall() {
    printf("\nYou are in the Grand Hall. There's a long table with strange items.\n");
    printf("You can: \n");
    printf("1. Investigate the table\n");
    printf("2. Go back to the entrance\n");
}

void dark_dungeon() {
    printf("\nYou enter the Dark Dungeon. It smells of dampness and decay.\n");
    printf("You can: \n");
    printf("1. Search for clues\n");
    printf("2. Leave immediately\n");
}

void enchanted_library() {
    printf("\nYou step into the Enchanted Library. Books are floating around!\n");
    printf("You can: \n");
    printf("1. Read a book\n");
    printf("2. Exit to the Grand Hall\n");
}

void investigate_table() {
    printf("\nYou found a mysterious map under the table! It reveals hidden passages in the castle.\n");
    printf("Congratulations! You've gained knowledge!\n");
}

void search_clues() {
    printf("\nAs you search the dungeon, you find a hidden trapdoor!\n");
    printf("You can: \n");
    printf("1. Enter the trapdoor\n");
    printf("2. Leave the dungeon\n");
}

void read_book() {
    printf("\nThe book has ancient spells. You can choose one to cast!\n");
    printf("1. Lightning Bolt\n");
    printf("2. Healing Light\n");
}

int main() {
    int choice;
    print_intro();
    print_options();
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        enter_castle();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                grand_hall();
                scanf("%d", &choice);
                if (choice == 1) {
                    investigate_table(); // .invoked function
                } else {
                    printf("You safely exit the castle. Game Over.\n");
                }
                break;
            case 2:
                dark_dungeon();
                scanf("%d", &choice);
                if (choice == 1) {
                    search_clues(); // .invoked function
                } else {
                    printf("You ran away from the dungeon. Game Over.\n");
                }
                break;
            case 3:
                enchanted_library();
                scanf("%d", &choice);
                if (choice == 1) {
                    read_book(); // .invoked function
                } else {
                    printf("You exited the library safely. Game Over.\n");
                }
                break;
            default:
                printf("That's not a valid choice. Game Over.\n");
                break;
        }
    } else {
        printf("You chose to run away. The adventure ends here.\n");
    }

    return 0;
}