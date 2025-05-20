//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
/*
 * This program demonstrates a simple example of data mining using the C language.
 * It reads in a text file, counts the frequency of each word, and displays the top 10
 * most frequent words in descending order.
 * 
 * Written by Donald Knuth, 2021.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
	char* word;
	int count;
} WordCount;

int compare(const void* a, const void* b) {
	WordCount* x = (WordCount*)a;
	WordCount* y = (WordCount*)b;
	return (y->count - x->count);
}

int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	
	FILE* fp;
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit(1);
	}
	
	WordCount wordCounts[MAX_WORDS];
	int numWords = 0;
	char word[MAX_WORD_LEN];
	
	// Read in each word and count its frequency
	while (fscanf(fp, "%s", word) == 1) {
		int i;
		for (i = 0; i < strlen(word); i++) {
			word[i] = tolower(word[i]);
		}
		int found = 0;
		for (i = 0; i < numWords; i++) {
			if (strcmp(word, wordCounts[i].word) == 0) {
				wordCounts[i].count++;
				found = 1;
				break;
			}
		}
		if (!found) {
			wordCounts[numWords].word = strdup(word);
			wordCounts[numWords].count = 1;
			numWords++;
		}
	}
	
	// Sort by frequency and display the top 10
	qsort(wordCounts, numWords, sizeof(WordCount), compare);
	printf("Top 10 most frequent words:\n");
	int i;
	for (i = 0; i < 10 && i < numWords; i++) {
		printf("%d. \"%s\" (%d occurrences)\n", i+1, wordCounts[i].word, wordCounts[i].count);
	}
	
	// Clean up
	fclose(fp);
	for (i = 0; i < numWords; i++) {
		free(wordCounts[i].word);
	}
	
	return 0;
}