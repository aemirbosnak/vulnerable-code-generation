//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdbool.h>

#define MAZE_SIZE 6
#define NUM_WORKERS 2
#define MSG_SIZE 128

typedef struct {
    long msg_type;
    int x;
    int y;
    int path[MAZE_SIZE * MAZE_SIZE];
    int path_length;
} Message;

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'S', '1', '1', '1', '1', '1'},
    {'0', '0', '1', '0', '0', '1'},
    {'1', '0', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '0', '1'},
    {'1', '1', '1', 'E', '1', '1'}
};

bool is_valid_move(int x, int y) {
    return (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && (maze[x][y] == '0' || maze[x][y] == 'E'));
}

void worker_function(int msg_queue_id) {
    Message msg;

    while (1) {
        // Receive a message
        msgrcv(msg_queue_id, &msg, sizeof(msg) - sizeof(long), 1, 0);

        // Check for the end condition signal
        if (msg.x == -1 && msg.y == -1) {
            break; // Exit worker if end signal is received
        }

        int x = msg.x;
        int y = msg.y;

        // Four possible directions: up, down, left, right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if (is_valid_move(new_x, new_y)) {
                // Create a new message for the path
                Message new_msg;
                new_msg.msg_type = 1;
                new_msg.x = new_x;
                new_msg.y = new_y;

                // Update the path
                memcpy(new_msg.path, msg.path, sizeof(int) * msg.path_length);
                new_msg.path[new_msg.path_length] = new_x * MAZE_SIZE + new_y;
                new_msg.path_length = msg.path_length + 1;

                // Check for exit condition
                if (maze[new_x][new_y] == 'E') {
                    printf("Path found: ");
                    for (int j = 0; j < new_msg.path_length; j++) {
                        int p = new_msg.path[j];
                        printf("(%d,%d) ", p / MAZE_SIZE, p % MAZE_SIZE);
                    }
                    printf("\n");
                    new_msg.x = -1; // Send exit signal
                    new_msg.y = -1;
                }

                // Send the message to the next worker
                msgsnd(msg_queue_id, &new_msg, sizeof(new_msg) - sizeof(long), 0);
            }
        }
    }
}

int main() {
    // Create message queue
    int msg_queue_id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msg_queue_id < 0) {
        perror("msgget");
        exit(1);
    }

    // Process for workers
    for (int i = 0; i < NUM_WORKERS; i++) {
        if (fork() == 0) {
            worker_function(msg_queue_id);
            exit(0);
        }
    }

    // Initial path message
    Message initial_msg;
    initial_msg.msg_type = 1;
    initial_msg.x = 0; // Starting point
    initial_msg.y = 0; // Starting point
    initial_msg.path_length = 0;
    initial_msg.path[0] = 0; // Add start position to path

    // Send initial message to workers
    msgsnd(msg_queue_id, &initial_msg, sizeof(initial_msg) - sizeof(long), 0);

    // Wait for all workers to finish
    for (int i = 0; i < NUM_WORKERS; i++) {
        wait(NULL);
    }

    // Clean up message queue
    msgctl(msg_queue_id, IPC_RMID, NULL);

    return 0;
}