//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char favorite_flower[NAME_LENGTH];
    char love_color[NAME_LENGTH];
} RomanticPartner;

RomanticPartner database[MAX_ENTRIES];
int current_count = 0;

void add_entry() {
    if (current_count >= MAX_ENTRIES) {
        printf("Alas! The memory of my heart can hold no more.\n");
        return;
    }
    
    RomanticPartner new_partner;
    printf("\nEnter the name of your beloved: ");
    fgets(new_partner.name, NAME_LENGTH, stdin);
    new_partner.name[strcspn(new_partner.name, "\n")] = 0; // Remove the newline character
    
    printf("What is their favorite flower? ");
    fgets(new_partner.favorite_flower, NAME_LENGTH, stdin);
    new_partner.favorite_flower[strcspn(new_partner.favorite_flower, "\n")] = 0; // Remove the newline character
    
    printf("What color enchants their soul? ");
    fgets(new_partner.love_color, NAME_LENGTH, stdin);
    new_partner.love_color[strcspn(new_partner.love_color, "\n")] = 0; // Remove the newline character

    database[current_count] = new_partner;
    current_count++;
    printf("Ah, your beloved has been added to the annals of your heart's database.\n");
}

void display_entries() {
    printf("\nThe names of the beloveds in the database:\n");
    for (int i = 0; i < current_count; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Favorite flower: %s\n", database[i].favorite_flower);
        printf("Love color: %s\n", database[i].love_color);
        printf("-------------------------\n");
    }

    if (current_count == 0) {
        printf("The pages are blank, as love has yet to awaken in this heart.\n");
    }
}

void search_entry() {
    char name[NAME_LENGTH];
    printf("Whose essence do you seek? Enter their name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character
    
    for (int i = 0; i < current_count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Ah! You have found your beloved!\n");
            printf("Name: %s\n", database[i].name);
            printf("Favorite flower: %s\n", database[i].favorite_flower);
            printf("Love color: %s\n", database[i].love_color);
            return;
        }
    }
    printf("Alas! No entry for this beloved was found in the story of your heart.\n");
}

void romantic_menu() {
    int choice;
    do {
        printf("\nWelcome to the Romance Database!\n");
        printf("1. Add a new romantic partner\n");
        printf("2. Display all entries\n");
        printf("3. Search for a romantic partner\n");
        printf("4. Exit\n");
        printf("Choose your desire (1-4): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Parting is such sweet sorrow, until we meet again.\n");
                break;
            default:
                printf("Oh, dear heart! That is not a valid choice.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Once upon a time, in the land of Romantic Echoes...\n");
    romantic_menu();
    return 0;
}