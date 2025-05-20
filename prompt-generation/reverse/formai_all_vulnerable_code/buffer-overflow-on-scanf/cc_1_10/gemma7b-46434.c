//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_WORDS 1024

typedef struct Word {
    char word[256];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int main() {
    Word* head = NULL;
    char word[256];

    printf("Enter a word: ");
    scanf("%s", word);

    head = insertWord(head, word);

    // Paranoid spell checking
    for (int i = 0; i < strlen(word); i++) {
        if (!isalnum(word[i]) || word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            printf("Error: Invalid character.\n");
            return 1;
        }
    }

    // Check if word is in dictionary
    Word* currentWord = head;
    while (currentWord) {
        if (strcmp(word, currentWord->word) == 0) {
            printf("Word found.\n");
            return 0;
        }
        currentWord = currentWord->next;
    }

    printf("Word not found.\n");
    return 1;
}