//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_BUFF_SIZE 1024

struct thread_input {
    char *buffer;
    int buffer_size;
    int *open_parens;
    int *closed_parens;
    bool *syntax_error;
};

void *parse_buffer(void *arg) {
    struct thread_input *input = (struct thread_input*) arg;
    
    int open_parens = 0;
    int closed_parens = 0;
    
    for(int i = 0; i < input->buffer_size; i++) {
        if(input->buffer[i] == '(') {
            open_parens++;
        }
        else if(input->buffer[i] == ')') {
            if(open_parens == 0) {
                *(input->syntax_error) = true;
                return NULL;
            }
            closed_parens++;
        }
    }
    
    *(input->open_parens) = open_parens;
    *(input->closed_parens) = closed_parens;
    
    return NULL;
}

int main() {
    char buffer[MAX_BUFF_SIZE];
    int buffer_size = 0;
    int open_parens = 0;
    int closed_parens = 0;
    bool syntax_error = false;
    
    // Read code from console
    printf("Enter code to parse:\n");
    while(fgets(buffer + buffer_size, MAX_BUFF_SIZE - buffer_size, stdin)) {
        buffer_size += strlen(buffer + buffer_size);
        if(buffer[buffer_size - 1] == '\n') {
            break;
        }
    }
    
    // Create threads to parse buffer
    pthread_t threads[MAX_THREADS];
    struct thread_input thread_inputs[MAX_THREADS];
    int threads_to_create = buffer_size > MAX_THREADS ? MAX_THREADS : buffer_size;
    int buffer_slice_size = buffer_size / threads_to_create;
    for(int i = 0; i < threads_to_create; i++) {
        thread_inputs[i].buffer = buffer + i * buffer_slice_size;
        thread_inputs[i].buffer_size = buffer_slice_size;
        thread_inputs[i].open_parens = &open_parens;
        thread_inputs[i].closed_parens = &closed_parens;
        thread_inputs[i].syntax_error = &syntax_error;
        
        pthread_create(&threads[i], NULL, parse_buffer, (void*) &thread_inputs[i]);
    }
    
    // Wait for threads to complete
    for(int i = 0; i < threads_to_create; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Check for syntax errors
    if(syntax_error) {
        printf("Syntax error: mismatched parentheses\n");
        return 1;
    }
    
    // Print results
    printf("Open parentheses: %d\n", open_parens);
    printf("Closed parentheses: %d\n", closed_parens);
    
    return 0;
}