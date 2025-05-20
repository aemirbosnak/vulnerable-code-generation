//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int hash_function(char* str) {
    int hash = 0;
    int i = 0;
    while (str[i]) {
        hash += str[i];
        i++;
    }
    return hash % MAX_STRING_LENGTH;
}

struct node {
    char* str;
    int count;
    struct node* next;
};

struct node* create_node(char* str, int count) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->str = str;
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

struct node** create_table() {
    struct node** table = (struct node**)malloc(MAX_STRING_LENGTH * sizeof(struct node*));
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        table[i] = NULL;
    }
    return table;
}

void insert_word(struct node** table, char* str) {
    int hash = hash_function(str);
    struct node* current_node = table[hash];
    while (current_node!= NULL) {
        if (strcmp(current_node->str, str) == 0) {
            current_node->count++;
            return;
        }
        current_node = current_node->next;
    }
    struct node* new_node = create_node(str, 1);
    new_node->next = table[hash];
    table[hash] = new_node;
}

void print_table(struct node** table) {
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        struct node* current_node = table[i];
        while (current_node!= NULL) {
            printf("%s %d\n", current_node->str, current_node->count);
            current_node = current_node->next;
        }
    }
}

int main() {
    char* words[] = {"hello", "world", "hello", "world", "world", "world", "world", "world", "world", "world"};
    int num_words = sizeof(words) / sizeof(words[0]);
    struct node** table = create_table();
    for (int i = 0; i < num_words; i++) {
        insert_word(table, words[i]);
    }
    print_table(table);
    return 0;
}