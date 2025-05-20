//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char name[MAX_SIZE];
    int size;
    int type;
    struct node *next;
} Node;

Node* create_node(char* name, int size, int type) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->type = type;
    new_node->next = NULL;
    return new_node;
}

void traverse_dir(Node* dir) {
    Node* current = dir;
    while (current!= NULL) {
        printf("%s (%d bytes) - ", current->name, current->size);
        if (current->type == 0) {
            printf("File\n");
        } else {
            printf("Directory\n");
        }
        current = current->next;
    }
}

int main() {
    Node* root = create_node("/", 0, 1);
    Node* romeo = create_node("Romeo", 0, 1);
    Node* juliet = create_node("Juliet", 0, 1);

    root->next = romeo;
    romeo->next = juliet;

    Node* romeo_love_letter = create_node("love_letter.txt", 1024, 0);
    romeo->next = romeo_love_letter;

    Node* juliet_diary = create_node("diary.txt", 2048, 0);
    juliet->next = juliet_diary;

    traverse_dir(root);

    return 0;
}