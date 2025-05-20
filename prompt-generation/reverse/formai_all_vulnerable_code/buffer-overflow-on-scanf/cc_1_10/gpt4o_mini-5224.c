//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SURVIVORS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int scavenged;
} Survivor;

// Function prototypes
void addSurvivor(Survivor *survivors, int *count);
void huntForSurvivors(Survivor *survivors, int count);
int linearSearch(Survivor *survivors, int count, const char *targetName);

int main() {
    Survivor survivors[MAX_SURVIVORS];
    int count = 0;
    int choice;

    printf("Welcome to the Survivor List Management in a Post-Apocalyptic World!\n");

    while (1) {
        printf("\n1. Add Survivor\n2. Hunt for Survivors\n3. Exit\n");
        printf("Choose your action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSurvivor(survivors, &count);
                break;
            case 2:
                huntForSurvivors(survivors, count);
                break;
            case 3:
                printf("Stay alive out there!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addSurvivor(Survivor *survivors, int *count) {
    if (*count >= MAX_SURVIVORS) {
        printf("We cannot save more survivors. We are out of space!\n");
        return;
    }

    Survivor newSurvivor;

    printf("Enter survivor's name: ");
    scanf("%s", newSurvivor.name);
    printf("Enter survivor's age: ");
    scanf("%d", &newSurvivor.age);
    newSurvivor.scavenged = 0; // Initially, they have not scavenged

    survivors[*count] = newSurvivor;
    (*count)++;
    printf("Survivor %s has been added to the list.\n", newSurvivor.name);
}

void huntForSurvivors(Survivor *survivors, int count) {
    char nameToFind[MAX_NAME_LENGTH];

    if (count == 0) {
        printf("There are no survivors to search for.\n");
        return;
    }

    printf("Enter the name of the survivor you are hunting for: ");
    scanf("%s", nameToFind);

    int index = linearSearch(survivors, count, nameToFind);
    if (index != -1) {
        printf("Survivor found: %s, Age: %d, Scavenged: %s\n", 
               survivors[index].name, 
               survivors[index].age, 
               survivors[index].scavenged ? "Yes" : "No");
    } else {
        printf("No survivor named %s found in the wasteland.\n", nameToFind);
    }
}

int linearSearch(Survivor *survivors, int count, const char *targetName) {
    for (int i = 0; i < count; i++) {
        if (strcmp(survivors[i].name, targetName) == 0) {
            return i; // Return the index of the found survivor
        }
    }
    return -1; // Not found
}