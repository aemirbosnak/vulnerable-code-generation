//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Trie_node {
  struct Trie_node *children[26];
  int isEndOfWord;
};

struct Trie_node *getNode(void) {
  struct Trie_node *pNode = NULL;
  pNode = (struct Trie_node *)malloc(sizeof(struct Trie_node));
  if (pNode) {
    int i;
    pNode->isEndOfWord = 0;
    for (i = 0; i < 26; i++) {
      pNode->children[i] = NULL;
    }
  }
  return pNode;
}

void insert(struct Trie_node *root, char *key) {
  int length = strlen(key);
  int index;
  struct Trie_node *pCrawl = root;
  for (int level = 0; level < length; level++) {
    index = key[level] - 'a';
    if (!pCrawl->children[index]) {
      pCrawl->children[index] = getNode();
    }
    pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = 1;
}

int search(struct Trie_node *root, char *key) {
  int length = strlen(key);
  int index;
  struct Trie_node *pCrawl = root;
  for (int level = 0; level < length; level++) {
    index = key[level] - 'a';
    if (!pCrawl->children[index]) {
      return 0;
    }
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int isPalindrome(char *str, int len) {
  int i = 0, j = len - 1;
  while (i < j) {
    if (str[i] != str[j]) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}

int checkPalindromes(char *word, int len) {
  int mid = len / 2;
  int i;
  for (i = 0; i < mid; i++) {
    if (word[i] != word[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int checkDoubleLetters(char *word, int len) {
  for (int i = 0; i < len - 1; i++) {
    if (word[i] == word[i + 1]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  struct Trie_node *root = getNode();
  FILE *fp;
  char word[100];
  fp = fopen("dictionary.txt", "r");
  while (!feof(fp)) {
    fscanf(fp, "%s", word);
    insert(root, word);
  }
  fclose(fp);
  int n;
  printf("Enter the number of words to check: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter a word: ");
    scanf("%s", word);
    int len = strlen(word);
    int result = search(root, word);
    if (result == 1) {
      printf("%s is a valid word.\n", word);
    } else {
      printf("%s is not a valid word.\n", word);
    }
    int isPalindrome = checkPalindromes(word, len);
    if (isPalindrome == 1) {
      printf("%s is a palindrome.\n", word);
    } else {
      printf("%s is not a palindrome.\n", word);
    }
    int hasDoubleLetters = checkDoubleLetters(word, len);
    if (hasDoubleLetters) {
      printf("%s contains double letters.\n", word);
    } else {
      printf("%s does not contain double letters.\n", word);
    }
  }
  return 0;
}