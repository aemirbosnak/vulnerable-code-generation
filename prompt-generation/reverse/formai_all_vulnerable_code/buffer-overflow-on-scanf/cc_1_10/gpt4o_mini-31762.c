//GPT-4o-mini DATASET v1.0 Category: Chess engine ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define SIZE 8

char board[SIZE][SIZE];
pthread_mutex_t mutex;

void initialize_board() {
    const char* initial_positions[] = {
        "rnbqkbrr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBRR"
    };

    for (int i = 0; i < SIZE; i++) {
        strcpy(board[i], initial_positions[i]);
    }
}

void print_board() {
    pthread_mutex_lock(&mutex);
    printf("\n  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
    pthread_mutex_unlock(&mutex);
}

int is_valid_move(int start_x, int start_y, int end_x, int end_y) {
    char piece = board[start_y][start_x];
    if (piece == ' ') {
        return 0; // No piece to move
    }
    // Basic validation (you can add more complex rules for actual chess here)
    return (end_x >= 0 && end_x < SIZE && end_y >= 0 && end_y < SIZE);
}

void* move_piece(void* args) {
    int* move = (int*)args;
    int start_x = move[0], start_y = move[1];
    int end_x = move[2], end_y = move[3];

    // Sleep to simulate thinking time
    sleep(1);
    
    if (is_valid_move(start_x, start_y, end_x, end_y)) {
        pthread_mutex_lock(&mutex);
        board[end_y][end_x] = board[start_y][start_x];
        board[start_y][start_x] = ' ';
        printf("Move made from (%d, %d) to (%d, %d)\n", start_x, start_y, end_x, end_y);
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Invalid move from (%d, %d) to (%d, %d)\n", start_x, start_y, end_x, end_y);
    }
    
    free(args);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    initialize_board();
    
    print_board();
    
    while (1) {
        int* move = (int*)malloc(4 * sizeof(int));
        
        printf("Enter your move (ex: e2 e4): ");
        char start[3], end[3];
        scanf("%s %s", start, end);

        move[0] = start[0] - 'a'; // Convert char to int
        move[1] = SIZE - (start[1] - '0'); // Convert 1-8 to 0-7
        move[2] = end[0] - 'a';
        move[3] = SIZE - (end[1] - '0');
        
        pthread_t thread;
        if (pthread_create(&thread, NULL, move_piece, move)) {
            printf("Error creating thread\n");
            free(move);
        }
        pthread_detach(thread);
        
        print_board();
    }
    
    pthread_mutex_destroy(&mutex);
    return 0;
}