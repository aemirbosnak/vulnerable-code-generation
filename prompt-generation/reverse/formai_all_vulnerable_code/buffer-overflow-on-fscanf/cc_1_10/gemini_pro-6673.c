//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[20];
    char number[11];
};

int main() {
    // Declare an array of phonebook entries
    struct phonebook phonebook[100];

    // Read in the phonebook from a file
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%s %s", phonebook[i].name, phonebook[i].number) != EOF) {
        i++;
    }

    fclose(file);

    // Print the phonebook
    printf("Name\t\tNumber\n");
    for (int j = 0; j < i; j++) {
        printf("%s\t\t%s\n", phonebook[j].name, phonebook[j].number);
    }

    // Search for a name in the phonebook
    char name[20];
    printf("Enter a name: ");
    scanf("%s", name);

    int found = 0;
    for (int k = 0; k < i; k++) {
        if (strcmp(name, phonebook[k].name) == 0) {
            printf("Found %s at %s\n", name, phonebook[k].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Name not found\n");
    }

    return 0;
}