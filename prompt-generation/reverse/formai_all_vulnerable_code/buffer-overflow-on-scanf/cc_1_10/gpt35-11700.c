//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50    // Maximum word length
#define MAX_WORDS 500      // Maximum number of unique words

// Node structure for unique word list
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordNode;

// Function to find index of word in unique word list
int find_word_index(WordNode *list, int len, char *word) {
    int i;
    for (i = 0; i < len; i++) {
        if (strcmp(list[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print list of unique words and their counts
void print_word_list(WordNode *list, int len) {
    int i;
    printf("\nWord Count:\n");
    for (i = 0; i < len; i++) {
        printf("%s: %d\n", list[i].word, list[i].count);
    }
}

// Main function that counts words in a text file
int main() {
    FILE *fp;
    char filename[100], word[MAX_WORD_LEN];
    WordNode word_list[MAX_WORDS];
    int word_count = 0, unique_word_count = 0, i, index;

    printf("Enter filename to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file. Exiting...\n");
        return 0;
    }

    // Loop through each word in file
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to lowercase
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Find word in list of unique words
        index = find_word_index(word_list, unique_word_count, word);
        // If word is not in list, add it
        if (index == -1) {
            strcpy(word_list[unique_word_count].word, word);
            word_list[unique_word_count].count = 1;
            unique_word_count++;
        }
        // If word is in list, increment its count
        else {
            word_list[index].count++;
        }
        word_count++;
    }
    fclose(fp);

    printf("Total words: %d\n", word_count);
    printf("Unique words: %d\n", unique_word_count);
    print_word_list(word_list, unique_word_count);

    return 0;
}