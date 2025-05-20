//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000
#define MAX_FILE_SIZE 1000000

//Node structure for hash table
typedef struct node{
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* next;
}node;

//Hash table
node* hashtable[MAX_WORD_COUNT];

//Function to hash the word
int hash(char* word){
    int sum = 0;
    while(*word){
        sum += tolower(*word);
        word++;
    }
    return sum % MAX_WORD_COUNT;
}

//Function to insert word in hash table
void insert(char* word){
    int index = hash(word);
    node* temp = hashtable[index];
    while(temp!= NULL){
        if(strcmp(temp->word, word) == 0){
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->word, word);
    newnode->count = 1;
    newnode->next = hashtable[index];
    hashtable[index] = newnode;
}

//Function to print hash table
void printtable(){
    for(int i=0; i<MAX_WORD_COUNT; i++){
        node* temp = hashtable[i];
        while(temp!= NULL){
            printf("%s : %d\n", temp->word, temp->count);
            temp = temp->next;
        }
    }
}

//Function to read file and count words
void countwords(char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        exit(0);
    }
    char word[MAX_WORD_LENGTH];
    char ch;
    int wordcount = 0;
    while((ch = fgetc(file))!= EOF){
        if(isalpha(ch)){
            word[0] = tolower(ch);
            int len = 1;
            while((ch = fgetc(file))!= EOF && isalnum(ch)){
                if(len >= MAX_WORD_LENGTH){
                    break;
                }
                word[len] = tolower(ch);
                len++;
            }
            word[len] = '\0';
            insert(word);
            wordcount++;
        }
    }
    fclose(file);
}

int main(){
    srand(time(NULL));
    printf("Welcome to the futuristic word frequency counter\n");
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    countwords(filename);
    printtable();
    return 0;
}