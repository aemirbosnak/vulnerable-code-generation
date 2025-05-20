//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 100

struct morse_code {
	char *character;
	char *code;
};

const struct morse_code morse_codes[] = {
	{ "A", ".-" },
	{ "B", "-..." },
	{ "C", "-.-." },
	{ "D", "-.." },
	{ "E", "." },
	{ "F", "..-." },
	{ "G", "--." },
	{ "H", "...." },
	{ "I", ".." },
	{ "J", ".---" },
	{ "K", "-.-" },
	{ "L", ".-.." },
	{ "M", "--" },
	{ "N", "-." },
	{ "O", "---" },
	{ "P", ".--." },
	{ "Q", "--.-" },
	{ "R", ".-." },
	{ "S", "..." },
	{ "T", "-" },
	{ "U", "..-"},
	{ "V", "...-" },
	{ "W", ".--" },
	{ "X", "-..-"},
	{ "Y", "-.--" },
	{ "Z", "--.." },
	{ " ", " " },
	{ NULL, NULL }
};

char *get_morse_code(char character) {
	const struct morse_code *code;
	for (code = morse_codes; code->character != NULL; code++) {
		if (*code->character == character) {
			return code->code;
		}
	}
	return NULL;
}

void convert_to_morse_code(char *text, char *morse_code) {
	int i, j, k;
	char *code;

	for (i = 0, k = 0; text[i] != '\0'; i++) {
		code = get_morse_code(text[i]);
		if (code != NULL) {
			for (j = 0; code[j] != '\0'; j++) {
				morse_code[k++] = code[j];
				morse_code[k++] = ' ';
			}
		}
	}
	morse_code[k] = '\0';
}

int main(void) {
	char text[MAX_CODE_LEN];
	char morse_code[MAX_CODE_LEN];

	printf("Enter text to convert to Morse code: ");
	scanf("%[^\n]", text);

	convert_to_morse_code(text, morse_code);

	printf("Morse code: %s\n", morse_code);

	return 0;
}