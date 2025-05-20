//Falcon-180B DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void print_list(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void reverse_list(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;

    while (current!= NULL) {
        struct node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    FILE* fp;
    char ch;
    struct node* head = NULL;

    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Unable to open file");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            int num = 0;
            ungetc(ch, fp);
            fscanf(fp, "%d", &num);
            add_node(&head, num);
        }
    }

    fclose(fp);

    printf("Original list: ");
    print_list(head);

    reverse_list(&head);

    printf("\nReversed list: ");
    print_list(head);

    return 0;
}