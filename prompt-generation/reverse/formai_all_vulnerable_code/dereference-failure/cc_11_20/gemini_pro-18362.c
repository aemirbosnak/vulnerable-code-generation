//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LEN 8
#define MAX_LEN 64

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <password>\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *password = argv[1];
	int len = strlen(password);

	if (len < MIN_LEN || len > MAX_LEN) {
		fprintf(stderr, "Password must be between %d and %d characters long.\n", MIN_LEN, MAX_LEN);
		return EXIT_FAILURE;
	}

	int score = 0;

	// Check for upper case letters.
	for (int i = 0; i < len; i++) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			score++;
			break;
		}
	}

	// Check for lower case letters.
	for (int i = 0; i < len; i++) {
		if (password[i] >= 'a' && password[i] <= 'z') {
			score++;
			break;
		}
	}

	// Check for digits.
	for (int i = 0; i < len; i++) {
		if (password[i] >= '0' && password[i] <= '9') {
			score++;
			break;
		}
	}

	// Check for special characters.
	for (int i = 0; i < len; i++) {
		if (password[i] < ' ' || password[i] > '~') {
			score++;
			break;
		}
	}

	// Check for consecutive characters.
	for (int i = 0; i < len - 1; i++) {
		if (password[i] == password[i + 1]) {
			score--;
			break;
		}
	}

	// Check for common words.
	char *common_words[] = {"password", "123456", "qwerty", "iloveyou", "princess", "rockyou", "monkey"};
	for (int i = 0; i < sizeof(common_words) / sizeof(char *); i++) {
		if (strcmp(password, common_words[i]) == 0) {
			score -= 10;
			break;
		}
	}

	// Print the score.
	printf("Password strength: %d\n", score);

	return EXIT_SUCCESS;
}