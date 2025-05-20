//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_KNIGHTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DEED_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char deed[MAX_DEED_LENGTH];
    int year;
} Knight;

typedef struct {
    Knight knights[MAX_KNIGHTS];
    int count;
} Kingdom;

// Function to add a knight to the kingdom
void addKnight(Kingdom *kingdom) {
    if (kingdom->count >= MAX_KNIGHTS) {
        printf("Alas! The kingdom can hold no more knights.\n");
        return;
    }

    Knight newKnight;
    printf("Enter the name of the valiant knight: ");
    scanf(" %[^\n]", newKnight.name);
    printf("Enter the deed of the noble knight: ");
    scanf(" %[^\n]", newKnight.deed);
    printf("Enter the year of great valor: ");
    scanf("%d", &newKnight.year);

    kingdom->knights[kingdom->count] = newKnight;
    kingdom->count++;
    printf("Huzzah! Sir %s has been added to the annals of our kingdom!\n", newKnight.name);
}

// Function to search for a knight by name
void searchKnight(Kingdom *kingdom, const char *name) {
    for (int i = 0; i < kingdom->count; i++) {
        if (strcmp(kingdom->knights[i].name, name) == 0) {
            printf("Sir %s's Deed: %s in the year %d.\n", 
                   kingdom->knights[i].name, 
                   kingdom->knights[i].deed, 
                   kingdom->knights[i].year);
            return;
        }
    }
    printf("Alas! No record found for Sir %s.\n", name);
}

// Function to display all knights
void displayKnights(Kingdom *kingdom) {
    if (kingdom->count == 0) {
        printf("The knightly records are bare and empty.\n");
        return;
    }
    
    printf("The noble knights of the kingdom are:\n");
    for (int i = 0; i < kingdom->count; i++) {
        printf("Sir %s, Deed: %s, Year: %d\n", 
               kingdom->knights[i].name, 
               kingdom->knights[i].deed, 
               kingdom->knights[i].year);
    }
}

// Main function
int main() {
    Kingdom kingdom;
    kingdom.count = 0;

    int choice;

    while (1) {
        printf("\nWelcome to the Kingdom of Knights!\n");
        printf("1. Add a Knight\n");
        printf("2. Search for a Knight\n");
        printf("3. Display All Knights\n");
        printf("4. Exit\n");
        printf("Choose thy quest (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addKnight(&kingdom);
                break;
            case 2: {
                char searchName[MAX_NAME_LENGTH];
                printf("Enter the name of the knight to seek: ");
                scanf(" %[^\n]", searchName);
                searchKnight(&kingdom, searchName);
                break;
            }
            case 3:
                displayKnights(&kingdom);
                break;
            case 4:
                printf("Farewell, noble seeker of knighthood!\n");
                return 0;
            default:
                printf("The fates have been unclear; choose wisely!\n");
        }
    }
    return 0;
}