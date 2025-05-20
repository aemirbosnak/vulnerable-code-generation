//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_MSG_LEN 100
#define CHARSET_LEN 26

char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                       "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char *alphabets = "abcdefghijklmnopqrstuvwxyz";

char msg[MAX_MSG_LEN];
int cur_pos = 0, num_threads;

pthread_mutex_t mutex;

void* convert_to_morse_code(void *arg) {
    int thread_id = *(int*)arg;
    int chunk_size = strlen(msg) / num_threads;
    int start_pos = thread_id * chunk_size;
    int end_pos = start_pos + chunk_size - 1;

    if (thread_id == num_threads-1) {
        end_pos = strlen(msg) - 1;
    }

    for (int i = start_pos; i <= end_pos; i++) {
        if (msg[i] == ' ') {
            printf(" ");
            continue;
        }

        int alpha_index = msg[i] - 'a';
        printf("%s ", morse_codes[alpha_index]);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the message to convert to Morse code (max length=%d):\n", MAX_MSG_LEN);
    fgets(msg, sizeof(msg), stdin);

    printf("Enter the number of threads to use:\n");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, convert_to_morse_code, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("\n");
    return 0;
}