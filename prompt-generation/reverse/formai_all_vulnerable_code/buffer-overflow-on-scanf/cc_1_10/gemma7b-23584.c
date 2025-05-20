//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_QUEUE 10

typedef struct Knight {
    char name[20];
    int sockfd;
    int status;
    struct Knight *next;
} Knight;

Knight *head = NULL;

void join_queue(char *name) {
    Knight *new_knight = malloc(sizeof(Knight));
    strcpy(new_knight->name, name);
    new_knight->sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    new_knight->status = 0;
    new_knight->next = NULL;

    if (head == NULL) {
        head = new_knight;
    } else {
        Knight *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_knight;
    }
}

int main() {
    char name[20];
    printf("Enter your knight name: ");
    scanf("%s", name);

    join_queue(name);

    Knight *current_knight = head;
    while (current_knight) {
        if (current_knight->status == 0) {
            printf("Hey, %s, your turn to fight!\n", current_knight->name);
            current_knight->status = 1;
        }
        current_knight = current_knight->next;
    }

    return 0;
}