//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_CUSTOMERS 100
#define MAX_WAIT_TIME 5

struct customer {
    int id;
    char name[50];
};

struct customer* customers = NULL;
int num_customers = 0;

int add_customer(char* name) {
    struct customer* new_customer = malloc(sizeof(struct customer));
    strcpy(new_customer->name, name);
    new_customer->id = num_customers++;
    customers = realloc(customers, sizeof(struct customer) * num_customers);
    customers[num_customers-1] = *new_customer;
    free(new_customer);
    return 0;
}

int get_customer_id(char* name) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            return customers[i].id;
        }
    }
    return -1;
}

void* fortune_teller(void* arg) {
    int i;
    int customer_id;
    int wait_time = rand() % MAX_WAIT_TIME;

    for (i = 0; i < wait_time; i++) {
        printf("Fortune teller is busy. Please wait...\n");
        sleep(1);
    }

    printf("Fortune teller is ready to serve customer %d.\n", *(int*) arg);

    customer_id = get_customer_id(*(char**) arg);
    if (customer_id == -1) {
        printf("Sorry, I cannot find a customer with that name.\n");
    } else {
        printf("Fortune for customer %d: You will have a lucky day today!\n", customer_id);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    char* names[MAX_CUSTOMERS];
    int ids[MAX_CUSTOMERS];

    srand(time(NULL));

    for (i = 0; i < MAX_CUSTOMERS; i++) {
        names[i] = malloc(sizeof(char) * 50);
        sprintf(names[i], "Customer %d", i);
        add_customer(names[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, fortune_teller, &ids[i]);
        printf("Thread %d created.\n", i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}