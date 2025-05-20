//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_SERVICE_LENGTH 50

typedef struct PasswordNode {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct PasswordNode* next;
} PasswordNode;

PasswordNode* head = NULL;
pthread_mutex_t lock;

void* add_password(void* arg) {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter service name: ");
    scanf("%s", service);
    printf("Enter password: ");
    scanf("%s", password);

    pthread_mutex_lock(&lock);

    PasswordNode* new_node = (PasswordNode*)malloc(sizeof(PasswordNode));
    strcpy(new_node->service, service);
    strcpy(new_node->password, password);
    new_node->next = head;
    head = new_node;

    printf("Password for %s added.\n", service);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* retrieve_password(void* arg) {
    char service[MAX_SERVICE_LENGTH];
    printf("Enter service name to retrieve password: ");
    scanf("%s", service);

    pthread_mutex_lock(&lock);

    PasswordNode* current = head;
    while (current != NULL) {
        if (strcmp(current->service, service) == 0) {
            printf("Password for %s is: %s\n", service, current->password);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        current = current->next;
    }
    printf("Password for %s not found.\n", service);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* delete_password(void* arg) {
    char service[MAX_SERVICE_LENGTH];
    printf("Enter service name to delete password: ");
    scanf("%s", service);

    pthread_mutex_lock(&lock);

    PasswordNode* current = head;
    PasswordNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->service, service) == 0) {
            if (prev == NULL) { // Deleting head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Password for %s deleted.\n", service);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        prev = current;
        current = current->next;
    }
    printf("Password for %s not found.\n", service);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int choice;

    pthread_mutex_init(&lock, NULL);

    while (1) {
        printf("Password Management System\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, add_password, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, retrieve_password, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                pthread_create(&threads[2], NULL, delete_password, NULL);
                pthread_join(threads[2], NULL);
                break;
            case 4:
                goto cleanup;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

cleanup:
    pthread_mutex_destroy(&lock);
    
    // Free linked list
    PasswordNode* current = head;
    while (current != NULL) {
        PasswordNode* temp = current;
        current = current->next;
        free(temp);
    }
    
    printf("Exiting the program.\n");
    return 0;
}