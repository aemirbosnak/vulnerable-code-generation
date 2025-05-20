//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: brave
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<time.h>

#define MAX_SIZE 1000000

typedef struct node{
    char *word;
    int freq;
    struct node *next;
}Node;

typedef struct hashTable{
    Node *table[MAX_SIZE];
}HashTable;

HashTable *createTable(){
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    int i;
    for(i=0;i<MAX_SIZE;i++){
        table->table[i] = NULL;
    }
    return table;
}

int hashFunc(char *str){
    int sum = 0;
    int i;
    for(i=0;i<strlen(str);i++){
        sum += tolower(str[i]);
    }
    return sum % MAX_SIZE;
}

void insertWord(HashTable *table,char *str){
    int index = hashFunc(str);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->word = strdup(str);
    newNode->freq = 1;
    newNode->next = table->table[index];
    table->table[index] = newNode;
}

void printTable(HashTable *table){
    int i;
    for(i=0;i<MAX_SIZE;i++){
        Node *temp = table->table[i];
        while(temp!=NULL){
            printf("%s %d\n",temp->word,temp->freq);
            temp = temp->next;
        }
    }
}

int main(){
    HashTable *table = createTable();
    char input[100];
    while(1){
        printf("Enter a string to insert or type 'exit' to quit: ");
        scanf("%s",input);
        if(strcmp(input,"exit")==0){
            break;
        }
        insertWord(table,input);
    }
    printf("Frequency of words:\n");
    printTable(table);
    return 0;
}