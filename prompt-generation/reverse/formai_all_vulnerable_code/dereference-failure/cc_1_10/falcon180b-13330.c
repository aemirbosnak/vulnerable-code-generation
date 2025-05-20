//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000 //maximum size of the word

//node structure for trie
struct node{
    int count;
    struct node *children[26]; //26 for english alphabets
};

//function for creating a new node
struct node* create_node(){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->count=0;
    for(int i=0;i<26;i++){
        new_node->children[i]=NULL;
    }
    return new_node;
}

//function for inserting a word in trie
void insert_word(struct node* root,char* word){
    int length=strlen(word);
    struct node* current_node=root;
    for(int i=0;i<length;i++){
        int index=tolower(word[i])-'a';
        if(current_node->children[index]==NULL){
            current_node->children[index]=create_node();
        }
        current_node=current_node->children[index];
    }
    current_node->count++;
}

//function for searching a word in trie
int search_word(struct node* root,char* word){
    int length=strlen(word);
    struct node* current_node=root;
    for(int i=0;i<length;i++){
        int index=tolower(word[i])-'a';
        if(current_node->children[index]==NULL){
            return 0;
        }
        current_node=current_node->children[index];
    }
    return current_node->count;
}

//main function
int main(){
    FILE* file;
    char word[MAX_SIZE];
    struct node* root=create_node();
    file=fopen("dictionary.txt","r");
    if(file==NULL){
        printf("Error opening file\n");
        return 1;
    }
    while(fscanf(file,"%s",word)!=EOF){
        insert_word(root,word);
    }
    fclose(file);

    char sentence[MAX_SIZE];
    printf("Enter the sentence to check spelling:\n");
    fgets(sentence,MAX_SIZE,stdin);

    char* token=strtok(sentence," \t\r\n,.?!;:");
    while(token!=NULL){
        int result=search_word(root,token);
        if(result==0){
            printf("%s is not in the dictionary\n",token);
        }
        token=strtok(NULL," \t\r\n,.?!;:");
    }
    return 0;
}