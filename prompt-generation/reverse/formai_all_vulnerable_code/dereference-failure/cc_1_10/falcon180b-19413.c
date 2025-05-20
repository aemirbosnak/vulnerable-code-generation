//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

typedef struct node {
    char* word;
    int freq;
    struct node* next;
} node;

node* create_node(char* word) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->word = word;
    new_node->freq = 1;
    new_node->next = NULL;
    return new_node;
}

void insert_word(node** head, char* word) {
    node* new_node = create_node(word);
    node* curr_node = *head;
    if (*head == NULL) {
        *head = new_node;
    } else {
        while (curr_node->next!= NULL && strcmp(curr_node->next->word, word) < 1) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void display_words(node* curr_node) {
    while (curr_node!= NULL) {
        printf("%s %d\n", curr_node->word, curr_node->freq);
        curr_node = curr_node->next;
    }
}

int main() {
    node* head = NULL;
    char* input_str;
    int i = 0, j = 0, k = 0;
    char* token;

    printf("Enter a string: ");
    scanf("%s", input_str);

    while (input_str[i]!= '\0') {
        if (isalpha(input_str[i])) {
            j = i;
            while (isalpha(input_str[i])) {
                i++;
            }
            token = (char*)malloc(sizeof(char) * (i - j + 1));
            strncpy(token, input_str + j, i - j);
            token[i - j] = '\0';
            insert_word(&head, token);
        }
        i++;
    }

    display_words(head);

    return 0;
}