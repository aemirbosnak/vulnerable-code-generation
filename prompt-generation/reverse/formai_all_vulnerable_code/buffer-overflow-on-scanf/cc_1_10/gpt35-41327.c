//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_COLOR_LENGTH 7
#define TOTAL_COLORS 7

// This array holds the supported colors and their correspondig codes.
char* colors[] = {"red", "green", "blue", "yellow", "white", "magenta", "cyan"};
char* color_codes[] = {"#FF0000", "#00FF00", "#0000FF", "#FFFF00", "#FFFFFF", "#FF00FF", "#00FFFF"};

// This data structure holds the input and output data for the threads.
struct thread_data_t {
    pthread_t thread_id;
    int thread_num;
    char to_convert[MAX_COLOR_LENGTH];
    char converted_code[MAX_COLOR_LENGTH];
};

// This method is the function executed by each thread.
void* convert_color_code(void* thread_arg) {
    struct thread_data_t* thread_data;
    thread_data = (struct thread_data_t*) thread_arg;

    printf("Thread #%d executing...\n", thread_data->thread_num);

    // Look for the color in the array.
    int i;
    for (i = 0; i < TOTAL_COLORS; i++) {
        if (strcmp(thread_data->to_convert, colors[i]) == 0) {
            strcpy(thread_data->converted_code, color_codes[i]);
            break;
        }
    }

    // If the color was not found, return an error message.
    if (i == TOTAL_COLORS) {
        strcpy(thread_data->converted_code, "ERROR");
    }

    pthread_exit(NULL);
}

int main() {
    int total_threads = 0;
    char input_color[MAX_COLOR_LENGTH];

    printf("Welcome to the Color Code Converter!\n");

    while (total_threads < MAX_THREADS) {
        printf("Enter a color to convert (or \"exit\" to quit): ");
        scanf("%s", input_color);

        // Exit condition.
        if (strcmp(input_color, "exit") == 0) {
            break;
        }

        // Create a new thread to handle the color conversion.
        struct thread_data_t* thread_data = (struct thread_data_t*) malloc(sizeof(struct thread_data_t));
        thread_data->thread_num = total_threads;
        strcpy(thread_data->to_convert, input_color);

        int rc = pthread_create(&thread_data->thread_id, NULL, convert_color_code, (void*) thread_data);

        // If the thread was successfully created, increment the thread counter.
        if (rc == 0) {
            total_threads++;
        } else {
            printf("Unable to create thread. Error code: %d\n", rc);
            free(thread_data);
        }
    }

    // Join all threads.
    for (int i = 0; i < total_threads; i++) {
        struct thread_data_t* thread_data;
        pthread_join(thread_data[i].thread_id, NULL);

        printf("%s = %s\n", thread_data[i].to_convert, thread_data[i].converted_code);

        free(thread_data);
    }

    printf("Goodbye!\n");

    return 0;
}