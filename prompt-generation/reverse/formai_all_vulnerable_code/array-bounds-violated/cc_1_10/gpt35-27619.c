//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>

void textToMorse(char* text);

int main(void) {
	char text[100];
	printf("Enter the text to convert to Morse code: ");
	scanf("%[^\n]%*c", text); // Reads input until new line char is encountered
	
	textToMorse(text);

	return 0;
}

void textToMorse(char* text) {
	char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
				"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
				"..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/", "", "", 
				"", "", "", "", "", "", "", "", "", "", "",
				".-.-.-", "--..--", "-.-.--"};
	// Morse code lookup table
	
	char output[500] = "";
	
	for(int i = 0; i < strlen(text); i++) {
		if(text[i] >= 'A' && text[i] <= 'Z') { // Uppercase letter
			strcat(output, morse[text[i] - 'A']);
			strcat(output, " ");
		}
		else if(text[i] >= 'a' && text[i] <= 'z') { // Lowercase letter
			strcat(output, morse[text[i] - 'a']);
			strcat(output, " ");
		}
		else if(text[i] >= '0' && text[i] <= '9') { // Number
			strcat(output, morse[text[i] - '0' + 26]);
			strcat(output, " ");
		}
		else { // Special character or space
			if(text[i] == ' ') { // Space
				strcat(output, "/ ");
			}
			else { // Special character
				strcat(output, morse[text[i] - 39 + 36]);
				strcat(output, " ");
			}
		}
	}
	
	printf("Morse Code: %s\n", output);
}