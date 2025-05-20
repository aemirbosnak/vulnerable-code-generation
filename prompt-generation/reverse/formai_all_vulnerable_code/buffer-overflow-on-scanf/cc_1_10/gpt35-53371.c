//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_DATA_SIZE 100
#define NUM_THREADS 2

typedef struct data {
    int id;
    char name[50];
    int age;
} Data;

Data data_list[MAX_DATA_SIZE];
int data_count = 0;

pthread_mutex_t mutex;

bool is_valid_data(Data d) {
    if (d.id <= 0 || d.age <= 0 || d.age > 150) {
        return false;
    }
    // Other custom validation logic can be added here
    return true;
}

void insert_data(Data d) {
    pthread_mutex_lock(&mutex);
    if (!is_valid_data(d)) {
        printf("Invalid data. Cannot insert.\n");
        return;
    }
    data_list[data_count++] = d;
    printf("Data inserted successfully.\n");
    pthread_mutex_unlock(&mutex);
}

void* get_input_thread(void* arg) {
    while (true) {
        Data new_data;
        printf("\nEnter data (ID Name Age): ");
        scanf("%d %s %d", &new_data.id, new_data.name, &new_data.age);
        insert_data(new_data);
    }
    pthread_exit(NULL);
}

void* print_data_thread(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        printf("\nData List:\n");
        for (int i = 0; i < data_count; i++) {
            printf("%d\t%s\t%d\n", data_list[i].id, data_list[i].name, data_list[i].age);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&threads[0], NULL, get_input_thread, NULL);
    pthread_create(&threads[1], NULL, print_data_thread, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}