//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct word {
    char *english;
    char *alien;
};

int main() {
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    char input_buffer[1024];
    char *token;

    // Load the dictionary
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionary_file, "%s %s", input_buffer, input_buffer)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary is full.\n");
            return 1;
        }

        dictionary[num_words].english = strdup(input_buffer);
        dictionary[num_words].alien = strdup(input_buffer + strlen(input_buffer) + 1);

        num_words++;
    }

    fclose(dictionary_file);

    // Translate sentences
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        token = strtok(input_buffer, ",.?!;:");

        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(dictionary[i].english, token) == 0) {
                    printf("%s ", dictionary[i].alien);
                    break;
                }
            }

            if (i == num_words) {
                printf("unknown ");
            }

            token = strtok(NULL, ",.?!;:");
        }

        printf("\n");
    }

    return 0;
}