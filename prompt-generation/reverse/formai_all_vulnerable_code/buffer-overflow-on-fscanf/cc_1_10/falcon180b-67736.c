//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_NAMES 1000
#define MAX_VERBS 1000
#define MAX_ADJECTIVES 1000

char names[MAX_NAMES][50];
char verbs[MAX_VERBS][50];
char adjectives[MAX_ADJECTIVES][50];

void load_words() {
    FILE *fp;
    char word[50];
    int i = 0;

    // Load names
    fp = fopen("names.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open names file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(names[i], word);
        i++;
    }
    fclose(fp);

    // Load verbs
    fp = fopen("verbs.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open verbs file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(verbs[i], word);
        i++;
    }
    fclose(fp);

    // Load adjectives
    fp = fopen("adjectives.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open adjectives file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(adjectives[i], word);
        i++;
    }
    fclose(fp);
}

void generate_conspiracy() {
    int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int i = 0;

    while (i < length) {
        int word_type = rand() % 3; // 0 = name, 1 = verb, 2 = adjective

        switch (word_type) {
            case 0:
                strcat(conspiracy, names[rand() % MAX_NAMES]);
                strcat(conspiracy, " ");
                break;
            case 1:
                strcat(conspiracy, verbs[rand() % MAX_VERBS]);
                strcat(conspiracy, " ");
                break;
            case 2:
                strcat(conspiracy, adjectives[rand() % MAX_ADJECTIVES]);
                strcat(conspiracy, " ");
                break;
        }

        i++;
    }

    printf("The %s is a %s orchestrated by %s.\n", conspiracy, conspiracy, conspiracy);
}

int main() {
    srand(time(NULL));
    load_words();
    generate_conspiracy();

    return 0;
}