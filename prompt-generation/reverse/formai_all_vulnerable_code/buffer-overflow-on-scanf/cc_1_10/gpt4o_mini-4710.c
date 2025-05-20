//GPT-4o-mini DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define TITLE_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char title[TITLE_LENGTH];
    char realm[NAME_LENGTH];
} Noble;

Noble phoneBook[MAX_ENTRIES];
int count = 0;

void addNoble();
void viewNobles();
void searchByName();

int main() {
    int choice;
    do {
        printf("\n~~~ The Noble's Phone Book ~~~\n");
        printf("1. Add Noble\n");
        printf("2. View Nobles\n");
        printf("3. Search by Name\n");
        printf("4. Depart from the Phone Book\n");
        printf("Choose thy fate (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNoble();
                break;
            case 2:
                viewNobles();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                printf("Farewell, brave soul!\n");
                break;
            default:
                printf("Noble scribe, please choose wisely (1-4).\n");
        }
    } while (choice != 4);
    
    return 0;
}

void addNoble() {
    if (count >= MAX_ENTRIES) {
        printf("Alas! The phone book is full, more scrolls cannot be added!\n");
        return;
    }

    Noble newNoble;
    printf("Enter the name of the noble: ");
    scanf(" %[^\n]", newNoble.name);
    printf("Enter the title of the noble: ");
    scanf(" %[^\n]", newNoble.title);
    printf("Enter the realm of the noble: ");
    scanf(" %[^\n]", newNoble.realm);

    phoneBook[count] = newNoble;
    count++;
    printf("The noble %s of the realm %s has been added to the tome of names!\n", newNoble.name, newNoble.realm);
}

void viewNobles() {
    if (count == 0) {
        printf("The phone book is barren; no nobles reside within it!\n");
        return;
    }

    printf("\n~~~ List of Noble Kind ~~~\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s, the %s from %s\n", i + 1, phoneBook[i].name, phoneBook[i].title, phoneBook[i].realm);
    }
}

void searchByName() {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the noble to search for: ");
    scanf(" %[^\n]", searchName);

    printf("\n~~~ Search Results ~~~\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(phoneBook[i].name, searchName) == 0) {
            printf("Noble found: %s, the %s from %s\n", phoneBook[i].name, phoneBook[i].title, phoneBook[i].realm);
            found = 1;
        }
    }
    if (!found) {
        printf("Alas! No noble by the name of %s can be found in these scrolls.\n", searchName);
    }
}