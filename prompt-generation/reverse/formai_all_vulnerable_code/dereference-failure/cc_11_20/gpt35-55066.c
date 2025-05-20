//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
// A multiplayer game using Interprocess Communication

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAP_SIZE 4096

typedef struct {
    int player_id;
    char message[256];
} shared_data;

int main() {
    int fd;
    pid_t pid;
    char *player_name;
    shared_data *shared_memory;

    // Create shared memory
    fd = shm_open("/myshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    ftruncate(fd, MAP_SIZE);
    shared_memory = mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Get player name
    player_name = (char *)malloc(256);
    printf("Enter your name: ");
    fgets(player_name, 256, stdin);
    player_name[strlen(player_name)-1] = '\0'; // Remove newline

    // Create child processes for players
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        int player_id = 1;
        while (1) {
            // Wait for message from other player
            while (shared_memory->player_id != player_id) {
                usleep(10000);
            }

            // Print message from other player
            printf("%s: %s\n", (player_id == 1) ? "Player 2" : "Player 1", shared_memory->message);

            // Get message from current player
            printf("%s, enter message: ", player_name);
            fgets(shared_memory->message, 256, stdin);
            shared_memory->message[strlen(shared_memory->message)-1] = '\0'; // Remove newline

            // Switch player ID
            shared_memory->player_id = (player_id == 1) ? 2 : 1;
        }
    }
    else {
        // Parent process
        int player_id = 2;
        shared_memory->player_id = 1; // Start with player 1

        while (1) {
            // Get message from current player
            printf("%s, enter message: ", player_name);
            fgets(shared_memory->message, 256, stdin);
            shared_memory->message[strlen(shared_memory->message)-1] = '\0'; // Remove newline

            // Switch player ID
            shared_memory->player_id = (player_id == 1) ? 2 : 1;

            // Wait for message from other player
            while (shared_memory->player_id != player_id) {
                usleep(10000);
            }

            // Print message from other player
            printf("%s: %s\n", (player_id == 1) ? "Player 2" : "Player 1", shared_memory->message);
        }
    }

    // Unmap shared memory
    munmap(shared_memory, MAP_SIZE);

    // Close shared memory object
    close(fd);

    return 0;
}