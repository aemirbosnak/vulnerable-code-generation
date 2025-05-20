//Falcon2-11B DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 10
#define MAX_OPERAND_SIZE 20

// Node structure for the linked list
typedef struct {
    char value[MAX_NUM_DIGITS];
    struct node *next;
} node;

// Linked list data structure
node *head = NULL;

// Function to add a new node to the linked list
node* add_node(char* value) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->value, value);
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    return new_node;
}

// Function to calculate the result of the expression
int calculate(node* head) {
    int result = 0;
    node* current = head;
    char op1[MAX_NUM_DIGITS], op2[MAX_NUM_DIGITS], op3[MAX_NUM_DIGITS], op4[MAX_NUM_DIGITS];
    char* op;
    
    while (current!= NULL) {
        if (current->next == NULL) {
            break;
        }
        
        if (strcmp(current->value, "+") == 0) {
            op = op1;
        } else if (strcmp(current->value, "-") == 0) {
            op = op2;
        } else if (strcmp(current->value, "*") == 0) {
            op = op3;
        } else if (strcmp(current->value, "/") == 0) {
            op = op4;
        } else {
            op = current->value;
        }
        
        current = current->next;
    }
    
    if (strcmp(op, "+") == 0) {
        node* temp = add_node(op1);
        node* temp2 = add_node(op2);
        temp->next = temp2;
        result = calculate(temp->next);
    } else if (strcmp(op, "-") == 0) {
        node* temp = add_node(op1);
        node* temp2 = add_node(op2);
        temp->next = temp2;
        result = calculate(temp->next);
    } else if (strcmp(op, "*") == 0) {
        node* temp = add_node(op1);
        node* temp2 = add_node(op2);
        temp->next = temp2;
        result = calculate(temp->next);
    } else if (strcmp(op, "/") == 0) {
        node* temp = add_node(op1);
        node* temp2 = add_node(op2);
        temp->next = temp2;
        result = calculate(temp->next);
    } else {
        result = atoi(op);
    }
    
    return result;
}

int main() {
    char op1[MAX_NUM_DIGITS], op2[MAX_NUM_DIGITS], op3[MAX_NUM_DIGITS], op4[MAX_NUM_DIGITS];
    char op;
    printf("Enter the expression (e.g. 3 + 4): ");
    scanf("%s", op1);
    head = add_node(op1);
    while (1) {
        printf("Enter the next operand or operator (+, -, *, /): ");
        scanf("%s", op);
        if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0) {
            head = add_node(op);
        } else {
            break;
        }
    }
    int result = calculate(head);
    printf("Result: %d\n", result);
    
    return 0;
}