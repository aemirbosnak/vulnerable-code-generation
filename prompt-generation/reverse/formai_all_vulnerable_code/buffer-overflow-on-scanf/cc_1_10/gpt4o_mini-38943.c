//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

typedef struct {
    int decimal;
    char hex_string[10];
} ConversionTask;

void *convert_to_hex(void *arg) {
    ConversionTask *task = (ConversionTask *)arg;
    sprintf(task->hex_string, "%X", task->decimal);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ConversionTask tasks[MAX_THREADS];
    int task_count = 0;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("You can enter up to %d decimal numbers (enter -1 to finish):\n", MAX_THREADS);
    
    while (task_count < MAX_THREADS) {
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        if (decimal == -1) {
            break;
        }

        tasks[task_count].decimal = decimal;
        
        if (pthread_create(&threads[task_count], NULL, convert_to_hex, (void *)&tasks[task_count])) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
        
        task_count++;
    }

    for (int i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nResults:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Decimal: %d => Hexadecimal: %s\n", tasks[i].decimal, tasks[i].hex_string);
    }

    return 0;
}