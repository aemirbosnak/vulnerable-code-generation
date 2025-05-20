//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>

#define MAX_SIZE 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
    int id;
} student;

typedef struct {
    int index;
    student* data;
} node;

node* root = NULL;

void create_node(int index, student* s) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->index = index;
    new_node->data = s;
    if (root == NULL) {
        root = new_node;
    } else {
        node* current_node = root;
        while (current_node->index < index) {
            current_node = current_node->data;
        }
        current_node->data = new_node;
    }
}

void traverse(node* n) {
    if (n == NULL) {
        return;
    }
    printf("%d %s\n", n->data->id, n->data->name);
    traverse(n->data);
}

int main() {
    int i, j;
    char name[MAX_NAME];
    student s[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        printf("enter name for student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("enter id for student %s: ", s[i].name);
        scanf("%d", &s[i].id);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        create_node(hash(s[i].name), &s[i]);
    }

    printf("enter name to search: ");
    scanf("%s", name);
    int index = hash(name);
    node* found_node = root;
    while (found_node!= NULL && found_node->index!= index) {
        found_node = found_node->data;
    }
    if (found_node!= NULL) {
        printf("found student with name %s\n", found_node->data->name);
        traverse(found_node->data);
    } else {
        printf("student not found\n");
    }

    return 0;
}

int hash(char* s) {
    int hash = 0;
    while (*s) {
        hash += *s++;
    }
    return hash % MAX_SIZE;
}