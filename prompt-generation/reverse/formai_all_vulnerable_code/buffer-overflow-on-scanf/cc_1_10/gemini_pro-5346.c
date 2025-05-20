//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// ASCII art character set
static char *charset = " .:-=+*#%@"
                        ".,-=+*#%"
                        "....:=-+*#"
                        "........:=-+*"
                        ".............:="
                        "................"
                        "................."
                        ".................."
                        "...................:";

// Thread data structure
typedef struct {
    int width;
    int height;
    char *text;
    char *art;
} thread_data;

// Thread function
void* generate_art(void *arg) {
    thread_data *data = (thread_data*) arg;
    int i, j;
    char *art = data->art;

    // Iterate over each character in the text
    for (i = 0; i < data->width; i++) {
        // Get the character's ASCII code
        int code = (int) data->text[i];

        // Convert the ASCII code to an index in the charset
        int index = code - 32;

        // Iterate over each row in the character's art
        for (j = 0; j < data->height; j++) {
            // Get the ASCII value of the character at the current index and row
            int value = charset[index * data->height + j];

            // Set the corresponding character in the art to the ASCII value
            art[i * data->height + j] = value;
        }
    }

    // Return the art
    return data->art;
}

int main() {
    // Get the input text and size
    char *text;
    int width, height;
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", text);
    printf("Enter the width and height of the art: ");
    scanf("%d %d", &width, &height);

    // Create a thread pool
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    // Divide the text into chunks and assign each chunk to a thread
    int chunk_size = width / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].width = chunk_size;
        data[i].height = height;
        data[i].text = text + i * chunk_size;
        data[i].art = malloc(chunk_size * height);

        // Create a thread to generate the art
        pthread_create(&threads[i], NULL, generate_art, (void*) &data[i]);
    }

    // Join the threads and collect the results
    char *art = malloc(width * height);
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        memcpy(art + i * chunk_size * height, data[i].art, chunk_size * height);
        free(data[i].art);
    }

    // Print the art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i * width + j]);
        }
        printf("\n");
    }

    // Free the memory
    free(art);
    free(text);

    return 0;
}