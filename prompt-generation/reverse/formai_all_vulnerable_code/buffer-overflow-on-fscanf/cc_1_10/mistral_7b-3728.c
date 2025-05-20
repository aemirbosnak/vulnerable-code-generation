//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_TABLE_SIZE 256

typedef struct AlienTranslation {
    char english[16];
    char alien[16];
} AlienTranslation;

AlienTranslation alienTable[ALIEN_TABLE_SIZE];

void loadAlienTable(const char* filename) {
    FILE* fp = fopen(filename, "r");
    int i = 0;
    if (fp) {
        while (fscanf(fp, "%s %s", alienTable[i].english, alienTable[i].alien) != EOF) {
            i++;
        }
        fclose(fp);
    }
}

int findEnglishIndex(const char* english) {
    for (int i = 0; i < ALIEN_TABLE_SIZE; i++) {
        if (strcmp(english, alienTable[i].english) == 0) {
            return i;
        }
    }
    return -1;
}

void translate(const char* english) {
    int index = findEnglishIndex(english);
    if (index >= 0) {
        printf("%s: %s\n", english, alienTable[index].alien);
    } else {
        printf("%s: Unknown\n", english);
    }
}

int main() {
    loadAlienTable("alien_table.txt");
    translate("hello");
    translate("world");
    translate("how are you");
    translate("I am fine");
    translate("goodbye");
    return 0;
}