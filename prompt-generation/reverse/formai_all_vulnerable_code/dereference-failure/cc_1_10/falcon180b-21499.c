//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    int id;
    char name[50];
    int price;
};

struct node {
    struct item item;
    int next;
};

struct node* root = NULL;
int count = 0;

void insert(int id, char* name, int price) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->item.id = id;
    strcpy(new_node->item.name, name);
    new_node->item.price = price;
    new_node->next = -1;

    if (root == NULL) {
        root = new_node;
    } else {
        int i = 0;
        while (i < count) {
            if (id < root->item.id) {
                new_node->next = root->next;
                root->next = i;
                break;
            } else {
                i++;
            }
        }
    }

    count++;
}

void search(int id) {
    int i = 0;
    struct node* curr_node = root;

    while (i < count && curr_node!= NULL) {
        if (id == curr_node->item.id) {
            printf("ID: %d\nName: %s\nPrice: %d\n", curr_node->item.id, curr_node->item.name, curr_node->item.price);
        } else if (id < curr_node->item.id) {
            curr_node = curr_node->next;
        } else {
            curr_node = curr_node->next;
        }
        i++;
    }
}

int main() {
    root = (struct node*)malloc(sizeof(struct node));
    root->next = -1;
    count = 0;

    insert(1, "Apple", 100);
    insert(2, "Banana", 200);
    insert(3, "Cherry", 300);

    search(1);
    search(2);
    search(3);
    search(4);

    return 0;
}