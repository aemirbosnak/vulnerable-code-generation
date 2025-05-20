//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome banner
void banner() {
    printf("██   ██ ███████ ██      ██████  ██ ███    ██ \n");
    printf("██   ██ ██      ██      ██   ██ ██ ████   ██ \n");
    printf("███████ █████   ██      ██████ ██ ██ ██  ██ \n");
    printf("██   ██ ██      ██      ██   ██ ██ ██  ██ ██ \n");
    printf("██   ██ ███████ ███████ ██████  ██ ██   ████ \n");
}

// Menu options
void menu() {
    printf("\n1. Add survivor to the list\n");
    printf("2. Remove survivor from the list\n");
    printf("3. Print the list of survivors\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Add survivor to the list
void add_survivor(char **list, int *numSurvivors) {
    char name[256];
    printf("Enter survivor's name: ");
    scanf("%s", name);
    list[*numSurvivors] = malloc(strlen(name) + 1);
    strcpy(list[*numSurvivors], name);
    (*numSurvivors)++;
}

// Remove survivor from the list
void remove_survivor(char **list, int *numSurvivors) {
    char name[256];
    printf("Enter survivor's name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *numSurvivors; i++) {
        if (strcmp(list[i], name) == 0) {
            free(list[i]);
            for (int j = i; j < *numSurvivors - 1; j++) {
                list[j] = list[j + 1];
            }
            (*numSurvivors)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Survivor not found.\n");
    }
}

// Print the list of survivors
void print_survivors(char **list, int numSurvivors) {
    printf("Survivors:\n");
    for (int i = 0; i < numSurvivors; i++) {
        printf("%s\n", list[i]);
    }
}

int main() {
    // Welcome Banner
    banner();

    // Initialize the list of survivors
    char **list = malloc(sizeof(char *));
    int numSurvivors = 0;

    // Main loop
    int choice;
    do {
        // Display the menu
        menu();

        // Get the user's choice
        scanf("%d", &choice);

        // Perform the chosen action
        switch (choice) {
            case 1:
                add_survivor(list, &numSurvivors);
                break;
            case 2:
                remove_survivor(list, &numSurvivors);
                break;
            case 3:
                print_survivors(list, numSurvivors);
                break;
            case 4:
                printf("Good luck out there.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    // Free the list of survivors
    for (int i = 0; i < numSurvivors; i++) {
        free(list[i]);
    }
    free(list);

    return 0;
}