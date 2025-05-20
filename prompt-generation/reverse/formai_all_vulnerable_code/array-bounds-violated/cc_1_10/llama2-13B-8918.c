//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1024
#define MAGIC_WORD "Congratulations!"

int main() {
    char str[MAX_LEN];
    int len = 0;
    int i, j;
    char temp[2];

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    len = strlen(str);

    // Shuffle the string
    for (i = 0; i < len; i++) {
        j = rand() % len;
        temp[0] = str[i];
        str[i] = str[j];
        str[j] = temp[0];
    }

    // Find the magic word
    for (i = 0; i < len; i++) {
        if (str[i] == MAGIC_WORD[0]) {
            for (j = i + 1; j < len; j++) {
                if (str[j] == MAGIC_WORD[1]) {
                    printf("Found the magic word %s\n", MAGIC_WORD);
                    break;
                }
            }
            break;
        }
    }

    // Reverse the string
    for (i = 0; i < len; i++) {
        temp[0] = str[i];
        str[i] = temp[len - i - 1];
        temp[len - i - 1] = temp[0];
    }

    printf("The shuffled string is: %s\n", str);

    return 0;
}