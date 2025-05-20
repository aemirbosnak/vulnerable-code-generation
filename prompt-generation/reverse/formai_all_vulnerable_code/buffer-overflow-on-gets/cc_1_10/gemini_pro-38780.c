//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int rand_range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void encrypt(char *text, int key)
{
	int i;
	for (i = 0; i < strlen(text); i++)
	{
		text[i] = text[i] + key;
	}
}

void decrypt(char *text, int key)
{
	int i;
	for (i = 0; i < strlen(text); i++)
	{
		text[i] = text[i] - key;
	}
}


int main()
{
	
	char text[100];
	int key;

	
	printf("Enter the text to encrypt: ");
	gets(text);

	
	printf("Enter the key (1-25): ");
	scanf("%d", &key);

	

	encrypt(text, key);
	printf("Encrypted text: %s\n", text);

	decrypt(text, key);
	printf("Decrypted text: %s\n", text);

	return 0;
}