//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_ITEMS 10
#define BILLING_THREADS 2

int menu[MAX_ITEMS] = {10, 20, 30, 40, 50, 60 ,70, 80, 90, 100};
int quantity[MAX_ITEMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int total = 0;

pthread_mutex_t lock;

void* takeOrder(void* arg){
    int item;
    int quantity_;
    while(1){
        printf("\nWhich item would you like to order?(1-10): ");
        scanf("%d", &item);
        if(item < 1 || item > 10){
            printf("Invalid choice. Please select a valid item from menu.");
            continue;
        }
        item--;
        printf("How many would you like to order? ");
        scanf("%d", &quantity_);
        quantity[item] += quantity_;
        printf("\nOrder added successfully.\n\n--------------------------------");
    }
}

void* calculateTotal(void* arg){
    while(1){
        pthread_mutex_lock(&lock);
        printf("\n\n========== Current Billing Bill ========");
        for(int i=0; i<MAX_ITEMS; i++){
            if(quantity[i] > 0){
                printf("\nItem %d: %d * %d = %d", i+1, menu[i], quantity[i], menu[i]*quantity[i]);
                total += menu[i]*quantity[i];
                quantity[i] = 0;
            }
        }
        printf("\nTotal: %d \n\n==============================================\n", total);
        total = 0;
        pthread_mutex_unlock(&lock);
    }
}

int main(){
    pthread_t billingThreads[BILLING_THREADS];
    pthread_mutex_init(&lock, NULL);

    for(int i=0; i<BILLING_THREADS; i++){
        if(i==0){
            pthread_create(&billingThreads[i], NULL, takeOrder, NULL);
        } else {
            pthread_create(&billingThreads[i], NULL, calculateTotal, NULL);
        }
    }

    for(int i=0; i<BILLING_THREADS; i++){
        pthread_join(billingThreads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}