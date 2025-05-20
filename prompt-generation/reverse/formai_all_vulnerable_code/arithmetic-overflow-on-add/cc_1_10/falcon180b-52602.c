//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 100

typedef struct Node{
    char data;
    int count;
    struct Node* left;
    struct Node* right;
}node;

typedef struct TrieNode{
    struct Node* root;
    int count;
}Trie;

void init(Trie* t){
    t->root=NULL;
    t->count=0;
}

void insert(Trie* t, char* word){
    int len=strlen(word);
    node* curr=t->root;
    for(int i=0;i<len;i++){
        int index=tolower(word[i])-'a';
        if(curr->left==NULL){
            curr->left=(node*)malloc(sizeof(node));
        }
        curr=curr->left;
    }
    curr->count++;
    t->count++;
}

void delete(Trie* t, char* word){
    int len=strlen(word);
    node* curr=t->root;
    for(int i=0;i<len;i++){
        int index=tolower(word[i])-'a';
        if(curr->left==NULL){
            return;
        }
        curr=curr->left;
    }
    curr->count--;
    t->count--;
}

void search(Trie* t, char* word){
    int len=strlen(word);
    node* curr=t->root;
    for(int i=0;i<len;i++){
        int index=tolower(word[i])-'a';
        if(curr->left==NULL){
            return;
        }
        curr=curr->left;
    }
    if(curr->count>0){
        printf("%s exists in the trie\n",word);
    }
    else{
        printf("%s does not exist in the trie\n",word);
    }
}

void display(Trie* t, char* prefix, int count){
    node* curr=t->root;
    for(int i=0;i<strlen(prefix);i++){
        int index=tolower(prefix[i])-'a';
        if(curr->left==NULL){
            return;
        }
        curr=curr->left;
    }
    if(curr->count>count){
        printf("%s %d\n",prefix,curr->count);
        for(int i=0;i<26;i++){
            if(curr->left->right!=NULL && curr->left->right->count>count){
                char ch=i+'a';
                display(t,prefix+ch,count);
            }
        }
    }
}

int main(){
    Trie t;
    init(&t);
    insert(&t,"hello");
    insert(&t,"world");
    insert(&t,"trie");
    insert(&t,"tree");
    insert(&t,"min");
    insert(&t,"max");
    insert(&t,"count");
    insert(&t,"display");
    insert(&t,"search");
    insert(&t,"delete");
    printf("Total words in trie: %d\n",t.count);
    search(&t,"hello");
    search(&t,"min");
    search(&t,"max");
    search(&t,"count");
    search(&t,"display");
    search(&t,"search");
    search(&t,"delete");
    display(&t,"",2);
    delete(&t,"hello");
    printf("Total words in trie after deleting 'hello': %d\n",t.count);
    display(&t,"",2);
    return 0;
}