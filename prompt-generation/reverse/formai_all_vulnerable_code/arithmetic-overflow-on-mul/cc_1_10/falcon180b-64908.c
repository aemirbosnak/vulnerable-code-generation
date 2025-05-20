//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_ROWS 4
#define MAX_COLS 4
#define TOTAL_CARDS (MAX_ROWS * MAX_COLS)
#define NUM_THREADS 2
#define SLEEP_TIME 100

int rows, cols, num_cards;
int cards[TOTAL_CARDS];
int matches[MAX_ROWS][MAX_COLS];
int thread_id[NUM_THREADS];

void init_cards() {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cards[i * cols + j] = rand() % 10 + 1;
        }
    }
}

void print_cards() {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%2d ", cards[i * cols + j]);
        }
        printf("\n");
    }
}

void shuffle_cards() {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < TOTAL_CARDS; i++) {
        j = rand() % TOTAL_CARDS;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void flip_card(int row, int col) {
    int index = row * cols + col;
    if (cards[index] == 0) {
        cards[index] = 1;
    } else {
        cards[index] = 0;
    }
}

void *thread_func(void *arg) {
    int id = *(int *) arg;
    int row = id / cols;
    int col = id % cols;
    int count = 0;
    while (count < 5) {
        flip_card(row, col);
        usleep(SLEEP_TIME);
        count++;
    }
    return NULL;
}

int main() {
    int i, j;
    srand(time(NULL));
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);
    num_cards = rows * cols;

    init_cards();
    shuffle_cards();

    printf("Initial board:\n");
    print_cards();

    pthread_t threads[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_id[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int matches_found = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (cards[i * cols + j] == 0) {
                matches[i][j] = 1;
                matches_found++;
            }
        }
    }

    if (matches_found == TOTAL_CARDS) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost. Try again.\n");
    }

    return 0;
}