//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 100
#define MAX_ACCOUNTS 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

pthread_mutex_t lock;

void *add_account(void *arg)
{
    int id = *(int *) arg;
    printf("Enter username for account %d: ", id);
    scanf("%s", accounts[id].username);
    printf("Enter password for account %d: ", id);
    scanf("%s", accounts[id].password);
    printf("Account %d created successfully.\n", id);

    pthread_mutex_lock(&lock);
    num_accounts++;
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *login(void *arg)
{
    char username[MAX_LEN];
    char password[MAX_LEN];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int found = 0;
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0 &&
            strcmp(password, accounts[i].password) == 0) {
            found = 1;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    if (found) {
        printf("Login successful.\n");
    } else {
        printf("Login failed.\n");
    }

    return NULL;
}

int main()
{
    pthread_t tid[MAX_ACCOUNTS];
    int ids[MAX_ACCOUNTS];

    pthread_mutex_init(&lock, NULL);

    char choice;
    do {
        printf("1. Create account\n");
        printf("2. Login\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                if (num_accounts >= MAX_ACCOUNTS) {
                    printf("Cannot create more accounts.\n");
                    break;
                }

                ids[num_accounts] = num_accounts;
                pthread_create(&tid[num_accounts], NULL, add_account, &ids[num_accounts]);
                break;
            }
            case '2': {
                pthread_t login_tid;
                pthread_create(&login_tid, NULL, login, NULL);
                pthread_join(login_tid, NULL);
                break;
            }
            case '3': {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while (choice != '3');

    for (int i = 0; i < num_accounts; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}