//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

// Function to calculate the frequency of a character in a string
int char_freq(char c, char *str) {
    int freq = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            freq++;
        }
    }

    return freq;
}

int main() {
    FILE *file;
    char filename[50];
    char ch;
    char str[MAX_CHAR];
    int char_count[MAX_CHAR] = {0};

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            str[0] = tolower(ch);
            int index = (int) str[0];
            char_count[index]++;
        }
    }

    fclose(file);

    printf("\nCharacter\tFrequency\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (isalpha((char) i) || isspace((char) i) || (int) i == '\n') {
            if (char_count[i] > 0) {
                printf("%c\t%d\n", i, char_count[i]);
            }
        }
    }

    return 0;
}