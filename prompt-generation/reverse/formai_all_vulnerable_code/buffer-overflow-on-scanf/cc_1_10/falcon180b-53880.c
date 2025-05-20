//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

struct word {
    char english[50];
    char alien[50];
};

int main() {
    FILE *fp;
    char filename[50];
    int count = 0;
    struct word dict[MAX_WORDS];

    printf("Enter the dictionary file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", dict[count].english, dict[count].alien)!= EOF) {
        count++;
    }

    fclose(fp);

    printf("Enter a sentence to translate: ");
    char sentence[100];
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < count; i++) {
            if (strcmp(token, dict[i].english) == 0) {
                printf("%s ", dict[i].alien);
                break;
            }
        }
        if (i == count) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}