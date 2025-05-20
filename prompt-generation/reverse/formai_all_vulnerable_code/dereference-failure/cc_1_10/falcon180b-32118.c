//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char word[50];
    struct node* next;
} Node;

// Function to create a new node
Node* newNode(char* str) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->word, str);
    node->next = NULL;
    return node;
}

// Function to check if a word exists in the linked list
Node* search(Node* head, char* str) {
    Node* curr = head;
    while (curr!= NULL) {
        if (strcmp(curr->word, str) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// Function to insert a word into the linked list
Node* insert(Node* head, char* str) {
    Node* curr = search(head, str);
    if (curr == NULL) {
        curr = newNode(str);
        curr->next = head;
        head = curr;
    }
    return head;
}

// Function to translate a sentence recursively
void translate(Node* dict, char* sentence, char* result) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        Node* curr = search(dict, token);
        if (curr == NULL) {
            strcat(result, token);
            strcat(result, " ");
        } else {
            strcat(result, curr->word);
            strcat(result, " ");
        }
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    Node* dict = NULL;
    dict = insert(dict, "cat");
    dict = insert(dict, "dog");
    dict = insert(dict, "bird");
    dict = insert(dict, "tree");
    dict = insert(dict, "house");
    dict = insert(dict, "car");
    dict = insert(dict, "person");
    dict = insert(dict, "food");

    char sentence[] = "The cat sat on the mat.";
    char result[1000] = "";
    translate(dict, sentence, result);
    printf("%s\n", result);

    return 0;
}