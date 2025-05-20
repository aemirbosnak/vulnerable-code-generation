//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000], word[100];
    int i, j, count, len;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    len = strlen(input);

    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    count = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            count++;
        }
    }

    printf("Word count: %d\n", count);

    count = 0;
    j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            word[j] = '\0';
            j = 0;
            count++;
            printf("%s\n", word);
            continue;
        } else {
            word[j] = input[i];
            j++;
        }
    }

    word[j] = '\0';
    count++;
    printf("%s\n", word);

    return 0;
}