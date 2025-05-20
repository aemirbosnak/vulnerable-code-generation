//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_MEMORY 1024

// Declare a struct for the Super-Silly-Serious-Names
typedef struct {
    char name[MAX_NAME_LENGTH];
} SuperSillyName;

// Function to add a name to the file
void addNameToFile(const char* filename, SuperSillyName name) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Oops! My file-opening skills have failed me! Unable to open file.\n");
        return;
    }
    fprintf(file, "%s\n", name.name);
    printf("🎉 Added \"%s\" to the list of Super Silly Names! 🎉\n", name.name);
    fclose(file);
}

// Function to display names from the file
void displayNamesFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Yikes! Can't read this book of names! Check for its existence, please.\n");
        return;
    }

    char buffer[MAX_MEMORY];
    printf("📚 Here are the names that I've collected:\n");
    while (fgets(buffer, MAX_MEMORY, file) != NULL) {
        // Remove newline character from buffer
        buffer[strcspn(buffer, "\n")] = 0;  
        printf("🤡 %s\n", buffer);
    }
    fclose(file);
}

// Function to search for a name in the file
void searchNameInFile(const char* filename, const char* nameToSearch) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Yikes! Can't find my treasure chest of names! Did you lose it?\n");
        return;
    }

    char buffer[MAX_MEMORY];
    int found = 0;
    while (fgets(buffer, MAX_MEMORY, file) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        if (strcmp(buffer, nameToSearch) == 0) {
            found = 1;
            printf("🎈 Hooray! Found the name \"%s\" in the treasure chest! 🎈\n", nameToSearch);
            break;
        }
    }
    
    if (!found) {
        printf("🤔 Sorry! The name \"%s\" is playing hide and seek! Not found!\n", nameToSearch);
    }

    fclose(file);
}

// The main event where everything comes together
int main() {
    char filename[] = "super_silly_names.txt";
    SuperSillyName name;
    int choice;

    do {
        printf("\n=== Welcome to the Super Silly Name Collector! ===\n");
        printf("1. Add a new Super Silly Name\n");
        printf("2. Display all Super Silly Names\n");
        printf("3. Search for a Super Silly Name\n");
        printf("4. Exit the madness!\n");
        printf("What's your choice? (Enter a number): ");
        scanf("%d", &choice);
        getchar();  // Absorb the newline character

        switch (choice) {
            case 1:
                printf("🤓 Enter a Super Silly Name (up to 100 characters): ");
                fgets(name.name, MAX_NAME_LENGTH, stdin);
                name.name[strcspn(name.name, "\n")] = 0; // Remove newline character
                addNameToFile(filename, name);
                break;
            case 2:
                displayNamesFromFile(filename);
                break;
            case 3:
                printf("🔍 Enter the name you want to search for: ");
                fgets(name.name, MAX_NAME_LENGTH, stdin);
                name.name[strcspn(name.name, "\n")] = 0; // Remove newline character
                searchNameInFile(filename, name.name);
                break;
            case 4:
                printf("👋 Thanks for playing! May your names be ever silly!\n");
                break;
            default:
                printf("🤷‍♂️ Are you confused? Please choose a valid option!\n");
        }
    } while (choice != 4);

    return 0;
}