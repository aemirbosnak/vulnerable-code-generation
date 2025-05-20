//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *next;
} Node;

void add_to_list(Node **head_ref, char val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(Node *node) {
    while (node != NULL) {
        printf("%c ", node->value);
        node = node->next;
    }
}

void delete_list(Node **head_ref) {
    Node *current = *head_ref;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int check_frame(char c, Node **head_ref) {
    int i, j;
  
    if (*head_ref == NULL) {
        add_to_list(head_ref, c);
        return 0;
    }
  
    add_to_list(head_ref, c);
  
    Node *tail = *head_ref;
    while (tail->next != NULL) {
        tail = tail->next;
    }
  
    Node *temp1 = *head_ref;
  
    while (temp1 != NULL && temp1 != tail) {
        Node *temp2 = temp1;
        for (j = 1; temp2 != tail && j < 4; j++) {
            temp2 = temp2->next;
        }
       
        if (temp2 == tail) {
            break;
        }
      
        temp1 = temp1->next;
    }
  
    if (temp1 == NULL) {
        delete_list(head_ref);
        printf("Intrusion detected\n");
        return 1;
    }
  
    Node *temp2 = temp1->next;
    temp1->next = NULL;
    delete_list(head_ref);
    add_to_list(head_ref, temp2->value);
    return 0;
}

void validate_input(char *input) {
    int i;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] < 'A' || input[i] > 'Z') {
            printf("Error: Non capital letter detected in input\n");
            exit(0);
        }
    }
}

void check_input(char *input) {
    Node *head = NULL;
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (check_frame(input[i], &head) == 1) {
            break;
        }
    }
    delete_list(&head);
}

int main() {
    char input[50];
    printf("Enter input: ");
    scanf("%s", input);
    validate_input(input);
    check_input(input);
    return 0;
}