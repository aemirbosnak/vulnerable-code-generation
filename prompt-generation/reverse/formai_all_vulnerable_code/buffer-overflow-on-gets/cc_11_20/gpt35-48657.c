//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

	char str[100], word[20], ch;
	int i, j, flag;

	printf("Enter a string: ");
	gets(str);

	i = 0;
	while (str[i] != '\0') {
		j = 0;
		while (isalpha(str[i]) && str[i] != '\0') {
			word[j] = tolower(str[i]);
			j++;
			i++;
		}
		word[j] = '\0';

		flag = 0;
		if (strlen(word) > 0) {
			FILE *fp = fopen("dictionary.txt", "r");
			if (fp == NULL) {
				printf("Dictionary file not found!\n");
				return 0;
			}
			while ((ch = fgetc(fp)) != EOF) {
				if (ch == '\n') {
					if (strcmp(word, str) == 0) {
						flag = 1;
						break;
					}
					memset(word, 0, sizeof(word));
					j = 0;
					continue;
				}
				if (isalpha(ch)) {
					word[j] = tolower(ch);
					j++;
				}
			}
			fclose(fp);
		}

		if (flag == 0 && strlen(word) > 0) {
			printf("'%s' is not spelled correctly\n", word);
		}

		if (str[i] != '\0') {
			i++;
		}
	}

	return 0;
}