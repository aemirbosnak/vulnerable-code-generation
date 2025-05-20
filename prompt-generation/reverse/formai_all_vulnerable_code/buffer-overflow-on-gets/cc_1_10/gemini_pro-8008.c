//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <string.h>

// The ultimate database indexing system, GUARANTEED to be the best!
// (Or at least the funniest...)

// Our database is a simple array of strings.
// (Don't worry, we'll add more features later, like, um... spell checking?)
char *database[] = {
    "Adam Sandler",
    "Bill Murray",
    "Chevy Chase",
    "David Spade",
    "Eddie Murphy",
    "Farley, Chris",
    "Gallagher, Gallagher",
    "Hader, Bill",
    "Iliza Shlesinger",
    "Jim Carrey",
};

// Our indexing system is a simple linear search.
// (But it's so fast, you won't even notice!)
int find_index(char *name) {
    for (int i = 0; i < sizeof(database) / sizeof(char *); i++) {
        if (strcmp(name, database[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Our main function is a simple loop that allows the user to search for names.
int main() {
    char name[100];
    while (1) {
        printf("Enter a name to search for (or 'quit' to exit): ");
        gets(name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        int index = find_index(name);
        if (index == -1) {
            printf("Sorry, that name is not in the database.\n");
        } else {
            printf("Found %s at index %d.\n", name, index);
        }
    }
    return 0;
}