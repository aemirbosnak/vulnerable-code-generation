//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold data for each calculation thread
struct thread_data {
    double operand1;
    double operand2;
    char operator;
    double result;
};

// The calculation function run by each thread
void *calculate(void *t_data) {
    struct thread_data *data;

    data = (struct thread_data *)t_data;

    switch (data->operator) {
        case '+':
            data->result = data->operand1 + data->operand2;
            break;
        case '-':
            data->result = data->operand1 - data->operand2;
            break;
        case '*':
            data->result = data->operand1 * data->operand2;
            break;
        case '/':
            data->result = data->operand1 / data->operand2;
            break;
    }
    pthread_exit(NULL);
}

int main() {
    // Create an array of thread data structures
    struct thread_data thread_data_array[5];

    // Create an array of threads to run the calculations
    pthread_t threads[5];

    int i;
    for (i = 0; i < 5; i++) {
        double operand1, operand2;
        char operator;

        printf("Enter an operation (+, -, *, /) and two operands:\n");
        scanf("%c %lf %lf", &operator, &operand1, &operand2);

        // Set the data for this thread
        thread_data_array[i].operand1 = operand1;
        thread_data_array[i].operand2 = operand2;
        thread_data_array[i].operator = operator;

        // Create the thread for this calculation
        int rc = pthread_create(&threads[i], NULL, calculate, (void *)&thread_data_array[i]);

        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish before printing the results
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results for each thread
    for (i = 0; i < 5; i++) {
        printf("%lf %c %lf = %lf\n", thread_data_array[i].operand1, thread_data_array[i].operator, thread_data_array[i].operand2, thread_data_array[i].result);
    }

    return 0;
}