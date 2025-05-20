//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *english;
    char *alien;
} translation_t;

int main() {
    FILE *dict;
    char line[1024];
    int count = 0;
    translation_t *translations = NULL;

    dict = fopen("dictionary.txt", "r");
    if (!dict) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), dict)) {
        char *english = strtok(line, ",");
        char *alien = strtok(NULL, ",");

        if (english && alien) {
            translations = realloc(translations, sizeof(translation_t) * ++count);
            translations[count-1].english = strdup(english);
            translations[count-1].alien = strdup(alien);
        }
    }

    fclose(dict);

    char input[1024];
    while (fgets(input, sizeof(input), stdin)) {
        char *token = strtok(input, " ");
        while (token) {
            int i;
            for (i = 0; i < count; i++) {
                if (strcmp(token, translations[i].english) == 0) {
                    printf("%s ", translations[i].alien);
                    break;
                }
            }
            if (i == count) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}