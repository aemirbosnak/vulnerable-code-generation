//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void compress(char *str) {
    	int len = strlen(str);
    	if (len == 0) {
        	return;
    	}

    	// Initialize variables
    	char currChar = str[0];
    	int count = 0;

    	// Loop through string, increment count if same character
    	// Otherwise, print out count and current character and reset count
    	for (int i = 0; i <= len; i++) {
        	if (str[i] == currChar) {
            		count++;
        	} else {
            		printf("%d%c", count, currChar);
            		currChar = str[i];
            		count = 1;
        	}
    	}
}

void decompress(char *str) {
    	int len = strlen(str);
    	if (len == 0) {
        	return;
    	}

    	// Initialize variables
    	char currChar = '\0';
    	int count = 0;

    	// Loop through string, accumulating digits and building count and current character
    	for (int i = 0; i <= len; i++) {
        	if (isdigit(str[i])) {
            		count = (count * 10) + (str[i] - '0');
        	} else {
            		for (int j = 0; j < count; j++) {
                		printf("%c", currChar);
            		}
            		currChar = str[i];
            		count = 0;
        	}
    	}
}

int main() {
    	char input[MAX_SIZE];
    	int choice;
    	printf("Enter a string to compress:\n");
    	fgets(input, MAX_SIZE, stdin);
    	input[strcspn(input, "\n")] = '\0';

    	// Loop to get user's choice for compression or decompression
    	do {
        	printf("Enter 1 to compress or 2 to decompress the string: ");
       		scanf("%d", &choice);
    	} while (choice != 1 && choice != 2);

    	if (choice == 1) {
        	compress(input);
    	} else {
        	decompress(input);
    	}
    
    	printf("\n");
    	return 0;
}