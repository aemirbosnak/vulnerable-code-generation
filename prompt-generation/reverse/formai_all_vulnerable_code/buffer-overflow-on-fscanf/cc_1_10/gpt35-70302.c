//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct word_node{
    char* word;
    int frequency;
    struct word_node* next;
} word_node;


void insert_word(word_node** head, char* word){
    word_node* current = *head;
    word_node* previous = NULL;
    while(current != NULL && strcmp(word, current->word) > 0){
        previous = current;
        current = current->next;
    }

    if(current == NULL || strcmp(word, current->word) != 0){
        word_node* new_node = (word_node*) malloc(sizeof(word_node));
        new_node->word = (char*) malloc(strlen(word)+1);
        strcpy(new_node->word, word);
        new_node->frequency = 1;
        new_node->next = current;

        if(previous == NULL){
            *head = new_node;
        }
        else{
            previous->next = new_node;
        }
    }
    else{
        current->frequency++;
    }
}

void print_words(word_node* head){
    while(head != NULL){
        printf("%-20s %d\n", head->word, head->frequency);
        head = head->next;
    }
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char current_word[MAX_WORD_LENGTH+1];
    word_node* head = NULL;
    while(fscanf(file, "%s", current_word) != EOF){
        int length = strlen(current_word);
        int i;
        for(i=0; i<length; i++){
            if(!isalpha(current_word[i])){
                current_word[i] = '\0';
                break;
            }
            else{
                current_word[i] = tolower(current_word[i]);
            }
        }

        if(i > 0){
            insert_word(&head, current_word);
        }
    }

    fclose(file);
    print_words(head);

    word_node* current = head;
    while(current != NULL){
        word_node* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    return 0;
}