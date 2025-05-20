//FormAI DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_ITEMS 100
#define MAX_DESC_LENGTH 50

float total_expense = 0;
pthread_mutex_t mutex;

struct expense {
    char desc[MAX_DESC_LENGTH];
    float cost;
    struct tm timestamp;
};

struct expense expense_list[MAX_ITEMS];
int list_size = 0;

void print_expense(struct expense e)
{
    printf("Description: %s\n", e.desc);
    printf("Cost: %.2f\n", e.cost);
    printf("Date: %d-%02d-%02d\n", e.timestamp.tm_year + 1900, e.timestamp.tm_mon + 1, e.timestamp.tm_mday);
    printf("Time: %02d:%02d:%02d\n", e.timestamp.tm_hour, e.timestamp.tm_min, e.timestamp.tm_sec);
}

void add_expense(char *desc, float cost)
{
    pthread_mutex_lock(&mutex);

    time_t now;
    time(&now);
    struct tm timestamp = *localtime(&now);

    strcpy(expense_list[list_size].desc, desc);
    expense_list[list_size].cost = cost;
    expense_list[list_size].timestamp = timestamp;
    list_size++;

    total_expense += cost;

    pthread_mutex_unlock(&mutex);

    printf("Expense added successfully!\n");
}

void print_all_expenses()
{
    pthread_mutex_lock(&mutex);

    if (list_size == 0) {
        printf("No expenses found.\n");
    } else {
        printf("Total expenses: %.2f\n", total_expense);
        for (int i = 0; i < list_size; i++) {
            printf("\n[%d]\n", i+1);
            print_expense(expense_list[i]);
        }
    }

    pthread_mutex_unlock(&mutex);
}

void clear_expenses()
{
    pthread_mutex_lock(&mutex);

    if (list_size == 0) {
        printf("No expenses found.\n");
    } else {
        list_size = 0;
        total_expense = 0;
        printf("All expenses cleared successfully.\n");
    }

    pthread_mutex_unlock(&mutex);
}

void *menu(void *arg)
{
    while (true) {
        printf("\n----Expense Tracker----\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Clear all expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        char choice = getchar();
        getchar(); //to consume the newline character

        switch (choice) {
            case '1': {
                char desc[MAX_DESC_LENGTH];
                float cost;

                printf("Enter expense description: ");
                scanf("%[^\n]", desc);
                getchar(); //to consume the newline character

                printf("Enter expense cost: ");
                scanf("%f", &cost);
                getchar(); //to consume the newline character

                add_expense(desc, cost);
                break;
            }
            case '2': {
                print_all_expenses();
                break;
            }
            case '3': {
                clear_expenses();
                break;
            }
            case '4': {
                pthread_exit(NULL);
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
        sleep(2);
        system("clear");
    }
}

int main()
{
    pthread_mutex_init(&mutex, NULL);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, menu, NULL);

    pthread_join(thread_id, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}