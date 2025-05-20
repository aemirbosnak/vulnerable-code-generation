//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for dictionary
typedef struct node {
    char word[50];
    struct node* next;
} node;

node* head = NULL;

// Function to add word to dictionary
void add(char* word) {
    node* new_node = (node*)malloc(sizeof(node));
    
    strcpy(new_node->word, word);
    new_node->next = NULL;
    
    if(head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

// Function to remove leading and trailing punctuations
char* remove_punctuations(char* str) {
    int len = strlen(str);
    
    while(ispunct(str[0])) {
        memmove(str, str+1, len--);
    }
    
    while(ispunct(str[len-1])) {
        len--;
    }
    
    str[len] = '\0';
    
    return str;
}

// Function to check if a word is present in dictionary
int check(node* curr, char* word) {
    if(curr == NULL) {
        return 0;
    }
    
    if(strcmp(curr->word, word) == 0) {
        return 1;
    }
    
    return check(curr->next, word);
}

int main() {
    // Reading dictionary file
    FILE* fp = fopen("dictionary.txt", "r");
    
    if(fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    
    char* line = NULL;
    size_t len = 0;
    
    while(getline(&line, &len, fp) != -1) {
        // Removing newline character from end of line
        line[strcspn(line, "\n")] = '\0';
        
        add(line);
    }
    
    fclose(fp);
    free(line);
    
    // Reading input file
    fp = fopen("input.txt", "r");
    
    if(fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    
    char buffer[100];
    
    while(fscanf(fp, "%s", buffer) == 1) {
        // Removing leading and trailing punctuations
        char* word = remove_punctuations(buffer);
        
        // Converting word to lowercase
        int i;
        
        for(i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Checking if word is present in dictionary
        if(!check(head, word)) {
            printf("%s is misspelled\n", buffer);
        }
    }
    
    fclose(fp);

    return 0;
}