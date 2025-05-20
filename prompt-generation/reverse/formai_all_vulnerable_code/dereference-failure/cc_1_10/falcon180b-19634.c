//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy *generate_conspiracy(int length, int num_words) {
    Conspiracy *conspiracy = malloc(sizeof(Conspiracy));
    conspiracy->name = malloc(sizeof(char) * (length + 1));
    conspiracy->description = malloc(sizeof(char) * (length * num_words + 1));

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        conspiracy->name[i] = rand() % 26 + 'A';
    }

    conspiracy->name[length] = '\0';

    int j = 0;
    for (int i = 0; i < num_words; i++) {
        char *word = malloc(sizeof(char) * (rand() % 10 + 1));
        for (int k = 0; k < strlen(word); k++) {
            word[k] = rand() % 26 + 'A';
        }
        word[strlen(word)] = '\0';

        strcat(conspiracy->description, word);
        strcat(conspiracy->description, " ");

        free(word);

        if (++j == length) {
            break;
        }
    }

    conspiracy->description[strlen(conspiracy->description) - 1] = '\0';

    return conspiracy;
}

void print_conspiracy(Conspiracy *conspiracy) {
    printf("The %s is a secretive organization that has been operating behind the scenes for centuries. Its true purpose remains unknown, but it is believed to be involved in %s.\n", conspiracy->name, conspiracy->description);
}

int main() {
    int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    int num_words = rand() % MAX_CONSPIRACY_WORDS + 1;

    Conspiracy *conspiracy = generate_conspiracy(length, num_words);
    print_conspiracy(conspiracy);

    free(conspiracy->name);
    free(conspiracy->description);
    free(conspiracy);

    return 0;
}