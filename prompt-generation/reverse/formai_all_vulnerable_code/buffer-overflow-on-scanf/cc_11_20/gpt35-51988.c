//FormAI DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char word[100];
	char dictionary[100][100] = {"hello", "world", "programming", "is", "fun"};
	int dict_size = 5;
	scanf("%s", word);

	int error_count = 0;

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] < 'a' || word[i] > 'z') {
			printf("Invalid character detected: %c\n", word[i]);
			error_count++;
		}
	}

	if (error_count > 0) {
		printf("The word contains %d invalid character(s).\n", error_count);
	} else {
		int found = 0;
		for (int i = 0; i < dict_size; i++) {
			if(strcmp(word, dictionary[i]) == 0) {
				found = 1;
				break;
			}
		}
		if (found) {
			printf("The word is spelled correctly!\n");
		} else {

			printf("Oops! It seems like the word may be misspelled.\n");
			int word_len = strlen(word);

			for (int i = 0; i < dict_size; i++) {
				int dict_word_len = strlen(dictionary[i]);
				if (abs(dict_word_len - word_len) > 1) {continue;}

				int errors = 0;
				for (int j = 0, k = 0; j < dict_word_len
					&& k < word_len; j++, k++) {
					if (dictionary[i][j] != word[k]) {
						errors++;
						if (errors > 1) {break;}
						
						if (dict_word_len > word_len) {
							k--;
						} else if (dict_word_len < word_len) {
							j--;
						}
					}
				}
				if (errors < 2) {
					printf("Did you mean %s?\n", dictionary[i]);
				}
			}
		}
	}
	return 0;
}