//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAMES 1000 // Maximum number of names to input

// Define a structure to store the name and its index
struct Names {
    char name[50]; // Stores a single name
    int index; // Stores the index of the name in the array
};

// Function to compare two names for sorting
int compare(const void *a, const void *b) {
    struct Names *nameA = (struct Names *)a;
    struct Names *nameB = (struct Names *)b;
    return strcmp(nameA->name, nameB->name);
}

// Function to create an index file
void create_index(struct Names list[], int count) {
    FILE *indexFile = fopen("index.txt", "w");
    if (indexFile == NULL) {
        printf("Could not create index file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(indexFile, "%s:%d\n", list[i].name, list[i].index);
    }
    fclose(indexFile);
}

// Function to search for a name in the index file
void search_index(char *name) {
    FILE *indexFile = fopen("index.txt", "r");
    if (indexFile == NULL) {
        printf("Could not open index file!\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), indexFile)) {
        char *token = strtok(line, ":");
        if (strcmp(token, name) == 0) {
            token = strtok(NULL, ":");
            int index = atoi(token);
            printf("%s found at index %d\n", name, index + 1);
            fclose(indexFile);
            return;
        }
    }
    printf("Name not found in index file!\n");
    fclose(indexFile);
    return;
}

// Main function to input names and create an index file
int main() {
    struct Names list[MAX_NAMES];
    int count = 0;

    printf("Enter names (type 'exit' to stop input):\n");
    char name[50];
    while (count < MAX_NAMES) {
        scanf("%s", name);
        if (strcmp(name, "exit") == 0) break;
        strcpy(list[count].name, name);
        list[count].index = count;
        count++;
    }

    qsort(list, count, sizeof(struct Names), compare);

    create_index(list, count);

    printf("\nEnter a name to search: ");
    scanf("%s", name);
    search_index(name);

    return 0;
}