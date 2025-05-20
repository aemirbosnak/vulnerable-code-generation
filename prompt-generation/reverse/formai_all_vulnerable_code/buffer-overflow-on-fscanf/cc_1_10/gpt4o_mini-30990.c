//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILENAME "survival_supplies.txt"

typedef struct {
    char name[30];
    int quantity;
} Supply;

void loadSupplies(Supply supplies[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("The world has gone silent... No supplies found. A bitter reality awaits.\n");
        *count = 0;
        return;
    }

    while (fscanf(file, "%s %d", supplies[*count].name, &supplies[*count].quantity) != EOF) {
        (*count)++;
        if (*count >= MAX_ITEMS) {
            break;
        }
    }
    fclose(file);
    printf("Supplies loaded from the remnants of civilization... %d items found.\n", *count);
}

void displaySupplies(Supply supplies[], int count) {
    printf("Current Survival Supplies:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", supplies[i].name, supplies[i].quantity);
    }
}

int searchSupply(Supply supplies[], int count, const char *query) {
    for (int i = 0; i < count; i++) {
        if (strcmp(supplies[i].name, query) == 0) {
            return i;
        }
    }
    return -1; // Supply not found
}

void userSearch(Supply supplies[], int count) {
    char query[30];
    printf("In this desolate wasteland, what supplies do you seek? (Enter supply name): ");
    scanf("%s", query);

    int index = searchSupply(supplies, count, query);
    if (index != -1) {
        printf("You have found %s: %d available.\n", supplies[index].name, supplies[index].quantity);
    } else {
        printf("Alas, %s is nowhere to be found. Keep searching...\n", query);
    }
}

void addSupply(Supply supplies[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("You cannot carry any more supplies. The end is near...\n");
        return;
    }

    printf("You stumble upon a stash! What supply did you find? ");
    scanf("%s", supplies[*count].name);
    printf("How many did you discover? ");
    scanf("%d", &supplies[*count].quantity);
    
    (*count)++;
    printf("You've added %s: %d to your inventory.\n", supplies[*count - 1].name, supplies[*count - 1].quantity);
}

void saveSupplies(Supply supplies[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Unable to save supplies. The world is collapsing...\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", supplies[i].name, supplies[i].quantity);
    }
    fclose(file);
    printf("Supplies have been saved for future wanderers...\n");
}

int main() {
    Supply supplies[MAX_ITEMS];
    int count = 0;

    loadSupplies(supplies, &count);
    
    int choice;
    while (1) {
        printf("\n[1] View Supplies\n[2] Search Supply\n[3] Add Supply\n[4] Save Supplies\n[0] Exit\n");
        printf("Choose your path (0-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySupplies(supplies, count);
                break;
            case 2:
                userSearch(supplies, count);
                break;
            case 3:
                addSupply(supplies, &count);
                break;
            case 4:
                saveSupplies(supplies, count);
                break;
            case 0:
                printf("You have chosen to rest... until next time.\n");
                exit(0);
            default:
                printf("The code of survival is broken... Please choose wisely.\n");
        }
    }
    return 0;
}