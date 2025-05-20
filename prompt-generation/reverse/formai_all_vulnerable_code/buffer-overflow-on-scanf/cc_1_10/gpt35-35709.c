//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

pthread_t tid[3];
pthread_mutex_t lock;

double result = 0;
double memory = 0;

bool is_clear = true;

void* addition(void *arg) {
    double num = *((double*) arg);
    pthread_mutex_lock(&lock);
    result += num;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* subtraction(void *arg) {
    double num = *((double*) arg);
    pthread_mutex_lock(&lock);
    result -= num;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* multiplication(void *arg) {
    double num = *((double*) arg);
    pthread_mutex_lock(&lock);
    result *= num;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* division(void *arg) {
    double num = *((double*) arg);
    pthread_mutex_lock(&lock);
    result /= num;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* clear(void *arg) {
    pthread_mutex_lock(&lock);
    result = 0;
    is_clear = true;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* memory_store(void *arg) {
    pthread_mutex_lock(&lock);
    memory = result;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* memory_recall(void *arg) {
    pthread_mutex_lock(&lock);
    result = memory;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void print_result() {
    printf("Result: %lf\n", result);
}

void print_menu() {
    printf("\n==== Calculator Menu ====\n"
           "1. Add\n"
           "2. Subtract\n"
           "3. Multiply\n"
           "4. Divide\n"
           "5. Clear\n"
           "6. Memory Store\n"
           "7. Memory Recall\n"
           "8. Exit\n"
          );
}

int main() {
    int choice;
    double num;
    
    pthread_mutex_init(&lock, NULL);
    
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a number to add: ");
                scanf("%lf", &num);
                
                pthread_create(&(tid[0]), NULL, &addition, &num);
                pthread_join(tid[0], NULL);
                
                print_result();
                is_clear = false;
                break;
            case 2:
                printf("Enter a number to subtract: ");
                scanf("%lf", &num);
                
                pthread_create(&(tid[1]), NULL, &subtraction, &num);
                pthread_join(tid[1], NULL);
                
                print_result();
                is_clear = false;
                break;
            case 3:
                printf("Enter a number to multiply: ");
                scanf("%lf", &num);
                
                pthread_create(&(tid[2]), NULL, &multiplication, &num);
                pthread_join(tid[2], NULL);
                
                print_result();
                is_clear = false;
                break;
            case 4:
                printf("Enter a number to divide: ");
                scanf("%lf", &num);
                
                pthread_create(&(tid[3]), NULL, &division, &num);
                pthread_join(tid[3], NULL);
                
                print_result();
                is_clear = false;
                break;
            case 5:
                pthread_create(&(tid[4]), NULL, &clear, NULL);
                pthread_join(tid[4], NULL);
                
                printf("Calculator has been cleared.\n");
                is_clear = true;
                break;
            case 6:
                pthread_create(&(tid[5]), NULL, &memory_store, NULL);
                pthread_join(tid[5], NULL);
                
                printf("Result stored in memory.\n");
                is_clear = false;
                break;
            case 7:
                if (memory == 0) {
                    printf("Memory is empty.\n");
                } else {
                    pthread_create(&(tid[6]), NULL, &memory_recall, NULL);
                    pthread_join(tid[6], NULL);
                    
                    printf("Memory value recalled.\n");
                    is_clear = false;
                }
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 8);
    
    pthread_mutex_destroy(&lock);
    
    return 0;
}