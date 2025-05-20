//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A little reminder that health is wealth, unless you're in a grocery store!
// That is still risky business!

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

// Structure to represent each medicine
struct Medicine {
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

// Our sincere apologies, but the medicine names can't be longer than this.
void printMenu() {
    printf("\n--- Welcome to Dr. Quack's Medicine Store! ---\n");
    printf("1. Add a medicine\n");
    printf("2. View all medicines\n");
    printf("3. Sell medicine\n");
    printf("4. Quit (because even medicine has to rest)\n");
}

// Function prototypes
void addMedicine(struct Medicine medicines[], int *medCount);
void viewMedicines(struct Medicine medicines[], int medCount);
void sellMedicine(struct Medicine medicines[], int *medCount);
void clearInputBuffer();

int main() {
    struct Medicine medicines[MAX_MEDICINES]; // Where we keep all the potions!
    int medCount = 0; // Start with no magic potions in stock!
    int choice;

    while (1) {
        printMenu();
        printf("Choose your potion: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Just in case someone tries to sneak a forbidden input!

        switch (choice) {
            case 1:
                addMedicine(medicines, &medCount);
                break;
            case 2:
                viewMedicines(medicines, medCount);
                break;
            case 3:
                sellMedicine(medicines, &medCount);
                break;
            case 4:
                printf("Thank you for stopping by! Remember, laughter is the best medicine, unless you need actual medicine ... then we'll sell you that too!\n");
                return 0;
            default:
                printf("Oops! Invalid choice! Maybe consider a career in potion making instead?\n");
        }
    }

    return 0;
}

void clearInputBuffer() {
    while(getchar() != '\n'); // Clear the input buffer because we don't want to deal with leftover junk!
}

void addMedicine(struct Medicine medicines[], int *medCount) {
    if (*medCount >= MAX_MEDICINES) {
        printf("Whoa there! We can't fit any more potions in this store!\n");
        return;
    }
    
    printf("Enter medicine name (keep it short, we're not writing a novel here): ");
    fgets(medicines[*medCount].name, NAME_LENGTH, stdin);
    medicines[*medCount].name[strcspn(medicines[*medCount].name, "\n")] = 0; // Strip newline character

    printf("Enter quantity (the more the merrier!): ");
    scanf("%d", &medicines[*medCount].quantity);
    clearInputBuffer(); // Always good to clear the air after a quantity!

    printf("Enter price (it's not free, sorry): ");
    scanf("%f", &medicines[*medCount].price);
    clearInputBuffer(); // No dirty inputs allowed!

    (*medCount)++;
    printf("The mighty %s has been added to the shelves!\n", medicines[*medCount - 1].name);
}

void viewMedicines(struct Medicine medicines[], int medCount) {
    if (medCount == 0) {
        printf("No potions in stock! Looks like a potion-less party here...\n");
        return;
    }

    printf("\n--- Current Potions in Store ---\n");
    for (int i = 0; i < medCount; i++) {
        printf("%d. %s - Quantity: %d  Price: %.2f\n", i + 1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("---------------------------------\n");
}

void sellMedicine(struct Medicine medicines[], int *medCount) {
    if (*medCount == 0) {
        printf("No potions left! Looks like everyone drank them all!\n");
        return;
    }

    printf("Which potion would you like to sell? (1 to %d): ", *medCount);
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();

    if (choice < 1 || choice > *medCount) {
        printf("Hmm... that potion doesn't seem to exist. Maybe check the back aisle again?\n");
        return;
    }

    choice--; // Because we are humans and started counting from 1!
    printf("You've chosen to sell %s. How many would you like to sell? ", medicines[choice].name);
    int sellQuantity;
    scanf("%d", &sellQuantity);
    clearInputBuffer();

    if (sellQuantity > medicines[choice].quantity) {
        printf("Woah there! You can't sell more than we have! Limited supply here, buddy!\n");
    } else {
        medicines[choice].quantity -= sellQuantity;
        printf("Sold %d of %s! Hope you made someone’s day!\n", sellQuantity, medicines[choice].name);
        if (medicines[choice].quantity == 0) {
            printf("Uh-oh! The potion %s is now out of stock!\n", medicines[choice].name);
            // Optionally we can choose to remove it from the inventory!
        }
    }
}