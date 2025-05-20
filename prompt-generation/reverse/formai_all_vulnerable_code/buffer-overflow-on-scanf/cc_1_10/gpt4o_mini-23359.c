//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BoxItem {
    char description[100];
    int mysteryNumber;
    struct BoxItem *next;
} BoxItem;

BoxItem *createItem(const char *description, int number) {
    BoxItem *newItem = (BoxItem *)malloc(sizeof(BoxItem));
    if (newItem) {
        strcpy(newItem->description, description);
        newItem->mysteryNumber = number;
        newItem->next = NULL;
    }
    return newItem;
}

void addItem(BoxItem **head, const char *description, int number) {
    BoxItem *newItem = createItem(description, number);
    if (*head == NULL) {
        *head = newItem;
    } else {
        BoxItem *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

void revealBox(BoxItem *head) {
    BoxItem *current = head;
    printf("Welcome to the Mystery Box!\n");
    printf("Here are the items inside:\n");
    while (current != NULL) {
        printf("Item: %s with a mystery number of: %d\n", current->description, current->mysteryNumber);
        current = current->next;
    }
    printf("What mysteries are hidden inside?\n");
}

void guessMystery(BoxItem *head) {
    if (head == NULL) {
        printf("The box is empty! No mysteries to guess.\n");
        return;
    }

    int guessedNumber;
    BoxItem *current = head;
    
    printf("Guess the mystery number of the next item:\n");
    while (current != NULL) {
        printf("Item: '%s', your guess: ", current->description);
        scanf("%d", &guessedNumber);
        
        if (guessedNumber == current->mysteryNumber) {
            printf("Correct! The mystery of '%s' is revealed! 🎉\n", current->description);
        } else {
            printf("Wrong guess for '%s'. The mystery number was %d 😢\n", current->description, current->mysteryNumber);
        }
        current = current->next;
    }
}

void freeBox(BoxItem *head) {
    BoxItem *current = head;
    BoxItem *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    BoxItem *mysteryBox = NULL;
    
    printf("Creating a mystery box...\n");
    addItem(&mysteryBox, "Old Leather Book", 42);
    addItem(&mysteryBox, "Ancient Astral Map", 23);
    addItem(&mysteryBox, "Crystal Orb", 17);
    addItem(&mysteryBox, "Enchanted Amulet", 99);
    
    revealBox(mysteryBox);
  
    guessMystery(mysteryBox);
    
    printf("Thank you for revealing the mysteries of the box!\n");
    
    freeBox(mysteryBox);
    
    return 0;
}