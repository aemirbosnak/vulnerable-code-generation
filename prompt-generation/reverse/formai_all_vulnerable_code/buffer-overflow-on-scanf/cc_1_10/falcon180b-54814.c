//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000000
#define MAX_CODE_SIZE 50000

struct trieNode{
    int count;
    struct trieNode *children[26];
};

struct trieNode *root = NULL;

void initTrie(){
    root = (struct trieNode*)malloc(sizeof(struct trieNode));
    root->count = 0;
    memset(root->children, 0, sizeof(root->children));
}

void insertWord(char *word){
    int len = strlen(word);
    struct trieNode *node = root;
    for(int i=0;i<len;i++){
        if(isalpha(word[i])){
            int index = tolower(word[i]) - 'a';
            if(node->children[index] == NULL){
                node->children[index] = (struct trieNode*)malloc(sizeof(struct trieNode));
            }
            node = node->children[index];
        }
    }
    node->count++;
}

void generateCode(struct trieNode *node, char *prefix){
    if(node->count == 0)
        return;
    if(node->count == 1){
        printf("%s -> %c\n", prefix, 'a' + node->children[0]->count);
        return;
    }
    int maxCount = 0;
    for(int i=0;i<26;i++){
        if(node->children[i]!= NULL && node->children[i]->count > maxCount){
            maxCount = node->children[i]->count;
        }
    }
    printf("%s -> %c\n", prefix, 'a' + maxCount);
    for(int i=0;i<26;i++){
        if(node->children[i]!= NULL && node->children[i]->count == maxCount){
            generateCode(node->children[i], prefix + (char)('a' + i));
        }
    }
}

int main(){
    char word[MAX_SIZE];
    initTrie();
    while(scanf("%s", word)!= EOF){
        insertWord(word);
    }
    generateCode(root, "");
    return 0;
}