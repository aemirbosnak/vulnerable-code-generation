//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_SIZE 10000

int dict_size = 0;
char dict[MAX_DICT_SIZE][MAX_WORD_LENGTH];
int dict_indices[MAX_DICT_SIZE];
int num_dict_indices = 0;

// Read words from a file into dictionary
void load_dict(char *file_path) {
    FILE *f = fopen(file_path, "r");
    if (f == NULL) {
        printf("Error: Cannot open file %s.\n", file_path);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(f, "%s", word) != EOF && dict_size < MAX_DICT_SIZE) {
        strcpy(dict[dict_size], word);
        dict_size++;
    }

    fclose(f);
}

// Search for a word in dictionary
int binary_search(char *word) {
    int low = 0, high = dict_size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(word, dict[mid]) < 0) {
            high = mid - 1;
        } else if (strcmp(word, dict[mid]) > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// Populate dict_indices with indices of dictionary words that differ by only one character
void get_similar_words_indices(char *word) {
    num_dict_indices = 0;
    for (int i = 0; i < dict_size; i++) {
        int count = 0;
        int dict_word_len = strlen(dict[i]);
        int word_len = strlen(word);
        if (abs(dict_word_len - word_len) > 1) continue;
        for (int j = 0, k = 0; j < dict_word_len && k < word_len; j++, k++) {
            if (dict[i][j] != word[k]) {
                if (count == 1) {
                    break;
                }
                count++;
                if (dict_word_len > word_len) {
                    k--;
                } else if (dict_word_len < word_len) {
                    j--;
                }
            }
        }
        if (count == 1) {
            dict_indices[num_dict_indices] = i;
            num_dict_indices++;
        }
    }
}

int main() {
    load_dict("words.txt");
    char user_input[MAX_WORD_LENGTH];
    printf("Enter word to check for spelling errors:\n");
    scanf("%s", user_input);

    int found_index = binary_search(user_input);
    if (found_index != -1) {
        printf("The word '%s' is spelled correctly.\n", user_input);
    } else {
        get_similar_words_indices(user_input);
        if (num_dict_indices > 0) {
            printf("Did you mean:\n");
            for (int i = 0; i < num_dict_indices; i++) {
                printf("- %s\n", dict[dict_indices[i]]);
            }
        } else {
            printf("The word '%s' is not in the dictionary and no similar words were found.\n", user_input);
        }
    }

    return 0;
}