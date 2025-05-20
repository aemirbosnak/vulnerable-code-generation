//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_WORDS 10000

typedef struct node{
    char word[MAX_WORD_LENGTH];
    struct node* next;
} Node;

Node* dictionary[MAX_DICT_WORDS];

int hash(char* str){
    int hash = 0;
    for(int i = 0; str[i] != '\0'; i++){
        hash += tolower(str[i]);
    }
    return hash % MAX_DICT_WORDS;
}

void load_dictionary(char* filename){
    FILE* dict_file = fopen(filename, "r");
    if(!dict_file){
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while(fgets(word, MAX_WORD_LENGTH, dict_file)){
        int len = strlen(word);
        if(word[len-1] == '\n'){
            word[len-1] = '\0';
        }
        int h = hash(word);
        Node* n = (Node*)malloc(sizeof(Node));
        strcpy(n->word, word);
        n->next = dictionary[h];
        dictionary[h] = n;
    }
    fclose(dict_file);
}

int is_misspelled(char* word){
    int h = hash(word);
    Node* n = dictionary[h];
    while(n){
        if(strcmp(n->word, word) == 0){
            return 0;
        }
        n = n->next;
    }
    return 1;
}

int main(){
    char dict_filename[] = "dictionary.txt";
    load_dictionary(dict_filename);
    char input[MAX_WORD_LENGTH];
    while(1){
        printf("Enter a word to check the spelling (or type 'exit' to quit): ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0){
            break;
        }
        if(is_misspelled(input)){
            printf("%s is misspelled.\n", input);
        } else {
            printf("%s is spelled correctly.\n", input);
        }
    }
    return 0;
}