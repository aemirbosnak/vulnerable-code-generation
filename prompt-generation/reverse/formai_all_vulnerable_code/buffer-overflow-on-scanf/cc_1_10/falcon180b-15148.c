//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *title;
    char *author;
    char *content;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} list;

list *create_list() {
    list *l = (list *) malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

node *create_node(char *title, char *author, char *content) {
    node *n = (node *) malloc(sizeof(node));
    n->title = title;
    n->author = author;
    n->content = content;
    n->next = NULL;
    return n;
}

void add_node(list *l, node *n) {
    if (l->head == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
}

void print_list(list *l) {
    node *n = l->head;
    while (n!= NULL) {
        printf("Title: %s\nAuthor: %s\nContent:\n%s\n\n", n->title, n->author, n->content);
        n = n->next;
    }
}

int main() {
    list *l = create_list();
    char title[MAX_SIZE], author[MAX_SIZE], content[MAX_SIZE];

    while (1) {
        printf("Enter title: ");
        scanf("%s", title);
        printf("Enter author: ");
        scanf("%s", author);
        printf("Enter content:\n");
        fgets(content, MAX_SIZE, stdin);

        node *n = create_node(strdup(title), strdup(author), strdup(content));
        add_node(l, n);

        printf("Do you want to add another book? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    print_list(l);

    return 0;
}