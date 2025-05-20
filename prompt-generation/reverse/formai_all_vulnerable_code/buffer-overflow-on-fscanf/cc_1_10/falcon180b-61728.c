//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

//Node structure for creating linked lists
struct node{
    char word[MAX_WORD_LENGTH];
    int count;
    struct node* next;
};

//Function to create a new node
struct node* create_node(char* word){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

//Function to count the frequency of a word
void count_word(struct node* head, char* word){
    struct node* current = head;
    while(current!= NULL){
        if(strcmp(current->word, word) == 0){
            current->count++;
            return;
        }
        current = current->next;
    }
    //If the word is not found, create a new node and add it to the end of the list
    current = create_node(word);
    current->next = NULL;
    if(head == NULL){
        head = current;
    }
    else{
        struct node* last = head;
        while(last->next!= NULL){
            last = last->next;
        }
        last->next = current;
    }
}

//Function to print the frequency of a word
void print_word(struct node* head, char* word){
    struct node* current = head;
    while(current!= NULL){
        if(strcmp(current->word, word) == 0){
            printf("%s: %d\n", current->word, current->count);
            return;
        }
        current = current->next;
    }
    printf("%s not found\n", word);
}

//Function to free the memory allocated for the linked lists
void free_list(struct node* head){
    struct node* current = head;
    while(current!= NULL){
        free(current->word);
        free(current);
        current = current->next;
    }
}

//Main function
int main(){
    char filename[50];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("File not found\n");
        return 0;
    }
    char word[MAX_WORD_LENGTH];
    struct node* head = NULL;
    while(fscanf(file, "%s", word)!= EOF){
        count_word(head, word);
    }
    fclose(file);
    printf("Enter the word to search for: ");
    scanf("%s", word);
    print_word(head, word);
    free_list(head);
    return 0;
}