//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

struct thread_data {
    char *string;
    int operation;
};

void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char *string = data->string;
    int operation = data->operation;

    switch(operation) {
        case 0: // Convert to uppercase
            for(int i=0; i<strlen(string); i++) {
                string[i] = toupper(string[i]);
            }
            break;
        case 1: // Convert to lowercase
            for(int i=0; i<strlen(string); i++) {
                string[i] = tolower(string[i]);
            }
            break;
        case 2: // Reverse the string
            for(int i=0, j=strlen(string)-1; i<j; i++, j--) {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
            break;
        default:
            break;
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    int num_threads = 0;
    char input[MAX_STRING_LENGTH];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the strings to be manipulated:\n");
    for(int i=0; i<num_threads; i++) {
        scanf("%s", input);
        data[i].string = strdup(input);
        printf("Enter the operation for string %d (0 for uppercase, 1 for lowercase, 2 for reverse): ", i+1);
        scanf("%d", &data[i].operation);
    }

    for(int i=0; i<num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    for(int i=0; i<num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}