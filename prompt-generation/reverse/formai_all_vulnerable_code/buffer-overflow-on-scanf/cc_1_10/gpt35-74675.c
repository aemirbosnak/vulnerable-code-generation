//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

struct password_data {
    char password[MAX_LENGTH];
    char hint[MAX_LENGTH];
};

struct password_data password_list[MAX_PASSWORDS];
int num_passwords = 0;

pthread_mutex_t lock;

void add_password(char password[], char hint[]) {
    pthread_mutex_lock(&lock);
    if (num_passwords < MAX_PASSWORDS) {
        strcpy(password_list[num_passwords].password, password);
        strcpy(password_list[num_passwords].hint, hint);
        num_passwords++;
        printf("Password added successfully\n");
    } else {
        printf("Cannot add password. Maximum number of passwords reached.\n");
    }
    pthread_mutex_unlock(&lock);
}

void list_passwords() {
    pthread_mutex_lock(&lock);
    if (num_passwords == 0) {
        printf("No passwords found\n");
    } else {
        printf("List of Passwords:\n");
        for (int i = 0; i < num_passwords; i++) {
            printf("%d. Password: %s, Hint: %s\n", i+1, password_list[i].password, password_list[i].hint);
        }
    }
    pthread_mutex_unlock(&lock);
}

void *add_password_thread(void *arg) {
    char password[MAX_LENGTH];
    char hint[MAX_LENGTH];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    printf("Enter hint: ");
    scanf("%s", hint);
    
    add_password(password, hint);
    
    pthread_exit(NULL);
}

void *list_passwords_thread(void *arg) {
    list_passwords();
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        password_list[i].password[0] = '\0';
        password_list[i].hint[0] = '\0';
    }
    
    pthread_mutex_init(&lock, NULL);
    
    while (1) {
        int choice;
        printf("\n1. Add a password\n");
        printf("2. List all passwords\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, add_password_thread, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, list_passwords_thread, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}