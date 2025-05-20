//Falcon-180B DATASET v1.0 Category: Recursive ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 10000

typedef struct node{
    char word[MAX_SIZE];
    int count;
    struct node* next;
}node_t;

node_t* create_node(char word[MAX_SIZE], int count){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

void delete_node(node_t* node){
    free(node);
}

void merge_nodes(node_t* node1, node_t* node2){
    if(node1->count > node2->count){
        node1->count += node2->count;
        delete_node(node2);
    }else{
        node2->count += node1->count;
        delete_node(node1);
    }
}

void print_word_count(node_t* node){
    printf("%s : %d\n", node->word, node->count);
}

void print_word_counts(node_t* node){
    while(node!= NULL){
        print_word_count(node);
        node = node->next;
    }
}

node_t* merge_sort(node_t* head){
    node_t* current = head;
    while(current!= NULL && current->next!= NULL){
        if(strcmp(current->word, current->next->word) > 0){
            node_t* temp = current->next;
            current->next = current->next->next;
            temp->next = merge_sort(current);
            current = temp;
        }else{
            current = current->next;
        }
    }
    return current;
}

int main(){
    FILE* file = fopen("input.txt", "r");
    if(file == NULL){
        printf("Error: could not open file.\n");
        exit(1);
    }

    char word[MAX_SIZE];
    node_t* head = NULL;
    while(fscanf(file, "%s", word)!= EOF){
        node_t* new_node = create_node(word, 1);
        if(head == NULL){
            head = new_node;
        }else{
            node_t* current = head;
            while(strcmp(current->word, word)!= 0 && current->next!= NULL){
                current = current->next;
            }
            if(strcmp(current->word, word) == 0){
                current->count++;
            }else{
                merge_nodes(current->next, new_node);
                current->next = new_node;
            }
        }
    }

    head = merge_sort(head);
    print_word_counts(head);

    fclose(file);
    return 0;
}