//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
/*
 * Sentiment Analysis Tool
 *
 * This program takes a sentence as input and returns its sentiment score.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Sentiment score definitions
#define POSITIVE 1
#define NEUTRAL 0
#define NEGATIVE -1

// Sentiment words definitions
char *positive_words[] = {
	"amazing", "awesome", "fantastic", "great", "incredible",
	"magnificent", "outstanding", "phenomenal", "superb", "terrific"
};

char *negative_words[] = {
	"awful", "bad", "disaster", "horrible", "horrific",
	"miserable", "nasty", "nightmare", "terrible", "unbearable"
};

// Function to determine the sentiment of a sentence
int sentiment_score(char *sentence) {
	int i, j, score = 0;

	// Loop through all words in the sentence
	for (i = 0; i < strlen(sentence); i++) {
		// Check if the current word is a positive word
		for (j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
			if (strcmp(sentence[i], positive_words[j]) == 0) {
				score += POSITIVE;
				break;
			}
		}

		// Check if the current word is a negative word
		for (j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
			if (strcmp(sentence[i], negative_words[j]) == 0) {
				score += NEGATIVE;
				break;
			}
		}
	}

	return score;
}

// Main function
int main() {
	char sentence[100];

	// Take input from the user
	printf("Enter a sentence: ");
	scanf("%99[^\n]", sentence);

	// Determine the sentiment of the sentence
	int score = sentiment_score(sentence);

	// Print the sentiment score
	if (score > 0) {
		printf("The sentence is positive.\n");
	} else if (score < 0) {
		printf("The sentence is negative.\n");
	} else {
		printf("The sentence is neutral.\n");
	}

	return 0;
}