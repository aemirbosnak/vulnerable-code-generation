//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

void generate_conspiracies() {
    int i, j, k;
    char buffer[MAX_WORDS];
    FILE *file;

    file = fopen("conspiracies.txt", "r");
    if (file == NULL) {
        printf("Error: could not open conspiracies file.\n");
        exit(1);
    }

    i = 0;
    while (i < MAX_CONSPIRACIES && fscanf(file, "%s %s", buffer, buffer)!= EOF) {
        conspiracies[i].name = strdup(buffer);
        conspiracies[i].description = strdup(buffer);
        i++;
    }

    fclose(file);
}

void print_conspiracy(int index) {
    printf("%s: %s\n", conspiracies[index].name, conspiracies[index].description);
}

int main() {
    int choice, index;

    srand(time(NULL));
    generate_conspiracies();

    do {
        printf("Enter a number to generate a random conspiracy theory:\n");
        for (index = 0; index < MAX_CONSPIRACIES; index++) {
            printf("%d. %s\n", index, conspiracies[index].name);
        }

        scanf("%d", &choice);
        if (choice >= 0 && choice < MAX_CONSPIRACIES) {
            print_conspiracy(choice);
        } else {
            printf("Invalid choice.\n");
        }

        printf("Press enter to generate another theory or any other key to exit.\n");
        getchar();
    } while (1);

    return 0;
}