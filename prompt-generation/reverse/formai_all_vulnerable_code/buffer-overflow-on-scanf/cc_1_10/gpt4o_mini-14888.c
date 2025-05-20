//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

void add_medicine() {
    if (count >= MAX_MEDICINES) {
        printf("Tough luck! We can't fit any more medicine in this cupboard of wonders.\n");
        return;
    }
    
    printf("Enter the name of the medicine: ");
    scanf("%s", store[count].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[count].price);
    printf("How many do we have? (Because just one won't cut it): ");
    scanf("%d", &store[count].quantity);
    
    printf("Medicine successfully added! Now it’s part of our magical store!\n");
    count++;
}

void display_medicines() {
    if (count == 0) {
        printf("Is this a ghost store? No medicines here to display!\n");
        return;
    }
    
    printf("Here’s our marvelous lineup of medicines:\n");
    printf("Name\t\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%.2f\t%d\n", store[i].name, store[i].price, store[i].quantity);
    }
}

void sell_medicine() {
    char name[50];
    int quantity;

    printf("What’s the magic potion you want? (Enter the medicine name): ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("How many units of %s do you want? (Be careful, they're not free!): ", store[i].name);
            scanf("%d", &quantity);
            if (quantity > store[i].quantity) {
                printf("Oops! We don’t have enough stock. We need a better inventory manager!\n");
            } else {
                store[i].quantity -= quantity;
                printf("You bought %d units of %s! We hope you enjoy your health potion!\n", quantity, store[i].name);
            }
            return;
        }
    }
    printf("Uh-oh! Looks like we don’t have that magical item!\n");
}

void restock_medicine() {
    char name[50];
    int quantity;
    
    printf("Which potion needs more ingredients? (Enter the medicine name): ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("How many more units of %s should we summon? (Let’s replenish our stock!): ", store[i].name);
            scanf("%d", &quantity);
            store[i].quantity += quantity;
            printf("Behold! %d units of %s have been magically summoned!\n", quantity, store[i].name);
            return;
        }
    }
    printf("Oops! Looks like you've entered the name of a ghost! We don’t stock that!\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Wacky Medical Store Management System!\n");
    while (1) {
        printf("\nChoose your adventure:\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Restock Medicine\n");
        printf("5. Exit\n");
        printf("What will it be? (Enter the number): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                sell_medicine();
                break;
            case 4:
                restock_medicine();
                break;
            case 5:
                printf("Thanks for visiting the Wacky Pharmacy! May your health be as good as our jokes!\n");
                exit(0);
            default:
                printf("Hmm... that option is as rare as a unicorn in a pharmacy! Try again!\n");
        }
    }
    
    return 0;
}