//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define DELIM ","

typedef struct {
    char* email;
    struct node* next;
} node;

node* head = NULL;

void add_node(char* email) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%s\n", curr_node->email);
        curr_node = curr_node->next;
    }
}

void delete_node(char* email) {
    node* prev_node = NULL;
    node* curr_node = head;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->email, email) == 0) {
            if (prev_node == NULL) {
                head = curr_node->next;
            } else {
                prev_node->next = curr_node->next;
            }
            free(curr_node->email);
            free(curr_node);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    char line[MAX_LINE_LEN];
    char* email = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, input_file))!= -1) {
        email = strtok(line, DELIM);
        while (email!= NULL) {
            add_node(email);
            email = strtok(NULL, DELIM);
        }
    }

    fclose(input_file);

    print_list();

    delete_node("example@example.com");

    print_list();

    return 0;
}