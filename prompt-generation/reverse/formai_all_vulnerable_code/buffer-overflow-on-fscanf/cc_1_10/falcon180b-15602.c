//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100000

struct trie_node{
    int count;
    struct trie_node *children[26];
};

struct trie_node *get_node(){
    struct trie_node *node = (struct trie_node *)malloc(sizeof(struct trie_node));
    node->count = 0;
    for(int i=0; i<26; i++){
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct trie_node *root, char *word){
    struct trie_node *node = root;
    int length = strlen(word);
    for(int i=0; i<length; i++){
        if(node->children[word[i]-'a'] == NULL){
            node->children[word[i]-'a'] = get_node();
        }
        node = node->children[word[i]-'a'];
    }
    node->count++;
}

bool search(struct trie_node *root, char *word){
    struct trie_node *node = root;
    int length = strlen(word);
    for(int i=0; i<length; i++){
        if(node->children[word[i]-'a'] == NULL){
            return false;
        }
        node = node->children[word[i]-'a'];
    }
    return node->count > 0;
}

void delete_trie(struct trie_node *root){
    for(int i=0; i<26; i++){
        if(root->children[i]!= NULL){
            delete_trie(root->children[i]);
        }
    }
    free(root);
}

int main(){
    char dictionary[MAX][100];
    int size = 0;
    FILE *file = fopen("dictionary.txt", "r");
    if(file == NULL){
        printf("Error: dictionary.txt not found.\n");
        exit(1);
    }
    char word[100];
    while(fscanf(file, "%s", word)!= EOF){
        strcpy(dictionary[size], word);
        size++;
    }
    fclose(file);
    struct trie_node *root = get_node();
    for(int i=0; i<size; i++){
        insert(root, dictionary[i]);
    }
    char input[100];
    while(1){
        printf("Enter a word to check spelling: ");
        scanf("%s", input);
        if(search(root, input)){
            printf("%s is spelled correctly.\n", input);
        }
        else{
            printf("%s is spelled incorrectly.\n", input);
        }
    }
    delete_trie(root);
    return 0;
}