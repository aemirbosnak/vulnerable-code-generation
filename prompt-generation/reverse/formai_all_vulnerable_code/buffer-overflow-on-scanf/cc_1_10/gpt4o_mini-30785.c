//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOWERS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int petals;
} Flower;

typedef struct {
    Flower flowers[MAX_FLOWERS];
    int count;
} FlowerDatabase;

void addFlower(FlowerDatabase *db) {
    if (db->count >= MAX_FLOWERS) {
        printf("🌼 Oops! The garden is full! Can't add more flowers! 🌼\n");
        return;
    }
    
    Flower newFlower;
    printf("🌸 Enter the name of the flower: ");
    scanf("%s", newFlower.name);
    
    printf("🌻 How many petals does \"%s\" have? ", newFlower.name);
    scanf("%d", &newFlower.petals);
    
    db->flowers[db->count] = newFlower;
    db->count++;
    
    printf("🎉 Hooray! \"%s\" with %d petals has been added to the garden! 🌈\n", newFlower.name, newFlower.petals);
}

void displayFlowers(FlowerDatabase *db) {
    if (db->count == 0) {
        printf("🌷 The garden is empty! Why not plant some flowers? 🌱\n");
        return;
    }
    
    printf("🌼 Here are the lovely flowers in our garden: 🌼\n");
    for (int i = 0; i < db->count; i++) {
        printf("🌺 \"%s\" has %d petals! 🌹\n", db->flowers[i].name, db->flowers[i].petals);
    }
}

void searchFlower(FlowerDatabase *db) {
    char searchName[NAME_LENGTH];
    printf("🔍 Enter the name of the flower you want to search for: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->flowers[i].name, searchName) == 0) {
            printf("✨ Found it! \"%s\" has %d petals! 🌻\n", searchName, db->flowers[i].petals);
            return;
        }
    }
    
    printf("😢 Sorry, no flower named \"%s\" in the garden! 🌸\n", searchName);
}

void showMenu() {
    printf("\n🌼 Welcome to the Flower Garden Database! 🌼\n");
    printf("1. Add a Flower\n");
    printf("2. Display all Flowers\n");
    printf("3. Search for a Flower\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    FlowerDatabase db;
    db.count = 0;
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addFlower(&db);
                break;
            case 2:
                displayFlowers(&db);
                break;
            case 3:
                searchFlower(&db);
                break;
            case 4:
                printf("🌻 Thank you for visiting the Flower Garden! Goodbye! 🌼\n");
                break;
            default:
                printf("🚫 Invalid choice! Please select again. 🌼\n");
        }
    } while (choice != 4);

    return 0;
}