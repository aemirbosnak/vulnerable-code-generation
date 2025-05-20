//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int start;
    int end;
} Appointment;

typedef struct Node {
    Appointment appt;
    struct Node *next;
} Node;

void create_list(Node **head, int days, int num_apps) {
    int i;
    for (i = 0; i < num_apps; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        scanf("%s %d %d", new_node->appt.name, &new_node->appt.start, &new_node->appt.end);
        new_node->next = *head;
        *head = new_node;
    }

    for (i = 0; i < days; i++) {
        printf("\nDay %d:\n", i + 1);
        Node *current = *head;
        while (current != NULL) {
            if (current->appt.start <= i + 1 && current->appt.end >= i + 1)
                printf("%s (%d-%d)\n", current->appt.name, current->appt.start, current->appt.end);
            current = current->next;
        }
    }
}

int main() {
    int days, num_apps;
    scanf("%d %d", &days, &num_apps);
    Node *head = NULL;
    create_list(&head, days, num_apps);

    // Free memory
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}