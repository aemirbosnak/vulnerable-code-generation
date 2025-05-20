//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1<<24

typedef struct node{
    char *word;
    struct node *next;
}node;

node *hash_table[HASH_SIZE];

//hash function
unsigned int hash(char *str){
    unsigned int h = 0;
    while(*str){
        h = h * 31 + *str;
        str++;
    }
    return h;
}

//insert a word into the hash table
void insert(char *word){
    unsigned int h = hash(word);
    node *new_node = (node*)malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

//check if a word is in the hash table
int check(char *word){
    unsigned int h = hash(word);
    node *curr = hash_table[h];
    while(curr){
        if(strcmp(curr->word, word) == 0){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int main(){
    //load the dictionary
    FILE *dict = fopen("dictionary.txt", "r");
    char word[100];
    while(fscanf(dict, "%s", word) != EOF){
        insert(word);
    }
    fclose(dict);

    //check the spelling
    char input[100];
    printf("Enter a word: ");
    scanf("%s", input);
    if(check(input)){
        printf("The word is spelled correctly.\n");
    }else{
        printf("The word is spelled incorrectly.\n");
    }

    return 0;
}