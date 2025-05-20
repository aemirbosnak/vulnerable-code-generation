//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 50

//Node structure for the trie
typedef struct trieNode{
    int count;
    struct trieNode* children[26];
}trieNode;

//Trie structure
trieNode* root = NULL;

//Function to create a new node
trieNode* newNode(){
    trieNode* node = (trieNode*)malloc(sizeof(trieNode));
    node->count = 0;
    for(int i=0;i<26;i++){
        node->children[i] = NULL;
    }
    return node;
}

//Function to insert a word into the trie
void insert(char* word){
    trieNode* current = root;
    int length = strlen(word);

    //Traverse the trie and create new nodes if necessary
    for(int i=0;i<length;i++){
        int index = tolower(word[i]) - 'a';
        if(current->children[index] == NULL){
            current->children[index] = newNode();
        }
        current = current->children[index];
    }

    //Mark the end of the word
    current->count++;
}

//Function to traverse the trie and print the word frequency
void traverse(trieNode* node,char prefix[]){
    if(node == NULL)
        return;

    //Print the word and its frequency
    if(node->count > 0){
        printf("%s : %d\n",prefix,node->count);
    }

    //Traverse the children of the node
    for(int i=0;i<26;i++){
        if(node->children[i]!= NULL){
            char ch = 'a' + i;
            prefix[strlen(prefix)] = ch;
            traverse(node->children[i],prefix);
        }
    }
}

//Main function
int main(){
    root = newNode();

    //Insert words into the trie
    insert("apple");
    insert("banana");
    insert("orange");
    insert("apple");
    insert("grape");

    //Traverse the trie and print the word frequency
    traverse(root,"");

    return 0;
}