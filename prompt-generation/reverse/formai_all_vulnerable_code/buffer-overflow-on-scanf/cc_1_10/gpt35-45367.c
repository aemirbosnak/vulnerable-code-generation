//FormAI DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

/* A structure to hold the word, it's frequency and it's size. */
typedef struct {
    char* word;         
    int frequency;      
    int size;           
} word_info;


/**
 * A helper function to read a word from a file and store it in buffer.
 * It also returns the length of the word read.
 */
int get_word(FILE *fp, char *buffer, size_t max_length)
{
    int i = 0, ch;

    while ((ch = fgetc(fp)) != EOF && !isalpha(ch)) {
        // skip non alpha characters
    }

    if (ch == EOF) {
        return 0;
    }

    buffer[i++] = tolower(ch);

    while (i < max_length && (ch = fgetc(fp)) != EOF && isalpha(ch)) {
        buffer[i++] = tolower(ch);
    }

    buffer[i] = '\0';

    return i;
}

/**
 * A helper function to search for a word in word_info array.
 * If the word is found, it returns the index of the word_info element,
 * otherwise it returns -1.
 */
int search_word(word_info *words, int num_words, char *word)
{
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * A helper function to add a word to word_info array.
 * If the word already exists, it increments the frequency
 * of the word else it creates a new word_info element and 
 * adds to the array.
 */
void add_word(word_info **words, int *num_words, char *word)
{
    int index;

    index = search_word(*words, *num_words, word);

    if (index != -1) {
        (*words)[index].frequency++;
    } else {
        // word not found, create new word info
        word_info wi;
        wi.word = strdup(word);
        wi.frequency = 1;
        wi.size = strlen(word);
        (*words)[*num_words] = wi;
        (*num_words)++;
    }
}

/**
 * A helper function to sort word_info in descending order based 
 * on frequency using bubble sort.
 */
void sort_words(word_info *words, int num_words)
{
    int i, j;
    word_info temp;

    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (words[j].frequency < words[j+1].frequency) {
                temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

/**
 * The main function which counts the number of words in a file,
 * stores the word frequency and prints the top 10 most frequent 
 * words along with their frequency and size.
 */
int main()
{
    char file_name[100];
    printf("Enter filename: ");
    scanf("%s", file_name);

    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Unable to open file.");
        exit(1);
    }

    char word_buffer[MAX_WORD_LENGTH];
    int num_words = 0;
    word_info *words = calloc(1000, sizeof(word_info));

    while (get_word(fp, word_buffer, MAX_WORD_LENGTH)) {
        add_word(&words, &num_words, word_buffer);
    }

    sort_words(words, num_words);

    printf("Top 10 most frequent words:\n");

    int i;

    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%d. %s - frequency: %d, length: %d\n", i + 1, words[i].word, words[i].frequency, words[i].size);
    }

    fclose(fp);

    return 0;
}