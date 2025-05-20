//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** top_ref, int new_data);
int pop(struct node** top_ref);
int peek(struct node* top);
void print_stack(struct node* stack);

int main() {

    struct node* stack = NULL;
    int choice, data;

    while(1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                data = peek(stack);
                if(data == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element is %d\n", data);
                break;
            case 4:
                print_stack(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(struct node** top_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct node** top_ref) {
    char res;
    struct node* top = *top_ref;
    if(top == NULL) {
        printf("Stack is empty\n");
        res = 0;
    }
    else {
        res = 1;
        *top_ref = top->next;
        free(top);
    }
    return res;
}

int peek(struct node* top) {
    if(top == NULL)
        return -1;
    else
        return top->data;
}

void print_stack(struct node* stack) {
    struct node* temp = stack;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}