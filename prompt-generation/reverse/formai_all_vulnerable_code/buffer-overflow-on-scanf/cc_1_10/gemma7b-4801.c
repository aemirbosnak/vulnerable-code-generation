//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT 8080

struct BankRecord {
    char name[20];
    int account_number;
    double balance;
    struct BankRecord* next;
};

void add_record(struct BankRecord** head) {
    struct BankRecord* new_record = malloc(sizeof(struct BankRecord));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (*head == NULL) {
        *head = new_record;
    } else {
        (*head)->next = new_record;
    }
}

void print_records(struct BankRecord* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Account number: %d\n", head->account_number);
        printf("Balance: %.2lf\n", head->balance);
        printf("\n");
        head = head->next;
    }
}

int main() {
    struct BankRecord* head = NULL;

    // Start server
    listen(SERVER_PORT);

    // Accept client connection
    int client_sockfd = accept(SERVER_PORT, NULL, NULL);

    // Client request
    char request[1024];
    recv(client_sockfd, request, 1024, 0);

    // Process request
    if (strcmp(request, "add") == 0) {
        add_record(&head);
    } else if (strcmp(request, "print") == 0) {
        print_records(head);
    }

    // Close client connection
    close(client_sockfd);

    return 0;
}