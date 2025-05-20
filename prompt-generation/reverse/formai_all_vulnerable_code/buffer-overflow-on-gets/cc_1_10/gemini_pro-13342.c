//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key. Yes, this is not secure, but it's just an example!
#define KEY 0x13

// Encrypt a single character
char encrypt(char c) {
	return c ^ KEY;
}

// Encrypt a string
void encrypt_string(char* str) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = encrypt(str[i]);
	}
}

// Decrypt a single character
char decrypt(char c) {
	return c ^ KEY;
}

// Decrypt a string
void decrypt_string(char* str) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = decrypt(str[i]);
	}
}

int main() {
	// Get the input string from the user
	char str[100];
	printf("Enter a string to encrypt: ");
	gets(str);

	// Encrypt the string
	encrypt_string(str);

	// Print the encrypted string
	printf("Encrypted string: %s\n", str);

	// Decrypt the string
	decrypt_string(str);

	// Print the decrypted string
	printf("Decrypted string: %s\n", str);

	return 0;
}