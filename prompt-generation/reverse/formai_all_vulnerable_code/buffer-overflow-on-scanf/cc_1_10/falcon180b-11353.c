//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    int freq;
    struct node *next;
};

struct node *hashTable[26] = {NULL};

void insert(char ch) {
    int index = ch - 'a';
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ch;
    newnode->freq = 1;
    newnode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newnode;
    } else {
        struct node *temp = hashTable[index];
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node *node) {
    while (node!= NULL) {
        printf("%c %d ", node->data, node->freq);
        node = node->next;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        insert(str[i]);
    }
    printf("\nFrequency of characters:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c ", 'a' + i);
        display(hashTable[i]);
        printf("\n");
    }
    return 0;
}