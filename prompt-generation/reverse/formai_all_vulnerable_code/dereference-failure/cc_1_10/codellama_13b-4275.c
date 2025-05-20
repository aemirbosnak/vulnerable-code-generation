//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
/*
 * Sentiment Analysis Tool
 *
 * This program takes a sentence as input and outputs its sentiment as a numerical value.
 * The sentiment is determined based on the use of positive and negative words in the sentence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the positive and negative words
const char *positive_words[] = {
	"good", "happy", "exciting", "positive", "great", "amazing"
};
const char *negative_words[] = {
	"bad", "sad", "boring", "negative", "terrible", "awful"
};

// Function to get the sentiment of a sentence
int get_sentiment(const char *sentence) {
	int sentiment = 0;
	char *token;
	char *tofree;

	// Tokenize the sentence
	token = strtok_r(sentence, " ", &tofree);
	while (token != NULL) {
		// Check if the word is positive or negative
		for (int i = 0; i < sizeof(positive_words) / sizeof(positive_words[0]); i++) {
			if (strcmp(token, positive_words[i]) == 0) {
				sentiment++;
			} else if (strcmp(token, negative_words[i]) == 0) {
				sentiment--;
			}
		}

		// Get the next word
		token = strtok_r(NULL, " ", &tofree);
	}

	// Return the sentiment
	return sentiment;
}

int main(void) {
	char sentence[100];

	// Get the sentence from the user
	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	// Get the sentiment of the sentence
	int sentiment = get_sentiment(sentence);

	// Print the sentiment
	printf("Sentiment: %d\n", sentiment);

	return 0;
}