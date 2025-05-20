//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int menu1 = 0, menu2 = 0, menu3 = 0, menu4 = 0;
int total = 0;

pthread_mutex_t mutex;

void *order1(void *n) {
    printf("Enter the quantity of Menu 1: ");
    scanf("%d", &menu1);
    pthread_mutex_lock(&mutex);
    total += (menu1 * 200);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *order2(void *n) {
    printf("Enter the quantity of Menu 2: ");
    scanf("%d", &menu2);
    pthread_mutex_lock(&mutex);
    total += (menu2 * 250);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *order3(void *n) {
    printf("Enter the quantity of Menu 3: ");
    scanf("%d", &menu3);
    pthread_mutex_lock(&mutex);
    total += (menu3 * 300);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *order4(void *n) {
    printf("Enter the quantity of Menu 4: ");
    scanf("%d", &menu4);
    pthread_mutex_lock(&mutex);
    total += (menu4 * 400);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t tid[4];
    
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid[0], NULL, order1, NULL);
    pthread_create(&tid[1], NULL, order2, NULL);
    pthread_create(&tid[2], NULL, order3, NULL);
    pthread_create(&tid[3], NULL, order4, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);

    printf("Menu 1 x%d  = 200 x %d = %d\n", menu1, menu1, menu1*200);
    printf("Menu 2 x%d  = 250 x %d = %d\n", menu2, menu2, menu2*250);
    printf("Menu 3 x%d  = 300 x %d = %d\n", menu3, menu3, menu3*300);
    printf("Menu 4 x%d  = 400 x %d = %d\n", menu4, menu4, menu4*400);
    printf("Total Bill = %d\n", total);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}