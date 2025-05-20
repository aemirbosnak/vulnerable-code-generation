//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_MESSAGES 100

typedef struct {
    char name[50];
    struct list_node *next;
} list_node;

typedef struct {
    char name[50];
    struct list_node *next;
} list_head;

typedef struct {
    char message[100];
    struct list_node *next;
} message_node;

list_node *head;
list_node *tail;
list_node *cur;

list_head *subscriptions;
message_node *messages;
int num_subscriptions;
int num_messages;

void add_subscriber(char *name) {
    list_node *node = (list_node*)malloc(sizeof(list_node));
    strcpy(node->name, name);
    node->next = NULL;
    
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    
    num_subscriptions++;
}

void remove_subscriber(char *name) {
    list_node *cur = head;
    
    while (cur!= NULL && strcmp(cur->name, name)!= 0) {
        cur = cur->next;
    }
    
    if (cur == NULL) {
        printf("Subscriber not found\n");
        return;
    }
    
    if (cur == head) {
        if (cur == tail) {
            free(cur);
            head = tail = NULL;
        } else {
            head = cur->next;
            free(cur);
        }
    } else {
        tail->next = cur->next;
        free(cur);
    }
    
    num_subscriptions--;
}

void add_message(char *message) {
    message_node *node = (message_node*)malloc(sizeof(message_node));
    strcpy(node->message, message);
    node->next = NULL;
    
    if (messages == NULL) {
        messages = node;
    } else {
        messages->next = node;
    }
    
    num_messages++;
}

void send_message() {
    message_node *cur = messages;
    
    while (cur!= NULL) {
        printf("%s\n", cur->message);
        cur = cur->next;
    }
}

void print_subscriptions() {
    list_head *cur = subscriptions;
    
    while (cur!= NULL) {
        printf("%s\n", cur->name);
        cur = cur->next;
    }
}

int main() {
    printf("Mailing list manager\n");
    
    char name[50];
    char message[100];
    
    while (1) {
        printf("1. Add subscriber\n2. Remove subscriber\n3. Send message\n4. Print subscriptions\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter subscriber name: ");
                scanf("%s", name);
                add_subscriber(name);
                break;
            case 2:
                printf("Enter subscriber name: ");
                scanf("%s", name);
                remove_subscriber(name);
                break;
            case 3:
                printf("Enter message: ");
                scanf("%s", message);
                add_message(message);
                break;
            case 4:
                print_subscriptions();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    
    return 0;
}