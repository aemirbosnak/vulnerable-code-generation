//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 1000
#define MAX_CONSPIRACIES 1000

typedef struct {
    char *name;
    char *description;
} conspiracy_t;

conspiracy_t conspiracies[MAX_CONSPIRACIES];

void generate_conspiracy(conspiracy_t *conspiracy) {
    int num_words = rand() % MAX_CONSPIRACY_WORDS + 1;
    conspiracy->name = malloc(num_words * sizeof(char));
    conspiracy->description = malloc(num_words * sizeof(char));

    int i;
    for (i = 0; i < num_words; i++) {
        char word[10];
        sprintf(word, "word%d", i);
        strcat(conspiracy->name, word);
        strcat(conspiracy->name, " ");

        strcat(conspiracy->description, word);
        strcat(conspiracy->description, " ");
    }

    conspiracy->name[strlen(conspiracy->name) - 1] = '\0';
    conspiracy->description[strlen(conspiracy->description) - 1] = '\0';
}

void generate_conspiracies() {
    int i;
    for (i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy(&conspiracies[i]);
    }
}

int main() {
    srand(time(NULL));

    generate_conspiracies();

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Generate a new conspiracy theory\n");
        printf("2. Print all conspiracy theories\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_conspiracy(&conspiracies[rand() % MAX_CONSPIRACIES]);
                break;
            case 2:
                printf("Conspiracy theories:\n");
                int j;
                for (j = 0; j < MAX_CONSPIRACIES; j++) {
                    printf("%s: %s\n", conspiracies[j].name, conspiracies[j].description);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}