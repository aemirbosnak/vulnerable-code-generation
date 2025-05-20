//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 10000 //maximum number of words that can be stored
#define MAX_WORD_LENGTH 50 //maximum length of a word

//node structure for linked list
typedef struct node{
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* next;
}node;

//function to compare two strings ignoring case
int compare(char* str1, char* str2){
    int i;
    for(i=0; str1[i] && str2[i] && tolower(str1[i]) == tolower(str2[i]); i++){
        ;
    }
    return tolower(str1[i]) - tolower(str2[i]);
}

//function to insert a word into the linked list
void insert(node** head, char* word){
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = *head;
    *head = new_node;
}

//function to print the linked list
void print_list(node* head){
    while(head!= NULL){
        printf("%s %d\n", head->word, head->count);
        head = head->next;
    }
}

//function to read a file and count the frequency of words
void count_words(char* filename, node** head){
    FILE* file;
    char word[MAX_WORD_LENGTH];
    int i;

    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    while(fscanf(file, "%s", word)!= EOF){
        for(i=0; i<strlen(word); i++){
            if(!isalpha(word[i])){
                word[i] = '\0';
                break;
            }
        }
        insert(head, word);
    }

    fclose(file);
}

int main(){
    node* head = NULL;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    count_words(filename, &head);
    print_list(head);

    return 0;
}