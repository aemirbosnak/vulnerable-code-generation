//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 20
#define MAX_CONSPIRACY_THEMES 10

typedef struct {
    char *name;
    int length;
    int probability;
} ConspiracyTheme;

ConspiracyTheme themes[] = {
    {"Illuminati", 9, 50},
    {"New World Order", 11, 40},
    {"Area 51", 6, 60},
    {"Flat Earth", 8, 30},
    {"Moon Landing Hoax", 13, 20},
    {"9/11 Conspiracy", 10, 45},
    {"Chemtrails", 9, 35},
    {"Lizard People", 11, 25},
    {"Big Pharma", 8, 40},
    {"MKUltra", 7, 30}
};

typedef struct {
    char *name;
    int length;
    int probability;
} ConspiracyWord;

ConspiracyWord words[] = {
    {"government", 10, 60},
    {"cover-up", 8, 50},
    {"secret", 6, 70},
    {"truth", 5, 80},
    {"evidence", 8, 40},
    {"control", 7, 30},
    {"alien", 5, 20},
    {"technology", 9, 10},
    {"power", 5, 40},
    {"manipulation", 11, 20}
};

void generate_conspiracy(char *conspiracy, int max_length) {
    srand(time(NULL));
    int theme_index = rand() % MAX_CONSPIRACY_THEMES;
    int word_count = rand() % MAX_CONSPIRACY_WORDS;
    int i;

    strcpy(conspiracy, themes[theme_index].name);
    int length = strlen(conspiracy);

    for (i = 0; i < word_count; i++) {
        int word_index = rand() % MAX_CONSPIRACY_WORDS;
        int word_length = words[word_index].length;

        if (length + word_length <= max_length) {
            strcat(conspiracy, " ");
            strcat(conspiracy, words[word_index].name);
            length += word_length;
        }
    }
}

int main() {
    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int length;

    printf("Enter the desired length of the conspiracy theory (1-100): ");
    scanf("%d", &length);

    generate_conspiracy(conspiracy, length);
    printf("Your random conspiracy theory: %s\n", conspiracy);

    return 0;
}