//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to remove leading and trailing spaces from a string
void trim(char* str) {
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    while (isspace(str[start])) {
        start++;
    }

    while (isspace(str[end])) {
        end--;
    }

    if (start > end) {
        str[0] = '\0';
    } else {
        memmove(str, str + start, end - start + 1);
        str[end - start + 1] = '\0';
    }
}

// Function to split a string into words
int split(char* str, char** words) {
    int count = 0;
    char* token = strtok(str, " ");

    while (token!= NULL) {
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to count the frequency of a word in a string
int count_word_frequency(char* str, char* word) {
    int count = 0;
    char* token = strtok(str, " ");

    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to perform data mining on a text file
void data_mining(char* filename, char* word) {
    FILE* file = fopen(filename, "r");
    char line[1024];
    char* words[100];
    int word_count;

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        trim(line);
        word_count = split(line, words);

        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {
                printf("Line %d: %s\n", i + 1, line);
            }
        }
    }

    fclose(file);
}

int main() {
    char filename[1024];
    char word[1024];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter word to search for: ");
    scanf("%s", word);

    data_mining(filename, word);

    return 0;
}