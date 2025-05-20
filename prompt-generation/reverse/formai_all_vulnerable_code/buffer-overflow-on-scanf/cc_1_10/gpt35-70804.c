//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printStack(struct Node* head) {
    printf("Stack: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int command, num;

    printf("===============================================\n");
    printf("Welcome to the Surrealist Stack Visualizer!\n");
    printf("===============================================\n");
    printf("In this world, stacks are represented by\n");
    printf("a never-ending spiral of stairs that lead\n");
    printf("to endless possibilities.\n\n");
    printf("Use the commands below to explore this world:\n\n");

    while(1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n\n");
        printf("Enter command: ");
        scanf("%d", &command);

        switch(command) {
            case 1:
                printf("\nYou step onto a stairway and start walking up.\n");
                printf("You arrive at a platform with a pedestal on it.\n");
                printf("On the pedestal is a small object. You pick it up\n");
                printf("and place it in your pocket. It's value is: ");
                srand(time(NULL));
                num = rand() % 1000;
                printf("%d\n\n", num);
                push(&head, num);
                break;
            case 2:
                printf("\nYou approach a dizzying spiral staircase.\n");
                printf("You take a deep breath and begin your descent down.\n");
                pop(&head);
                break;
            case 3:
                printf("\nYou stand at the center of an endless spiral staircase.\n");
                printf("The stairs below you are lined with countless objects,\n");
                printf("each with their own unique value. You start counting: \n");
                printStack(head);
                break;
            case 4:
                printf("\nYou've seen enough of this surreal world.\n");
                printf("You leave through a portal that appears out of nowhere.\n");
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("\nYou try to move but suddenly freeze.\n");
                printf("The world stops revolving around you as\n");
                printf("you realize you've entered a place outside of time.\n");
                printf("You hear a voice echoing in your head:\n");
                printf("\"Invalid command. Try again.\"\n\n");
                break;
        }
    }

    return 0;
}