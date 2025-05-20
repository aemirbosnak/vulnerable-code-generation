//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_ITEMS 5

// Structure to hold menu items
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Structure for each player
typedef struct {
    char name[30];
    int order[MAX_ITEMS];
    float total_bill;
} Player;

// Function prototypes
void displayMenu(MenuItem menu[], int itemCount);
void takeOrder(Player *player, MenuItem menu[], int itemCount);
void calculateTotal(Player *player, MenuItem menu[], int itemCount);
void displayBill(Player *player);

int main() {
    MenuItem menu[] = {
        {"Coffee", 2.5},
        {"Tea", 1.5},
        {"Sandwich", 3.0},
        {"Cake", 4.0},
        {"Soda", 1.0}
    };
    int itemCount = sizeof(menu) / sizeof(menu[0]);
    
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    
    printf("Welcome to the Multiplayer Cafe Billing System!\n");
    printf("How many players are ordering? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    for (int i = 0; i < playerCount; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        memset(players[i].order, 0, sizeof(players[i].order)); // Initialize order to zero
        players[i].total_bill = 0.0;
        
        printf("Player %s, here is the menu:\n", players[i].name);
        displayMenu(menu, itemCount);
        takeOrder(&players[i], menu, itemCount);
        calculateTotal(&players[i], menu, itemCount);
        displayBill(&players[i]);
    }
    
    return 0;
}

void displayMenu(MenuItem menu[], int itemCount) {
    printf("Menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder(Player *player, MenuItem menu[], int itemCount) {
    printf("Please enter the item numbers you wish to order (0 to finish):\n");
    int itemNumber;
    while (1) {
        printf("Enter item number: ");
        scanf("%d", &itemNumber);
        if (itemNumber == 0) break; // Finish ordering
        if (itemNumber < 1 || itemNumber > itemCount) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }
        player->order[itemNumber - 1]++;
    }
}

void calculateTotal(Player *player, MenuItem menu[], int itemCount) {
    player->total_bill = 0.0;
    for (int i = 0; i < itemCount; i++) {
        player->total_bill += player->order[i] * menu[i].price;
    }
}

void displayBill(Player *player) {
    printf("\nBill for %s:\n", player->name);
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (player->order[i] > 0) {
            printf("%d x %s - $%.2f\n", player->order[i], player->name, player->order[i] * (player->order[i] > 0 ? (i + 1) : 0));
        }
    }
    printf("Total Bill: $%.2f\n", player->total_bill);
}