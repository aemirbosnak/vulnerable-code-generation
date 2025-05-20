//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct {
    char operation[10];
    double operand1;
    double operand2;
    double result;
} CalculationRequest;

void* perform_calculation(void* arg) {
    CalculationRequest* req = (CalculationRequest*)arg;
    
    if (strcmp(req->operation, "add") == 0) {
        req->result = req->operand1 + req->operand2;
    } else if (strcmp(req->operation, "subtract") == 0) {
        req->result = req->operand1 - req->operand2;
    } else if (strcmp(req->operation, "multiply") == 0) {
        req->result = req->operand1 * req->operand2;
    } else if (strcmp(req->operation, "divide") == 0) {
        if (req->operand2 != 0) {
            req->result = req->operand1 / req->operand2;
        } else {
            printf("Error: Division by zero\n");
            req->result = 0;
        }
    } else if (strcmp(req->operation, "sin") == 0) {
        req->result = sin(req->operand1);
    } else if (strcmp(req->operation, "cos") == 0) {
        req->result = cos(req->operand1);
    } else if (strcmp(req->operation, "tan") == 0) {
        req->result = tan(req->operand1);
    } else {
        printf("Error: Unknown operation\n");
        req->result = 0;
    }
    
    return NULL;
}

void get_input(CalculationRequest* req) {
    printf("Enter operation (add/subtract/multiply/divide/sin/cos/tan): ");
    scanf("%s", req->operation);
    if (strcmp(req->operation, "sin") == 0 || strcmp(req->operation, "cos") == 0 || strcmp(req->operation, "tan") == 0) {
        printf("Enter operand: ");
        scanf("%lf", &req->operand1);
        req->operand2 = 0; // for unary operations
    } else {
        printf("Enter first operand: ");
        scanf("%lf", &req->operand1);
        printf("Enter second operand: ");
        scanf("%lf", &req->operand2);
    }
}

int main() {
    pthread_t threads[MAX];
    CalculationRequest requests[MAX];
    int count = 0;
    char continue_calc;

    do {
        get_input(&requests[count]);
        
        if (pthread_create(&threads[count], NULL, perform_calculation, (void*)&requests[count]) != 0) {
            printf("Error creating thread\n");
            return 1;
        }
        
        count++;
        
        printf("Would you like to perform another calculation? (y/n): ");
        scanf(" %c", &continue_calc);
        
    } while (continue_calc == 'y' && count < MAX);

    // Wait for all threads to finish and print results
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
        printf("Operation: %s, Result: %.4f\n", requests[i].operation, requests[i].result);
    }

    return 0;
}