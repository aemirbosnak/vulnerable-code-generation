//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    void (*operation)(char*, char*);
} Task;

void* reverse_string(void* arg) {
    Task* task = (Task*) arg;
    int len = strlen(task->input);
    for (int i = 0; i < len; i++) {
        task->output[i] = task->input[len - i - 1];
    }
    task->output[len] = '\0';
    return NULL;
}

void* to_uppercase(void* arg) {
    Task* task = (Task*) arg;
    int i = 0;
    while (task->input[i]) {
        task->output[i] = toupper(task->input[i]);
        i++;
    }
    task->output[i] = '\0';
    return NULL;
}

void* to_lowercase(void* arg) {
    Task* task = (Task*) arg;
    int i = 0;
    while (task->input[i]) {
        task->output[i] = tolower(task->input[i]);
        i++;
    }
    task->output[i] = '\0';
    return NULL;
}

void print_options() {
    printf("Choose a string manipulation option:\n");
    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Convert to Lowercase\n");
    printf("4. Exit\n");
}

int main() {
    char continue_choice = 'y';
    
    while (continue_choice == 'y') {
        Task task;
        pthread_t thread_id;

        print_options();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        if (choice == 4) {
            break;
        }

        printf("Enter a string (max %d characters): ", MAX_LENGTH - 1);
        fgets(task.input, MAX_LENGTH, stdin);
        
        // Remove newline character if present
        size_t len = strlen(task.input);
        if (len > 0 && task.input[len - 1] == '\n') {
            task.input[len - 1] = '\0';
        }

        switch (choice) {
            case 1:
                task.operation = reverse_string;
                break;
            case 2:
                task.operation = to_uppercase;
                break;
            case 3:
                task.operation = to_lowercase;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        printf("Processing your request...\n");

        // Create a new thread for the chosen operation
        if (pthread_create(&thread_id, NULL, task.operation, &task) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }

        // Wait for the thread to finish
        pthread_join(thread_id, NULL);

        // Display the output
        printf("Output: %s\n", task.output);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continue_choice);
    }

    printf("Thank you for using the string manipulation program!\n");
    return 0;
}