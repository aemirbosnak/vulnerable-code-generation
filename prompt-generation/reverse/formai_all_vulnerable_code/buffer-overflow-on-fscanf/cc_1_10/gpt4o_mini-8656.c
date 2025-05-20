//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LENGTH 50
#define FILENAME "noble_records.txt"

typedef struct {
    char name[NAME_LENGTH];
    int age;
    int wealth;
} Noble;

void addNoble(Noble nobles[], int *count) {
    if (*count >= MAX_PLAYERS) {
        printf("Alas! The roster is full.\n");
        return;
    }

    Noble newNoble;

    printf("Enter the name of the noble: ");
    scanf(" %[^\n]", newNoble.name);
    printf("Enter the age of %s: ", newNoble.name);
    scanf("%d", &newNoble.age);
    printf("Enter the wealth of %s: ", newNoble.name);
    scanf("%d", &newNoble.wealth);

    nobles[*count] = newNoble;
    (*count)++;
    printf("A new noble has been added to the roster!\n");
}

void saveNoblesToFile(Noble nobles[], int count) {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Alas! The file could not be opened for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %d\n", nobles[i].name, nobles[i].age, nobles[i].wealth);
    }

    fclose(fp);
    printf("The noble records have been inscribed deep into the parchment.\n");
}

void loadNoblesFromFile(Noble nobles[], int *count) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("Alas! The file could not be opened for reading. Perhaps it is a malicious sorcery?\n");
        return;
    }

    while (fscanf(fp, " %[^\n] %d %d", nobles[*count].name, &nobles[*count].age, &nobles[*count].wealth) == 3) {
        (*count)++;
        if (*count >= MAX_PLAYERS) {
            printf("Beware! The list is full, refuse any more additions from this parchment.\n");
            break;
        }
    }

    fclose(fp);
    printf("The noble records have been retrieved from the sacred parchment.\n");
}

void displayNobleRecords(Noble nobles[], int count) {
    if (count == 0) {
        printf("The noble roster is empty, devoid of illustrious names.\n");
        return;
    }

    printf("\n--- Noble Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Noble Name: %s, Age: %d, Wealth: %d\n", nobles[i].name, nobles[i].age, nobles[i].wealth);
    }
}

int main() {
    Noble nobles[MAX_PLAYERS];
    int count = 0;
    int choice;

    loadNoblesFromFile(nobles, &count);

    while (1) {
        printf("\n--- Noble Management Menu ---\n");
        printf("1. Add Noble\n");
        printf("2. Display Nobles\n");
        printf("3. Save Nobles to File\n");
        printf("4. Quit\n");
        printf("Select your destiny (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNoble(nobles, &count);
                break;
            case 2:
                displayNobleRecords(nobles, count);
                break;
            case 3:
                saveNoblesToFile(nobles, count);
                break;
            case 4:
                printf("Farewell, noble friend! May your travels be blessed.\n");
                return 0;
            default:
                printf("Beware! Such choices lead to unknown perils.\n");
        }
    }

    return 0;
}