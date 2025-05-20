//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char description[100];
} Location;

typedef struct {
    char name[30];
    char dialogue[100];
} Character;

void showLocation(Location loc) {
    printf("\nYou are at: %s\n", loc.name);
    printf("%s\n\n", loc.description);
}

void showDialogue(Character chr) {
    printf("%s says: \"%s\"\n", chr.name, chr.dialogue);
}

int main() {
    Location townSquare = {"Town Square", "A lively area with shops, benches, and a fountain."};
    Location beach = {"Beach", "A sandy stretch where you can hear the waves crashing."};
    Location lighthouse = {"Lighthouse", "A tall structure overlooking the sea, guiding lost ships."};

    Character oldMan = {"Old Man", "Ah, you've come to visit our lovely town, have you?"};
    Character fisherman = {"Fisherman", "The sea is more than just water; it's a friend."};

    int choice;
    int gameOver = 0;

    printf("Welcome to the Seaside Town Adventure!\n");
    printf("Your journey begins in the Town Square.\n");

    while (!gameOver) {
        showLocation(townSquare);

        printf("What would you like to do?\n");
        printf("1. Go to the Beach\n");
        printf("2. Visit the Lighthouse\n");
        printf("3. Talk to the Old Man\n");
        printf("4. Check Inventory\n");
        printf("5. Exit Game\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showLocation(beach);
                printf("You walk towards the beach. The sound of waves is calming.\n\n");
                break;
            case 2:
                showLocation(lighthouse);
                printf("The lighthouse stands tall against the backdrop of the setting sun.\n\n");
                break;
            case 3:
                showDialogue(oldMan);
                printf("What would you like to ask?\n");
                printf("1. About the town\n");
                printf("2. About the lighthouse\n");
                printf("3. Goodbye\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Old Man: \"This town has a rich history, filled with sailors and stories.\"\n");
                } else if (choice == 2) {
                    printf("Old Man: \"The lighthouse has been here for over a century, guiding boats safely.\"\n");
                }
                printf("\n");
                break;
            case 4:
                printf("You check your inventory, but it is empty for now.\n\n");
                break;
            case 5:
                printf("Thank you for playing! Goodbye.\n");
                gameOver = 1;
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}