//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Linked list node structure
typedef struct {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

// Linked list structure
node *head = NULL;

// Function to add word to linked list
void add_word(char *word) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

// Function to search for word in linked list
int search_word(char *word) {
    node *current = head;
    while (current!= NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to display linked list
void display_list() {
    node *current = head;
    while (current!= NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
}

// Function to read file and add words to linked list
int read_file(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i = 0;
        while (line[i]!= '\0' && isspace(line[i])) {
            i++;
        }
        if (line[i]!= '\0') {
            strcpy(word, &line[i]);
            add_word(word);
            count++;
        }
    }

    fclose(fp);
    return count;
}

// Function to search for words in file
int search_file(char *filename, char *word) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i = 0;
        while (line[i]!= '\0' && isspace(line[i])) {
            i++;
        }
        if (line[i]!= '\0') {
            char *ptr = strstr(line, word);
            if (ptr!= NULL) {
                printf("Line %d: %s\n", count+1, line);
                count++;
            }
        }
    }

    fclose(fp);
    return count;
}

int main() {
    char filename[256], word[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    if (read_file(filename) == 0) {
        return 1;
    }

    printf("Enter word to search for: ");
    scanf("%s", word);

    int count = search_file(filename, word);

    if (count == 0) {
        printf("Word not found.\n");
    } else {
        printf("Found %d occurrences of '%s'.\n", count, word);
    }

    return 0;
}