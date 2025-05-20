//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLUES 100
#define MAX_LEN 256

typedef struct {
    char clue[MAX_LEN];
    int importance; // On a scale of 1 to 10
} Clue;

void add_clue(const char *filename, Clue *clue) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        fprintf(stderr, "Could not open file for appending.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s;%d\n", clue->clue, clue->importance);
    fclose(file);
}

void load_clues(const char *filename, Clue *clues, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%[^;];%d\n", clues[*count].clue, &clues[*count].importance) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void display_clues(Clue *clues, int count) {
    printf("Clues Found:\n");
    for (int i = 0; i < count; i++) {
        printf("Clue: %s | Importance: %d\n", clues[i].clue, clues[i].importance);
    }
}

void search_clue(Clue *clues, int count, const char *search_term) {
    printf("Searching for: %s\n", search_term);
    for (int i = 0; i < count; i++) {
        if (strstr(clues[i].clue, search_term) != NULL) {
            printf("Found! Clue: %s | Importance: %d\n", clues[i].clue, clues[i].importance);
            return;
        }
    }
    printf("No clue containing '%s' was found.\n", search_term);
}

int main() {
    Clue clues[MAX_CLUES];
    int clue_count = 0;
    char filename[] = "clues.txt";
    int choice;
    char search_term[MAX_LEN];
    
    printf("Welcome to the Sherlock Holmes' Clue Tracker!\n");

    // Load existing clues from file
    load_clues(filename, clues, &clue_count);
    display_clues(clues, clue_count);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a new clue\n");
        printf("2. Search for a clue\n");
        printf("3. Display all clues\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                if (clue_count < MAX_CLUES) {
                    Clue new_clue;
                    printf("Enter the clue: ");
                    fgets(new_clue.clue, MAX_LEN, stdin);
                    new_clue.clue[strcspn(new_clue.clue, "\n")] = 0; // Remove newline
                    printf("Enter importance (1-10): ");
                    scanf("%d", &new_clue.importance);
                    add_clue(filename, &new_clue);
                    clues[clue_count] = new_clue; // Update local array
                    clue_count++;
                } else {
                    printf("Clue limit reached!\n");
                }
                break;
            case 2:
                printf("Enter the search term: ");
                fgets(search_term, MAX_LEN, stdin);
                search_term[strcspn(search_term, "\n")] = 0; // Remove newline
                search_clue(clues, clue_count, search_term);
                break;
            case 3:
                display_clues(clues, clue_count);
                break;
            case 4:
                printf("Exiting the Clue Tracker. Farewell!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}