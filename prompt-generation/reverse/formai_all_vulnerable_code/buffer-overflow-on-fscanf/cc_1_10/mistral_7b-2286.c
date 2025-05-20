//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define WORD_SIZE 50
#define DICTIONARY_SIZE 10000
char dictionary[DICTIONARY_SIZE][WORD_SIZE];
int load_dictionary() {
 int fd, i = 0;
 char word[WORD_SIZE];
 fd = open("dictionary.txt", O_RDONLY);
 if (fd < 0) {
 fprintf(stderr, "Error: Could not open dictionary file\n");
 return -1;
 }
 while (fscanf(fd, "%s", word) != EOF) {
 strcpy(dictionary[i], word);
 i++;
 }
 close(fd);
 return i;
}
int hash_func(char *word) {
 int hash = 0;
 for (int i = 0; i < strlen(word); i++) {
 hash = hash * 31 + word[i];
 }
 return hash % DICTIONARY_SIZE;
}
int check_word(char *word) {
 int hash = hash_func(word);
 if (strcmp(dictionary[hash], word) == 0) {
 return 1;
 }
 return 0;
}
int main(int argc, char **argv) {
 if (argc < 2) {
 printf("Usage: %s <text_file>\n", argv[0]);
 return 1;
 }
 int fd, line_number = 1, words_count = 0, i;
 int dictionary_size = load_dictionary();
 char text[1024], word[WORD_SIZE];
 fd = open(argv[1], O_RDONLY);
 if (fd < 0) {
 fprintf(stderr, "Error: Could not open text file\n");
 return 1;
 }
 while ((i = read(fd, text, 1024)) > 0) {
 text[i] = '\0';
 char *token = strtok(text, " \t\n\r.,;:!");
 while (token != NULL) {
 if (strlen(token) > WORD_SIZE - 1) {
 printf("Warning: Word '%s' is too long\n", token);
 } else if (!check_word(token)) {
 printf("Error at line %d: Misspelled word '%s'\n", line_number, token);
 }
 words_count++;
 token = strtok(NULL, " \t\n\r.,;:!");
 }
 strcpy(text, "");
 line_number++;
 }
 close(fd);
 printf("Total words: %d\n", words_count);
 return 0;
}