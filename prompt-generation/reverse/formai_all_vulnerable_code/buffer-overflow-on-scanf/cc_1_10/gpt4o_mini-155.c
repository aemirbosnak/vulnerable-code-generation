//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define FILENAME "shocking_data.txt"

typedef struct {
    char name[50];
    int age;
    float score;
} Entry;

void printMenu() {
    printf("******************************************\n");
    printf("*               SHOCKING MENU          *\n");
    printf("******************************************\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry By Name\n");
    printf("4. Delete Entry By Name\n");
    printf("5. Exit\n");
    printf("******************************************\n");
    printf("Choose an option: ");
}

void addEntry(FILE *file) {
    Entry e;
    
    printf("Enter name: ");
    scanf("%s", e.name);
    printf("Enter age: ");
    scanf("%d", &e.age);
    printf("Enter score: ");
    scanf("%f", &e.score);
    
    fwrite(&e, sizeof(Entry), 1, file);
    printf("Entry added shockingly!\n");
}

void viewEntries(FILE *file) {
    Entry e;
    rewind(file);
    
    printf("******************************************\n");
    printf("*            ENTRIES VIEW               *\n");
    printf("******************************************\n");
    
    while (fread(&e, sizeof(Entry), 1, file)) {
        printf("Name: %s | Age: %d | Score: %.2f\n", e.name, e.age, e.score);
    }
    printf("******************************************\n");
}

void searchEntry(FILE *file) {
    char name[50];
    Entry e;
    int found = 0;

    printf("Enter name to search: ");
    scanf("%s", name);
    rewind(file);
    
    while (fread(&e, sizeof(Entry), 1, file)) {
        if (strcmp(e.name, name) == 0) {
            printf("Found Entry!\n");
            printf("Name: %s | Age: %d | Score: %.2f\n", e.name, e.age, e.score);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Entry with name \"%s\" not found!\n", name);
    }
}

void deleteEntry(FILE *file) {
    FILE *tempFile = fopen("temp.txt", "wb");
    Entry e;
    char name[50];
    int deleted = 0;

    printf("Enter name to delete: ");
    scanf("%s", name);
    rewind(file);
    
    while (fread(&e, sizeof(Entry), 1, file)) {
        if (strcmp(e.name, name) != 0) {
            fwrite(&e, sizeof(Entry), 1, tempFile);
        } else {
            deleted = 1;
            printf("Entry with name \"%s\" has been shockingly deleted!\n", name);
        }
    }
    
    fclose(tempFile);
    fclose(file);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    
    if (!deleted) {
        printf("No entry with the name \"%s\" to delete!\n", name);
    }
}

int main() {
    FILE *file;
    int option;

    file = fopen(FILENAME, "ab+"); // Opens file in append plus mode
    if (!file) {
        printf("Unable to open file! Oh no!\n");
        return 1;
    }
    
    while (1) {
        printMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addEntry(file);
                break;
            case 2:
                viewEntries(file);
                break;
            case 3:
                searchEntry(file);
                break;
            case 4:
                deleteEntry(file);
                break;
            case 5:
                printf("Exiting... Bye-bye! Shocked yet?\n");
                fclose(file);
                return 0;
            default:
                printf("Invalid option! Shocking!\n");
        }
    }

    return 0;
}