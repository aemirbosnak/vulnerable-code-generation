//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PLAYERS 4
#define NUM_RESOURCES 5

struct player {
    int id;
    int resources[NUM_RESOURCES];
    int num_resources;
};

struct task {
    int player_id;
    int resource_id;
    int amount;
};

struct task_queue {
    struct task *tasks;
    int num_tasks;
};

struct game_state {
    struct player players[NUM_PLAYERS];
    struct task_queue task_queue;
};

// Initialize the game state
void init_game_state(struct game_state *game_state) {
    // Initialize the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        game_state->players[i].id = i;
        for (int j = 0; j < NUM_RESOURCES; j++) {
            game_state->players[i].resources[j] = rand() % 10;
            game_state->players[i].num_resources++;
        }
    }

    // Initialize the task queue
    game_state->task_queue.tasks = NULL;
    game_state->task_queue.num_tasks = 0;
}

// Add a task to the task queue
void add_task(struct game_state *game_state, struct task *task) {
    // Reallocate the task queue if necessary
    if (game_state->task_queue.num_tasks == 0) {
        game_state->task_queue.tasks = malloc(sizeof(struct task));
    } else {
        game_state->task_queue.tasks = realloc(game_state->task_queue.tasks, sizeof(struct task) * (game_state->task_queue.num_tasks + 1));
    }

    // Add the task to the queue
    game_state->task_queue.tasks[game_state->task_queue.num_tasks] = *task;
    game_state->task_queue.num_tasks++;
}

// Execute the next task in the task queue
void execute_next_task(struct game_state *game_state) {
    // Get the next task from the queue
    struct task task = game_state->task_queue.tasks[0];

    // Remove the task from the queue
    for (int i = 0; i < game_state->task_queue.num_tasks - 1; i++) {
        game_state->task_queue.tasks[i] = game_state->task_queue.tasks[i + 1];
    }
    game_state->task_queue.num_tasks--;

    // Execute the task
    if (game_state->players[task.player_id].resources[task.resource_id] >= task.amount) {
        game_state->players[task.player_id].resources[task.resource_id] -= task.amount;
        printf("Player %d produced %d units of resource %d\n", task.player_id, task.amount, task.resource_id);
    } else {
        printf("Player %d does not have enough resources to produce %d units of resource %d\n", task.player_id, task.amount, task.resource_id);
    }
}

// Main game loop
void game_loop(struct game_state *game_state) {
    while (1) {
        // Get input from the players
        for (int i = 0; i < NUM_PLAYERS; i++) {
            int player_id = i;
            int resource_id;
            int amount;
            printf("Player %d, enter the resource you want to produce and the amount: ", player_id);
            scanf("%d %d", &resource_id, &amount);

            // Add the task to the queue
            struct task task = { .player_id = player_id, .resource_id = resource_id, .amount = amount };
            add_task(game_state, &task);
        }

        // Execute the next task in the queue
        execute_next_task(game_state);

        // Check if the game is over
        int all_players_have_resources = 1;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (game_state->players[i].num_resources == 0) {
                all_players_have_resources = 0;
                break;
            }
        }

        if (!all_players_have_resources) {
            printf("Game over!\n");
            break;
        }
    }
}

// Main function
int main() {
    // Initialize the game state
    struct game_state game_state;
    init_game_state(&game_state);

    // Start the game loop
    game_loop(&game_state);

    return 0;
}